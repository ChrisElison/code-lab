# Vibecoded Grim Dawn character savefile parser
# Grok spat this code out and amazingly it works!
# I will edit it and see if I can get more stats out and parse the tagSkillClassName into a proper GD class combo
# 2026-05-25 18:40

import struct
import sys


class CryptoDataBuffer:
    XOR_KEY = 0x55555555  # 1431655765
    PRIME = 39916801
    TABLE_SIZE = 256

    def __init__(self, data: bytes):
        self.data = data
        self.cursor = 0
        self.key = 0
        self.table = [0] * self.TABLE_SIZE

    def read_uint(self) -> int:
        """Read raw 4-byte unsigned int (little-endian)."""
        if self.cursor + 4 > len(self.data):
            raise EOFError("Unexpected end of file")
        value = struct.unpack_from("<I", self.data, self.cursor)[0]
        self.cursor += 4
        return value

    def read_bytes(self, length: int) -> bytes:
        """Read raw bytes."""
        if self.cursor + length > len(self.data):
            raise EOFError("Unexpected end of file")
        value = self.data[self.cursor : self.cursor + length]
        self.cursor += length
        return value

    def generate_table(self, pkey: int):
        self.table = [0] * self.TABLE_SIZE
        for i in range(self.TABLE_SIZE):
            pkey = ((pkey >> 1) | (pkey << 31)) & 0xFFFFFFFF
            pkey = (pkey * self.PRIME) & 0xFFFFFFFF
            self.table[i] = pkey

    def update_key(self, raw_bytes: bytes):
        """Update key using original (encrypted) bytes."""
        for b in raw_bytes:
            self.key = (self.key ^ self.table[b]) & 0xFFFFFFFF

    def read_crypto_key(self):
        num = self.read_uint()
        num ^= self.XOR_KEY
        self.key = num
        self.generate_table(num)

    def read_crypto_int_unchecked(self, update_key=True) -> int:
        num = self.read_uint()
        value = (num ^ self.key) & 0xFFFFFFFF
        value = struct.unpack("<i", struct.pack("<I", value))[0]  # signed int
        if update_key:
            self.update_key(struct.pack("<I", num))
        return value

    def read_crypto_byte(self) -> int:
        raw = self.read_bytes(1)
        b = raw[0]
        value = (b ^ (self.key & 0xFF)) & 0xFF
        self.update_key(raw)
        return value

    def read_crypto_bool(self) -> bool:
        return self.read_crypto_byte() == 1

    def read_crypto_string(self) -> str:
        length = self.read_crypto_int_unchecked()  # length as uint
        if length == 0:
            return ""
        raw = self.read_bytes(length)
        decrypted = bytearray()
        for b in raw:
            num2 = b ^ (self.key & 0xFF)
            self.key = (self.key ^ self.table[b]) & 0xFFFFFFFF
            decrypted.append(num2)
        return decrypted.decode("ascii", errors="replace")

    def read_crypto_wstring(self) -> str:
        """Wide string (UTF-8 in practice for names)."""
        length = self.read_crypto_int_unchecked()  # number of *characters*
        if length == 0:
            return ""
        raw = self.read_bytes(length * 2)
        decrypted = bytearray()
        for b in raw:
            num2 = b ^ (self.key & 0xFF)
            self.key = (self.key ^ self.table[b]) & 0xFFFFFFFF
            decrypted.append(num2)
        return decrypted.decode("utf-8", errors="replace")

    def read_block_end(self):
        self.read_crypto_int_unchecked(False)  # usually 0


# ====================== High-level Parser ======================


def parse_gdc(filename: str):
    with open(filename, "rb") as f:
        data = f.read()

    reader = CryptoDataBuffer(data)

    reader.read_crypto_key()

    # Header magic/version
    magic = reader.read_crypto_int_unchecked()
    if magic != 0x58434447:  # "GDCX"
        raise ValueError("Invalid GDC file")

    reader.read_crypto_int_unchecked()  # version (usually 1)

    # Read Header
    name = reader.read_crypto_wstring()
    sex = reader.read_crypto_byte()
    class_id = reader.read_crypto_string()
    level = reader.read_crypto_int_unchecked()
    hardcore = reader.read_crypto_bool()

    reader.read_block_end()  # End of header block

    print(f"Character: {name}")
    print(f"Level: {level}")
    print(f"Class: {class_id}")
    print(f"Sex: {sex}")
    print(f"Hardcore: {hardcore}")


# ====================== Usage ======================
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python gdparser.py <character.gdc>")
        sys.exit(1)
    parse_gdc(sys.argv[1])

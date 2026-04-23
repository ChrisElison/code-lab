# Random password generator using chr() and randint() to lookup ASCII values
# ASCII table: https://www.asciitable.com/asciifull.gif
# 24/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

import random

passLen = 16  # Password length
password = "" # Empty string to hold new password

for x in range(0, passLen):
    # We first generate a random number between 1 and 3 to choose whether
    # to add a number, lower case letter or upper case letter. Unfortunately,
    # 0-9,A-Z and a-z are not together in one range in the ASCII table. We could
    # just use the range 48-122, which would include non-alphanumeric characters,
    # but for this example we just want alphanumerics
    
    # Choose which range to use (0-9, A-Z, a-z)
    range = random.randint(1,3)
    
    # Number 0-9
    if (range == 1):
        char = chr(random.randint(48,57))
        password = password + char
    
    # Letters A-Z
    if (range == 2):
        char = chr(random.randint(65,90))
        password = password + char
    
    # Letter a-z
    if (range == 3):
        char = chr(random.randint(97,122))
        password = password + char

print("Your new password is:", password)

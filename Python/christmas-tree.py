# Christmas tree example
# 04/05/2026
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

# Draws a Christmas tree using asterisks (*)

rows = int(input("Enter num of rows: "))

for i in range(rows):
    for j in range(rows - i - 1):
        print(end=" ")
    for j in range(2 * i + 1):
        print("*", end="")
    print()



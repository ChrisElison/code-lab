# List prime numbers between 2 and 100
# 23/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

import math

def checkPrime(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True
    
for i in range(2, 100):
    if checkPrime(i):
        print(i, "Prime!")

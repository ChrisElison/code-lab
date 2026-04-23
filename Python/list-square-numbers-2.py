# Detect square and non-square numbers using math.sqrt() and is_integer()
# 23/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

import math

for i in range(1, 101):
    #print(i, math.sqrt(i).is_integer())
    if(math.sqrt(i).is_integer()):
        print(i, "- Square!")
    else:
        print(i, "- Not square!")

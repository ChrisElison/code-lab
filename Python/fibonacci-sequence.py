# Fibonacci sequence in Python by Chris Elison
# 2026-04-16 14:52
# 
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

i = [0, 1]

for x in range (1, 10):
    fib = (i[x] + i[x-1])
    i.append(fib)

print(i)

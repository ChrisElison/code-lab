# Basic arithmetic with variables
# Date: 04/03/2025
# 
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

# Declare some numbers
x = 256
y = 16

# Add x & y together in a new variable, z. Print z to the output
z = x + y
print(z)

# Subtract y from x
z = x - y
print(z)

# Multiply x by y
z = x * y
print(z)

# Divide x by y
z = x / y
print(z)

# Using the modulo operator to calculate remainders
print(16 % 3) # Prints 1: 3 goes into 16 five times with 1 remainder
print(25 % 5) # Prints 0: 5 goes into 25 five times with 0 remainder

# Modulo can be used to see if a number is odd or even
myNumber = 24

# If number can be divided by 2 with no remainders it is even
if (myNumber % 2 == 0):
    print("Number is even!")
else:
    print("Number is odd!")

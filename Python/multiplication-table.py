# Multiplication table example with for loop
# Input a number and print a multiplication table
# Date: 04/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

# Ask user for a number to multiply
print("Enter a number to multiply:")

# Input the number as an integer
myNumber = int(input())

# Begin for loop, we specify a range of 1 to 11 because the loop counts from 0
for x in range(1, 11):
    # Calculate each result by multiplying x by the number to multiply
    result = x * myNumber
    # Print the result on screen
    print(x, "X", myNumber, "=", result)

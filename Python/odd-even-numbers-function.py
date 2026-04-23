# Using a function to check if a number is even or odd
# 'True' and 'False' are capitalised in Python - easy mistake to make!
# 19/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

# Declare a function called 'isNumberEven', function returns either True or False
# Functions need to be declared before being called, so put this at the top of the code
def isNumberEven(number):
    # Use modulus operator to determine if a number can be 
    # divided by 2 without any remainders
    if (number % 2 == 0):
        return True
    else:
        return False

# Prompt user to input a number
myNumber = int(input("Enter a number: "))

# Call 'isNumberEven' function in an if statement
if isNumberEven(myNumber) == True:
    print("Number is even!")
else:
    print("Number is odd!")

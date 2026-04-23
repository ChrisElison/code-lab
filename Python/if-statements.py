# If statements and less than/greater than & equals
# 24/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

# Example comparing strings
myPassword = "letmein!"
if (input("Enter the password: ") == myPassword):
    print("Correct password!")
else:
    print("Incorrect password!")

print()

# Comparing integers using > (Greater than)
# This only works if the given age is over 18
myAge = 18
if (myAge > 18):
    print("You are over 18! Welcome!")
else:
    print("Sorry, you are not old enough!")

print()

# This code uses >= (Greater than or equal to), so any age 18+ works
myAge = 18
if (myAge >= 18):
    print("You are 18 or over! Welcome!")
else:
    print("Sorry, you are not old enough!")

print()

# Another way to compare integers, this time with < (Less than)
myAge = 17
if (myAge < 18):
    print("Sorry, you are too young to enter!")
else:
    print("Welcome!")

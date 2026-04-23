# List (Arrays) examples
# 16/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

# Declare a list of strings
myFamily = ["Dad", "Mum", "Evie", "Mia", "Liv"]

# Print the first element in the list (starts at zero)
print("First:", myFamily[0])

# Print the third element of the list
print("Third:", myFamily[2])

# Print the last element in the list with -1
print("Last:", myFamily[-1])

print()

# Get the length (count) of the array
length = len(myFamily)
print("Length:", length)

print()

# Use a for loop to list every element in the array
for person in myFamily:
    print(person)

print()

# Add values to the list
myFamily.append("Nana")
myFamily.append("Grandad")
myFamily.append("Chris")
myFamily.append("Sarah")
myFamily.append("Homer Simpson")

# Use a for loop to list every element in the array
for person in myFamily:
    print(person)

# Remove an element from the list
myFamily.remove("Homer Simpson")

# Sort the list alphabetically
myFamily.sort()

print()

# Use a for loop to list every element in the array
for person in myFamily:
    print(person)

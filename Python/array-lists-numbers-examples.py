# List (Arrays) examples with integers
# 16/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

# Declare a list with some random numbers
myNumbers = [5, 17, 23, 8, 98, 3, 50, 27, 35, 84, 45]

# Sort the list
myNumbers.sort()

# Print out the list of number
for number in myNumbers:
    print(number)

print()

# Print the smallest and largest numbers
print("Smallest number: ", min(myNumbers))
print("Largest number: ", max(myNumbers))

# Print the sum total of all the numbers
print("Sum total: ", sum(myNumbers))

# Calculate the average, round to 2 decimal places
average = round(sum(myNumbers) / len(myNumbers), 2)
print("Average: ", average)

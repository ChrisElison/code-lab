# This example takes a string and outputs a new string alternating between upper
# and lower case letters
# 24/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

myStr = "hello, my name is evie and i like to program in python!"
myMsg = ""

# Loop through each letter in the myStr string
for x in range(0, len(myStr)):
    # If character position is even, append capitalised letter to myMsg
    # Spaces count as characters!
    if (x % 2 == 0):
        # Append myMsg with new character, use the .upper method to capitalise letter
        # String characters can be accessed just like lists/arrays using [x]
        myMsg = myMsg + myStr[x].upper()
    else:
        # Else do the same but with a lower case letter
        myMsg = myMsg + myStr[x].lower()

# Print the final myMsg string
print(myMsg)

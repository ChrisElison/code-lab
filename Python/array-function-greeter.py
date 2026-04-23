# Greeting function using function and array
# 08/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

# Function to greet a given name
def greeter(name):
    print("Hello, " + name + "!")

# Declare a list (array) of names
names = ["Chris", "Nana", "Mummy", "Daddy", "Mia", "Liv", "Sarah", "Grandad"]

# Loop through the array/list
for x in names:
    greeter(x)

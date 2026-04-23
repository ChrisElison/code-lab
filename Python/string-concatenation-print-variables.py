# Print() examples and string concatenation with variables
# Date: 06/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

# Output a message using print()
print("Hello, my name is Evie")

# Print a string
myGreeting = "Hello, I am Uncle Chris!"
print(myGreeting)

print("") # You can use an empty print() statement to make a blank line

# Example of concatenating variables and strings using print()
myAge = 41       # This is an integer, not a string as it has no quotation marks! Integers are whole numbers (no decimal points)
myName = "Chris" # This is a string, notice the quotation marks
myTown = "Sale"
myFood = "McDonald's"

# Printing variables out using the comma or + method
print("Hello, my name is", myName, "and I am", myAge, "years old.")
print("I live in " + myTown + " and my favourite food is " + myFood)

#########
# This line causes an error! When using '+' we can only concatenate strings not integers!
#print("Hello, my name is" + myName + "and I am" + myAge + "years old.")
#########

# This example uses the F-String method of concatenating variables into a string
myHobby = "Gaming"
myGame = "Minecraft"
myHouseNumber = 6
myGreeting = f"This is an F-String! My favourite hobby is {myHobby} and my favourite game is {myGame}! I live at number {myHouseNumber}"
print(myGreeting)

print("")

# Be careful when dealing with numbers, don't include the quotation marks if you intend a variable to be an integer number!
x = "12"
y = "34"
print(x + y) # Prints "1234"

# This adds the two numbers as expected
x = 12
y = 34
print(x + y) # Prints 46

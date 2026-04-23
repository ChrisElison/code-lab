# Python class and object example with methods
# 23/03/2025
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

class Person():
    # This method is called when the object is created
    # Methods are just functions that belong to a class/object
    # In it we can define what variables the object has, these are called members
    # This is called a constructor method
    def __init__(self, name, age):
        self.name = name
        self.age = age
        
    # This method is called when the object is deleted, it is a destructor method
    def __del__(self):
        print("Goodbye from", self.name,"!")
    
    # A custom method to greet using the object's name and age
    def greet(self):
        print("Hello, my name is", self.name, "and I am", self.age)


# Create a new object called 'chris' and set his name and age in the constructor
chris = Person("Christopher", 41)

# We call the greet() method with a '.' after the object name
chris.greet()

# We can access object members, too
print(chris.age)

bob = Person("Bob", 35)
bob.greet()

print()

# Delete chris and bob objects
del chris
del bob

# This line causes an error, the chris object no longer exists!
#chris.greet()

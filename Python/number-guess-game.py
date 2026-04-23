# Random Number Guessing Game
# Guess the number in less than 10 guesses
# Date: 02/03/2025
# 
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

import random

secretNumber = random.randint(1,100) # Generate a random number between 1 & 100
guesses = 10                         # Number of guesses we are allowed to make

while guesses > 0:
    print("I'm thinking of a number! Make your guess:")
    guess = int(input())

    if guess < secretNumber:
        print("Too low!")
        guesses = guesses -1
    elif guess > secretNumber:
        print("Too high!")
        guesses = guesses -1
    elif guess == secretNumber:
        print("Well done, you guessed correctly!")
        break

if guesses == 0:
    print("Sorry, you ran out of guesses! The correct answer was:", secretNumber)
    print("Thanks for playing!")
else:
    print("Thanks for playing!")

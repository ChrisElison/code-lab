# Farenheit to Celsius converter
# 30/04/2026
#
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

fahrenheit = int(input("Enter temperature in Fahrenheit: "))

# We can use round() to round to 2 decimal places
celsius = round(((fahrenheit - 32) * 5/9), 2)

print(fahrenheit,"°F =", celsius,"°C")

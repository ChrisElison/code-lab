# Python dictionaries example
# 19/03/2025
# #
# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

# Declare a dictionary of cities and their populations
# City names are the keys, populations are values
cityPopulations = {
    "Belfast" : 348005,
    "Birmingham" : 4332629,
    "Cardiff" : 362310,
    "Edinburgh" : 514990,
    "Glasgow" : 635130,
    "London" : 890000,
    "Manchester" : 2867769
}

# Print the number of cities in the dictionary
print("Found", len(cityPopulations), "cities!")

print()

# List each key and value in the dictionary
for city in cityPopulations:
    print(city, ": ", cityPopulations[city])
    
print()

# Print the value of a specific city
print("Manchester population:", cityPopulations["Manchester"])

# Add a new key/value to the dictionary
cityPopulations.update({"Newcastle" : 300100})

print()

# Print the number of cities in the dictionary
print("Found", len(cityPopulations), "cities!")

print()

# List each key and value in the dictionary
for city in cityPopulations:
    print(city, ": ", cityPopulations[city])

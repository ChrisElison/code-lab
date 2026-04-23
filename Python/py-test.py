# Copyright (c) 2026 Christopher Elison <chriselison.uk>
# Licensed under the MIT License.

def print_stars(x):
	for j in range(x):
		print("*", end='')
	print()

for i in range(10):
	print_stars(i)

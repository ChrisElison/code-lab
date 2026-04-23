/*
 * Word Reverser
 * Reverses a string provided from the command line argument.
 *
 * Usage: ./rev-string HelloWorld
 *
 * Author:   Chris Elison - https://chriselison.uk
 * Started:  2026-04-01 18:00
 * Modified: 2026-04-01 18:52
 *
 * To Do:
 * 	-  Attempt to remove string.h functions
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	/* Ensure only one (two really) argument is provided, first arg is program name */
	if(argc != 2) {
		printf("Usage: ./rev-string your_string_here\n");
		return 0;
	}

	const char *input = argv[1];
	size_t len = strlen(input);
	char my_str[len + 1];
	strncpy(my_str, input, len);
	my_str[len] = '\0';

	/* Output the word in correct order first: */
	printf("Word: ");
	for(int i=0;i<sizeof(my_str);i++) {
		printf("%c",my_str[i]);
	}
	printf("\n");

	/* Now output the word reversed: */
	printf("Reversed: ");
	for(int j=sizeof(my_str);j>=0;j--) {
		printf("%c",my_str[j-1]);
	}
	printf("\n");

	return 0;
}

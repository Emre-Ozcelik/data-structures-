/**
 -------------------------------------
 @file  main.c
 Lab 1 Main Function Source Code File
 -------------------------------------
 Author:  David Brown
 ID:      999999999
 Email:   dbrown@wlu.ca
 Version: 2023-08-30
 -------------------------------------
 DO NOT CHANGE CONTENTS
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"
#include "functions.h"

/**
 * Test the various parameter handling functions.
 *
 * @param argc - count of elements in args
 * @param args - array of strings passed on command line
 * @return EXIT_SUCCESS
 */
int main(int argc, char *args[]) {
	setbuf(stdout, NULL);
	parameters(argc, args);

	if (argc > 1) {
		if (strcmp(args[1], "int") == 0) {
			int total = int_total(argc, args);
			printf("Integer Total: %d\n", total);
		} else if (strcmp(args[1], "double") == 0) {
			double total = double_total(argc, args);
			printf("Double Total: %lf\n", total);
		} else {
			printf("Bad type parameter\n");
		}
	}
	return EXIT_SUCCESS;
}

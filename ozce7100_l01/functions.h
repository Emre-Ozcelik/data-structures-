/**
 -------------------------------------
 @file  functions.h
 Lab 1 Functions Header File
 -------------------------------------
 Author:  David Brown
 ID:      123456789
 Email:   dbrown@wlu.ca
 Version: 2023-08-30
 -------------------------------------
 DO NOT CHANGE CONTENTS
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Prototypes.

/**
 * Prints all parameters passed on command line.
 *
 * @param argc - count of elements in args
 * @param args - array of strings
 */
void parameters(int argc, char *args[]);

/**
 * Treats parameters greater than index 1 as integers
 * and returns their total.
 *
 * @param argc - count of elements in args
 * @param args - array of strings
 * @return integer total of args[2]+
 */
int int_total(int argc, char *args[]);

/**
 * Treats parameters greater than index 1 as doubles
 * and returns their total.
 *
 * @param argc - count of elements in args
 * @param args - array of strings
 * @return double total of args[2]+
 */
double double_total(int argc, char *args[]);

#endif /* FUNCTIONS_H_ */

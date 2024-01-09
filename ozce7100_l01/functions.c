/**
 -------------------------------------
 @file  functions.c
 Lab 1 Functions Source Code File
 -------------------------------------
 Author:Ilyas Emre Ozcelik
 ID:210807100
 Email:ozce7100@mylaurier.ca
 Version: 2023-08-30
 -------------------------------------
 */
#include "functions.h"

// Prints all parameters passed on command line.
void parameters(int argc, char *args[]) {
    for (int i = 0; i < argc; ++i) {
        printf("%d: %s\n", i, args[i]);
    }
    return;
}

// Treats parameters greater than index 1 as integers
// and returns their total.
int int_total(int argc, char *args[]) {
    int tot = 0;
    int value;
    for (int i = 1; i < argc; ++i) {
        if (sscanf(args[i], "%d", &value) == 1) {
            tot += value;
        }
    }
    return tot;
}

// Treats parameters greater than index 1 as doubles
// and returns their total.
double double_total(int argc, char *args[]) {
    double tot = 0;
    double value;
    for (int i = 1; i < argc; ++i) {
        if (sscanf(args[i], "%lf", &value) == 1) {
            tot += value;
        }
    }
    return tot;
}

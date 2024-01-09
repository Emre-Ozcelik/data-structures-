/**
 * -------------------------------------
 * @file  main.c
 * Assignment 1 Main Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2023-09-07
 *
 * -------------------------------------
 */
#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#include "functions.h"

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);

    printf("Sqr ft to acres: %.2f\n", feet_to_acres(100000));
    printf("Time to mow lawn: %d minutes\n", mow_lawn(10.0, 10.0, 5.0));
    printf("Date conversion: %d\n", date_convert(25101962));
    printf("time: %d seconds\n", falling_time(50));
    printf("Hypotenuse: %.2f\n", hypotenuse(3.0, 4.0));
    printf("Sum of even numbers till 100: %d\n", sum_even(100));
    printf("Partial harmonic sum till 4: %.2f\n", sum_partial_harmonic(4));
    printf("Years to reach population: %d\n", population_growth(10, 10.0, 100));


	return 0;
}

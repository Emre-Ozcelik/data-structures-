/**
 * -------------------------------------
 * @file  functions.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @author emre ozcelik, 210807100, ozce7100@mylaurier.ca
 *
 * @version 2023-09-07
 *
 * -------------------------------------
 */

#include "functions.h"
#include <math.h>

double feet_to_acres(int square_feet) {
    double tot = 0.0;
     tot = square_feet/FEET_PER_ACRE;
    return tot;
}

int mow_lawn(double width, double length, double speed) {
    double round_time = (width * length) / speed;
    int time = (int) round_time;

    if(round_time > time) {
        time += 1;
    }

    return time;
}

int date_convert(int date_number) {
    int answer = 0;
    int day = date_number / 1000000;
    int month = (date_number / 10000) % 100;
    int year = date_number % 10000;
    answer = year * 10000 + month * 100 + day;
    return answer;
}

int falling_time(int distance) {
    double round_time = sqrt((2 * distance) / GRAVITY_ACCEL);
    int time = (int) round_time;
    return time;
}

double hypotenuse(double side1, double side2) {
    double square_of_side1, square_of_side2, sum_of_squares;

    square_of_side1 = side1 * side1;    // Calculate the square of each side
    square_of_side2 = side2 * side2;
    sum_of_squares = square_of_side1 + square_of_side2;    // Sum up the squares of the sides

    double result = sqrt(sum_of_squares);    // Calculate the square root of the sum to get the hypotenuse
    return result;
}

int sum_even(int n) {
    int sum = 0;
    int j = 2;

    while (j <= n) {
        sum += j;
        j += 2;
    }

    return sum;
}

double sum_partial_harmonic(int n) {
    double sum = 0.0;
    int j = 1;

    while(j <= n) {
        sum += 1.0 / j;
        ++j;
    }

    return sum;
}

int population_growth(int start, double rate, int target) {
    int years = 0;
    double population = (double)start;

    for (years = 0; population < target; years++) {
    population *= 1 + (rate / 100);
    }
    return years;
}

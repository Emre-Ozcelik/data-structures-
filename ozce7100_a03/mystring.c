#include "mystring.h"
#include <ctype.h>

int str_length(char *s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

int word_count(char *s) {
    int count = 0;
    int word = 0;
    while (*s != '\0') {
        if (*s != ' ' && word == 0) {
            count++;
            word = 1;
        }
        else if (*s == ' ') {
            word = 0;
        }
        s++;
    }
    return count;
}

void lower_case(char *s) {
    while (*s != '\0') {
        if (*s >= 'A' && *s <= 'Z') {
            *s = tolower(*s);
        }
        s++;
    }
}

void str_trim(char *s) {
    int i = 0, j = str_length(s) - 1;
    while (s[i] == ' ') {
        i++;
    }
    while (j >= 0 && s[j] == ' ') {
        j--;
    }
    int k = 0;
    for (int m = i; m <= j; m++) {
        if (s[m] != ' ' || (s[m] == ' ' && s[m + 1] != ' ')) {
            s[k++] = s[m];
        }
    }
    s[k] = '\0';
}
/*
--------------------------------------------------
Project: cp264-a3q1
File:    mystring_main.c, public test driver
Author:  HBF
Version: 2023-01-26
--------------------------------------------------
*/
#include <stdio.h>
#include "mystring.h"

int main(int argc, char* args[]) {
  setbuf(stdout, NULL);
  char str[100] = "     This Is    a Test   String   ";
  printf("str:\"%s\"\n", str);
  printf("str_length(str):%d\n", str_length(str));  
  printf("word_count(str):%d\n", word_count(str)); 
  str_trim(str);
  lower_case(str);
  printf("str_trim(str):\"%s\"\n", str);
  printf("str_length(str_trim(str)):%d\n", str_length(str));
  return 0;
}
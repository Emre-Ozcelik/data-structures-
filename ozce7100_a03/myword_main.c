/*
--------------------------------------------------
Project: cp264-a3q2
File:    myword_main.c, a public test driver
Author:  HBF
Version: 2023-01-26
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

void display_wordstats_words(WORDSTATS *wordstats, WORD *words);
void read_display_file(char *filename);

int main(int argc, char *args[]) {  
  char infilename[40] = "textdata.txt";      //default input file name
  char outfilename[40] = "word_report.txt";  //default output file name

  if (argc > 1) {  
    if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }

  WORD words[MAX_WORDS] = {0};
  WORDSTATS wordstats = {0};
  process_word(infilename, words, &wordstats);
  display_wordstats_words(&wordstats, words);

  save_file(outfilename, words, &wordstats);

  read_display_file(outfilename);


  return 0;
}

void display_wordstats_words(WORDSTATS *wordstats, WORD *words) {
  printf("\n%s:%s\n","word stats", "value");
  printf("%s:%d\n", "line count", wordstats->line_count);
  printf("%s:%d\n", "total word count", wordstats->total_word_count);
  printf("%s:%d\n", "distinct word count", wordstats->distinct_word_count);

  printf("\n%s:%s\n","distinct words", "frequency");
  int i;
  for (i = 0; i < wordstats->distinct_word_count; i++) {
    printf("%s:%d\n", words[i].word, words[i].frequency);
  }
}

void read_display_file(char *filename)
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
      printf("\nno file\n");
  else
      printf("\nfile contents\n");
  char line[1000];
  while (fgets(line, 1000, fp) != NULL) {
     printf("%s", line);
  }
  fclose(fp);
}
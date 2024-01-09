#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

int process_word(char *filename, WORD *words, WORDSTATS *wordstats) {
    const char delimiters[] = " .,;:!()&?-\n\t\r\"\'";
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i, found;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    wordstats->line_count = 0;
    wordstats->total_word_count = 0;
    wordstats->distinct_word_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        wordstats->line_count++;
        char *token = strtok(line, delimiters);
        while (token != NULL) {
            lower_case(token);
            str_trim(token);
            wordstats->total_word_count++;
            found = 0;
            for (i = 0; i < wordstats->distinct_word_count; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    found = 1;
                    words[i].frequency++;
                    break;
                }
            }
            if (!found) {
                strcpy(words[wordstats->distinct_word_count].word, token);
                words[wordstats->distinct_word_count].frequency = 1;
                wordstats->distinct_word_count++;
            }
            token = strtok(NULL, delimiters);
        }
    }
    fclose(fp);
    return 0;
}

int save_file(char *filename, WORD *words, WORDSTATS *wordstats) {
    FILE *fp;
    int i;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }
    fprintf(fp, "word stats:value\n");
    fprintf(fp, "line count:%d\n", wordstats->line_count);
    fprintf(fp, "total word count:%d\n", wordstats->total_word_count);
    fprintf(fp, "distinct word count:%d\n", wordstats->distinct_word_count);
    fprintf(fp, "\ndistinct words:frequency\n");
    for (i = 0; i < wordstats->distinct_word_count; i++) {
        fprintf(fp, "%s:%d\n", words[i].word, words[i].frequency);
    }
    fclose(fp);
    return 0;
}

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 1000

int count_row(char *filename) {
  FILE *fp = fopen(filename, "r");
  int count = 0;
  for (char i = getc(fp); i != EOF; i = getc(fp))
    if (i == '\n')
      count = count + 1;
  fclose(fp);
  return count;
}

int main(int argc, char *argv[]) {

  char f[] = "-f\0";
  char r[] = "-r\0";
  char h[] = "-h\0";
  char ma[] = "-max\0";
  char mi[] = "-min\0";
  FILE *fp = fopen(argv[argc - 1], "r");

  // Error in file opening
  if (!fp) {
    printf("Can't open file\n");
    return 0;
  }
  for (int i = 0; i < argc; i++) {
    // printf("argv[%d] is %s\n", i, argv[i]);

    //-f
    if (!strcmp(argv[i], f)) {
      char row[MAXCHAR];
      char *firstrow = fgets(row, MAXCHAR, fp);
      char *token = strtok(firstrow, ",");
      int iterator = 0;
      while (token != NULL) {
        // printf("%s\n", token );
        iterator++;
        token = strtok(NULL, ",");
      }

      printf("%d\n", iterator);

    } //-r
    else if (!strcmp(argv[i], r)) {
      int count = 0;
      int c;
      for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
          count = count + 1;
      printf("%d\n", count);
    } //-h
    else if (!strcmp(argv[i], h)) {

    } // max
    else if (!strcmp(argv[i], ma)) {
      char row[MAXCHAR];
      int input = atoi(argv[i + 1]); // user input field
      char *firstrow = fgets(row, MAXCHAR, fp);
      char *token2 = strtok(firstrow, ",");

      int max = 0;
      int file_row_num = count_row(argv[argc - 1]);
      for (int z = 0; z < file_row_num; z++) {
        firstrow = fgets(firstrow, MAXCHAR, fp);
        token2 = strtok(firstrow, ",");

        if (atoi(token2) > max) {
          max = atoi(token2);
        }
      }
      i++;
      printf("The Max value of %d is %d\n", input, max);
    } // min
    else if (!strcmp(argv[i], mi)) {
      char row[MAXCHAR];
      int input = atoi(argv[i + 1]); // user input field
      char *firstrow = fgets(row, MAXCHAR, fp);
      char *token2 = strtok(firstrow, ",");
      int min = 999999999;
      int file_row_num = count_row(argv[argc - 1]);
      char first_letter;
      char last_letter;

      // state to see if loop should be executed for find quotation mark
      int sw = 0;

      for (int z = 0; z < file_row_num; z++) {
        firstrow = fgets(firstrow, MAXCHAR, fp);
        for (int n = 0; n < input + 1; n++) {
          if (n == 0) {
            token2 = strtok(firstrow, ",");

            first_letter = token2[0];
            last_letter = token2[strlen(token2) - 1];
            // see if end and begin quotation mark exist
            if ((first_letter == '"') && last_letter != '"') {
              sw = 1;
            }
          } else {
            if (sw == 0) {
              token2 = strtok(NULL, ",");
              first_letter = token2[0];
              last_letter = token2[strlen(token2) - 1];
              // see if end and begin quotation mark exist
              if ((first_letter == '"') && last_letter != '"') {
                sw = 1;
              }
            }
            // case of end quotation mark doesn't exit
            if (sw == 1) {
              // loop strtok() until find the end quotation mark
              while (sw == 1) {
                token2 = strtok(NULL, ",");
                last_letter = token2[strlen(token2) - 1];
                // if end quotaion mark found, set sw=0 for exiting the loop
                if (last_letter == '"') {
                  sw = 0;
                }
              }
            }
          }
        }

        if (atoi(token2) < min) {
          min = atoi(token2);
        }
      }
      i++;
      printf("The Min value of %d is %d\n", input, min);
    }
  }
  fclose(fp);
  return 0;
}
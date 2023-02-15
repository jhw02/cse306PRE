#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#define MAXCHAR 1000

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
      char row[MAXCHAR];
      int count = 0;
      int c;
      // fgets(row, MAXCHAR, fp);
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
      for (int z = 0; z < 810; z++) {
        // char z = getc(fp); z != EOF; z = getc(fp)
        firstrow = fgets(firstrow, MAXCHAR, fp);
        token2 = strtok(firstrow, ",");
        printf("%s\n", token2);
        for (int j = 1; j < input; j++) {
          token2 = strtok(NULL, ",");
        }
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
      for (int z = 0; z < 810; z++) {

        firstrow = fgets(firstrow, MAXCHAR, fp);
        token2 = strtok(firstrow, ",");
        for (int j = 1; j < input; j++) {
          token2 = strtok(NULL, ",");
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
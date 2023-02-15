#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#define MAXCHAR 1000

int main(int argc, char *argv[]) {

  char f[] = "-f\0";
  char r[] = "-r\0";
  char h[] = "-h\0";

  FILE *fp = fopen(argv[argc - 1], "r");

  // Error in file opening
  if (!fp) {
    printf("Can't open file\n");
    return 0;
  }

  for (int i = 0; i < argc; i++) {
    printf("argv[%d] is %s\n", i, argv[i]);
    char *input = argv[i];

    //-f
    if (input == f) {
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
    else if (input == r) {
      char row[MAXCHAR];
      int count = 1;
      int c;
      fgets(row, MAXCHAR, fp);
      for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
          count = count + 1;
      printf("%d\n", count);
    } //-h
    else if (input == h) {
      char row[MAXCHAR];
      printf("%s\n", row);
      fgets((char *)MAXCHAR, MAXCHAR, fp);
      printf("%s\n", row);
    }
  }
  fclose(fp);
  return 0;
}
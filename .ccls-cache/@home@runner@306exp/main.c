#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#define MAXCHAR 1000

int main() {
  // Substitute the file_path string
  // with full path of CSV file
  FILE *fp = fopen("05020004-eng.csv", "r");

  char name[50];
  int accountno, amount;

  if (!fp) {
    // Error in file opening
    printf("Can't open file\n");
    return 0;
  }

  // Asking user input for the
  // new record to be added
  printf("\nEnter Account Holder Name\n");
  scanf("%s", &name);
  printf("\nEnter Account Number\n");
  scanf("%d", &accountno);
  printf("\nEnter Available Amount\n");
  scanf("%d", &amount);

  // Saving data in file
  fprintf(fp, "%s, %d, %d\n", name, accountno, amount);

  printf("\nNew Account added to record");

  fclose(fp);
  return 0;
}
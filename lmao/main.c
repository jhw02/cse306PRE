#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<stdbool.h>
#define MAXCHAR 1000


char *my_strtok(char *str, const char *delim) {
    static char *s = NULL;
    if (str)
        s = str;
    if (!s)
        return NULL;
    char *start = s;
    while (*s && !strchr(delim, *s)) {
        s++;
    }
    if (*s) {
        *s = '\0';
        s++;
    }
    return start;
}

int main()
{

    FILE *fp;
    fp = fopen("05020004-eng.csv", "r");
    char row[MAXCHAR];
    if (!fp) {

        printf("No file found fucking cunt\n");
        return 1;
    }
    int count=1;
    int c;
    fgets(row, MAXCHAR, fp);
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    // fgets(row, MAXCHAR, fp);

    printf("%d",count);



    const char delimiter[] = ",";
// if its not  "' "
    char *token = my_strtok(row, delimiter);
    char *words[]={};
    words[0]="haha";
    words[1]="lol";
    words[0]="adibro";
    char *newwords[]={};
    newwords[0]=words[0];
    //printf(newwords[0]);
    token = my_strtok(NULL, delimiter);
    token = my_strtok(NULL, delimiter);
    //printf("%s\n", token);


//    while (feof(fp) != true)
//    {
//
//        printf("Row: %s", row);
//    }


    fclose(fp);
    return 0;
}

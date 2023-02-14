#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<stdbool.h>
#define MAXCHAR 1000


int main()
{

    FILE *fp;
    fp = fopen("05020004-eng.csv", "r");
    char row[MAXCHAR];
    if (!fp) {

        printf("No file found fucking cunt\n");
        return 1;
    }


    //-f
    char *firstrow =fgets(row, MAXCHAR, fp);
    char *token = strtok(firstrow, ",");
    int iterator =0;
    while( token != NULL ) {
        //printf("%s\n", token );
        iterator ++;
        token = strtok(NULL, ",");
    }

    printf("%d\n",iterator);



    // -r
    int count=1;
    int c;
    fgets(row, MAXCHAR, fp);
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;


    printf("%d\n",count);


    //-h
    // read and discard the header line
    printf("%s\n", row);
    fgets((char *) MAXCHAR, MAXCHAR, fp);
    printf("%s\n", row);

    // if not used then dont discard




    const char delimiter[] = ",";

    //char *token = my_strtok(row, delimiter);
    char *words[]={};
    words[0]="haha";
    words[1]="lol";
    words[0]="adibro";
    char *newwords[]={};
    newwords[0]=words[0];
    //printf(newwords[0]);
    //token = my_strtok(NULL, delimiter);
    //token = my_strtok(NULL, delimiter);
    //printf("%s\n", token);


//    while (feof(fp) != true)
//    {
//
//        printf("Row: %s", row);
//    }


    fclose(fp);
    return 0;
}

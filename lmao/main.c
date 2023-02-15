#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<stdbool.h>
#define MAXCHAR 1000


int fvalue(){
    FILE *fp;
    fp = fopen("05020004-eng.csv", "r");
    char row[MAXCHAR];
    char *firstrow = fgets(row, MAXCHAR, fp);
    int iterator =0;
    char *token = strtok(firstrow, ",");
    while( token != NULL ) {
        //printf("%s\n", token );
        iterator ++;
        token = strtok(NULL, ",");
    }

    //printf("%d\n",iterator);
return iterator;

}

int rvalue( ){
    // -r
    FILE *fp;
    fp = fopen("05020004-eng.csv", "r");
    char row[MAXCHAR];
    int count=1;

    fgets(row, MAXCHAR, fp);


    for (int c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') {// Increment count if this character is newline
            count = count + 1;
        }
    }


    return count;

}
int main() {

    FILE *fp;
    fp = fopen("05020004-eng.csv", "r");
    char row[MAXCHAR];
    if (!fp) {

        printf("No file found fucking cunt\n");
        return 1;
    }


    //-min //-max 
    int input = 0; //user input of what field they want
    char *firstrow = fgets(row, MAXCHAR, fp);
    firstrow = fgets(firstrow, MAXCHAR, fp);
    char *token2 = strtok(firstrow, ",");
    int max = 0;
    int min = 999999999;
    for (int i = 0; i < 810; i++) {

        firstrow = fgets(firstrow, MAXCHAR, fp);
        token2 = strtok(firstrow, ",");
        for (int j = 1; j < input; j++) {
            token2 = strtok(NULL, ",");
        }
        if (atoi(token2) > max) {
            max = atoi(token2);
        }
        if (atoi(token2) < min) {
            min = atoi(token2);
        }

        //printf("%s\n", token2);
        //printf("\n");


    }
    printf("The Max value of 0 is %d\n", max);
    printf("The Min value of 0 is %d\n", min);


    //-f
    int k = fvalue();
    printf("%d\n",k);



    // -r
    int j = rvalue();
    printf("%d\n",j);

//    //-h
//    // read and discard the header line
//    //printf("%s\n", row);
//    fgets((char *) MAXCHAR, MAXCHAR, fp);
//    //printf("%s\n", row);
//
//    // if not used then dont discard
//
//
//    //-max 0
//    firstrow =fgets(row, MAXCHAR, fp);
//    //fgets(firstrow, MAXCHAR, fp);
//    printf("haha\n");
//    c=getc(fp);
//    c=getc(fp);
//    c=getc(fp);
//    c=getc(fp);
//    c=getc(fp);
//    printf("%d",c);
//    token = strtok(firstrow, ",");
//    for (c = getc(fp); c != EOF; c = getc(fp)) {
//
//        if (c == '\n') { // Increment count if this character is newline
//            printf(row);
//            count++;
//            fgets(row, MAXCHAR, fp);
//            printf("%s", token);
//            printf(row);
//        }
//    }
//
//
//
//
//
//    //char *token = my_strtok(row, delimiter);
//    char *words[]={};
//    words[0]="haha";
//    words[1]="lol";
//    words[0]="adibro";
//    char *newwords[]={};
//    newwords[0]=words[0];
//    //printf(newwords[0]);
//    //token = my_strtok(NULL, delimiter);
//    //token = my_strtok(NULL, delimiter);
//    //printf("%s\n", token);
//
//

//
//
//    fclose(fp);
//    return 0;
//}
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ex01Fn.h"

#define ERR_ARGC -1
#define ERR_FOPEN_FAIL -2

#define MAX_ROW_SIZE 1000 + 1

int main(int argc, char** argv) {

    node_t* head = NULL; // head pointer
    char linebuff[MAX_ROW_SIZE];
    char* token = NULL;

    if(argc != 3){
        fprintf(stderr, "\n%s: Error, incorrect number of parameters (%d)", argv[0], argc);
        return ERR_ARGC;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if(inputFile == NULL){
        fprintf(stderr, "\n%s: Error, failed to open %s.", argv[0], argv[1]);
        return ERR_FOPEN_FAIL;
    }

    while(fgets(linebuff, MAX_ROW_SIZE, inputFile) != NULL){

        token = strtok(linebuff, " ");
        while(token != NULL){

            addStr(token, &head);

            token = strtok(NULL, " ");
        }
    }
    fclose(inputFile);


    FILE* outputFile = fopen(argv[2], "w");
    fListPrint(outputFile, &head);

    freeListMem(head);
    free(token);
    return 0;
}

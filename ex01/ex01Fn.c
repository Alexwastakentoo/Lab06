//
// Created by skyle on 28/11/2021.
//

#include "ex01Fn.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void addStr(char* str, node_t** head){

    node_t* temp = *head;

    while(temp->next != NULL){
        if(!stricmp(temp->next->string, str) && temp->next != NULL){
            printf("String: %s found in list ", str); fflush(stdout);
            temp->next->occ++;
            printf("increasing occurrence, occ: %d.\n", temp->next->occ); fflush(stdout);
            return;
        }
        temp = temp->next;
    }

    printf("String: %s was not found in list, new string stored.\n", str); fflush(stdout);

    headIns(head);
    temp->next->string = strdup(str);
    temp->next->occ = 1;
}

void headIns(node_t** head){

    node_t* temp = NULL;

    temp = (node_t*) malloc(sizeof(node_t));
    if(temp == NULL){
        fprintf(stderr, "[HeadIns] Error allocating memory\n");
        freeListMem(*head);
        exit(EXIT_FAILURE);
    }

    temp->next = *head;
    head = &temp;

    // if we're making a new node a new string has been found --> set occ directly to 1
   // *head->next->occ = 1;

}

void fListPrint(FILE* fp, node_t** head){

    node_t* temp = NULL;
    temp = *head;

    if(fp == NULL){
        fprintf(stderr, "[fListPrint] Error, unable to open file.\n");
        freeListMem(*head);
        exit(EXIT_FAILURE);
    }

    while(temp->next != NULL){
        fprintf(fp, "| String: %s || Occurrence: %d |\n", temp->next->string, temp->next->occ);
        temp = temp->next;
    }

}

void freeListMem(node_t* head){

    node_t* i = head, *temp = NULL;
    free(head);
    while(i != NULL){
        temp = i;
        free(temp->string);
        free(temp);

        i = i->next;
    }

}
//
// Created by skyle on 28/11/2021.
//

#ifndef LAB06_EX01FN_H
#define LAB06_EX01FN_H

#include <stdio.h>

typedef struct node_s{
    char* string;
    int occ;

    struct node_s *next;
} node_t;

void addStr(char* str, node_t** temp); // check if str is present in the list then increment occurrence or add to list
void headIns(node_t** head); // head insertion also sets head->next->occ = 1;
void fListPrint(FILE* fp, node_t** head); // prints list's contents into the desired output file
void freeListMem(node_t* head); // free list memory

#endif //LAB06_EX01FN_H

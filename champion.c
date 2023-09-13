#include "champion.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Champion* createChampion() {
    // Allocate memory for Champion struct
    Champion* newChampion = (Champion*)malloc(sizeof(Champion));
    // Generate rand number between 0 and 3
    int random = rand() % 4;
    // give a role and level based on number
    switch(random) {
        case 0:
            newChampion->role = MAGE;
            newChampion->level = rand() % 4 + 5;
            break;
        case 1:
            newChampion->role = FIGHTER;
            newChampion->level = rand() % 4 + 1;
            break;
        case 2:
            newChampion->role = SUPPORT;
            newChampion->level = rand() % 4 + 3;
            break;
        case 3:
            newChampion->role = TANK;
            newChampion->level = rand() % 8 + 1;
            break;
        default:
            // error message and return NULL if the random number is invalid
            printf("invalid random number in createChampion");
            return NULL;
    }
    // Set  next pointer to null and return the new Champion
    newChampion->next = NULL;
    return newChampion;
}

Champion* addChampion(Champion *head, Champion *c) {
    // if list is empty, return the new Champion as head of the list
    if (head == NULL) {
        return c;
    } else if (c->level > head->level) {
        // If the new Champion has a higher level than head
        // put it at the beginning of the list and return as the new head
        c->next = head;
        return c;
    } else {
        
        // Find  correct position to put the new Champion based on its level
        Champion* prev = head;
        Champion* current = head->next;
        while(current != NULL && c->level <= current->level) {
            prev = current;
            current = current->next;
        }
        prev->next = c;
        c->next = current;
        return head;
    }
}

Champion* buildChampionList(int n) {
    Champion* head = NULL;
    // Create n new Champions and add them to the list
    for (int i = 0; i < n; i++) {
        Champion* newNode = createChampion();
        head = addChampion(head, newNode);
    }
    return head;
}

void printChampionList(Champion *head) {
    Champion* current = head;
    // Traverse the list and print each champions role and level
    while(current != NULL) {
        switch(current->role) {
            case MAGE:
                printf("M");
                break;
            case FIGHTER:
                printf("F");
                break;
            case SUPPORT:
                printf("S");
                break;
            case TANK:
                printf("T");
                break;
            default:
                printf("error in printChampionList\n");
                break;
        }
        printf("%d ", current->level);
        current = current->next;
    }
    printf("\n");
}

Champion* removeChampion(Champion *head) {
    if (head == NULL) {
        // If the list is empty, return NULL
        return NULL;
    } else {
        Champion *next = head->next;
                free(head); //free memory
                return next;
            }
        }

        Champion* destroyChampionList(Champion *head) {
            while (head != NULL) {
                Champion* current = head;
                head = head->next;
                removeChampion(current);
            }
            return NULL;
        }

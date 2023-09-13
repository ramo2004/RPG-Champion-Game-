#include "champion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    srand(time(NULL)); //seed for rand num generator
    
    int numChampions = 0;
    int roundNum = 1;
    //check if user put enough arguments
    if (argc < 2) {
        printf("NOT ENOUGH ARGUMENTS\n");
        return 1;
    }
    
    if (sscanf(argv[1], "%d", &numChampions) != 1) {
        printf("invalid selection\n");
        return 1;
    }
    //2 lists of champions
    Champion* player1 = buildChampionList(numChampions);
    Champion* player2 = buildChampionList(numChampions);
    
    // main game text
    printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n\n");
    while (player1 != NULL && player2 != NULL) {
        printf("----- ROUND %d -----\n", roundNum);
        printf("Player 1: ");
        printChampionList(player1);
        printf("Player 2: ");
        printChampionList(player2);
        roundNum++; //increment round number
        
        Champion champion1 = {player1->role, player1->level, NULL};
        Champion champion2 = {player2->role, player2->level, NULL};
        //print type and levels for each champions
        switch(champion1.role) {
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
        printf("%d v ", champion1.level);
        
        switch(champion2.role) {
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
        printf("%d\n", champion2.level);
        //remove champions used from lists
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        
        switch(champion1.role) {
            case MAGE:
                switch(champion2.role) {
                    case MAGE:
                        //outcome of rounds
                        printf("Player 1 is a MAGE and Player 2 is a MAGE\n");
                        if (champion1.level == champion2.level) {
                            printf("Nothing happens - no penalty or reward.\n");
                            break;
                        } else if (champion1.level > champion2.level) {
                            player1 = addChampion(player1, createChampion());
                            player2 = removeChampion(player2);
                            printf("Player 1 (MAGE) wins and gains a new champion.\n");
                            printf("Player 2 (MAGE) loses one champion.\n");
                        } else {
                            player1 = removeChampion(player1);
                            player2 = addChampion(player2, createChampion());
                            printf("Player 1 (MAGE) loses one champion.\n");
                            printf("Player 2 (MAGE) wins and gains a new champion.\n");
                        }
                        break;
                    case FIGHTER:
                        //outcome of rounds
                        printf("Player 1 is a MAGE and Player 2 is a FIGHTER\n");
                        if (champion1.level == champion2.level) {
                            printf("Nothing happens - no penalty or reward.\n");
                            break;
                        } else if (champion1.level > champion2.level) {
                            player1 = addChampion(player1, createChampion());
                            printf("Player 1 (MAGE) wins one champion.\n");
                            printf("Player 2 (FIGHTER) loses with no penalty.\n");
                        } else {
                            player1 = removeChampion(player1);
                            printf("Player 1 (MAGE) loses one champion.\n");
                            printf("Player 2 (FIGHTER) wins with no reward.\n");
                        }
                        break;
                    case SUPPORT:
                        // outcome of rounds
                        printf("Player 1 is a MAGE and Player 2 is a SUPPORT\n");
                        if (champion1.level == champion2.level) {
                            printf("Nothing happens - no penalty or reward.\n");
                            break;
                        } else if (champion1.level > champion2.level) {
                            player1 = addChampion(player1, createChampion());
                            player2 = removeChampion(player2);
                            player2 = removeChampion(player2);
                            printf("Player 1 (MAGE) wins one champion.\n");
                            printf("Player 2 (SUPPORT) loses two champions.\n");
                        } else {
                            player1 = removeChampion(player1);
                            player2 = addChampion(player2, createChampion());
                            player2 = addChampion(player2, createChampion());
                            printf("Player 1 (MAGE) loses one champion.\n");
                            printf("Player 2 (SUPPORT) wins two champions.\n");
                        }
                        break;
                    case TANK:
                        // outcome
                        printf("Player 1 is a MAGE and Player 2 is a TANK\n");
                        player1 = addChampion(player1, createChampion());
                        player2 = removeChampion(player2);
                        printf("Player 1 (MAGE) wins one champion.\n");
                        printf("Player 2 (TANK) loses one champion.\n");
                        break;
                    default:
                        printf("error in round outcome\n");
                        break;
                }
                break;
            case FIGHTER:
                switch(champion2.role) {
                    case MAGE:
                        
                        printf("Player 1 is a FIGHTER and Player 2 is a MAGE\n");
                        if (champion1.level == champion2.level) {
                            printf("Nothing happens - no penalty or reward.\n");
                            break;
                        } else if (champion1.level > champion2.level) {
                            player2 = removeChampion(player2);
                            printf("Player 1 (FIGHTER) wins with no reward.\n");
                            printf("Player 2 (MAGE) loses one champion.\n");
                        } else {
                            player2 = addChampion(player2, createChampion());
                            printf("Player 1 (FIGHTER) loses with no penalty.\n");
                            printf("Player 2 (MAGE) wins one champion.\n");
                        }
                        break;
                    case FIGHTER:
                        printf("Player 1 is a FIGHTER and Player 2 is a FIGHTER\n");
                        player1 = addChampion(player1, createChampion());
                        player2 = addChampion(player2, createChampion());
                        printf("Player 1 (FIGHTER) wins one champion.\n");
                        printf("Player 2 (FIGHTER) wins one champion.\n");
                        break;
                    case SUPPORT:
                        printf("Player 1 is a FIGHTER and Player 2 is a SUPPORT\n");
                        if (champion1.level == champion2.level) {
                            printf("Nothing happens - no penalty or reward.\n");
                            break;
                        } else if (champion1.level > champion2.level) {
                            player2 = removeChampion(player2);
                            printf("Player 1 (FIGHTER) wins with no reward.\n");
                            printf("Player 2 (SUPPORT) loses one champion.\n");
                        } else {
                            player2 = addChampion(player1, createChampion());
                            printf("Player 1 (FIGHTER) loses with no penalty.\n");
                            printf("Player 2 (SUPPORT) wins one champion.\n");
                        }
                        break;
                    case TANK:

                        printf("Player 1 is a FIGHTER and Player 2 is a TANK\n");
                        player1 = addChampion(player1, createChampion());
                        printf("Player 1 (FIGHTER) wins one champion.\n");
                        printf("Player 2 (TANK) loses with no penalty.\n");
                        break;
                    default:
                        printf("error in round outcome\n");
                        break;
                }
                break;
            case SUPPORT:
                switch(champion2.role) {
                    case MAGE:
                    
                        printf("Player 1 is a SUPPORT and Player 2 is a MAGE\n");
                        if (champion1.level == champion2.level) {
                            printf("Nothing happens - no penalty or reward.\n");
                            break;
                        } else if (champion1.level > champion2.level) {
                            player1 = addChampion(player1, createChampion());
                            player1 = addChampion(player1, createChampion());
                            player2 = removeChampion(player2);
                            printf("Player 1 (SUPPORT) wins two champions.\n");
                            printf("Player 2 (MAGE) loses one champion.\n");
                        } else {
                            player2 = addChampion(player2, createChampion());
                            player1 = removeChampion(player1);
                            player1 = removeChampion(player1);
                            printf("Player 1 (SUPPORT) loses two champions.\n");
                            printf("Player 2 (MAGE) wins one champion.\n");
                        }
                        break;
                    case FIGHTER:
                        
                        printf("Player 1 is a SUPPORT and Player 2 is a FIGHTER\n");
                        if (champion1.level == champion2.level) {
                            printf("Nothing happens - no penalty or reward.\n");
                            break;
                        } else if (champion1.level > champion2.level) {
                            player1 = addChampion(player2, createChampion());
                            printf("Player 1 (SUPPORT) wins one champion.\n");
                            printf("Player 2 (FIGHTER) loses with no penalty.\n");
                        } else {
                            player1 = removeChampion(player1);
                            printf("Player 1 (SUPPORT) loses one champion.\n");
                            printf("Player 2 (FIGHTER) wins with no reward.\n");
                        }
                        break;
                    case SUPPORT:
                    
                        printf("Player 1 is a SUPPORT and Player 2 is a SUPPORT\n");
                        player1 = removeChampion(player1);
                        player2 = removeChampion(player2);
                        printf("Player 1 (SUPPORT) loses one champion.\n");
                        printf("Player 2 (SUPPORT) loses one champion.\n");
                        break;
                    case TANK:
                
                        printf("Player 1 is a SUPPORT and Player 2 is a TANK\n");
                        player2 = addChampion(player2, createChampion());
                        printf("Player 1 (SUPPORT) loses with no penalty.\n");
                        printf("Player 2 (TANK) wins and gains one new champion.\n");
                        break;
                    default:
                        printf("error in round outcome\n");
                        break;
                }
                break;
            case TANK:
                switch(champion2.role) {
                    case MAGE:
                        printf("Player 1 is a TANK and Player 2 is a MAGE\n");
                        player1 = removeChampion(player1);
                        player2 = addChampion(player2, createChampion());
                        printf("Player 1 (TANK) wins and gains one new champion.\n");
                        printf("Player 2 (MAGE) loses one champion.\n");
                        break;
                    case FIGHTER:
                        printf("Player 1 is a TANK and Player 2 is a FIGHTER\n");
                        player2 = addChampion(player2, createChampion());
                        printf("Player 1 (TANK) loses with no penalty.");
                        printf("Player 2 (FIGHTER) wins one new champion.\n");
                        break;
                    case SUPPORT:
                        printf("Player 1 is a TANK and Player 2 is a SUPPORT\n");
                        player1 = addChampion(player1, createChampion());
                        printf("Player 1 (TANK) wins one new champion.\n");
                        printf("Player 2 (SUPPORT) loses with no penalty.\n");
                        break;
                    case TANK:
                        printf("Player 1 is a TANK and Player 2 is a TANK\n");
                        printf("Nothing happens - no penalty or reward.\n");
                        break;
                    default:
                        printf("error in round outcome\n");
                        break;
                }
                break;
            default:
                printf("error in round outcome1\n");
                break;
        }
        printf("\n");
    }
    printf("============ GAME OVER  =============\n\n");
    //print ending champion list for each player
    printf("Player 1 ending champion list: ");
    printChampionList(player1);
    printf("\n");
    printf("Player 2 ending champion list: ");
    printChampionList(player2);
    printf("\n");
    //outcomes for which player won or tie
    if (player1 == NULL && player2 == NULL) {
        printf("TIE -- both players ran out of champions.\n");
    } else if (player1 == NULL) {
        printf("Player 1 ran out of champions. Player 2 wins.\n");
    } else {
        printf("Player 2 ran out of champions. Player 1 wins.\n");
    }
    
    player1 = destroyChampionList(player1); //frees memory by destroying lists
    player2 = destroyChampionList(player2);
    return 0;
}


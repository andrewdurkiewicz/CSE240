#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
 
#pragma warning(disable : 4996)
 
void fillArray(char *letters, int size), mainMenu(), menu1(char *letters, int size);
void removeChar(char *letters, char removeThisChar, int size), mergesort(char *letters, int size);
int main_choice, character_amt, menu1_choice, size, size, menu2_choice;
int findchar(char *letters, char searchForChar, int size);
void menu2(char **letters, int charAmt, int strAmt);
char searchForChar;
int occurances, strAmt, charAmt;
 
int main() {
    mainMenu();
    return 0;
}
 
void mainMenu() {
    printf("Welcome to Assignment 3!\n");
    printf("Menu:\n");
    printf("1 - Single Dimension Array Processing\n");
    printf("2 - Two-D Processing\n");
    printf("Choose an option:\n");
    scanf("%i", &main_choice);
 
    switch (main_choice) {
    case 1:
        printf("How many characters?\n");
        scanf("%i", &character_amt);
        char *letters = (char *)malloc((character_amt + 1) * sizeof(char));
        fillArray(letters, character_amt);
        int i = 0;
        printf("filling your array:\n");
        while (*(letters + i) != '\0') {
            printf("%c", *(letters + i));
            i++;
        }
        menu1(letters, character_amt);
        break;
    case 2:
        printf("How many strings do you want to enter?\n");
        scanf("%i", &strAmt);
        printf("What is the max size of the strings?\n");
        scanf("%i", &charAmt);
        char frominput;
        //declare our pointer array
        char **letters2D = (char **)malloc(strAmt * sizeof(char *));
        for (int row = 0; row < charAmt; row++) {
            letters2D[row] = (char *)malloc((charAmt + 1) * sizeof(char));
        }
        for (int i = 0; i < strAmt; i++) {
            for (int j = 0; j <= charAmt; j++) {
                letters2D[i][j] = '\0';
            }
        }
        for (int i = 0; i < strAmt; i++) {
            printf("Enter String %i:", i + 1);
            scanf("%s", letters2D[i]);
        }
        menu2(letters2D, charAmt, strAmt);
 
        break;
 
    default:
        printf("I am sorry %i is not a valid choice, please try again\n", main_choice);
        break;
 
    }
}
 
void menu1(char *letters, int size) {
    printf("\n\n");
    printf("Which option would you like?\n");
    printf("1. Check frequency of a letter\n");
    printf("2. Remove a letter\n");
    printf("3. Sort\n");
    scanf("%i", &menu1_choice);
    switch (menu1_choice) {
    case 1:
        printf("Which character?\n");
        getchar();
        char searchForChar = getchar();
        occurances = findchar(letters, searchForChar, size);
        printf("There are %i occurances of %c\n", occurances, searchForChar);
        occurances = 0;
        menu1(letters, size);
        break;
    case 2:
        printf("Which character?\n");
        getchar();
        char removeThisChar = getchar();
        removeChar(letters, removeThisChar, size);
        for (int j = 0; j < size; j++) {
            printf("%c", *(letters + j));
        }
        printf("\n");
        printf("%c has been removed\n", removeThisChar);
        for (int i = 0; *(letters + i) != '\0'; i++) {
            printf("%c", *(letters + i));
        }
        menu1(letters, size);
        break;
 
    case 3:
        printf("Now Sorting:\n");
        mergesort(letters, size);
        for (int i = 0; *(letters + i) != '\0'; i++) {
            printf("%c", *(letters + i));
        }
        menu1(letters, size);
        break;
    }
}
 
void menu2(char **letters2D, int charAmt, int strAmt) {
    printf("\n");
    printf("What would you like to do?\n");
    printf("1.     Check frequency of a letter\n");
    printf("2.     Remove a letter\n");
    scanf("%i", &menu2_choice);
    switch (menu2_choice) {
    case 1:
        printf("Which character?\n");
        getchar();
        char search2 = getchar();
        for (int i = 0; i < strAmt; i++) {
           
            char findoccurance[] = "";
            occurances = findchar(*(letters2D + i), search2, charAmt);
            printf("%s - %i occurances\n", *(letters2D + i), occurances);
            occurances = 0;
        }
        menu2(letters2D, charAmt, strAmt);
    case 2:
        printf("What letter?\n");
        getchar();
        char search_rem = getchar();
        char letter[100];
        printf("Now Removing your letters:\n");
        for (int i = 0; i < strAmt; i++) {
            strcpy(letter, *(letters2D + i));
            removeChar(letter, search_rem, charAmt);
            printf("%s\n", letter);
        }
        menu2(letters2D, charAmt, strAmt);
 
    default:
        printf("I am sorry %i is not a valid choice, please try again\n", menu1_choice);
        menu2(letters2D, charAmt, strAmt);
 
    }
}
 
 
 
void fillArray(char *letters, int size) {
    srand(time(NULL));
    for (int i = 0; i <= size; i++) {
        *(letters + i) = '\0';
    }
    for (int i = 0; i < size; i++) {
        *(letters + i) = (97 + rand() % 26);
    }
 
}
 
int findchar(char *letters, char searchForChar, int size) {
    for (int j = 0; j < size; j++) {
        if (*(letters + j) == searchForChar) {
            occurances++;
        }
        else {
            continue;
        }
    }
    return occurances;
}
 
void removeChar(char *letters, char removeThisChar, int size) {
 
    char *afterfix = (char *)malloc((size + 1) * sizeof(char));
    int j = 0;
 
    for (int i = 0; i < size; i++) {
        if (*(letters + i) != removeThisChar) {
            *(afterfix + j) = *(letters + i);
            j++;
        }
        else {
            continue;
        }
    }
    *(afterfix + j) = '\0';
    strcpy(letters, afterfix);
}
 
void mergesort(char *letters, int size) {
    //we need to find the length;
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (*(letters + i) > *(letters + j)) {
                temp = *(letters + i);
                *(letters + i) = *(letters + j);
                *(letters + j) = temp;
            }
        }
    }
    strcpy(letters, letters);
}
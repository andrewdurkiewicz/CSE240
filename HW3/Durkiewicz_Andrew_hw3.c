#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#pragma warning(disable : 4996)
int main_choice, menu1_choice, menu2_choice;
int occurances = 0;
void mainMenu(char letters[]), menu1(char letters[]), menu2(char letters[], char letters2D[10][16]);
void findchar(char letters[], char searchForChar), removeChar(char letters[], char searchForChar);
void mergesort(char letters[]), removechar2(char letters[], char removeThisChar);


int main() {
	//initialize our array of random letters (length = 50)
	srand(time(NULL));
	int i = 0;
	char letters[51];
	while (i<51) {
		letters[i] = (97 + rand() % 26);
		i++;
	}
	letters[50] = '\0';//to know when to stop we end it with a null character
	mainMenu(letters); //changes choice to 1 or 2;

	return 0;
}

void mainMenu(char letters[]) {
	char letters2D[10];
	printf("Welcome to Assignment 3!\n");
	printf("Menu:\n");
	printf("1 - Single Dimension Array Processing\n");
	printf("2 - Two-D Processing\n");
	printf("Choose an option:\n");
	scanf("%i", &main_choice);

	//switch case for possible submenu
	switch (main_choice) {
	case 1:
		menu1(letters);
	case 2:
		menu2(letters, letters2D);
	default:
		printf("I am sorry %i is not a valid choice, please try again\n", main_choice);
		mainMenu(letters);
	}
}

void menu1(char letters[]) {
	printf("\n");
	printf("Here is the randomized 1D array: \n");
	int j = 0;
	while (letters[j] != '\0') {
		printf("%c", letters[j]);
		j++;
	}
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
		occurances = 0;
		findchar(letters, searchForChar);
		printf("There are %i occurances\n", occurances);
		printf("\n\n");
		mainMenu(letters);
	case 2:
		printf("Which character?\n");
		getchar();
		char removeThisChar = getchar();
		removeChar(letters, removeThisChar);
		printf("%s", letters);
		printf("\n\n");
		mainMenu(letters);
	case 3:
		mergesort(letters);
		printf("%s", letters);
		printf("\n\n");
		mainMenu(letters);
	default:
		printf("I am sorry %i is not a valid choice, please try again\n", menu1_choice);
		menu1(letters);
	}

}

void menu2(char letters[], char letters2D[10][16]) {
	printf("Enter 10 characters of maximum 15 charcters in length\n");
	for (int i = 0; i < 10; i++) {
		printf("Enter String %d:", (i+1));
		scanf("%s", letters);
		strcpy(letters2D[i], letters);
		letters2D[i][15] = '\0';
	}
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
		for (int i = 0; i < 10; i++) {
			occurances = 0;
			char findoccurance[] = "";
			strcpy(findoccurance, letters2D[i]);
			findchar(findoccurance, search2);
			printf("%s - %i occurances\n", findoccurance, occurances - 1);
			occurances = 0;
		}
			mainMenu(letters);
	case 2:
		printf("Which character?\n");
		getchar();
		char remove2 = getchar();
		char removeOccurance[] = "";

		for (int i = 0; i < 10; i++) {
			strcpy(removeOccurance, letters2D[i]);
			removechar2(removeOccurance, remove2);
			printf("%s becomes - %s\n", letters2D[i],removeOccurance);
		}
		mainMenu(letters);
	default:
		printf("I am sorry %i is not a valid choice, please try again\n", menu1_choice);
		menu1(letters);
		}

	}

void findchar(char letters[], char searchForChar) {
	for (int i = 0; i < 51; i++) {
		if (letters[i] == searchForChar) {
			occurances++;

		}
		else {
			continue;
		}
	}

}

void removechar2(char letters[], char removeThisChar) {
	char afterfix[16] = { '\0' };
	int j = 0;
	for (int i = 0; i < 16; i++) {
		if (letters[i] != removeThisChar) {
			afterfix[j] = letters[i];
			j++;

		}
		else {
			continue;
		}
	}
	afterfix;
	afterfix[j + 1] = '\0';
	strcpy(letters, afterfix);

}

void removeChar(char letters[], char removeThisChar) {
	char afterfix[50] = {'\0'};
	int j = 0;
	for (int i = 0; i < 50; i++) {
		if (letters[i] != removeThisChar) {
			afterfix[j] = letters[i];
			j++;

		}
		else {
			continue;
		}
	}
	afterfix;
	afterfix[j + 1] = '\0';
	strcpy(letters, afterfix);

}

void mergesort(char letters[]) {
	//we need to find the length:
	int length = 50;
	int temp;
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (letters[i] > letters[j]) {
				temp = letters[i];
				letters[i] = letters[j];
				letters[j] = temp;
			}
		}
	}
	strcpy(letters, letters);


}

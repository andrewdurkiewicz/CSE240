//Homework 5, Andrew Durkiewicz

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>



typedef struct cardStruct cardStruct;
typedef enum cardSuite cardSuite;
typedef enum cardValue cardValue;
typedef int bool;

enum cardSuite{
	diamonds = 0,
	clubs,
	hearts,
	spades

};

enum cardValue{
	two = 2,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace
};

struct cardStruct{
	cardValue value;
	cardSuite suit;
};

cardStruct **buildDeck(int rows, int column);
void printCard(int card, int suite);
void shuffleDeck(cardStruct **cardPtr,int size);
void printGrid(cardStruct** playArea, int rows, int cols);
void getLocation(int *ch1, int rows, int columns);
void flipCard(int x, int y);
bool checkForWin(int rows, int columns);
int **shownCards;


int main(){
	setlocale(LC_CTYPE, "");
	wprintf(L"Welcome to CSE240 Memory!\n");
	wprintf(L"The rules are simple, pick two cards and see if they match. Continue\n");
	wprintf(L"until you’ve matched all of the cards!\n");
	wprintf(L"You may enter '-1' for your cards at any time during the game to quit.\n\n");
	wprintf(L"How many columns of cards do you want to play with? Minimum of 3, maximum of 13:");
	int rows = 4, notValCol = 1, columns;
	while(notValCol == 1){
		scanf("%i",&columns);
		fflush(stdin);
		if(columns < 0){
			wprintf(L"Goodbye!\n");
			exit(0);
		}
		if(columns > 2 && columns < 14){
			notValCol = 0;
		}
		else{
			wprintf(L"Error, columns out of bounds! must be between 3 and 13\n");
			wprintf(L"How many columns of cards do you want to play with? Minimum of 3, maximum of 13:\n");
			notValCol = 1;
		}
	}
	//make the parallel array
	shownCards = (int **)malloc((rows)*sizeof(int *));
	for(int i = 0; i < rows; i++){
		shownCards[i] = (int *)malloc((columns)*sizeof(int));
	}

	cardStruct **dealerDeck = buildDeck(rows, columns);
	shuffleDeck(dealerDeck,rows*columns);
	printGrid(dealerDeck,rows, columns);
	while(checkForWin(rows, columns)){
		int ch1[4] = {14,14,14,14};
		int *choices = &ch1[0];
		getLocation(choices, rows, columns);
		flipCard(choices[0],choices[1]);
		flipCard(choices[2],choices[3]);
		printGrid(dealerDeck,rows,columns);
		wprintf(L"press anything to continue\n");
		fflush(stdin);
		getchar();
		getchar();
		if(dealerDeck[choices[0]][choices[1]].value != dealerDeck[choices[2]][choices[3]].value){
				wprintf(L"ROUGH! Sorry, was wrong\n");
				flipCard(choices[0],choices[1]);
				flipCard(choices[2],choices[3]);
		}
		else if(dealerDeck[choices[0]][choices[1]].value == dealerDeck[choices[2]][choices[3]].value){
			shownCards[choices[0]][choices[1]] = 3;
			shownCards[choices[2]][choices[3]] = 3;
		}
		printGrid(dealerDeck,rows,columns);
	}
	wprintf(L"Thanks for playing, You win!!!");
	return 0;
}

bool checkForWin(int rows, int columns){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(shownCards[i][j] != 3){
				return 1;
			}
		}
	}
	return 0;
}

void getLocation(int *ch1, int rows, int columns){
	int  badinput = 1;
	while(badinput){
		wprintf(L"Choose card 1 in format row column: (ex: '1 2'): ");
		scanf("%i %i",&ch1[0],&ch1[1]);
		fflush(stdin);
		wprintf(L"Choose card 1 in format row column: (ex: '1 2'): ");
		scanf("%i %i",&ch1[2],&ch1[3]);
		fflush(stdin);
		if(ch1[0] < 0 || ch1[1] < 0 || ch1[2] < 0 || ch1[3] < 0){
			wprintf(L"Goodbye!\n");
			exit(0);
		}

		if(ch1[0] >= rows || ch1[2] >= rows){
			wprintf(L"Error! row input out of bounds. row index values range from 0 to %i. retry!\n", rows - 1);
		}
		else if(ch1[1] >= columns || ch1[3] >= columns){
			wprintf(L"Error! column input out of bounds. column index values range from 0 to %i. retry!\n", columns - 1);
		}
		else if(shownCards[ch1[0]][ch1[1]] == 3 || shownCards[ch1[2]][ch1[3]] == 3){
			wprintf(L"Error! card already flipped, retry!\n");
		}
		else{
			badinput = 0;
		}
	}
}

void printGrid(cardStruct** playArea, int rows, int columns) {
	system("clear");
	wprintf(L"###");
	for(int i = 0; i < columns; i++){
		wprintf(L" %i  ", i);
	}
	wprintf(L"\n");
	for(int i = 0; i < rows; i++){
		wprintf(L"%i: ", i);
		for(int j = 0; j<columns; j++){
			if(shownCards[i][j] == 0){
				printCard(99,99);
			}
			else{
				printCard((int) playArea[i][j].value,(int) playArea[i][j].suit);
			}
		}
		wprintf(L"\n");
	}

}

void flipCard(int x, int y){
	if(shownCards[x][y] == 1){
		shownCards[x][y] = 0;
	}
	else if(shownCards[x][y] == 0){
		shownCards[x][y] = 1;

	}
	else if(shownCards[x][y] == 3){
		wprintf(L"Card %i %i already flipped!\n");
	}
}
void shuffleDeck(cardStruct **cardPtr, int size){
	srand((unsigned) time(NULL));

	cardStruct temp1;
	int columns = size / 4;
	int rows = 4;

	for(int i = 0; i < rows; i++){
		for(int j = 0;j < columns; j++){
			int r = rand() % size;
			temp1 = cardPtr[i][j];
			cardPtr[i][j] = cardPtr[r%rows][r%columns];
			cardPtr[r%rows][r%columns] = temp1;
		}
	}

}

cardStruct **buildDeck(int rows, int columns){
	cardStruct **dealerDeck = (cardStruct **)malloc((rows)*sizeof(cardStruct *));
	for(int i = 0; i < rows; i++){
		dealerDeck[i] = (cardStruct *)malloc((columns)*sizeof(cardStruct));
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			dealerDeck[i][j].suit = i;
			dealerDeck[i][j].value = j+2;
		}
	}

	return dealerDeck;
}

void printCard(int card, int suit){

		wchar_t suiteOpt[4] = {0x2660, 0x2665, 0x2663, 0x2666};
		switch(card){

			case 2:
				wprintf(L"%i%lc ", 2 , suiteOpt[suit]);
				break;
			case 3:
				wprintf(L"%i%lc ", 3 , suiteOpt[suit]);
				break;
			case 4:
				wprintf(L"%i%lc ", 4 , suiteOpt[suit]);
				break;
			case 5:
				wprintf(L"%i%lc ", 5 , suiteOpt[suit]);
				break;
			case 6:
				wprintf(L"%i%lc ", 6 , suiteOpt[suit]);
				break;
			case 7:
				wprintf(L"%i%lc ", 7 , suiteOpt[suit]);
				break;
			case 8:
				wprintf(L"%i%lc ", 8 , suiteOpt[suit]);
				break;
			case 9:
				wprintf(L"%i%lc ", 9 , suiteOpt[suit]);
				break;
			case 10:
				wprintf(L"%i%lc ", 10 , suiteOpt[suit]);
				break;
			case 11:
				wprintf(L"%lc%lc ", 'J' , suiteOpt[suit]);
				break;
			case 12:
				wprintf(L"%lc%lc ", 'Q' , suiteOpt[suit]);
				break;
			case 13:
				wprintf(L"%lc%lc ", 'K' , suiteOpt[suit]);
				break;
			case 14:
				wprintf(L"%lc%lc ", 'A' , suiteOpt[suit]);
				break;
			case 99:
				wprintf(L" xx ");
				break;
		}


	}

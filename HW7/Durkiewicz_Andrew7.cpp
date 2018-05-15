#include <iostream>
#include "Durkiewicz_LinkedList.h"
#include <stdlib.h>
#include <string>
using namespace std;
struct T
{
	string name;
	int person;

};

void printarray(T *anArray, int size);

int main()
{
	int p = 0, n = 0;
	linkedlist<T> list = linkedlist<T>();
	cout << "How many people are there in total? (Pick a value between 2 and 100)" << endl << flush;
	cin >> p;
	while (p < 2 || p > 100)
	{	
		cout << "Error, total out of range, please re-enter!: " << endl << flush;
		cin >> p;
	}

	cout << "Now we need a number between 1 and 20. This represents the n'th person around the circle to be killed each turn" << endl << flush;
	cin >> n;
	while (n < 1 || n > 20)
	{
		cout << "Error, total out of range, please re-enter!: " << endl << flush;
		cin >> n;
	}
	// make the list
	for (int i = p; i > 0; i--)
	{
		T data = { to_string(i), i };
		list.addToFront(data);

	}
	int ourlength = list.length();

		for (int i = 1; i < (ourlength); i++) {
			list.removeAtIndex((list.length() - 1) % (n*i));
		
		}
		list.removeAtIndex(0);

	
		cout << "Your Best chance at surviving is to be at index: ";
	printarray(list.toarray(), list.length());
	system("pause");

	

	
	return 0;
}

void printarray(T *anArray, int size)
{
	//cout << alist.length();
	for (int i = 0; i < size; i++)
	{
		cout << anArray[i].name << endl;
	}

}


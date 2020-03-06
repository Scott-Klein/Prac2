#include "MyCollection.h"
#include <iostream>


using namespace std;
//Forward decl
void IntCollectionTest();
void CharCollectionTest();

template <typename T>
void PrintSearchResult(T& itemToFind, int index)
{
	if (index > 0)
	{
		cout << "Found " << itemToFind << " at index " << index << endl;
	}
	else
	{
		cout << "Did not find " << itemToFind << endl;
	}
}


int main()
{
	cout << "Commencing <Int> tests" << endl;
	IntCollectionTest();
	cout << endl << "Commencing <Char> tests" << endl;
	CharCollectionTest();
}

void CharCollectionTest()
{
	int index = -1;
	char charArr[] = { 'a', 'z', 'c', 't', 'o', 'f', 'b' };
	char charToFind = 'z';
	char charToNotFind = 'q';

	MyCollection<char>* collectionOfChar = new MyCollection<char>(charArr, 7);

	collectionOfChar->LinearSearch(charToFind, index);
	cout << "<Char> LINEAR SEARCH *******" << endl;
	PrintSearchResult(charToFind, index);


	collectionOfChar->Sort();
	collectionOfChar->BinarySearch(charToFind, index);
	cout << "<Char> BINARY SEARCH *******" << endl;
	PrintSearchResult(charToFind, index);


	collectionOfChar->BinarySearch(charToNotFind, index);
	cout << "<Char> BINARY SEARCH *******" << endl;
	PrintSearchResult(charToNotFind, index);
	delete collectionOfChar;
}

void IntCollectionTest()
{
	int index = -1;
	int numToFind = 55;
	int arr[] = { 1,4,2,5,55,3,44,33,7 };
	MyCollection<int>* collectionOfInt = new MyCollection<int>(arr, 9);

	collectionOfInt->LinearSearch(numToFind, index);
	cout << "<Int> LINEAR SEARCH *******" << endl;
	PrintSearchResult(numToFind, index);

	//Binary Search
	collectionOfInt->Sort();
	collectionOfInt->BinarySearch(numToFind, index);
	cout << "<Int> BINARY SEARCH *******" << endl;
	PrintSearchResult(numToFind, index);

	delete collectionOfInt;
}


#include "MyCollection.h"
#include <iostream>

using namespace std;

int main()
{
	int arr[] = { 1,4,2,5,55,3,44,33,7 };
	MyCollection<int>* collection = new MyCollection<int>(arr, 9);



	collection->Sort();
	


	delete collection;
}
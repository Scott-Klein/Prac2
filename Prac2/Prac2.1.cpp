#include <iostream>

using namespace std;

// Linear search.
int main()
{
	int numToFind;
	cin >> numToFind;
	bool foundNum = false;
	int arr[] = { 1,3,8,9,12,14,22,25,33,34,38,59,61,66,68,73,75,99,101,203,454 };
	int arraySize = 21;

	for (int i = 0; i < arraySize; i++)
	{
		if (arr[i] == numToFind)
		{
			foundNum = true;
			cout << "FOUND NUMBER " << numToFind << " at index: " << i << endl;
		}
	}

	if (!foundNum)
	{
		cout << "Your search didn't uncover the number. Bad luck.";
	}
}
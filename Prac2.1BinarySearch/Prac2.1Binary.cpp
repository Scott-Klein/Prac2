#include <iostream>

using namespace std;

// Binary search.
int main()
{
	int numToFind;
	cin >> numToFind;
	bool foundNum = false;
	int arr[] = { 1,3,8,9,12,14,22,25,33,34,38,59,61,66,68,73,75,99,101,203,454 };
	int arraySize = 21;

	int first = 0;
	int last = arraySize - 1;
	int mid;

	while (first <= last && !foundNum)
	{
		mid = (first + last) / 2;

		if (arr[mid]== numToFind)
		{
			foundNum = true;
		}
		else if (arr[mid] > numToFind)
		{
			last = mid - 1;
		}
		else 
		{
			first = mid + 1;
		}
	}

	if (foundNum)
	{
		cout << "FOUND NUMBER " << numToFind << endl;
	}
	else
	{
		cout << "Your search didn't uncover the number. Bad luck.";
	}
}
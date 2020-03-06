
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

#define nine 9
void Setup();
void GenerateRandomPositions(vector<int>& randomPositions);
int GetNewRandom();
void WriteToArray(vector<int>& arr, vector<int>& randomPositions);
void PrintArray(vector<vector<int>> results);
void PrintVector(vector<int> result);

static int randomCalls;
static vector<int> occuredNumbers;

int main()
{
	vector<vector<int>> allResults;
	Setup();
	for (int i = 0; i < 10; i++)
	{
		randomCalls = 0;
		occuredNumbers = { 0,1,2,3,4,5,6,7,8 };
		vector<int> arr = { 0,0,0,0,0,0,0,0,0,0 };
		vector<int> randomPositions = { 0,0,0,0,0,0 };
		GenerateRandomPositions(randomPositions);
		WriteToArray(arr, randomPositions);
		arr[9] = randomCalls;
		allResults.push_back(arr);
	}

	PrintArray(allResults);
}

void GenerateRandomPositions(vector<int>& positions)
{
	for (int i = 0; i < 6; i++)
	{
		positions[i] = GetNewRandom();
	}
}

int GetNewRandom()
{
	int randomNum;

	randomNum = rand() % occuredNumbers.size();

	int result = occuredNumbers[randomNum];
	occuredNumbers.erase(occuredNumbers.begin() + randomNum);

	randomCalls++;

	return result;
}


void WriteToArray(vector<int>& arr, vector<int>& randomPositions)
{
	for (int i = 0; i < 6; i++)
	{
		arr[randomPositions[i]] = i + 1;
	}
}

void PrintArray(vector<vector<int>> results)
{
	for (int i = 0; i < results.size(); i++)
	{
		PrintVector(results[i]);
		cout << endl;
	}

}

void PrintVector(vector<int> result)
{
	//0, 3, 6, 
	//1, 4, 7, 
	//2, 5, 8
	cout << " ";
	for (int i = 0; i < 3; i++)
	{
		cout << "--- ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j+=3)
		{
			cout << "| "<< result[i + j] << " ";
		}
		cout << "| " << endl;
	}
	cout << " ";
	for (int i = 0; i < 3; i++)
	{
		cout << "--- ";
	}
}



void Setup()
{
	srand(time(NULL));
}

#pragma once
#include <vector>

using namespace std;

template <class T>
class MyCollection
{
private:
	vector<T> list;

	bool IsAscendingOrder()
	{
		for (int i = 0; i < list.size() - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
				return false;
			}
		}
		return true;
	}
public:
	MyCollection(T* input, int length)
	{
		for (int i = 0; i < length; i++)
		{
			list.push_back(input[i]);
		}
	}

	bool LinearSearch(T item, int& loc)
	{
		for (int i = 0; i < list.size(); i++)
		{
			loc = i;
			if (item == list[i])
			{
				return true;
			}
		}
		loc = -1;
		return false;
	}
	void Sort()
	{
		while (!IsAscendingOrder())
		{
			for (int i = 0; i < list.size()-1; i++)
			{
				if (list[i] > list[i+1])
				{
					T lesser = list[i + 1];
					list[i + 1] = list[i];
					list[i] = lesser;
				}
			}
		}
	}
	bool BinarySearch(T item, int& loc)
	{
		return false;
	}

};


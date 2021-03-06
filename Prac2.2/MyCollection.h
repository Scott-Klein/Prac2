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
		loc = -1;
		int mid;
		int first = 0;
		int last = list.size() - 1;
		bool found = false;

		while (first <= last && !found)
		{
			mid = (first + last) / 2;

			if (list[mid] == item)
			{
				found = true;
				loc = mid;
			}
			else if (list[mid] > item) 
			{
				last = mid - 1;
			}
			else
			{
				first = mid + 1;
			}
		}

		return found;
	}

};


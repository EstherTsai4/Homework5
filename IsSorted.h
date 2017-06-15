#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
bool isSorted(const T list[], int size)
{
	//create temporary list
	T* temp = new T[size];

	//set index i as smallest number
	for (int i = 0; i < size; i++)
	{
		//create temporary list and actually perform the sort function and store in the temporary list
		T currentMin = list[i];
		int currentMinIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (currentMin > list[j])
			{
				currentMin = list[j];
				currentMinIndex = j;
			}
		}

		//temporary list is sorted
		temp[i] = list[currentMinIndex];
	}

	//goes through each element in temp and the given list
	//if one of the elements are not equal, return false otherwise return true
	for (int i = 0; i < size; i++)
	{
		if (temp[i] != list[i])
		{
			return false;
		}
	}
	return true;
}
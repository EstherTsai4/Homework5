#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void shuffle(vector<T>& v);

template <typename T>
void shuffle(vector<T>& v)
{
	//simulate random number generator
	srand(time(NULL));

	for (int i = 0; i < v.size(); i++)
	{
		//creates a temporary empty vector
		T* temp = new T[v.size()];
		int size = v.size();
		int index = i;
		//sets first element in vector to temporary vector
		temp[index] = v[index];

		//get a random number within the size of the given vector as a random index in vector
		int x = rand() % size;

		//swaps the element at the random index with the first element in the vector
		v[index] = v[x];
		v[x] = temp[index];
	}
}
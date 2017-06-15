#include <iostream>
#include <string>
using namespace std;

//template stands for any data type; use T to initilize variables
template <typename T>
int linearSearch(const T list[], T key, int arraySize)
{
	//goes through each value of the array to find the value (key)
	for (int i = 0; i < arraySize; i++)
	{
		//if the value is found, return the index of the value
		if (key == list[i])
		{
			return i;
		}
	}
	//if the value does not exist, return -1
	return -1;
}

//displays the array
template<typename T>
void printArray(const T list[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
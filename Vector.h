#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector
{
public:
	//constructors without argument and with argument
	Vector();
	Vector(unsigned int size);
	Vector(unsigned int size, T value);

	//append value onto vector
	void push_back(T value);

	//remove last element from vector
	void pop_back();

	//gives number of elements in the vector
	unsigned size() const;

	//returns element at specified index
	T at(int index) const;

	//returns true if vector is empty
	bool empty() const;

	//removes all elements from vector
	void clear();

	//swaps contents of vector with specified vector
	void swap(Vector<T> &v2);

	//prints the vector
	void printVector();
private:
	unsigned int capacity;
	unsigned int numberOfElements;
	T* elements;
};

//default constructor
template <typename T>
Vector<T>::Vector()
{
	//number of elements is 0
	numberOfElements = 0;
	capacity = 0;
	elements = new T[capacity];
}

//sets the size equal to the specified size and creates vector from the size. Number of elements is 0
template<typename T>
Vector<T>::Vector(unsigned int size)
{
	capacity = size;
	elements = new T[capacity];
	numberOfElements = 0;
}

//sets the size equal to the specified size and sets the elements of the vector to the specified value
//increments numberofelements by one for each value added to vector
template<typename T>
Vector<T>::Vector(unsigned int size, T value)
{
	capacity = size;
	elements = new T[capacity];
	numberOfElements = capacity;

	//sets each element of the vector size to the value 
	for (int i = 0; i < capacity; i++)
	{
		elements[i] = value;
	}
}

//appends value to the vector
template<typename T>
void Vector<T>::push_back(T value)
{
	//if the number of elements in the vector is equal to or greater than the capacity
	if (numberOfElements >= capacity)
	{
		//if the capacity is zero, make the capacity one
		if (capacity == 0)
		{
			capacity = 1;
		}
		else 
		{
			//double the capacity and create a temporary array and copy the original array to the temp array
			unsigned int newSize = 2 * capacity;
			T* Temp = new T[newSize];
			for (int i = 0; i < capacity; i++)
			{
				Temp[i] = elements[i];
			}
			//set the element array to the temporary array
			//make the new size the capacity
			elements = Temp;
			capacity = newSize;
		}
	}
	//add the desired value into the vector
	elements[numberOfElements++] = value;
}

//deletes value last added to vector
template<typename T>
void Vector<T>::pop_back()
{
	//moves back one place in the vector
	--numberOfElements;
}

//returns the number of elements in the vector
template<typename T>
unsigned Vector<T>::size() const
{
	return numberOfElements;
}

//returns the element at the specified index
template<typename T>
T Vector<T>::at(int index) const
{
	return elements[index];
}

//returns true if vector is empty
template<typename T>
bool Vector<T>::empty() const
{
	//if the element returns empty, output true
	if (elements.empty())
	{
		return true;
	}
	//else output false
	else
	{
		return false;
	}
}

//removes all elements from vector
template<typename T>
void Vector<T>::clear()
{
	delete [] elements;
}

//swaps values of vector with desired vector
template<typename T>
void Vector<T>::swap(Vector<T> &v2)
{
	//sets up a temporary vector
	T* temp = new T[capacity];
	//for each value in the current vector save it to the temporary vector
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = elements[i];
		//save the element of vector 2 in the original vector
		elements[i] = v2.at(i);
	}
	//clear all elements in the second vector
	v2.clear();

	//put in each element from the temporary vector to vector 2
	for (int i = 0; i < capacity; i++)
	{
		v2.push_back(temp[i]);
	}

	//clear the temporary vector to get memory
	delete[] temp;
}

template <typename T>
void Vector<T>::printVector()
{
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << elements[i] << " ";
	}
	cout << endl;
}
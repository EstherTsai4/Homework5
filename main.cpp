#include <iostream>
#include <iomanip>
#include "LinearSearch.cpp"
#include "IsSorted.h"
#include "Shuffle.h"
#include "Vector.h"
#include "Account.h"
using namespace std;

int main()
{
	//Exercise 12.2 Linear Search
	//Test an int array
	int intArray[] = { 1, 2, 3, 4, 5, 6 };
	//display the array by calling the function to display arrray
	cout << "intArray is: ";
	printArray(intArray, 6);
	//call function to find the value in array and display the index
	cout << "The location of the value 3 in intArray is: " << linearSearch(intArray, 3, 6) << endl;

	//test a double array
	double doubleArray[] = { 1.4, 2.6, 5.5, 6, 7.8 };
	//display the array by calling function printArray
	cout << "doubleArray is: ";
	printArray(doubleArray, 5);
	//call function to find the value in array and display the index
	cout << "The location of the value 7.8 in doubleArray is: " << linearSearch(doubleArray, 7.8, 5) << endl;

	//test a string array 
	string stringArray[] = { "Esther", "Ivanna", "Tsai" };
	//display the array by calling function printArray
	cout << "stringArray is: ";
	printArray(stringArray, 3);
	//call function to find the value in array and display the index
	cout << "The location of the value 'Esther' in stringArray is: " << linearSearch(stringArray, string("Esther"), 3) << endl;
	

	//Exercise 12.4 Is Sorted?
	//test int array
	int sortedInt[] = { 1, 2, 3, 4, 5 };
	int notSortedInt[] = { 2, 5, 1, 3, 4 };
	//call function to see if the array is sorted
	cout << "The sortedInt array is sorted? True(1) or False(0) " << isSorted(sortedInt, 5) << endl;
	cout << "The notSortedInt array is sorted? " << isSorted(notSortedInt, 5) << endl;

	//test double array
	double sortedDouble[] = { 1.1, 1.2, 1.3, 1.4, 1.5 };
	double notSortedDouble[] = { 5.5, 2.3, 1.0, 9.7, 4.5 };
	//call function to see if array is sorted
	cout << "The sortedDouble array is sorted? " << isSorted(sortedDouble, 5) << endl;
	cout << "The notSortedDouble array is sorted? " << isSorted(notSortedDouble, 5) << endl;

	//test string array
	string sortedString[] = { "Esther", "Grouse", "Mouse" };
	string notSortedString[] = { "Cat", "Apple", "Tree" };
	//call function to see if array is sorted
	cout << "The sortedString array is sorted? " << isSorted(sortedString, 3) << endl;
	cout << "The notSortedString array is sorted? " << isSorted(notSortedString, 3) << endl;

	//Exercise 12.8 Implement vector class
	//test integer Vector object
	Vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	//print vector v1
	cout << "Vector v1 object elements before pop back are: " << endl;
	v1.printVector();
	//call pop_back
	v1.pop_back();
	cout << "Vector v1 object elements after pop back are: " << endl;
	v1.printVector();
	//return the size of the vector
	cout << "The size of Vector object v1 is: " << v1.size() << endl;
	//return element at index 4
	cout << "At index 4, the element of v1 is: " << v1.at(4) << endl;

	//Exercise 12.20 Shuffle Vector
	vector <int> IntVector;
	for (int i = 0; i < 10; i++)
	{
		IntVector.push_back(i + 1);
	}
	cout << "Before shuffling the numbers of IntVector is: ";
	for (int i = 0; i < 10; i++)
	{
		cout << IntVector[i] << " ";
	}
	cout << endl;

	shuffle(IntVector);

	cout << "After shuffling, the numbers of IntVector is: ";
	for (int i = 0; i < 10; i++)
	{
		cout << IntVector[i] << " ";
	}
	cout << endl;

	//Exercise 12.25: Account Class
	//declare variables
	double annualInterestRate = 0;
	double balance = 0;
	int ID = 0;
	string name = "";

	//ask user to create an account
	cout << "Please enter in your name and ID: ";
	cin >> name;
	cin >> ID;
	cout << "Welcome " << name << "! Please enter in your current balance: ";
	cin >> balance;
	cout << "What is the annual interest rate? ";
	cin >> annualInterestRate;

	//create an account object from inputs
	Account account1(name, ID, balance);
	account1.setAnnualInterestRate(annualInterestRate);

	//ask for transactions until user quits
	char choice = 'a';
	double amount = 0;
	cout << "Would you like to make a withdrawal (w), deposit(d), or quit (q) ? ";
	cin >> choice;
	//as long as the user does not enter q the program will keep going
	while (tolower(choice) != 'q')
	{
		//choice for withdrawal calls withdraw function within account class
		if (tolower(choice) == 'w')
		{
			cout << "How much would you like to withdraw? ";
			cin >> amount;
			account1.withdraw(amount);
		}
		//choice for deposit calls deposit function within account class
		else if (tolower(choice) == 'd')
		{
			cout << "How much would you like to deposit? ";
			cin >> amount;
			account1.deposit(amount);
		}

		//let user decide if they want to make another transaction
		cout << "Would you like to make another withdrawal/deposit? Or would you like to quit? ";
		cin >> choice;
	}
	//display the transaction history
	cout << "This is a summary of your transactions: " << endl;
	cout << "Name : " << name << right << setw(5) << "ID: " << account1.getID() << setw(5) << "Starting Balance: " << account1.getBalance() << endl;
	cout << "Annual Interest Rate: " << account1.getAnnualInterestRate() << endl;
	account1.printTransations();
	
	return 0;
}
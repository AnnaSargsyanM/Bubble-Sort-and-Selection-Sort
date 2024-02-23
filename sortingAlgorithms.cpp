//     This program reads the student names from a text file. Then prompts the 
//     user for a student name, searches it, and displays the index if found. 
//     Also, the program rearranges the student names in ascending and 
//     descending formats.
//
//****************************************************************************************************

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int NUM_NAMES = 10;

void readNames(const string&, string[], const int);
void displayNames(const string[], const int);
void selectionSort(string[], const int);
int binarySearchNames(const string[], const int, const string&);
void selectionSortDescending(string[], const int);

int main()
{
	string names[NUM_NAMES];
	string name;
	string inputFile = "StudentNames.txt";

	readNames(inputFile, names, NUM_NAMES);

	cout << "Names in the file are: " << endl;
	displayNames(names, NUM_NAMES);
	cout << endl;	
	
	selectionSort(names, NUM_NAMES);
	cout << "Names in the ascending order are as follows: " << endl;
	displayNames(names, NUM_NAMES);
	cout << endl;



	cout << "Enter the name you are looking for: " << endl;
	getline(cin, name);
	int index = binarySearchNames(names, NUM_NAMES, name);
	if (index == -1)
	{
		cout << "Name '" << name << "' not found in the array." << endl;
	}
	else
	{
		cout << "Name '" << name << "' found at the index: " << index + 1<< endl;
	}


	cout << endl;
	selectionSortDescending(names, NUM_NAMES);
	cout << "Names in the descending order are as follows: " << endl;
	displayNames(names, NUM_NAMES);

}

//****************************************************************************************************

void readNames(const string& inputFile, string names[], const int NUM_NAMES)
{
	ifstream StudentNames_file(inputFile);

	if (!StudentNames_file)
	{
		cout << "Unable to open file " << inputFile << endl;
		return;
	}

	for (int i = 0; i < NUM_NAMES; i++)
	{
		if (!getline(StudentNames_file, names[i]))
		{
			cout << "Failed to read data from file " << inputFile << endl;
			StudentNames_file.close();
			return;
		}
	}

	StudentNames_file.close();
}

//****************************************************************************************************

void displayNames(const string names[], const int NUM_NAMES)
{
	for (int i = 0; i < NUM_NAMES; i++)
	{
		cout << names[i] << endl;
	}
}

//****************************************************************************************************
void selectionSort(string names[], const int NUM_NAMES)
{
	int minIndex;
	string minValue;

	for (int i = 0; i < (NUM_NAMES - 1); i++)
	{
		minIndex = i;
		minValue = names[i];
		for (int j = i + 1; j < NUM_NAMES; j++)
		{
			if (names[j] < minValue)
			{
				minValue = names[j];
				minIndex = j;
			}
		}
		swap(names[minIndex], names[i]);
	}
}

//****************************************************************************************************

int binarySearchNames(const string names[], const int NUM_NAMES, const string& name)
{
	int first = 0,
		last = NUM_NAMES - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (names[middle] == name)
		{
			found = true;
			position = middle;
		}
		else if (names[middle] > name)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}

	if (!found)
	{
		position = -1;
	}

	return position;
}

//****************************************************************************************************

void selectionSortDescending(string names[], const int NUM_NAMES)
{
	int minIndex;
	string minValue;

	for (int i = 0; i < (NUM_NAMES - 1); i++)
	{
		minIndex = i;
		minValue = names[i];
		for (int j = i + 1; j < NUM_NAMES; j++)
		{
			if (names[j] > minValue)
			{
				minValue = names[j];
				minIndex = j;
			}
		}
		swap(names[minIndex], names[i]);
	}
}

//****************************************************************************************************
/*

Names in the file are :
Smith, John
Song, Mona
Jones, Trevor
Li, Na
Zhang, Xiu Ying
Saleem, Mohammad
Lloyd, Arthur
Jones, Rhys
Evans, Olivia
Davies, Emily

Names in the ascending order are as follows :
Davies, Emily
Evans, Olivia
Jones, Rhys
Jones, Trevor
Li, Na
Lloyd, Arthur
Saleem, Mohammad
Smith, John
Song, Mona
Zhang, Xiu Ying

Enter the name you are looking for:
Jones, Rhys
Name 'Jones, Rhys' found at the index : 3

Names in the descending order are as follows :
Zhang, Xiu Ying
Song, Mona
Smith, John
Saleem, Mohammad
Lloyd, Arthur
Li, Na
Jones, Trevor
Jones, Rhys
Evans, Olivia
Davies, Emily

*/



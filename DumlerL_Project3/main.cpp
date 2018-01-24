/**********************************************
* Name: Lauren Dumler						  *
* Date: December 5, 2017					  *
* Assignment: Project 3: Sets				  *
***********************************************
* This program takes 2 sets of numbers and	  * 
prints out the union, difference, or		  *
intersection of them.						  *
***********************************************/

#include <iostream>
#include "set.h"
#include "set.cpp"
#include <string>
using namespace std;

int main() {
	string input;
	cout << "\nInput vector 1 (like num1,num2,...numN): ";
	getline(cin, input);

	string delim = ",";

	Set<int> *setA = new Set<int>();
	Set<int> *setB = new Set<int>();

	int temp;
	size_t pos = 0;
	string token;
	while ((pos = input.find(delim)) != string::npos) {
		token = input.substr(0, pos);
		temp = stoi(token);
		setA->add(temp);
		input.erase(0, pos + delim.length());
	}
	temp = stoi(input);
	setA->add(temp);
	
	cout << "\nInput vector 2 (like num1,num2,...numN): ";
	getline(cin, input);

	pos = 0;
	while ((pos = input.find(delim)) != string::npos) {
		token = input.substr(0, pos);
		temp = stoi(token);
		setB->add(temp);
		input.erase(0, pos + delim.length());
	}
	temp = stoi(input);
	setB->add(temp);

	setA->quickSort(setA->stuff, 0, setA->place-1);
	setB->quickSort(setB->stuff, 0, setB->place-1);

	cout << "\nThe sorted sets are:";
	setA->print();
	cout << "\n";
	setB->print();
	cout << "\n";

	char answer = 'a';

	while (answer != 'q' && answer != 'Q') {
		cout << "\nEnter (i)ntersect, (u)nion, (d)ifference, or (q)uit: ";
		cin >> answer;

		if (answer == 'i' || answer == 'I')
		{
			setA->Intersection(setB);
		}

		else if (answer == 'u' || answer == 'U') {
			setA->Union(setB);
		}

		else if (answer == 'd' || answer == 'D') {
			setA->Difference(setB);
		}

		else cout << "Input invalid." << endl;
	}

	getchar();

	delete setA;
	delete setB;
		
	return 0;
}
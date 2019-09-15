// ElevatorProjectVS2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "queue.h"
#include <string>

using namespace std;

int main()
{
    cout << "Hello World!\n";

	queue<string> names;
	names.push("Rich");
	names.push("Debbie");
	names.push("Robin");
	names.push("Dustin");
	names.push("Jonathan");

	string first = names.front();

	names.pop();
	names.push("Philip");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
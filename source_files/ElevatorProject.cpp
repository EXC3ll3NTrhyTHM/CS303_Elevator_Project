// ElevatorProjectVS2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "queue.h"
#include "circular_queue.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	const int ELEVATOR_CAPACITY = 10;
	const int STARTING_FLOOR = 0;
	int personCurrentFloor;
	int personDesiredFloor;
	int elevatorCurrentFloor;
	string elevatorDirection;

	// Below is seeded random number generation using the system time to reset the seed every execution to ensure the number generated is truely random.
	// Also the static_cast thing is used here because the time() function returns a slightly different data type than what srand() is expecting causing C++ to dynamically type cast the returned value which threw an warning when the program was ran. Using the static_cast() function makes the casting handled by the program and not the compiler so that the warning message does not display.
	srand(static_cast<unsigned int>(time(NULL)));

	elevatorCurrentFloor = STARTING_FLOOR;
	int numberOfPeopleWantingOnElevator = (rand() % 50) + 1;
	cout << "People in the building: " << numberOfPeopleWantingOnElevator << endl;

	// Assign people wanting on elevator a current floor and desired floor.
	for (int i = 0; i < numberOfPeopleWantingOnElevator; i++) {
		// Create an array of people with values for desired floor and current floor
	}

	// Declaring a circular queue. The size of the queue (10) represents the elevator weight capacity converted to number of people.
	CQ::queue<int> elevator(ELEVATOR_CAPACITY);

	while (numberOfPeopleWantingOnElevator > 0) {
		personCurrentFloor = (rand() % 10) + 1;

		// Do-while ensures desired floor is not the current floor
		do {
			personDesiredFloor = (rand() % 10) + 1;
		} while (personDesiredFloor == personCurrentFloor);

		// Case for elevator needing to travel up to get to person who pressed button
		if (personCurrentFloor > elevatorCurrentFloor) {
			elevatorDirection = "Up";
			elevatorCurrentFloor = personCurrentFloor;
			elevator.push(personDesiredFloor);
			if (elevatorCurrentFloor > personDesiredFloor) {
				elevatorDirection = "Up";
				elevatorCurrentFloor = personDesiredFloor;
				elevator.pop();
				--numberOfPeopleWantingOnElevator;
			}
			else if (personCurrentFloor > elevatorCurrentFloor) {
				elevatorDirection = "Down";
				elevatorCurrentFloor = personDesiredFloor;
				elevator.pop();
				--numberOfPeopleWantingOnElevator;
			}
		}
		// Case for elevator needing to travel down to get to person who pressed button
		else if (personCurrentFloor < elevatorCurrentFloor) {
			elevatorDirection = "Down";
			elevatorCurrentFloor = personCurrentFloor;
			elevator.push(personDesiredFloor);
			if (elevatorCurrentFloor > personDesiredFloor) {
				elevatorDirection = "Up";
				elevatorCurrentFloor = personDesiredFloor;
				elevator.pop();
				--numberOfPeopleWantingOnElevator;
			}
			else if (personCurrentFloor > elevatorCurrentFloor) {
				elevatorDirection = "Down";
				elevatorCurrentFloor = personDesiredFloor;
				elevator.pop();
				--numberOfPeopleWantingOnElevator;
			}
		}
		// Case for elevator not needing to travel to get to person who pressed button
		else {
			elevator.push(personDesiredFloor);
			if (elevatorCurrentFloor > personDesiredFloor) {
				elevatorDirection = "Up";
				elevatorCurrentFloor = personDesiredFloor;
				elevator.pop();
				--numberOfPeopleWantingOnElevator;
			}
			else if (personCurrentFloor > elevatorCurrentFloor) {
				elevatorDirection = "Down";
				elevatorCurrentFloor = personDesiredFloor;
				elevator.pop();
				--numberOfPeopleWantingOnElevator;
			}
		}
	}
}
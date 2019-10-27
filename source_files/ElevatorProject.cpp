// ElevatorProjectVS2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "person.h"
#include "vector.h"
#include "elevator.h"

int main()
{
	const int STARTING_FLOOR = 0;
	int personCurrentFloor;
	int personDesiredFloor;
	int ID;
	int elevatorCurrentFloor;
	int waitTime;
	std::string elevatorDirection;
	KW::vector<person> waitingList;
	elevator Elevator;
	int i;
	int k;

	srand(static_cast<unsigned int>(time(NULL)));// Random number generator seed

	elevatorCurrentFloor = STARTING_FLOOR;
	int numberOfPeopleWantingOnElevator = (rand() % 15 + 1);// Picks random number between 1 and 15
	std::cout << "People in the building trying to get on elevator: " << numberOfPeopleWantingOnElevator << std::endl;

	// Create a vector of people with values for desired floor and current floor
	for (int i = 0; i < numberOfPeopleWantingOnElevator; i++) {
		ID = i + 1;
		personCurrentFloor = (rand() % 9); // 0 is the ground floor.

		// Do-while ensures desired floor is not the current floor for the same person
		do {
			personDesiredFloor = (rand() % 9); // 0 is the ground floor.
		} while (personDesiredFloor == personCurrentFloor);
		waitingList.push_back(person(personCurrentFloor, personDesiredFloor, ID));
	}

	std::cout << "Waitlist at the very beginning" << std::endl;
	for (int i = 0; i < numberOfPeopleWantingOnElevator; i++) {
		std::cout << "Person " << i + 1 << ": " << waitingList[i].currentFloor << " " << waitingList[i].desiredFloor << std::endl;
	}

	Elevator.direction = "Up"; //Since elevator is on the ground floor at the beginning of the program, set direction to "Up"
	while (waitingList.size() > 0) {

		// Sets the target to the highest floor where sb. is waiting to get in.
	/************************************************************************************************************/
		k = waitingList[0].currentFloor;
		for (int i = 0; i < waitingList.size(); i++) {
			if (waitingList[i].currentFloor > k) {
				k = waitingList[i].currentFloor;
			}
		}

		Elevator.setTargetFloor(k);
		std::cout << "Target floor set to:" << Elevator.targetFloor << std::endl;
		std::cout << "Current floor is: " << Elevator.currentFloor << std::endl;
		if ((Elevator.currentFloor <= Elevator.targetFloor) && (Elevator.direction == "Up")) {
			Elevator.moveUpAndCheckEachFloor(waitingList);
		}
		else {
			Elevator.moveDownAndCheckEachFloor(waitingList);
		}
	}
}
/**********************************************************************************************************************/
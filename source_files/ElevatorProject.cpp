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
	int waitTime;
	std::string elevatorDirection;
	KW::vector<person> waitingList;
	elevator Elevator;
	int i;
	Elevator.currentFloor = STARTING_FLOOR;


	srand(static_cast<unsigned int>(time(NULL)));// Random number generator seed
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

	/*
	Elevator starts
	*/
	while (waitingList.size() > 0) {
		Elevator.setTargetFloor(waitingList[0].currentFloor);
		std::cout << "Target floor set to:" << Elevator.targetFloor << std::endl;
		if (Elevator.currentFloor < Elevator.targetFloor) {
			Elevator.moveUpAndCheckEachFloor(waitingList);
		}
		else if (Elevator.currentFloor > Elevator.targetFloor) {
			Elevator.moveDownAndCheckEachFloor(waitingList);
		}
		else if (Elevator.currentFloor == Elevator.targetFloor) {
			Elevator.elevatorCarriage.push_back(waitingList[0]);
			waitingList.erase(0);
			Elevator.setTargetFloor(Elevator.elevatorCarriage[Elevator.elevatorCarriage.size() - 1].desiredFloor);
			if (Elevator.currentFloor < Elevator.targetFloor) {
				Elevator.moveDownAndCheckEachFloor(waitingList);
			}
			else {
				Elevator.moveDownAndCheckEachFloor(waitingList);
			}
		}
	}
}
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
	const int STARTING_FLOOR = 1; 
	int personCurrentFloor;
	int personDesiredFloor;
	int elevatorCurrentFloor;
	int waitTime;
	std::string elevatorDirection;
	KW::vector<person> waitingList;
	elevator Elevator;
	int i;

	srand(static_cast<unsigned int>(time(NULL)));// Random number generator seed

	elevatorCurrentFloor = STARTING_FLOOR;
	int numberOfPeopleWantingOnElevator = (rand() % 99) + 1;// Picks random number between 1 and 100
	std::cout << "People in the building trying to get on elevator: " << numberOfPeopleWantingOnElevator << std::endl;

	// Create a vector of people with values for desired floor and current floor
	for (int i = 0; i < numberOfPeopleWantingOnElevator; i++) {
		personCurrentFloor = (rand() % 9) + 1;

		// Do-while ensures desired floor is not the current floor
		do {
			personDesiredFloor = (rand() % 9) + 1; 
		} while (personDesiredFloor == personCurrentFloor);
		waitingList.push_back(person(personCurrentFloor, personDesiredFloor));
	}
	
	while (waitingList.size() > 0) {

		// Travels to current floor of next person in waitingList vector
	/************************************************************************************************************/
		Elevator.setTargetFloor(waitingList[0].currentFloor);
		if (Elevator.currentFloor < Elevator.targetFloor) {
			Elevator.moveUpAndCheckEachFloor(waitingList);
		}
		else if (Elevator.currentFloor > Elevator.targetFloor) {
			Elevator.moveDownAndCheckEachFloor(waitingList);
		}
	/**********************************************************************************************************************/
		// Current floor of next person in waitingList vector reached
		Elevator.elevatorCarriage.push_back(waitingList[0]); // First person who pushed button now gets on
		waitingList.erase(0);
		int personWhoPushedButton = Elevator.elevatorCarriage.size() - 1;

		// Travel to person desired floor
		Elevator.setTargetFloor(Elevator.elevatorCarriage[personWhoPushedButton].desiredFloor);
		if (Elevator.currentFloor < Elevator.targetFloor) {
			Elevator.moveUpAndCheckEachFloor(waitingList);
		}
		else if (Elevator.currentFloor > Elevator.targetFloor) {
			Elevator.moveDownAndCheckEachFloor(waitingList);		
		}
	}

	// Checking that no one was left on the elevator
	std::cout << "Waiting list size: " << waitingList.size() << std::endl;
	std::cout << "Elevator carriage size: " << Elevator.elevatorCarriage.size() << std::endl;
	if (Elevator.elevatorCarriage.size() > 0) {
		std::cout << "Elevator current floor: " << Elevator.currentFloor << std::endl;
		for (int i = 0; i < Elevator.elevatorCarriage.size(); i++) {
			std::cout << "Current floor: " << Elevator.elevatorCarriage[i].currentFloor << " Desired Floor: " << Elevator.elevatorCarriage[i].desiredFloor << std::endl;
		}
	}
}
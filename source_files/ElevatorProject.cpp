// ElevatorProjectVS2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
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
	elevator Elevator2;
	int i;
	Elevator.currentFloor = STARTING_FLOOR;

	/*
	Boilerplate
	*/
	srand(static_cast<unsigned int>(time(NULL)));// Random number generator seed
	int numberOfPeopleWantingOnElevator = (rand() % 14 + 1);// Picks random number between 1 and 15
	std::cout << "People in the building trying to get on elevator: " << numberOfPeopleWantingOnElevator << std::endl;

	// Create a vector of people with values for desired floor and current floor
	for (i = 0; i < numberOfPeopleWantingOnElevator; i++) {
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
	First elevator starts
	*/
	Elevator.elevatorStartTime = std::chrono::high_resolution_clock::now();
	Elevator2.elevatorStartTime = std::chrono::high_resolution_clock::now();

	int halfOfWaitingList = waitingList.size() / 2;

	std::cout << "Half of waiting list: " << halfOfWaitingList << std::endl;
	while (waitingList.size() > halfOfWaitingList) {
		Elevator.setTargetFloor(waitingList[0].currentFloor);// First person in the waiting list is the priority for the elevator
		std::cout << "Target floor set to: " << Elevator.targetFloor << std::endl;
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

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

	std::cout << "Second Elevator Start, Waiting list size: " << waitingList.size() << std::endl;
	for (i = 0; i < waitingList.size(); i++) {
		std::cout << waitingList[i].currentFloor << " " << waitingList[i].desiredFloor << std::endl;
	}

	/*
	Second elevator starts
	If everyone was picked up by the first elevator then this one will not pick any one up
	*/
	while (waitingList.size() > 0) {
		Elevator2.setTargetFloor(waitingList[0].currentFloor);
		std::cout << "Target floor set to: " << Elevator.targetFloor << std::endl;
		if (Elevator2.currentFloor < Elevator2.targetFloor) {
			Elevator2.moveUpAndCheckEachFloor(waitingList);
		}
		else if (Elevator2.currentFloor > Elevator2.targetFloor) {
			Elevator2.moveDownAndCheckEachFloor(waitingList);
		}
		else if (Elevator2.currentFloor == Elevator2.targetFloor) {
			Elevator2.elevatorCarriage.push_back(waitingList[0]);
			waitingList.erase(0);
			Elevator2.setTargetFloor(Elevator2.elevatorCarriage[Elevator2.elevatorCarriage.size() - 1].desiredFloor);
			if (Elevator2.currentFloor < Elevator2.targetFloor) {
				Elevator2.moveDownAndCheckEachFloor(waitingList);
			}
			else {
				Elevator2.moveDownAndCheckEachFloor(waitingList);
			}
		}
	}

	std::cout << "Waiting list size: " << waitingList.size() << std::endl;
	std::cout << "Elevator carriage size: " << Elevator.elevatorCarriage.size() << std::endl;
	std::cout << "Elevator2 carriage size: " << Elevator2.elevatorCarriage.size() << std::endl;
}
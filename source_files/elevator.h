#pragma once
#include <string>
#include "person.h"
#include "vector.h"
#include <ratio>
#include <ctime>
#include <chrono>
#include <chrono>
class elevator
{
public:
	std::string direction;
	int currentFloor;
	int targetFloor;
	KW::vector<person> elevatorCarriage;
	std::chrono::high_resolution_clock::time_point elevatorStartTime;
	elevator();
	
	void setCurrentFloor(int currentFloor1);

	void setTargetFloor(int targetFloor1);

	int getCurrentFloor();

	int getTargetFloor();

	void moveUpAndCheckEachFloor(KW::vector<person>& waitingList); //Have to use pass by reference to get the vectors modified also outside of the functions.

	void moveDownAndCheckEachFloor(KW::vector<person>& waitingList);

	void getsOnElevator(person p) {
		elevatorCarriage.push_back(p);
	}
};

void elevator::setCurrentFloor(int currentFloor1) {
	currentFloor = currentFloor1;
}
void elevator::setTargetFloor(int targetFloor1) {
	targetFloor = targetFloor1;
}

int elevator::getCurrentFloor() {
	return currentFloor;
}

int elevator::getTargetFloor() {
	return targetFloor;
}

void elevator::moveUpAndCheckEachFloor(KW::vector<person>& waitingList) {
	direction = "Up";
	int i;
	while (currentFloor <= targetFloor) {
		i = 0;
		std::cout << "Current floor is: " << currentFloor << std::endl;
		/*
		While loop for people getting onto the elevator
		Checks everyone in the waiting list for if they are on the current floor of the elevator and if they want to go to a floor higher than the current floor
		*/
		while (i < waitingList.size() && elevatorCarriage.size() < 10) {
			if (currentFloor == waitingList[i].currentFloor && currentFloor < waitingList[i].desiredFloor) {// If person is on current floor and their desired floor is greater than the current floor, they get on
				elevatorCarriage.push_back(waitingList[i]);
				std::cout << "Got in ID : " << waitingList[i].ID << std::endl;
				if (targetFloor < waitingList[i].desiredFloor) {
					targetFloor = waitingList[i].desiredFloor; //Everytime a person gets in, check and set targetfloor to highest desired floor.
					std::cout << "Target floor is now : " << waitingList[i].desiredFloor << std::endl;
				}
				std::cout << "Popped off from the waitlist, ID : " << waitingList[i].ID << std::endl;
				waitingList.erase(i);
				std::cout << "Num of people in the elevator: " << elevatorCarriage.size() << std::endl;
				std::cout << "Num of people in the waitlist: " << waitingList.size() << std::endl;
			}
			else {
				i++;
			}
		}

		i = 0;
		//People getting off the elevator
		while (i < elevatorCarriage.size()) {
			if (elevatorCarriage[i].desiredFloor == currentFloor) {
				std::cout << "Got off, ID : " << elevatorCarriage[i].ID << std::endl;
				elevatorCarriage[i].setWaitTime(std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - elevatorStartTime));
				std::cout << elevatorCarriage[i].ID << " waited: " << elevatorCarriage[i].timeWaited.count() << std::endl;
				elevatorCarriage.erase(i);
				std::cout << "Current Floor is " << currentFloor << std::endl;
				std::cout << "Num of people in the elevator: " << elevatorCarriage.size() << std::endl;
				std::cout << "Num of people in the waitlist: " << waitingList.size() << std::endl;
			}
			else {
				i++;
			}
		}
		if (currentFloor != 10) {
			setCurrentFloor(currentFloor += 1);
		}
		else {
			break;
		}
	}
}

void elevator::moveDownAndCheckEachFloor(KW::vector<person>& waitingList) {
	direction = "Down";// Elevator goes down
	int i;
	while (currentFloor >= targetFloor) {
		i = 0;
		std::cout << "Current floor is: " << currentFloor << std::endl;
		while (i < waitingList.size() && elevatorCarriage.size() < 10) {

			if (waitingList[i].currentFloor == currentFloor && waitingList[i].desiredFloor < currentFloor) {
				elevatorCarriage.push_back(waitingList[i]);// If person is on current floor and wants to go to floor that is at or before target floor elevator picks them up
				std::cout << "Got in, ID : " << waitingList[i].ID << std::endl;
				if (targetFloor > waitingList[i].desiredFloor) {
					targetFloor = waitingList[i].desiredFloor; //Everytime sb. gets in check and set targetfloor to lowest desired floor.
					std::cout << "Target floor is now : " << waitingList[i].desiredFloor << std::endl;
				}
				std::cout << "Popped off from the waitlist, ID : " << waitingList[i].ID << std::endl;
				waitingList.erase(i);
				std::cout << "Current Floor is " << currentFloor << std::endl;
				std::cout << "Num of people in the elevator: " << elevatorCarriage.size() << std::endl;
				std::cout << "Num of people in the waitlist: " << waitingList.size() << std::endl;
			}
			else {
				i++;
			}
		}
		i = 0;
		while (i < elevatorCarriage.size()) {
			if (elevatorCarriage[i].desiredFloor == currentFloor) {
				std::cout << "Got off, ID :" << elevatorCarriage[i].ID << std::endl;
				elevatorCarriage[i].setWaitTime(std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - elevatorStartTime));
				std::cout << elevatorCarriage[i].ID << " waited: " << elevatorCarriage[i].timeWaited.count() << std::endl;
				elevatorCarriage.erase(i);
				std::cout << "Current Floor is " << currentFloor << std::endl;
				std::cout << "Num of people in the elevator: " << elevatorCarriage.size() << std::endl;
				std::cout << "Num of people in the waitlist: " << waitingList.size() << std::endl;
			}
			else {
				i++;
			}
		}
		if (currentFloor != 0) {
			setCurrentFloor(currentFloor -= 1);
		}
		else {
			break;
		}
	}
}

elevator::elevator() {
	currentFloor = 0;
	targetFloor = 0;
}
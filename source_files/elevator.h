#pragma once
#include <string>
#include "person.h"
#include "vector.h"
class elevator
{
public:
	std::string direction;
	int currentFloor;
	int targetFloor;
	KW::vector<person> elevatorCarriage;
	elevator();

	void setCurrentFloor(int currentFloor1);

	void setTargetFloor(int targetFloor1);

	int getCurrentFloor();

	int getTargetFloor();

	void moveUpAndCheckEachFloor(KW::vector<person> &waitingList); //Have to use pass by reference to get the vectors modified also outside of the functions.

	void moveDownAndCheckEachFloor(KW::vector<person> &waitingList);

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

void elevator::moveUpAndCheckEachFloor(KW::vector<person> &waitingList) {
	direction = "Up";
	int i;
	while (currentFloor <= targetFloor) {
		setCurrentFloor(currentFloor += 1);
		i = 0;
		//Conditional people are getting onto the elevator
		std::cout << "Current floor is: " << currentFloor << std::endl;
		while (i < waitingList.size() && elevatorCarriage.size() < 10) {
			if (currentFloor == waitingList[i].currentFloor && currentFloor < waitingList[i].desiredFloor) {// If person is on current floor and wants to get off before target floor or at target floor, elevator picks them up
				elevatorCarriage.push_back(waitingList[i]);
				std::cout << "Got in ID : " << waitingList[i].ID << std::endl;
				if (targetFloor < waitingList[i].desiredFloor) {
					targetFloor = waitingList[i].desiredFloor; //Everytime sb. gets in check and set targetfloor to highest desired floor.
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
				elevatorCarriage.erase(i);
				std::cout << "Num of people in the elevator: " << elevatorCarriage.size() << std::endl;
				std::cout << "Num of people in the waitlist: " << waitingList.size() << std::endl;
				if ((elevatorCarriage.size() == 0) && (waitingList.size() == 0)) { //If there is no one left in the elevator, end program.
					std::cout << "Nobody in the carriage and waitlist. End of program" << std::endl;
					currentFloor = 0; //Elevator goesto ground floor when everybody gets off and there is no request because ground floor is the most used floor.
					std::cout << "Elevator is back on the ground floor." << std::endl;
					exit(0);
				}
			}

			else {
				i++;
			}
		}
	}
}

void elevator::moveDownAndCheckEachFloor(KW::vector<person> &waitingList) {
	direction = "Down";// Elevator goes down
	int i;
	while (currentFloor >= targetFloor) {
		setCurrentFloor(currentFloor -= 1);
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
				elevatorCarriage.erase(i);
				std::cout << "Num of people in the elevator: " << elevatorCarriage.size() << std::endl;
				std::cout << "Num of people in the waitlist: " << waitingList.size() << std::endl;
				if ((elevatorCarriage.size() == 0) && (waitingList.size() == 0)) { //Only need to check at target floor bc otherwise there will always be sb. in the carriage.
					std::cout << "Nobody in the carriage and waitlist. End of program" << std::endl;
					currentFloor = 0; //Elevator goes to ground floor when everybody gets off and there is no request because ground floor is the most used floor.
					std::cout << "Elevator is back on the ground floor." << std::endl;
					exit(0);
				}
			}
			else {
				i++;
			}
		}
	}
}

elevator::elevator() {
	currentFloor = 0;
	targetFloor = 0;
}
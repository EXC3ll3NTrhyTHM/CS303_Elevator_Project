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
		Doesnt allow final spot in elevator to be filled as that is reserved for the first person who pushed the button
		*/
		while (i < waitingList.size() && elevatorCarriage.size() < 9) {
			if (currentFloor == waitingList[i].currentFloor && currentFloor < waitingList[i].desiredFloor) {// If person is on current floor and their desired floor is greater than the current floor, they get on
				elevatorCarriage.push_back(waitingList[i]);
				std::cout << "Got in ID : " << waitingList[i].ID << std::endl;
				if (targetFloor < waitingList[i].desiredFloor) {
					targetFloor = waitingList[i].desiredFloor; //Everytime sb. gets in, check and set targetfloor to highest desired floor.
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
			}

			else {
				i++;
			}
		}
		/*
		Moved this to bottom so that the floor the elevator started on is checked
		*/
		setCurrentFloor(currentFloor += 1);
	}
}

void elevator::moveDownAndCheckEachFloor(KW::vector<person>& waitingList) {
	direction = "Down";// Elevator goes down
	int i;
	while (currentFloor >= targetFloor) {
		i = 0;
		std::cout << "Current floor is: " << currentFloor << std::endl;
		while (i < waitingList.size() && elevatorCarriage.size() < 9) {

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
			}
			else {
				i++;
			}
		}
		/*
		Moved this to bottom so that the floor the elevator started on is checked
		*/
		setCurrentFloor(currentFloor -= 1);
	}
}

elevator::elevator() {
	currentFloor = 0;
	targetFloor = 0;
}
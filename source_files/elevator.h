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
	int longestFloorsTraveled = 0;
	KW::vector<person> elevatorCarriage;
	elevator();

	void setCurrentFloor(int currentFloor1);

	void setTargetFloor(int targetFloor1);

	int getCurrentFloor();

	int getTargetFloor();

	void moveUpAndCheckEachFloor(KW::vector<person> waitingList);
	
	void moveDownAndCheckEachFloor(KW::vector<person> waitingList);

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

void elevator::moveUpAndCheckEachFloor(KW::vector<person> waitingList) {
	direction = "Up";
	int i;
	while (currentFloor != targetFloor) {
		i = 0;
		//Conditional people are getting onto the elevator
		while (i < waitingList.size() && elevatorCarriage.size() < 10) {
			if (currentFloor == waitingList[i].currentFloor && targetFloor >= waitingList[i].desiredFloor && currentFloor < waitingList[i].desiredFloor) {// If person is on current floor and wants to get off before target floor or at target floor, elevator picks them up
				elevatorCarriage.push_back(waitingList[i]);
				waitingList.erase(i);
			}
			else {
				i++;
			}
		}
		i = 0;
		//People getting off the elevator
		while (i < elevatorCarriage.size()) {
			if (elevatorCarriage[i].desiredFloor == currentFloor) {
				if (elevatorCarriage[i].floorsTraveled > longestFloorsTraveled) {
					longestFloorsTraveled = elevatorCarriage[i].floorsTraveled;
				}
				elevatorCarriage.erase(i);
			}
			else {
				elevatorCarriage[i].floorsTraveled = elevatorCarriage[i].floorsTraveled + 1;
				i++;
			}
		}
		setCurrentFloor(currentFloor += 1);
	}

	// WaitingList isnt checked here because the target destination isnt set
	if (currentFloor == targetFloor) {
		i = 0;
		while (i < elevatorCarriage.size()) {
			if (elevatorCarriage[i].desiredFloor == currentFloor) {
				if (elevatorCarriage[i].floorsTraveled > longestFloorsTraveled) {
					longestFloorsTraveled = elevatorCarriage[i].floorsTraveled;
				}
				elevatorCarriage.erase(i);
			}
			else {
				elevatorCarriage[i].floorsTraveled = elevatorCarriage[i].floorsTraveled + 1;
				i++;
			}
		}
	}
}

void elevator::moveDownAndCheckEachFloor(KW::vector<person> waitingList) {
	direction = "Down";// Elevator goes down
	int i;
	while (currentFloor != targetFloor) {
		i = 0;
		while (i < waitingList.size() && elevatorCarriage.size() < 10) {
			if (waitingList[i].currentFloor == currentFloor && waitingList[i].desiredFloor >= targetFloor && waitingList[i].desiredFloor < currentFloor) {
				elevatorCarriage.push_back(waitingList[i]);// If person is on current floor and wants to go to floor that is at or before target floor elevator picks them up
				waitingList.erase(i);
			}
			else {
				i++;
			}
		}
		i = 0;
		while (i < elevatorCarriage.size()) {
			if (elevatorCarriage[i].desiredFloor == currentFloor) {
				if (elevatorCarriage[i].floorsTraveled > longestFloorsTraveled) {
					longestFloorsTraveled = elevatorCarriage[i].floorsTraveled;
				}
				elevatorCarriage.erase(i);
			}
			else {
				elevatorCarriage[i].floorsTraveled = elevatorCarriage[i].floorsTraveled + 1;
				i++;
			}
		}
		setCurrentFloor(currentFloor -= 1);
	}
	if (currentFloor == targetFloor) {
		i = 0;
		while (i < elevatorCarriage.size()) {
			if (elevatorCarriage[i].desiredFloor == currentFloor) {
				if (elevatorCarriage[i].floorsTraveled > longestFloorsTraveled) {
					longestFloorsTraveled = elevatorCarriage[i].floorsTraveled;
				}
				elevatorCarriage.erase(i);
			}
			else {
				elevatorCarriage[i].floorsTraveled = elevatorCarriage[i].floorsTraveled + 1;
				i++;
			}
		}
	}
}

elevator::elevator() {
	currentFloor = 0;
	targetFloor = 0;
}
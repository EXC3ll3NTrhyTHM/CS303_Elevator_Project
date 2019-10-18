#pragma once
class person
{
public:
	int currentFloor;
	int desiredFloor;
	int floorsTraveled;
	person(int x, int y);
	person();

	void setCurrentFloor(int x);

	void setDesiredFloor(int x);

	void setWaitTime(int x);

	int getCurrentFloor() const;

	int getDesiredFloor() const;

	int getWaitTime();
};

void person::setCurrentFloor(int x) {
	currentFloor = x;
}

void person::setDesiredFloor(int x) {
	desiredFloor = x;
}

void person::setWaitTime(int x) {
	floorsTraveled = x;
}

int person::getCurrentFloor() const {
	return currentFloor;
}

int person::getDesiredFloor() const {
	return desiredFloor;
}

int person::getWaitTime() {
	return floorsTraveled;
}

person::person(int x, int y) {
	currentFloor = x;
	desiredFloor = y;
	floorsTraveled = 0;
}

person::person() {
	currentFloor = 0;
	desiredFloor = 0;
	floorsTraveled = 0;
}
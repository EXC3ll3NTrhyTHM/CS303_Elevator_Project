#pragma once
class person
{
public:
	int currentFloor;
	int desiredFloor;
	int ID;
	std::chrono::duration<double> timeWaited;
	person(int x, int y, int z);
	person();

	void setCurrentFloor(int x);

	void setDesiredFloor(int x);

	void setWaitTime(std::chrono::duration<double> x);

	int getCurrentFloor() const;

	int getDesiredFloor() const;

	std::chrono::duration<double> getWaitTime();
};

void person::setCurrentFloor(int x) {
	currentFloor = x;
}

void person::setDesiredFloor(int x) {
	desiredFloor = x;
}

void person::setWaitTime(std::chrono::duration<double> x) {
	timeWaited = x;
}

int person::getCurrentFloor() const {
	return currentFloor;
}

int person::getDesiredFloor() const {
	return desiredFloor;
}

std::chrono::duration<double> person::getWaitTime() {
	return timeWaited;
}

person::person(int x, int y, int z) {
	currentFloor = x;
	desiredFloor = y;
	ID = z;
}

person::person() {
	currentFloor = 0;
	desiredFloor = 0;
	ID = 0;
}
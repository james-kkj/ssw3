#include <string>


class space
{
protected:
	char state;		//B,R
	std::string borrower;
	int returnHour;
public:
	std::string name();
	char showState();
	int showReturnHour();
	void _return();
};

std::string space::name() {
	return borrower;
}


char space::showState() {
	return state;
}

int space::showReturnHour() {
	return returnHour;
}

void space::_return() {
	state = 'R';
	borrower = "";
	returnHour = 0;
}

class studyRoom :public space
{
public:
	studyRoom();
	void borrow(int hour, std::string memberName, int time);
};

studyRoom::studyRoom() {
	state = 'R';
	returnHour = 0;
}

void studyRoom::borrow(int hour, std::string memberName, int time) {
	state = 'B';
	borrower = memberName;
	returnHour = hour + time;
}


class seat :public space
{
public:
	seat();
	void borrow(int hour, std::string memberName, std::string memberType, int time);
};

seat::seat() {
	state = 'R';
	returnHour = 0;
}

void seat::borrow(int hour, std::string memberName, std::string memberType, int time) {
	state = 'B';
	borrower = memberName;
	returnHour = hour + time;
}

#include <string>
#include <vector>
#include <cstdlib>

class member
{
protected:
	std::string memberName;
	std::string memberType;
	std::vector<std::string> borrowList;
	int borrowNum;
	int borrowCapacity;
	int restrictedDate;
public:
	void borrow(std::string resourceType, std::string resourceName);
	void receive(std::string ResourceName);
	std::string name();
	void restrict(int restrictDay, int date);
	int showBorrowNum();
	int showborrowCapacity();
	int showRestrictedDate();
	int isBorrow(std::string resourceName);
};

class undergraduate :public member
{
public:
	undergraduate(std::string name);
};

class graduate :public member
{
public:
	graduate(std::string name);
};

class faculty :public member
{
public:
	faculty(std::string name);
};

faculty::faculty(std::string name) {
	memberName = name;
	memberType = "faculty";
	borrowNum = 0;
	borrowCapacity = 0;
	restrictedDate = 0;
}

graduate::graduate(std::string name) {
	memberName = name;
	memberType = "graduate";
	borrowNum = 0;
	borrowCapacity = 0;
	restrictedDate = 0;
}

undergraduate::undergraduate(std::string name) {
	memberName = name;
	memberType = "Undergraduate";
	borrowNum = 0;
	borrowCapacity = 0;
	restrictedDate = 0;
}

std::string member::name() {
	return memberName;
}

int member::showBorrowNum() {
	return borrowNum;
}

void member::borrow(std::string resourceType, std::string resourceName) {
	if (resourceType == "Book" || resourceType == "Magazine") {
		borrowNum++;
	}
	else if (resourceType == "E-book") {
		int capacity = atoi(resourceName.substr(resourceName.find("[") + 1, resourceName.find("]")).c_str());
		borrowCapacity = borrowCapacity + capacity;
	}
	borrowList.push_back(resourceName);
}

void member::receive(std::string resourceName) {
	for (int i = 0; i < borrowNum; i++) {
		if (borrowList.at(i) == resourceName) {
			borrowList.erase(borrowList.begin() + i);
			borrowNum--;
			break;
		}
	}
}

void member::restrict(int restrictDay, int date) {
	restrictedDate = date + restrictDay;
}

int member::showborrowCapacity() {
	return borrowCapacity;
}

int member::showRestrictedDate() {
	return restrictedDate;
}

int member::isBorrow(std::string resourceName) {
	for (int i = 0; i < borrowNum; i++) {
		if (borrowList.at(i) == resourceName)
			return 1;
	}
	return 0;
}



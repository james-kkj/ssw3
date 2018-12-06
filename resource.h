#include <string>

class resource
{
protected:
	std::string resourceName;
	std::string resourceType;
	char state;
	int borrowDate;
	int receiveDate;
public:
	int showBorrowDate();
	int showReceiveDate();
	std::string name();
	char showState();
};

class book :public resource
{
	std::string borrower;
public:
	book(std::string name);
	void borrow(int date, std::string memberType, std::string memberName);
	int receive(int date, std::string memberName);
	std::string showBorrower();
};

class magazine :public resource
{
	std::string borrower;
	std::string magazineCategory;
	int magazineMonth;
public:
	magazine(std::string name);
	void borrow(int date, std::string memberType, std::string memberName);
	int receive(int date, std::string memberName);
	std::string showBorrower();
};

class e_book :public resource
{
	std::vector<std::string> borrowerList;
	int borrowerNumber;
public:
	e_book(std::string name);
	void borrow(int date, std::string memberType, std::string memberName);
	int receive(int date, std::string memberName);
	int isBorrower(std::string memberName);
};




book::book(std::string name) {
	resourceName = name;
	resourceType = "Book";
	state = 'R';
}

magazine::magazine(std::string name) {
	resourceName = name;//Newton[18/02]
	resourceType = "magazine";
	magazineCategory = name.substr(0, name.find("["));//Newton
	state = 'R';
}

e_book::e_book(std::string name) {
	resourceName = name;
	resourceType = "E-book";
	state = 'R';
}


int resource::showBorrowDate() {
	return borrowDate;
}

int resource::showReceiveDate() {
	return receiveDate;
}

std::string resource::name() {
	return resourceName;
}

char resource::showState() {
	return state;
}


void book::borrow(int date, std::string memberType, std::string memberName) {
	state = 'B';
	borrower = memberName;
	borrowDate = date;
	if (memberType == "Undergraduate") {
		receiveDate = borrowDate + 13;
	}
	else if (memberType == "Graduate") {
		receiveDate = borrowDate + 29;
	}
	else if (memberType == "Faculty") {
		receiveDate = borrowDate + 29;
	}
}

int book::receive(int date, std::string memberName) {
	state = 'R';
	borrower = "";
	if (date > showReceiveDate()) {
		return date - showReceiveDate();
	}
	return 0;
}

std::string book::showBorrower() {
	return borrower;
}

void magazine::borrow(int date, std::string memberType, std::string memberName) {
	state = 'B';
	borrower = memberName;
	borrowDate = date;
	if (memberType == "Undergraduate") {
		receiveDate = borrowDate + 13;
	}
	else if (memberType == "Graduate") {
		receiveDate = borrowDate + 29;
	}
	else if (memberType == "Faculty") {
		receiveDate = borrowDate + 29;
	}
}

int magazine::receive(int date, std::string memberName) {
	state = 'R';
	borrower = "";
	if (date > showReceiveDate()) {
		return date - showReceiveDate();
	}
	return 0;
}

std::string magazine::showBorrower() {
	return borrower;
}

void e_book::borrow(int date, std::string memberType, std::string memberName) {
	borrowerList.push_back(memberName);
}

int e_book::receive(int date, std::string memberName) {
	for (int i = 0; i < borrowerNumber; i++) {
		if (borrowerList.at(i) == memberName) {
			borrowerList.erase(borrowerList.begin() + i);
			borrowerNumber--;
			break;
		}
	}
	return 0;
}

//exist borrower : return 1, no exist borrower : return 0
int e_book::isBorrower(std::string memberName) {
	for (int i = 0; i < borrowerNumber; i++) {
		if (borrowerList.at(i) == memberName) {
			return 1;
		}
	}
	return 0;
}

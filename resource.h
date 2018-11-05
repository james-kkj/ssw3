#include <string>

class resource
{
protected:
	std::string ResourceName;
	std::string ResourceType;
	char state;
	std::string Borrower;
	int BorrowDate;
	int ReturnDate;
public:
	int ShowBorrowDate();
	int ShowReturnDate();
	void Borrow(int Date, std::string MemberName);
	int Return(int Date, std::string MemberName);
	std::string Name();
	char ShowState();
	std::string ShowBorrower();
};

int resource::ShowBorrowDate() {
	return BorrowDate;
}

int resource::ShowReturnDate() {
	return ReturnDate;
}

void resource::Borrow(int Date, std::string MemberName) {
	state = 'B';
	Borrower = MemberName; 
	BorrowDate = Date;
	ReturnDate = BorrowDate + 13;
}

int resource::Return(int Date, std::string MemberName) {
	state = 'R';
	if (Date > ShowReturnDate()) {
		return Date - ShowReturnDate();
	}
	return 0;
}

std::string resource::Name() {
	return ResourceName;
}

char resource::ShowState() {
	return state;
}

std::string resource::ShowBorrower() {
	return Borrower;
}

class book :public resource
{
public:
	book(std::string name);
};

book::book(std::string name) {
	ResourceName = name;
	ResourceType = "Book";
	state = 'R';
}

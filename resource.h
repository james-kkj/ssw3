#include <string>

class resource
{
protected:
	std::string ResourceName;
	std::string ResourceType;
	char state;
	std::string Borrower;
	std::string date;
public:
	void Borrow(std::string MemberName);
	void Return();
	std::string Name();
	char ShowState();
};

void resource::Borrow(std::string MemberName) {
	state = 'B';
	Borrower = MemberName; 
}

void resource::Return() {
	state = 'R';
}

std::string resource::Name() {
	return ResourceName;
}

char resource::ShowState() {
	return state;
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

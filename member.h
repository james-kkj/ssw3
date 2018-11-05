#include <string>
#include <vector>

class member
{
protected:
	std::string MemberName;
	std::string MemberType;
	std::vector<std::string> BorrowList;
	int BorrowNum;
	std::string date;
public:
	void Borrow(std::string ResourceName);
	void Return(std::string ResourceName);
	std::string Name();
	int ShowBorrowNum();
	int isBorrow(std::string ResourceName);
};

void member::Borrow(std::string ResourceName) {
	BorrowNum++;
	BorrowList.push_back(ResourceName);
	//date
}

void member::Return(std::string ResourceName) {
	BorrowNum--;
	//date
}

std::string member::Name() {
	return MemberName;
}

class undergraduate :public member
{
public:
	undergraduate(std::string name);
};

int member::ShowBorrowNum() {
	return BorrowNum;
}

int member::isBorrow(std::string ResourceName) {
	for (int i = 0; i < BorrowNum; i++) {
		if (BorrowList.at(i) == ResourceName)
			return 1;
	}
	return 0;
}

undergraduate::undergraduate(std::string name) {
	MemberName = name;
	MemberType = "Undergraduate";
	BorrowNum = 0;
}



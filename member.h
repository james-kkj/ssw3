#include <string>
#include <vector>

class member
{
protected:
	std::string MemberName;
	std::string MemberType;
	std::vector<std::string> BorrowList;
	int BorrowNum;
	int RestrictedDate;
public:
	void Borrow(std::string ResourceName);
	void Return(std::string ResourceName);
	std::string Name();
	void restrict(int RestrictDay, int Date);
	int ShowBorrowNum();
	int ShowRestrictedDate();
	int isBorrow(std::string ResourceName);
};

void member::Borrow(std::string ResourceName) {
	BorrowNum++;
	BorrowList.push_back(ResourceName);
}

void member::Return(std::string ResourceName) {
	BorrowNum--;
	BorrowList.pop_back();
}

std::string member::Name() {
	return MemberName;
}

void member::restrict(int RestrictDay, int Date) {
	RestrictedDate = Date + RestrictDay;
}

int member::ShowBorrowNum() {
	return BorrowNum;
}

int member::ShowRestrictedDate() {
	return RestrictedDate;
}

int member::isBorrow(std::string ResourceName) {
	for (int i = 0; i < BorrowNum; i++) {
		if (BorrowList.at(i) == ResourceName)
			return 1;
	}
	return 0;
}

class undergraduate :public member
{
public:
	undergraduate(std::string name);
};

undergraduate::undergraduate(std::string name) {
	MemberName = name;
	MemberType = "Undergraduate";
	BorrowNum = 0;
	RestrictedDate = 0;
}



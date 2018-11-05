#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "resource.h"
#include "member.h"

class library
{
	int Op_num;
	std::vector<book> BookList;
	std::vector<undergraduate> UndergraduateList;
	int TotalBookNumber;
	int TotalUndergraduateNumber;
	std::string Description;
	
public:
	library();
	int ConvertDate(std::string Date);
	std::string ReverseConvertDate(int ConvertedDate);
	void AddResource(std::string ResourceName, std::string ResourceType);
	void AddMember(std::string MemberName, std::string MemberType);
	int isResource(std::string ResourceName, std::string ResourceType);
	int isMember(std::string MemberName, std::string MemberType);
	undergraduate* findUndergraduate(std::string MemberName);
	book* findBook(std::string ResourceName);
	int CheckBorrowlimit(std::string MemberType, std::string MemberName);
	int CheckAlreadyBorrow(std::string NemberName, std::string ResourceName);
	int Borrow(std::string Date, std::string ResourceType, std::string ResourceName,
				std::string MemberType, std::string MemberName);
	int didBorrow(std::string ResourceName);
	int Return(std::string Date, std::string ResourceType, std::string ResourceName,
				std::string MemberType, std::string MemberName);
	int Operation(std::string Date, std::string ResourceType, std::string ResourceName,
				std::string Operation, std::string MemberType, std::string MemberName);
	int ShowOp_num();
	std::string ShowDescription();
};

library::library() {
	Op_num = 1;
	TotalBookNumber = 0;
	TotalUndergraduateNumber = 0;
}

int library::ConvertDate(std::string Date) {
	int year = atoi(Date.substr(0, 2).c_str());
	int month = atoi(Date.substr(3, 5).c_str());
	int day = atoi(Date.substr(6, 9).c_str());
	return year * 360 + month * 30 + day;
}

std::string library::ReverseConvertDate(int ConvertedDate) {
	int year = ConvertedDate / 360;
	std::string _year = std::to_string(year);
	if (year < 10) {
		_year = "0" + _year;
	}
	int month = ConvertedDate % 360 / 30;
	std::string _month = std::to_string(month);
	if (month < 10) {
		_month = "0" + _month;
	}
	int day = ConvertedDate % 30;
	std::string _day = std::to_string(day);
	if (day < 10) {
		_day = "0" + _day;
	}
	return _year + "/" + _month + "/" + _day;
}

void library::AddResource(std::string ResourceName, std::string ResourceType) {
	if (ResourceType == "Book") {
		book _book(ResourceName);
		BookList.push_back(_book);
		TotalBookNumber++;
	}
}

void library::AddMember(std::string MemberName, std::string MemberType) {
	if (MemberType == "Undergraduate") {
		undergraduate _undergraduate(MemberName);
		UndergraduateList.push_back(_undergraduate);
		TotalUndergraduateNumber++;
	}
}

int library::isResource(std::string ResourceName, std::string ResourceType) {
	if (ResourceType == "Book") {
		for (int i = 0; i < TotalBookNumber; i++) {
			if (BookList.at(i).Name() == ResourceName)
				return 0;
		}
	}
	return 1;
}

int library::isMember(std::string MemberName, std::string MemberType) {
	if (MemberType == "Undergraduate") {
		for (int i = 0; i < TotalUndergraduateNumber; i++) {
			if (UndergraduateList.at(i).Name() == MemberName)
				return 0;
		}
	}
	return -1;
}

undergraduate* library::findUndergraduate(std::string MemberName) {
	for (int i = 0; i < TotalUndergraduateNumber; i++) {
		if (UndergraduateList.at(i).Name() == MemberName)
			return &UndergraduateList.at(i);
	}
	return NULL;
}

book* library::findBook(std::string ResourceName) {
	for (int i = 0; i < TotalBookNumber; i++) {
		if (BookList.at(i).Name() == ResourceName)
			return &BookList.at(i);
	}
	return NULL;
}

int library::CheckBorrowlimit(std::string MemberType, std::string MemberName) {
	if (MemberType == "Undergraduate") {
		if (findUndergraduate(MemberName)->ShowBorrowNum() >= 1) {
			return 2;
		}
	}
	return 0;
}

int library::CheckAlreadyBorrow(std::string NemberName, std::string ResourceName) {
	if (findUndergraduate(NemberName)->isBorrow(ResourceName) == 1) {
		return 4;
	}
	else if (findBook(ResourceName)->ShowState() == 'B') {
		return 5;
	}
	return 0;
}

int library::Borrow(std::string Date, std::string ResourceType, std::string ResourceName,
					std::string MemberType, std::string MemberName) {
	if (isResource(ResourceName, ResourceType) == 1) {
		Description = "Non exist resource.";
		return 1;
	}

	if (isMember(MemberName, MemberType) == -1) {
		AddMember(MemberName, MemberType);		
	}

	if (CheckBorrowlimit(MemberType, MemberName) == 2) {
		Description = "Exceeds your possible number of borrow. Possible # of borrows: 1";
		return 2;
	}

	if (CheckAlreadyBorrow(MemberName, ResourceName) == 4) {
		Description = "You already borrowed this book at " + Date;
		return 4;
	}
	
	if (CheckAlreadyBorrow(MemberName, ResourceName) == 5) {
		Description = "Other member already borrowed this book. This book will be returned at " + ReverseConvertDate(findBook(ResourceName)->ShowReturnDate());
		return 5;
	}

	if (ConvertDate(Date) <= findUndergraduate(MemberName)->ShowRestrictedDate()) {
		Description = "Restricted member until " + ReverseConvertDate(findUndergraduate(MemberName)->ShowRestrictedDate());
		return 6;
	}

	findUndergraduate(MemberName)->Borrow(ResourceName);
	findBook(ResourceName)->Borrow(ConvertDate(Date), MemberName);
	Description = "Success.";
	return 0;
}


int library::Return(std::string Date, std::string ResourceType, std::string ResourceName,
						std::string MemberType, std::string MemberName) {
	if (findBook(ResourceName)->ShowBorrower() != MemberName) {
		Description = "You did not borrow this book.";
		return 3;
	}
	
	findUndergraduate(MemberName)->Return(ResourceName);

	int RestrictDay;
	if ((RestrictDay = findBook(ResourceName)->Return(ConvertDate(Date), MemberName)) != 0) {
		findUndergraduate(MemberName)->restrict(RestrictDay, ConvertDate(Date));
		Description = "Delayed return. You'll be restricted until " + ReverseConvertDate(findUndergraduate(MemberName)->ShowRestrictedDate());
		return 7;
	}
	return 0;
}


int library::Operation(std::string Date, std::string ResourceType, std::string ResourceName,
	std::string Operation, std::string MemberType, std::string MemberName) {
	int Return_code;
	if (Operation == "B") {
		Return_code = Borrow(Date, ResourceType, ResourceName, MemberType, MemberName);
	}
	else if (Operation == "R")
		Return_code = Return(Date, ResourceType, ResourceName, MemberType, MemberName);
	Op_num++;
	return Return_code;
}

int library::ShowOp_num() {
	return Op_num;
}

std::string library::ShowDescription() {
	return Description;
}



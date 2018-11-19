#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "resource.h"
#include "member.h"
#include "space.h"

#define FLOOR 3
#define SEATS_PER_FLOOR 50
#define STUDY_ROOM_NUM 10

class library
{
	int Op_num;
	int date;
	//std::vector<book> BookList;
	//std::vector<undergraduate> UndergraduateList;
	studyRoom studyRoomList[10];
	seat seatList[3][50];
	//int TotalBookNumber;
	//int TotalUndergraduateNumber;
	int TotalStudyRoomNumber;
	int TotalSeatListNumber[3];
	std::string Description;
	
public:
	library();
	int showDate();
	void checkDate(std::string _date);
	//int ConvertDate(std::string Date);
	int getDate(std::string date);
	//std::string ReverseConvertDate(int ConvertedDate);
	std::string reverseConvertDate(int convertedDate);
	/*
	//void AddResource(std::string ResourceName, std::string ResourceType);
	//void AddMember(std::string MemberName, std::string MemberType);
	//int isResource(std::string ResourceName, std::string ResourceType);
	//int isMember(std::string MemberName, std::string MemberType);
	//undergraduate* findUndergraduate(std::string MemberName);
	//book* findBook(std::string ResourceName);
	//int CheckBorrowlimit(std::string MemberType, std::string MemberName);
	//int CheckAlreadyBorrow(std::string NemberName, std::string ResourceName);
	//int Borrow(std::string Date, std::string ResourceType, std::string ResourceName,
	//			std::string MemberType, std::string MemberName);
	//int didBorrow(std::string ResourceName);
	//int Return(std::string Date, std::string ResourceType, std::string ResourceName,
	//			std::string MemberType, std::string MemberName);
	//int Operation(std::string Date, std::string ResourceType, std::string ResourceName,
	//			std::string Operation, std::string MemberType, std::string MemberName);
	*/
	int operation(std::string date, std::string spaceType, std::string spaceNumber, std::string operation,
		std::string memberType, std::string memberName, std::string numberOfMember, std::string time);
	int borrowStudyRoom(int hour, int studyRoomId, std::string memberType,
		std::string memberName, std::string numberOfMember, std::string time);
	int borrowSeat(int hour, int floor, std::string memberType,
		std::string memberName, std::string numberOfMember, std::string time);
	int isEmptyRoom(int roomNumber);
	int findEmptySeat(int floor, int returnHour, int hour, std::string memberName, std::string memberType, int time);
	int returnStudyRoom(int hour, int spaceNumber, std::string memberType, std::string memberName);
	int returnSeat(int hour, int spaceNumber, std::string memberType, std::string memberName);
	int ShowOp_num();
	std::string ShowDescription();
	void reset();
};

library::library() {
	Op_num = 1;
	date = 0;
	studyRoom *studyRoomList = new studyRoom[10];
	seat **seatList = new seat*[3];
	for (int i = 0; i < 3; i++) {
		seatList[i] = new seat[50];
	}
	//TotalBookNumber = 0;
	//TotalUndergraduateNumber = 0;
}

int library::showDate() {
	return date;
}

void library::checkDate(std::string _date) {
	int nowDate = getDate(_date);
	if (date != nowDate) {
		reset();
	}
	//시간 지난 자리 자동 반납
	else {
		int hour = atoi(_date.substr(11, 13).c_str());
		for (int i = 0; i < 10; i++) {
			if (studyRoomList[i].showReturnHour() <= hour)
				studyRoomList[i]._return();
			else continue;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 50; j++) {
				if (seatList[i][j].showReturnHour() <= hour)
					seatList[i][j]._return();
				else continue;
			}
		}
	}
}

int library::getDate(std::string date) {
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 7).c_str());
	int day = atoi(date.substr(8, 10).c_str());
	return year * 360 + month * 30 + day;
}

/*int library::ConvertDate(std::string Date) {
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
*/
/*
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
}*/

int library::operation(std::string date, std::string spaceType, std::string spaceNumber, std::string operation,
	std::string memberType, std::string memberName, std::string numberOfMember, std::string time) {
	int returnCode;
	Op_num++;
	//8-유효한 공간 이름인지 확인
	int _spaceNumber = atoi(spaceNumber.c_str());
	if (spaceType != "StudyRoom" && spaceType != "Seat") {
		Description = "Invalid space id.";
		return 8;
	}
	else if (spaceType == "StudyRoom" && _spaceNumber > 10) {
		Description = "Invalid space id.";
		return 8;
	}
	else if (spaceType == "Seat" && _spaceNumber > 3) {
		Description = "Invalid space id.";
		return 8;
	}
	//9-이용가능한 시간대인지 확인
	int hour = atoi(date.substr(11, 13).c_str());
	if (spaceType == "StudyRoom" && (hour < 9 || hour > 18)) {
		Description = "This spaceis not available now. Available from 09 to 18.";
		return 9;
	}
	else if (spaceType == "Seat" && spaceNumber == "2" && (hour < 9 || hour > 21)) {
		Description = "This spaceis not available now. Available from 09 to 21.";
		return 9;
	}
	else if (spaceType == "Seat" && spaceNumber == "3" && (hour < 9 || hour > 18)) {
		Description = "This spaceis not available now. Available from 09 to 18.";
		return 9;
	}
	//operation		
	if (operation == "B" && spaceType == "StudyRoom") {
		returnCode = borrowStudyRoom(hour, _spaceNumber, memberType, memberName, numberOfMember, time);
	}
	else if (operation == "B" && spaceType == "Seat") {
		returnCode = borrowSeat(hour, _spaceNumber, memberType, memberName, numberOfMember, time);
	}
	else if (operation == "R" && spaceType == "StudyRoom") {
		returnCode = returnStudyRoom(hour, _spaceNumber, memberType, memberName);
	}
	else if (operation == "R" && spaceType == "Seat") {
		returnCode = returnSeat(hour, _spaceNumber, memberType, memberName);
	}
	if (returnCode == 0) {
		Description = "Success.";
	}
	return returnCode;
}

int library::ShowOp_num() {
	return Op_num;
}

std::string library::ShowDescription() {
	return Description;
}

int library::borrowStudyRoom(int hour, int studyRoomId, std::string memberType,
						std::string memberName, std::string numberOfMember, std::string time) {
	//11-이미 같은 종류의 공간을 빌렸는지 확인
	for (int i = 0; i < 10; i++) {
		if (studyRoomList[i].name() == memberName) {
			Description = "You already borrowed this kind of space.";
			return 11;
		}
		else continue;
	}
	//12-정원을 초과하지 않는지 확인
	int _numOfMember = atoi(numberOfMember.c_str());
	if (_numOfMember > 6) {
		Description = "Exceed available number.";
		return 12;
	}
	//13-이미 사용시간을 모두 쓰진 않았는지 확인?, 사용가능시간을 초과하지 않았는지 확인
	int _time = atoi(time.c_str());
	if (_time > 3) {
		Description = "Exceed available time.";
		return 13;
	}
	//14-스터디룸이 이미 빌려지지 않았는지 확인
	if (isEmptyRoom(studyRoomId) != 0) {
		int returnHour = studyRoomList[studyRoomId].showReturnHour();
		std::string str = std::to_string(returnHour);
		Description = "There is no remain space. This space is available after " + str + ".";
		return 14;
	}
	//borrow
	studyRoomList[studyRoomId].borrow(hour, memberName, _time);
	return 0;
}

int library::isEmptyRoom(int roomNumber) {
	if (studyRoomList[roomNumber].showState() == 'R')
		return 0;
	else return 1;
}

int library::borrowSeat(int hour, int floor, std::string memberType,
	std::string memberName, std::string numberOfMember, std::string time) {
	//11-이미 같은 종류의 공간을 빌렸는지 확인
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 50; j++) {
			if (seatList[i][j].name() == memberName) {
				Description = "You already borrowed this kind of space.";
				return 11;
			}
			else continue;
		}
	}
	//12-정원을 초과하지 않는지 확인
	int _numOfMember = atoi(numberOfMember.c_str());
	if (_numOfMember > 1) {
		Description = "Exceed available number.";
		return 12;
	}
	//사용가능시간을 초과하지 않았는지 확인
	int _time = atoi(time.c_str());
	if (_time > 3) {
		Description = "Exceed available time.";
		return 13;
	}
	//14-해당 층에 남은 자리가 있는지 확인 및 빌림
	int returnHour = 24;
	returnHour = findEmptySeat(floor, returnHour, hour, memberName, memberType, _time);//자리가 있으면 자리를 빌리고 0을, 자리가 없으면 반납예정시간을 리턴
	if (returnHour != 0) {
		std::string str = std::to_string(returnHour);
		Description = "There is no remain space. This space is available after " + str + ".";
		return 14;
	}
	//borrow
	//seatList[floor].borrow(convertedDate, memberName);
	return 0;
}

int library::findEmptySeat(int floor, int returnHour, int hour, std::string memberName, std::string memberType, int time) {
	for (int i = 0; i < 50; i++) {
		if (seatList[floor][i].showState() == 'R') {
			seatList[floor][i].borrow(hour, memberName, memberType, time);
			return 0;
		}
		else {
			if (seatList[floor][i].showReturnHour() < returnHour) {
				returnHour = seatList[floor][i].showReturnHour();
			}
		}
	}
	return returnHour;
}

int library::returnStudyRoom(int hour, int spaceNumber, std::string memberType, std::string memberName) {
	if (studyRoomList[spaceNumber].name() != memberName) {
		Description = "You did not borrow this place.";
		return 10;
	}
	else {
		studyRoomList[spaceNumber]._return();
		return 0;
	}
}

int library::returnSeat(int hour, int spaceNumber, std::string memberType, std::string memberName) {
	for (int i = 0; i < 50; i++) {
		if (seatList[spaceNumber][i].name() == memberName) {
			seatList[spaceNumber][i]._return();
			return 0;
		}
		else continue;
	}
	Description = "You did not borrow this place.";
	return 10;
}

/*
std::string library::reverseConvertDate(int convertedDate) {
	int year, month, day, time;
	std::string _year, _month, _day, _time;
	
	year = convertedDate / (360 * 24);

	month = convertedDate % (360 * 24) / (30 * 24);
	if (month < 10) {
		_month = "0" + _month;
	}

	day = convertedDate % (30 * 24) / 24;
	if (day < 10) {
		_day = "0" + _day;
	}

	time = convertedDate % 24;
	if (time < 10) {
		_time = "0" + _time;
	}

	return _year + "/" + _month + "/" + _day + "/" + _time;
}
*/
void library::reset() {
	for (int i = 0; i < 10; i++) {
		studyRoomList[i]._return();
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 50; j++) {
			seatList[i][j]._return();
		}
	}
}

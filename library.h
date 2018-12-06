#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "resource.h"
#include "member.h"
#include "space.h"

#define MONTH_PER_YEAR 12
#define FLOOR 3
#define SEATS_PER_FLOOR 50
#define STUDY_ROOM_NUM 10

class library
{
	int op_num;
	int date;
	std::vector<book> bookList;
	std::vector<magazine> magazineList;
	std::vector<std::string> magazineCategoryList;
	std::vector<e_book> e_bookList;
	std::vector<undergraduate> undergraduateList;
	std::vector<graduate> graduateList;
	std::vector<faculty> facultyList;
	int totalBookNumber;
	int totalMagazineNumber;
	int totalMagazineCategotyNumber;
	int totalE_bookNumber;
	int totalUndergraduateNumber;
	int totalGraduateNumber;
	int totalFacultyNumber;
	std::string description;
	//#2
	studyRoom studyRoomList[10];
	seat seatList[FLOOR][SEATS_PER_FLOOR];
	int TotalStudyRoomNumber;
	int TotalSeatListNumber[FLOOR];

public:
	library();
	void addResource(std::string resourceName, std::string resourceType);
	int showOp_num();
	void checkDate(std::string today);
	int convertDate(std::string date);
	int operation(std::string date, std::string resourceType, std::string resourceName,
		std::string operation, std::string memberType, std::string memberName);
	int isMember(std::string memberName, std::string memberType);
	void addMember(std::string memberName, std::string memberType);
	int borrow(std::string date, std::string resourceType, std::string resourceName,
		std::string memberType, std::string memberName);
	int receive(std::string date, std::string resourceType, std::string resourceName,
		std::string memberType, std::string memberName);
	void updateMagazine(std::string date);
	int isResource(std::string resourceName, std::string resourceType);
	book* findBook(std::string resourceName);
	magazine* findMagazine(std::string resourceName);
	e_book* findE_book(std::string resourceName);
	undergraduate* findUndergraduate(std::string memberName);
	graduate* findGraduate(std::string memberName);
	faculty* findFaculty(std::string memberName);
	int checkBorrowlimit(std::string memberType, std::string memberName);
	int checkCapcitylimit(std::string memberType, std::string memberName, int resourceCapacity);
	int checkAlreadyBorrow(std::string memberType, std::string memberName, std::string resourceType, std::string resourceName);
	std::string showDescription();
	std::string reverseConvertDate(int convertedDate);
	void debug();
	//#2
	void s_checkDate(std::string _date);
	int s_getDate(std::string date);
	int s_operation(std::string date, std::string spaceType, std::string spaceNumber, std::string operation,
		std::string memberType, std::string memberName, std::string numberOfMember, std::string time);
	int borrowStudyRoom(int hour, int studyRoomId, std::string memberType,
		std::string memberName, std::string numberOfMember, std::string time);
	int borrowSeat(int hour, int floor, std::string memberType,
		std::string memberName, std::string numberOfMember, std::string time);
	int isEmptyRoom(int roomNumber);
	int findEmptySeat(int floor, int returnHour, int hour, std::string memberName, std::string memberType, int time);
	int returnStudyRoom(int hour, int spaceNumber, std::string memberType, std::string memberName);
	int returnSeat(int hour, int spaceNumber, std::string memberType, std::string memberName);
	void reset();



};

library::library() {
	op_num = 1;
	int date = 0;
	totalBookNumber = 0;
	totalMagazineNumber = 0;
	totalE_bookNumber = 0;
	totalUndergraduateNumber = 0;
	totalGraduateNumber = 0;
	totalFacultyNumber = 0;
	TotalStudyRoomNumber = 0;
	for (int i = 0; i < FLOOR; i++) {
		TotalSeatListNumber[i] = 0;
	}
}

void library::addResource(std::string resourceName, std::string resourceType) {
	if (resourceType == "Book") {
		book _book(resourceName);
		bookList.push_back(_book);
		totalBookNumber++;
	}
	else if (resourceType == "Magazine") {
		magazineCategoryList.push_back(resourceName);
		totalMagazineCategotyNumber++;
	}
	else if (resourceType == "E-book") {
		e_book _e_book(resourceName);
		e_bookList.push_back(_e_book);
		totalE_bookNumber++;
	}
}

int library::showOp_num() {
	return op_num;
}

int library::operation(std::string date, std::string resourceType, std::string resourceName,
	std::string operation, std::string memberType, std::string memberName) {
	int return_code = 0;
	checkDate(date);
	if (isMember(memberName, memberType) == 0) {
		addMember(memberName, memberType);
	}
	if (operation == "B") {
		return_code = borrow(date, resourceType, resourceName, memberType, memberName);
	}
	else if (operation == "R")
		return_code = receive(date, resourceType, resourceName, memberType, memberName);
	op_num++;
	return return_code;
}

void library::checkDate(std::string _today) {
	int today = convertDate(_today);
	if (today > date) {
		updateMagazine(_today);
		date = today;
	}
}

void library::updateMagazine(std::string date) {
	int year = atoi(date.substr(0, 2).c_str());
	int month = atoi(date.substr(3, 5).c_str());
	int yearmonth = 12 * year + month;

	for (int i = 0; i < totalMagazineCategotyNumber; i++) {
		std::string magazineCategory = magazineCategoryList.at(i);
		for (int j = 1; j <= yearmonth; j++) {
			int _year = (j - 1) / 12;
			int _month = (j - 1) % 12 + 1;
			std::string magazineName;
			if (_year < 10 && _month < 10) {
				magazineName = magazineCategory + "[0" + std::to_string(_year) + "/0" + std::to_string(_month) + "]";
			}
			else if (_year < 10 && _month >= 10) {
				magazineName = magazineCategory + "[0" + std::to_string(_year) + "/" + std::to_string(_month) + "]";
			}
			else if (_year >= 10 && _month < 10) {
				magazineName = magazineCategory + "[" + std::to_string(_year) + "/0" + std::to_string(_month) + "]";
			}
			else if (_year >= 10 && _month >= 10) {
				magazineName = magazineCategory + "[" + std::to_string(_year) + "/" + std::to_string(_month) + "]";
			}
			//delete magazine
			if (j < yearmonth - 11) {
				if (isResource(magazineName, "Magazine") == 1) {
					if (findMagazine(magazineName)->showState() == 'R') {

						for (int k = 0; k < totalMagazineNumber; k++) {
							if (magazineList.at(k).name() == magazineName) {
								magazineList.erase(magazineList.begin() + k);
								totalMagazineNumber--;
								break;
							}
						}
					}
				}
			}
			//add magazine
			else {
				if (isResource(magazineName, "Magazine") == 0) {
					magazine _magazine(magazineName);
					magazineList.push_back(_magazine);
					totalMagazineNumber++;
				}
			}
		}
	}
}

int library::isResource(std::string resourceName, std::string resourceType) {
	if (resourceType == "Book") {
		for (int i = 0; i < totalBookNumber; i++) {
			if (bookList.at(i).name() == resourceName)
				return 1;
		}
	}
	else if (resourceType == "Magazine") {
		for (int i = 0; i < totalMagazineNumber; i++) {
			if (magazineList.at(i).name() == resourceName)
				return 1;
		}
	}
	else if (resourceType == "E-book") {
		for (int i = 0; i < totalE_bookNumber; i++) {
			if (e_bookList.at(i).name() == resourceName)
				return 1;
		}
	}
	return 0;
}

int library::isMember(std::string memberName, std::string memberType) {
	if (memberType == "Undergraduate") {
		for (int i = 0; i < totalUndergraduateNumber; i++) {
			if (undergraduateList.at(i).name() == memberName)
				return 1;
		}
	}
	else if (memberType == "Graduate") {
		for (int i = 0; i < totalGraduateNumber; i++) {
			if (graduateList.at(i).name() == memberName)
				return 1;
		}
	}
	else if (memberType == "Faculty") {
		for (int i = 0; i < totalFacultyNumber; i++) {
			if (facultyList.at(i).name() == memberName)
				return 1;
		}
	}
	return 0;
}

void library::addMember(std::string memberName, std::string memberType) {
	if (memberType == "Undergraduate") {
		undergraduate _undergraduate(memberName);
		undergraduateList.push_back(_undergraduate);
		totalUndergraduateNumber++;
	}
	else if (memberType == "Graduate") {
		graduate _graduate(memberName);
		graduateList.push_back(_graduate);
		totalGraduateNumber++;
	}
	else if (memberType == "Faculty") {
		faculty _faculty(memberName);
		facultyList.push_back(_faculty);
		totalFacultyNumber++;
	}
}

int library::borrow(std::string date, std::string resourceType, std::string resourceName,
	std::string memberType, std::string memberName) {
	if (isResource(resourceName, resourceType) == 0) {
		description = "Non exist resource.";
		return 1;
	}

	if (resourceType == "Book" || resourceType == "Magazine") {
		if (checkBorrowlimit(memberType, memberName) == 2) {
			if (memberType == "Undergraduate") {
				description = "Exceeds your possible number of borrow. Possible # of borrows: 1";
			}
			else if (memberType == "Graduate") {
				description = "Exceeds your possible number of borrow. Possible # of borrows: 5";
			}
			else if (memberType == "Faculty") {
				description = "Exceeds your possible number of borrow. Possible # of borrows: 10";
			}
			return 2;
		}
	}
	else if (resourceType == "E-book") {
		std::string _capacity = resourceName.substr(resourceName.find("[") + 1, resourceName.find("]"));
		int resourceCapacity = atoi(_capacity.c_str());
		if (checkCapcitylimit(memberType, memberName, resourceCapacity) == 1) {
			description = "Exceeds your strage capacity.";
			return 15;
		}
	}

	if (checkAlreadyBorrow(memberType, memberName, resourceType, resourceName) == 4) {
		description = "You already borrowed this book at " + date;
		return 4;
	}
	else if (checkAlreadyBorrow(memberType, memberName, resourceType, resourceName) == 5) {
		description = "Other member already borrowed this book. This book will be returned at " + reverseConvertDate(findBook(resourceName)->showReceiveDate());
		return 5;
	}

	if (memberType == "Undergraduate") {
		if (convertDate(date) <= findUndergraduate(memberName)->showRestrictedDate()) {
			description = "Restricted member until " + reverseConvertDate(findUndergraduate(memberName)->showRestrictedDate());
			return 6;
		}
	}
	else if (memberType == "Graduate") {
		if (convertDate(date) <= findGraduate(memberName)->showRestrictedDate()) {
			description = "Previously borrowed books are overdue, so borrow is limited.";
			return 16;
		}
	}
	else if (memberType == "Faculty") {
		if (convertDate(date) <= findFaculty(memberName)->showRestrictedDate()) {
			description = "Previously borrowed books are overdue, so borrow is limited.";
			return 16;
		}
	}

	//borrow success
		//update memeber data
	if (memberType == "Undergraduate") {
		findUndergraduate(memberName)->borrow(resourceType, resourceName);
	}
	else if (memberType == "Graduate") {
		findGraduate(memberName)->borrow(resourceType, resourceName);
	}
	else if (memberType == "Faculty") {
		findFaculty(memberName)->borrow(resourceType, resourceName);
	}
	//update space data
	if (resourceType == "Book") {
		findBook(resourceName)->borrow(convertDate(date), memberType, memberName);
	}
	else if (resourceType == "Magazine") {
		findMagazine(resourceName)->borrow(convertDate(date), memberType, memberName);
	}
	else if (resourceType == "E-Book") {
		findE_book(resourceName)->borrow(convertDate(date), memberType, memberName);
	}
	description = "Success.";
	return 0;
}

int library::receive(std::string date, std::string resourceType, std::string resourceName,
	std::string memberType, std::string memberName) {
	if (resourceType == "Book") {
		if (findBook(resourceName)->showBorrower() != memberName) {
			description = "You did not borrow this book.";
			return 3;
		}
	}
	else if (resourceType == "Magazine") {
		if (findMagazine(resourceName)->showBorrower() != memberName) {
			description = "You did not borrow this magazine.";
			return 3;
		}
	}
	else if (resourceType == "E-book") {
		if (findE_book(resourceName)->isBorrower(memberName) != 1) {
			description = "You did not borrow this E-book.";
			return 3;
		}
	}

	if (memberType == "Undergraduate") {
		findUndergraduate(memberName)->receive(resourceName);
	}
	else if (memberType == "Graduate") {
		findGraduate(memberName)->receive(resourceName);
	}
	else if (memberType == "Faculty") {
		findFaculty(memberName)->receive(resourceName);
	}
	//delayed case
	int restrictDay;
	if (resourceType == "Book") {
		if ((restrictDay = findBook(resourceName)->receive(convertDate(date), memberName)) != 0) {
			if (memberType == "Undergraduate") {
				findUndergraduate(memberName)->restrict(restrictDay, convertDate(date));
				description = "Delayed return. You'll be restricted until " + reverseConvertDate(findUndergraduate(memberName)->showRestrictedDate());
			}
			else if (memberType == "Graduate") {
				findGraduate(memberName)->restrict(restrictDay, convertDate(date));
				description = "Delayed return. You'll be restricted until " + reverseConvertDate(findGraduate(memberName)->showRestrictedDate());
			}
			else if (memberType == "Faculty") {
				findFaculty(memberName)->restrict(restrictDay, convertDate(date));
				description = "Delayed return. You'll be restricted until " + reverseConvertDate(findFaculty(memberName)->showRestrictedDate());
			}
			return 7;
		}
	}
	else if (resourceType == "Magazine") {
		if ((restrictDay = findMagazine(resourceName)->receive(convertDate(date), memberName)) != 0) {
			if (memberType == "Undergraduate") {
				findUndergraduate(memberName)->restrict(restrictDay, convertDate(date));
				description = "Delayed return. You'll be restricted until " + reverseConvertDate(findUndergraduate(memberName)->showRestrictedDate());
			}
			else if (memberType == "Graduate") {
				findGraduate(memberName)->restrict(restrictDay, convertDate(date));
				description = "Delayed return. You'll be restricted until " + reverseConvertDate(findGraduate(memberName)->showRestrictedDate());
			}
			else if (memberType == "Faculty") {
				findFaculty(memberName)->restrict(restrictDay, convertDate(date));
				description = "Delayed return. You'll be restricted until " + reverseConvertDate(findFaculty(memberName)->showRestrictedDate());
			}
			return 7;
		}
	}
	else if (resourceType == "E-book") {
		findE_book(resourceName)->receive(convertDate(date), memberName);
	}
	description = "Success.";
	return 0;
}

undergraduate* library::findUndergraduate(std::string memberName) {
	for (int i = 0; i < totalUndergraduateNumber; i++) {
		if (undergraduateList.at(i).name() == memberName)
			return &undergraduateList.at(i);
	}
	return NULL;
}

graduate* library::findGraduate(std::string memberName) {
	for (int i = 0; i < totalGraduateNumber; i++) {
		if (graduateList.at(i).name() == memberName)
			return &graduateList.at(i);
	}
	return NULL;
}

faculty* library::findFaculty(std::string memberName) {
	for (int i = 0; i < totalFacultyNumber; i++) {
		if (facultyList.at(i).name() == memberName)
			return &facultyList.at(i);
	}
	return NULL;
}

book* library::findBook(std::string resourceName) {
	for (int i = 0; i < totalBookNumber; i++) {
		if (bookList.at(i).name() == resourceName)
			return &bookList.at(i);
	}
	return NULL;
}

magazine* library::findMagazine(std::string resourceName) {
	for (int i = 0; i < totalMagazineNumber; i++) {
		if (magazineList.at(i).name() == resourceName)
			return &magazineList.at(i);
	}
	return NULL;
}

e_book* library::findE_book(std::string resourceName) {
	for (int i = 0; i < totalBookNumber; i++) {
		if (e_bookList.at(i).name() == resourceName)
			return &e_bookList.at(i);
	}
	return NULL;
}

int library::checkBorrowlimit(std::string memberType, std::string memberName) {
	if (memberType == "Undergraduate") {
		if (findUndergraduate(memberName)->showBorrowNum() >= 1) {
			return 2;
		}
	}
	else if (memberType == "Graduate") {
		if (findGraduate(memberName)->showBorrowNum() >= 5) {
			return 2;
		}
	}
	else if (memberType == "Faculty") {
		if (findFaculty(memberName)->showBorrowNum() >= 10) {
			return 2;
		}
	}
	return 0;
}

int library::checkCapcitylimit(std::string memberType, std::string memberName, int resourceCapacity) {
	if (memberType == "Undergraduate") {
		if (findUndergraduate(memberName)->showborrowCapacity() + resourceCapacity >= 100) {
			return 1;
		}
	}
	else if (memberType == "Graduate") {
		if (findGraduate(memberName)->showborrowCapacity() + resourceCapacity >= 500) {
			return 1;
		}
	}
	else if (memberType == "Faculty") {
		if (findFaculty(memberName)->showborrowCapacity() + resourceCapacity >= 1000) {
			return 1;
		}
	}
	return 0;
}

int library::checkAlreadyBorrow(std::string memberType, std::string memberName, std::string resourceType, std::string resourceName) {
	if (memberType == "Undergraduate") {
		if (findUndergraduate(memberName)->isBorrow(resourceName) == 1) {
			return 4;
		}
	}
	else if (memberType == "Graduate") {
		if (findGraduate(memberName)->isBorrow(resourceName) == 1) {
			return 4;
		}
	}
	else if (memberType == "Faculty") {
		if (findFaculty(memberName)->isBorrow(resourceName) == 1) {
			return 4;
		}
	}

	if (resourceType == "Book") {
		if (findBook(resourceName)->showState() == 'B') {
			return 5;
		}
	}
	else if (resourceType == "Magazine") {
		if (findMagazine(resourceName)->showState() == 'B') {
			return 5;
		}
	}
	/*	else if (resourceType == "E-book") {
			if (findE_book(resourceName)->showState() == 'B') {
				return 5;
			}
		}*/
	return 0;
}

std::string library::showDescription() {
	return description;
}

int library::convertDate(std::string Date) {
	int year = atoi(Date.substr(0, 2).c_str());
	int month = atoi(Date.substr(3, 5).c_str());
	int day = atoi(Date.substr(6, 9).c_str());
	return year * 360 + month * 30 + day;
}

std::string library::reverseConvertDate(int ConvertedDate) {
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

void library::s_checkDate(std::string _date) {
	int nowDate = s_getDate(_date);

	if (date != nowDate) {
		reset();
		date = nowDate;
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
			for (int j = 0; j < SEATS_PER_FLOOR; j++) {
				if (seatList[i][j].showReturnHour() <= hour)
					seatList[i][j]._return();
				else continue;
			}
		}
	}
}

int library::s_getDate(std::string date) {
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 7).c_str());
	int day = atoi(date.substr(8, 10).c_str());
	return year * 360 + month * 30 + day;
}

int library::s_operation(std::string date, std::string spaceType, std::string spaceNumber, std::string operation,
	std::string memberType, std::string memberName, std::string numberOfMember, std::string time) {
	int returnCode;
	op_num++;

	//exception handling
	try {
		int handle;
		if (s_getDate(date) < s_getDate("2010/01/01/00")) {
			handle = 1;
			throw handle;
		}
		else if (spaceType != "Seat" && spaceType != "StudyRoom") {
			handle = 2;
			throw handle;
		}
		else if (operation != "B" && operation != "R" && operation != "E" && operation != "C") {
			handle = 3;
			throw handle;
		}
		else if (memberType != "Undergraduate" && memberType != "Graduate" && memberType != "Faculty") {
			handle = 4;
			throw handle;
		}
		else if (atoi(time.c_str()) < 0) {
			handle = 6;
			throw handle;
		}
	}
	catch (int handle) {
		if (handle == 1)
			description = "Date out of range";
		else if (handle == 2)
			description = "Non-exist space Type";
		else if (handle == 3)
			description = "Non-exist operation";
		else if (handle == 4)
			description = "Non-exist member type";
		else if (handle == 5)
			description = "Member name with numbers";
		else if (handle == 6)
			description = "Negative time";
		return -1;

	}

	//8-유효한 공간 이름인지 확인
	int _spaceNumber = atoi(spaceNumber.c_str());
	if (spaceType != "StudyRoom" && spaceType != "Seat") {
		description = "Invalid space id.";
		return 8;
	}
	else if (spaceType == "StudyRoom" && _spaceNumber > 10) {
		description = "Invalid space id.";
		return 8;
	}
	else if (spaceType == "Seat" && _spaceNumber > 3) {
		description = "Invalid space id.";
		return 8;
	}
	//9-이용가능한 시간대인지 확인
	int hour = atoi(date.substr(11, 13).c_str());
	if (spaceType == "StudyRoom" && (hour < 9 || hour > 18)) {
		description = "This space is not available now. Available from 09 to 18.";
		return 9;
	}
	else if (spaceType == "Seat" && spaceNumber == "2" && (hour < 9 || hour > 21)) {
		description = "This space is not available now. Available from 09 to 21.";
		return 9;
	}
	else if (spaceType == "Seat" && spaceNumber == "3" && (hour < 9 || hour > 18)) {
		description = "This space is not available now. Available from 09 to 18.";
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
		description = "Success.";
	}
	return returnCode;
}

int library::borrowStudyRoom(int hour, int studyRoomId, std::string memberType,
	std::string memberName, std::string numberOfMember, std::string time) {
	//11-이미 같은 종류의 공간을 빌렸는지 확인
	for (int i = 0; i < 10; i++) {
		if (studyRoomList[i].name() == memberName) {
			description = "You already borrowed this kind of space.";
			return 11;
		}
		else continue;
	}
	//12-정원을 초과하지 않는지 확인
	int _numOfMember = atoi(numberOfMember.c_str());
	if (_numOfMember > 6) {
		description = "Exceed available number.";
		return 12;
	}
	//13-이미 사용시간을 모두 쓰진 않았는지 확인?, 사용가능시간을 초과하지 않았는지 확인
	int _time = atoi(time.c_str());
	if (_time > 3) {
		description = "Exceed available time.";
		return 13;
	}
	//14-스터디룸이 이미 빌려지지 않았는지 확인
	if (isEmptyRoom(studyRoomId) != 0) {
		int returnHour = studyRoomList[studyRoomId].showReturnHour();
		std::string str = std::to_string(returnHour);
		description = "There is no remain space. This space is available after " + str + ".";
		return 14;
	}
	//borrow
	studyRoomList[studyRoomId].borrow(hour, memberName, _time);
	return 0;
}

int library::borrowSeat(int hour, int floor, std::string memberType,
	std::string memberName, std::string numberOfMember, std::string time) {
	//11-이미 같은 종류의 공간을 빌렸는지 확인
	for (int i = 0; i < FLOOR; i++) {
		for (int j = 0; j < SEATS_PER_FLOOR; j++) {
			if (seatList[i][j].name() == memberName) {
				description = "You already borrowed this kind of space.";
				return 11;
			}
			//else continue;
		}
	}
	//12-정원을 초과하지 않는지 확인
	int _numOfMember = atoi(numberOfMember.c_str());
	if (_numOfMember > 1) {
		description = "Exceed available number.";
		return 12;
	}
	//사용가능시간을 초과하지 않았는지 확인
	int _time = atoi(time.c_str());
	if (_time > 3) {
		description = "Exceed available time.";
		return 13;
	}
	//14-해당 층에 남은 자리가 있는지 확인 및 빌림
	int returnHour = 24;
	returnHour = findEmptySeat(floor, returnHour, hour, memberName, memberType, _time);//자리가 있으면 자리를 빌리고 0을, 자리가 없으면 반납예정시간을 리턴
	if (returnHour != 0) {
		std::string str = std::to_string(returnHour);
		description = "There is no remain space. This space is available after " + str + ".";
		return 14;
	}
	//borrow
	//seatList[floor].borrow(convertedDate, memberName);
	return 0;
}

int library::isEmptyRoom(int roomNumber) {
	if (studyRoomList[roomNumber].showState() == 'R')
		return 0;
	else return 1;
}

int library::findEmptySeat(int floor, int returnHour, int hour, std::string memberName, std::string memberType, int time) {
	for (int i = 0; i < SEATS_PER_FLOOR; i++) {
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
		description = "You did not borrow this place.";
		return 10;
	}
	else {
		studyRoomList[spaceNumber]._return();
		return 0;
	}
}

int library::returnSeat(int hour, int spaceNumber, std::string memberType, std::string memberName) {
	for (int i = 0; i < SEATS_PER_FLOOR; i++) {
		if (seatList[spaceNumber][i].name() == memberName) {
			seatList[spaceNumber][i]._return();
			return 0;
		}
		else continue;
	}
	description = "You did not borrow this place.";
	return 10;
}

void library::reset() {
	for (int i = 0; i < 10; i++) {
		studyRoomList[i]._return();
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < SEATS_PER_FLOOR; j++) {
			seatList[i][j]._return();
		}
	}
}




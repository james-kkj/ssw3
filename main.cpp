#include <iostream>
#include <string>
#include <fstream>
#include "library.h"

using namespace std;


int main() {
	//get resource.dat
	class library _library;

	ifstream resourceFile("resource.dat");
	if (resourceFile.fail()) {
		cout << "resource open error." << endl;
		return 1;
	}
	string resourceInput;
	string _resourceName, _resourceType;
	getline(resourceFile, resourceInput);
	while (getline(resourceFile, resourceInput)) {
		_resourceType = resourceInput.substr(0, resourceInput.find("\t"));
		_resourceName = resourceInput.substr(resourceInput.find("\t") + 1);
		_library.addResource(_resourceName, _resourceType);
	}



	//get input.dat
	cout << "Op_#\tReturn_code\tDescription" << endl;
	int return_code = -1, op_num;

	ifstream inputFile("input.dat");
	if (inputFile.fail()) {
		cout << "input open error." << endl;
		return 1;
	}
	string input;
	string date, resourceType, resourceName, operation, memberType, memberName;

	ifstream spaceFile("space.dat");
	if (spaceFile.fail()) {
		cout << "space open error." << endl;
		return 1;
	}
	string space;
	string s_date, s_spaceType, s_spaceNumber, s_operation, s_memberType, s_memberName, s_numberOfMember, s_time;

	//pass first line
	getline(inputFile, input);
	getline(spaceFile, space);

	//read input file
	getline(inputFile, input);
	date = input.substr(0, input.find("\t"));
	input = input.substr(input.find("\t") + 1);
	resourceType = input.substr(0, input.find("\t"));
	input = input.substr(input.find("\t") + 1);
	resourceName = input.substr(0, input.find("\t"));
	input = input.substr(input.find("\t") + 1);
	operation = input.substr(0, input.find("\t"));
	input = input.substr(input.find("\t") + 1);
	memberType = input.substr(0, input.find("\t"));
	input = input.substr(input.find("\t") + 1);
	memberName = input;
	//read space file
	getline(spaceFile, space);
	s_date = space.substr(0, space.find("\t"));
	space = space.substr(space.find("\t") + 1);
	s_spaceType = space.substr(0, space.find("\t"));
	space = space.substr(space.find("\t") + 1);
	s_spaceNumber = space.substr(0, space.find("\t"));
	space = space.substr(space.find("\t") + 1);
	s_operation = space.substr(0, space.find("\t"));
	space = space.substr(space.find("\t") + 1);
	s_memberType = space.substr(0, space.find("\t"));
	space = space.substr(space.find("\t") + 1);
	s_memberName = space.substr(0, space.find("\t"));
	if (s_operation == "B") {
		space = space.substr(space.find("\t") + 1);
		s_numberOfMember = space.substr(0, space.find("\t"));
		space = space.substr(space.find("\t") + 1);
		s_time = space;
	}
	else if (s_operation == "R") {
		space = space.substr(space.find("\t") + 1);
		s_numberOfMember = "";
		space = space.substr(space.find("\t") + 1);
		s_time = "";
	}

	//compare date
	int _date, _s_date;
	while (1) {
		_date = _library.convertDate(date);
		_s_date = _library.convertDate(s_date.substr(2, 11));
		if (_date < _s_date) {
			//operate
			op_num = _library.showOp_num();
			return_code = _library.operation(date, resourceType, resourceName,
				operation, memberType, memberName);
			//print
			cout << op_num << "\t" << return_code << "\t" << _library.showDescription() << endl;

			//read input file
			if (getline(inputFile, input)) {
				date = input.substr(0, input.find("\t"));
				input = input.substr(input.find("\t") + 1);
				resourceType = input.substr(0, input.find("\t"));
				input = input.substr(input.find("\t") + 1);
				resourceName = input.substr(0, input.find("\t"));
				input = input.substr(input.find("\t") + 1);
				operation = input.substr(0, input.find("\t"));
				input = input.substr(input.find("\t") + 1);
				memberType = input.substr(0, input.find("\t"));
				input = input.substr(input.find("\t") + 1);
				memberName = input;

			}
			else {
				//operate
				op_num = _library.showOp_num();
				_library.s_checkDate(s_date);
				return_code = _library.s_operation(s_date, s_spaceType, s_spaceNumber, s_operation,
					s_memberType, s_memberName, s_numberOfMember, s_time);
				//print
				cout << op_num << "\t" << return_code << "\t" << _library.showDescription() << endl;
				break;
			}
		}
		else {
			//read space file
			//operate
			op_num = _library.showOp_num();
			_library.s_checkDate(s_date);
			return_code = _library.s_operation(s_date, s_spaceType, s_spaceNumber, s_operation,
				s_memberType, s_memberName, s_numberOfMember, s_time);
			//print
			cout << op_num << "\t" << return_code << "\t" << _library.showDescription() << endl;

			if (getline(spaceFile, space)) {
				s_date = space.substr(0, space.find("\t"));
				space = space.substr(space.find("\t") + 1);
				s_spaceType = space.substr(0, space.find("\t"));
				space = space.substr(space.find("\t") + 1);
				s_spaceNumber = space.substr(0, space.find("\t"));
				space = space.substr(space.find("\t") + 1);
				s_operation = space.substr(0, space.find("\t"));
				space = space.substr(space.find("\t") + 1);
				s_memberType = space.substr(0, space.find("\t"));
				space = space.substr(space.find("\t") + 1);
				s_memberName = space.substr(0, space.find("\t"));
				if (s_operation == "B") {
					space = space.substr(space.find("\t") + 1);
					s_numberOfMember = space.substr(0, space.find("\t"));
					space = space.substr(space.find("\t") + 1);
					s_time = space;
				}
				else if (s_operation == "R") {
					space = space.substr(space.find("\t") + 1);
					s_numberOfMember = "";
					space = space.substr(space.find("\t") + 1);
					s_time = "";
				}
			}
			else {
				//operate
				op_num = _library.showOp_num();
				return_code = _library.operation(date, resourceType, resourceName,
					operation, memberType, memberName);
				//print
				cout << op_num << "\t" << return_code << "\t" << _library.showDescription() << endl;
				break;
			}
		}
	}
	//remain only input
	while (getline(inputFile, input)) {
		//read input file
		date = input.substr(0, input.find("\t"));
		input = input.substr(input.find("\t") + 1);
		resourceType = input.substr(0, input.find("\t"));
		input = input.substr(input.find("\t") + 1);
		resourceName = input.substr(0, input.find("\t"));
		input = input.substr(input.find("\t") + 1);
		operation = input.substr(0, input.find("\t"));
		input = input.substr(input.find("\t") + 1);
		memberType = input.substr(0, input.find("\t"));
		input = input.substr(input.find("\t") + 1);
		memberName = input;
		//operate
		op_num = _library.showOp_num();
		return_code = _library.operation(date, resourceType, resourceName,
			operation, memberType, memberName);
		//print
		cout << op_num << "\t" << return_code << "\t" << _library.showDescription() << endl;
	}
	//remain only space
	while (getline(spaceFile, space)) {
		s_date = space.substr(0, space.find("\t"));
		space = space.substr(space.find("\t") + 1);
		s_spaceType = space.substr(0, space.find("\t"));
		space = space.substr(space.find("\t") + 1);
		s_spaceNumber = space.substr(0, space.find("\t"));
		space = space.substr(space.find("\t") + 1);
		s_operation = space.substr(0, space.find("\t"));
		space = space.substr(space.find("\t") + 1);
		s_memberType = space.substr(0, space.find("\t"));
		space = space.substr(space.find("\t") + 1);
		s_memberName = space.substr(0, space.find("\t"));
		if (s_operation == "B") {
			space = space.substr(space.find("\t") + 1);
			s_numberOfMember = space.substr(0, space.find("\t"));
			space = space.substr(space.find("\t") + 1);
			s_time = space;
		}
		else if (s_operation == "R") {
			space = space.substr(space.find("\t") + 1);
			s_numberOfMember = "";
			space = space.substr(space.find("\t") + 1);
			s_time = "";
		}
		//operate
		op_num = _library.showOp_num();
		_library.s_checkDate(s_date);
		return_code = _library.s_operation(s_date, s_spaceType, s_spaceNumber, s_operation,
			s_memberType, s_memberName, s_numberOfMember, s_time);
		//print
		cout << op_num << "\t" << return_code << "\t" << _library.showDescription() << endl;
	}
	return 0;
}


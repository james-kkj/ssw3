#include <iostream>
#include <string>
#include <fstream>
#include "library.h"


using namespace std;


int main() {
	class library _library;
	//get resource.dat
/*	ifstream ResourceFile("resource.dat");
	if (ResourceFile.fail()) {
		cout << "resource open error." << endl;
		return 1;
	}
	string ResourceInput;
	string _ResourceName, _ResourceType;
	getline(ResourceFile, ResourceInput);
	while (getline(ResourceFile, ResourceInput)) {
		_ResourceType = ResourceInput.substr(0, ResourceInput.find("\t"));
		_ResourceName = ResourceInput.substr(ResourceInput.find("\t")+1);
		_library.AddResource(_ResourceName, _ResourceType);
	}

//get input.dat
	cout << "Op_#\tReturn_code\tDescription" << endl;

	ifstream InputFile("input.dat");
	if (InputFile.fail()) {
		cout << "input open error." << endl;
		return 1;
	}
	string Input;
	string Date, ResourceType, ResourceName, Operation, MemberType, MemberName;
	int Return_code = 0, Op_num;
	getline(InputFile, Input);
	while (getline(InputFile, Input)) {
		Date = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		ResourceType = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		ResourceName = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		Operation = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		MemberType = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		MemberName = Input;
		//operate
		Op_num = _library.ShowOp_num();
		Return_code = _library.Operation(Date, ResourceType, ResourceName,
						Operation, MemberType, MemberName);
		//print
		cout << Op_num << "\t" << Return_code << "\t" << _library.ShowDescription() << endl;
	}
*/

	//get space.dat
	cout << "Op_#\tReturn_code\tDescription" << endl;

	ifstream InputFile("space.dat");
	if (InputFile.fail()) {
		cout << "space open error." << endl;
		return 1;
	}
	string Input;
	//string Date, ResourceType, ResourceName, Operation, MemberType, MemberName;
	string date, spaceType, spaceNumber, operation, memberType, memberName, numberOfMember, time;
	int Return_code = 0, Op_num;
	getline(InputFile, Input);
	while (getline(InputFile, Input)) {
		/*Date = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		ResourceType = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		ResourceName = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		Operation = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		MemberType = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		MemberName = Input;*/
		date = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		spaceType = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		spaceNumber = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		operation = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		memberType = Input.substr(0, Input.find("\t"));
		Input = Input.substr(Input.find("\t") + 1);
		memberName = Input;
		if (operation == "B") {
			Input = Input.substr(Input.find("\t") + 1);
			numberOfMember = Input.substr(0, Input.find("\t"));
			Input = Input.substr(Input.find("\t") + 1);
			time = Input;
		}
		else if (operation == "R") {
			Input = Input.substr(Input.find("\t") + 1);
			numberOfMember = "";
			Input = Input.substr(Input.find("\t") + 1);
			time = "";
		}
		//operate
		Op_num = _library.ShowOp_num();
		//Return_code = _library.Operation(Date, ResourceType, ResourceName,
		//				Operation, MemberType, MemberName);
		Return_code = _library.operation(date, spaceType, spaceNumber, operation, 
						memberType, memberName, numberOfMember, time);
		//print
		cout << Op_num << "\t" << Return_code << "\t" << _library.ShowDescription() << endl;
	}

}

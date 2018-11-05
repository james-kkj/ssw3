#include <iostream>
#include <string>
#include <fstream>
#include "library.h"

using namespace std;


int main() {
//get resource.dat
	class library _library;

	ifstream ResourceFile("resource.dat");
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
//_library.showBookList();

//get input.dat
	cout << "Op_#\tReturn_code\tDescription" << endl;

	ifstream InputFile("input.dat");
	if (InputFile.fail()) {
		cout << "input open error." << endl;
		return 1;
	}
	string Input;
	string Date, ResourceType, ResourceName, Operation, MemberType, MemberName;
	int Return_code, Op_num;
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
		
		cout << Date << ResourceType << ResourceName << Operation << MemberType << MemberName << endl;
		Op_num = _library.ShowOp_num();
		Return_code = _library.Operation(Date, ResourceType, ResourceName,
						Operation, MemberType, MemberName);

		cout << Op_num << "\t" << Return_code << "\t" << _library.ShowDescription() << endl;
	}

}

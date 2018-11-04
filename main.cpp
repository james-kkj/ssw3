#include <iostream>
#include <string>
#include <fstream>
//#include <library.h>

using namespace std;


int main() {
//get resource.dat
	//class library _library;

	ifstream ResourceFile("resource.dat");
	if (ResourceFile.fail()) {
		cout << "resource open error." << endl;
		return 1;
	}
	string ResourceInput;
	string _ResourceName, _ResourceType;
	getline(ResourceFile, ResourceInput);
	while (getline(ResourceFile, ResourceInput)) {
		_ResourceName = ResourceInput.substr(0, ResourceInput.find("\t"));
		_ResourceType = ResourceInput.substr(ResourceInput.find("\t"));
		//_library.AddResource(ResourceName, ResourceType);
		cout << _ResourceName << "1" << _ResourceType << endl;
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
		
		cout << Date << "1" << ResourceType << "1" << ResourceName << "1" << Operation << "1" << MemberType << "1" << MemberName << endl;
	}
}

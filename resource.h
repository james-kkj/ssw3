class resource
{
	string ResourceNmae;
	string ResourceType;
	char state;
public:
	void resource(string name, string type);
	Borrow();
	Return();
};

void resource::resource(string name, string type) {
	ResourceName = name;
	ResourceType = type;
	state = 'R'
}

void resource::Borrow() {
	state = 'B';
}

void resource::Return() {
	state = 'R';
}

class undergraduate :public resource{};
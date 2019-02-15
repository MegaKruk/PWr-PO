#pragma once
#include <string>
#include <vector>
using namespace std;

class Slav
{
private:
	static void init();

	static std::vector <string> names;
	static int _counter;

	string _name;
	int _id;

enum sex
{
	male,
	female
};

public:
	Slav();
	static int counter() {return _counter;}
	string name() {return _name;}
	int id() {return _id;}

	string description();
	sex whatSex ();
};
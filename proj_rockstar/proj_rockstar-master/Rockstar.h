#pragma once
#include <vector>
#include <string>

using namespace std;


struct enc
{
	string text;
	int cortexvalue;
	int livervalue;
	int bonesvalue;
	int heartvalue;
	int veneralvalue;
	int cardiovascularvalue;
	float bankvalue;
	int popularityvalue;
	int skillvalue;
};

struct act
{
	string text;
	int cortexvalue;
	int livervalue;
	int bonesvalue;
	int heartvalue;
	int veneralvalue;
	int cardiovascularvalue;
	float cost;
};

class Rockstar
{
	static vector <string> names;

	string _name;


	int _cortexhp;
	int _liverhp;
	int _boneshp;
	int _hearthp;
	int _veneralhp;
	int _cardiovascularhp;

	int _popularity;
	int _skill;
	float _bank;

	bool _isdead;

	static void init();

public:
	Rockstar();

	string name() { return _name; }
	void increase(float n) { _bank += n; }
	int cortexhp() { return _cortexhp; }
	int liverhp() { return  _liverhp; }
	int boneshp() { return  _boneshp; }
	int hearthp() { return  _hearthp; }
	int veneralhp() { return  _veneralhp; }
	int cardiovascularhp() { return  _cardiovascularhp; }

	int popularity() { return  _popularity; }
	int skill() { return  _skill; }
	float bank() { return  _bank; }

	bool isalive();

	void increasepop();
	void decreasepop();
	void encounter();
	int choosingactivity();
	void activity();
	void death();

	string description();


};

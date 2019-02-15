#pragma once
#include <string>
#include "Rockstar.h"

using namespace std;


class Concert
{
	int _rating;
	string _howitwent;
	float _income;

public:
	Concert(Rockstar x);
	Rockstar swap();

	int rating() { return _rating; }
	string howitwent() { return _howitwent; }
	float income() { return _income; }

	static int RandomRating();
	static int FinalRating();
	float FinalIncome(int);
	string FinalResult(int);

	void transfer();

	string description();

};

#include "Concert.h"
#include "Rockstar.h"
#include <stdlib.h>
#include <string>
#include <iterator>

Rockstar r;

int Concert::RandomRating()
{
	return rand() % 100 + 1;
}

int Concert::FinalRating()
{
	return RandomRating() + RandomRating() * r.skill() / 10;
}


float Concert::FinalIncome(int _rating)
{


	if (_rating <= 40)
	{
		return 100 + 100 * r.popularity() / 10;
		r.decreasepop();
	}
	else {

	if (_rating > 40 && _rating <= 80)
	{
		return 500 + (500 * r.popularity() / 10);
	}
	else {

		if (_rating > 80)
		{
			return 2000 + 2000 * r.popularity() / 10;
			r.increasepop();
		}
		else {

			if (_rating > 666)
			{
				return 10000 + 10000 * r.popularity() / 10;
				r.increasepop();
			}
			else return 0;


}
}
}
}

string Concert::FinalResult(int _rating)
{

	if (_rating <= 40)
	{
		return "Zenada. Poziom radia. ";
	}
	else {

		if (_rating > 40 && _rating <= 80)
		{
			return "Bylo w porzadku. Dalo siê sluchac. ";
		}
		else {

			if (_rating > 80)
			{

				return "Scena jest Twoja! Jestes legenda Rocka! ";
			}
			else {

				if (_rating > 666)
				{
					return "Twoja Moc Rocka rzuci³a œwiat na kolana!!!  ";
				}
				else return 0;


}
}
}
}

void Concert::transfer()
{
	r.increase(_income);
}


Concert::Concert(Rockstar x)
{
	r = x;
	_rating = FinalRating();
	_income = FinalIncome(_rating);
	_howitwent = FinalResult(_rating);
}

string Concert::description()
{
	return "\n\tRezultat koncertu: " + howitwent() +
		"\n\tZarobiles: " + to_string(income()) + "\n";
}

Rockstar Concert::swap() 
{	
	return r;
}
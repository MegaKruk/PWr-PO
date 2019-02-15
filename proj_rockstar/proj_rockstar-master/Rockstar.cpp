#include "Rockstar.h"
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

vector <string> Rockstar::names;

using namespace std;


enc encounters[10] =
{
	{ "Odwiedzasz lekarza. Ten robi Ci badania i zastanawia si�, jakim cudem jeszcze �yjesz. +5 do wszystkich hp ",
	5,5,5,5,5,5,0,0,0 },
	{ "Wdajesz si� w b�jk� w barze. Dajesz lokalnym gazetom mas� materia�u o tym, �e rock to Z�O. -5 do hp ko�ci i szpiku ",
	0,0,-5,0,0,0,0,0,0 },
	{ "Do Twojej przyczepy zawita�y groupies. Czujesz, �e to b�dzie dobry dzie�. -5 do hp dr�g wenerycznych ",
	0,0,0,0,-5,0,0,0,0 },
	{ "Zepsu� si� sprz�t, koncert zostaje op�niony. Fani powoli szykuj� wid�y i pochodnie. -1 do popularno�ci ",
	0,0,0,0,0,0,0,-1,0 },
	{ "Mened�er za�atwi� Ci ca�� g�r� towaru 'na popraw� kreatywno�ci'. Masz ochot� bra� si� za nast�pny kawa�ek, ale drog� do studia zagradza Ci smok. -5 do hp rdzenia kr�gowego ",
	-5,0,0,0,0,0,0,0,0 },
	{ "Na scen� wpada nietoperz. My�lisz, �e to zabawka rzucona przez fan�w. Odgryzasz mu g�ow�. Czujesz krew w ustach. To by� prawdziwy nietoperz. Co� ty narobi�?! -5 do hp uk�adu krwiono�nego ",
	0,0,0,0,0,-5,0,0,0 },
	{ "Upijasz si� i postanawiasz odda� honor �o�nierzom poleg�ym pod Alamo. Poprzez odlanie si� na pomnik. To nie tak mia�o by�! Sp�dzasz kilka nocy w areszcie. -1 do umiej�tno�ci ",
	0,0,0,0,0,0,0,0,-1 },
	{ "Ostatnie miesi�ce sp�dzi�e� na nagrywaniu p�yty. Padasz ze zm�czenia, ale warto by�o. +10 000 $ ",
	0,0,0,0,0,0,10000,0,0 },
	{ "Pieczesz ciasto z hashu. Przychodzi Twoja �ona i cz�stuje nim pastora. Boisz si�, �e pastor nie prze�yje gigantycznej dawki. Ufff... Prze�y�. Jeste�cie teraz najlepszymi przyjaci�mi z pastorem. -5 do hp serca ",
	0,0,0,-5,0,0,0,0,0 },
	{ "Idziecie z ca�ym zespo�em si� napi�. Budzisz si� przy basenie wype�nionym czekolad� i �elkami. Nic nie pami�tasz, ale strasznie boli Ci� brzuch. -10 do hp w�troby ",
	0,-10,0,0,0,0,0,0,0 }

};

act activities[7] =
{
	{ "Kupujesz heroin� za 10 000 $. Nowy materia� sam si� nie napisze! -5 do hp rdzenia kr�gowego ",
	-5,0,0,0,0,0,10000 },
	{ "Nie ma to jak odetchn�� po koncercie z LSD. Koszt - 5 000 $. Wra�enia? Bezcenne! -5 do hp ko�ci i szpiku ",
	0,0,-5,0,0,0,5000 },
	{ "Kocham wiersze Stachury... i stary dobry hash od wietnamczyka za rogiem za 1000 $. -5 do hp serca ",
	0,0,0,-5,0,0,1000 },
	{ "Pragniesz z kumplami uczyni� ho�d najstarszej profesji na �wiecie za jedyne 500 $ za noc! -5 do hp dr�g wenerycznych ",
	0,0,0,0,-5,0,500 },
	{ "Spotykasz Boba Marleya za scen� po koncercie. Sp�dzasz wiecz�r po jamajsku po czym szturmujesz lokalny fast-food. Zastanawiasz si� jak zjad�e� r�wnowarto�� 200 $ w burgerach. -5 do hp uk�adu krwiono�nego -2 do hp w�troby ",
	0,-2,0,0,0,-5,200 },
	{ "Sp�dzasz wiecz�r szukaj�c dna butelki. Kupujesz zapas taniej w�dki dla siebie i zespo�u za 100 $. -5 do hp w�troby ",
	0,-5,0,0,0,0,100 },
	{ "Wracasz do przyczepy i �pisz jak zabity. Czujesz jak tw�j organizm oddycha z ulg�. +1 do wszystkich hp",
	1,1,1,1,1,1,0 }

};


void Rockstar::init()
{
	ifstream file("names.txt");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

int RandomizeStats()
{
	return rand() % 51 + 50;
}

bool Rockstar::isalive()
{
	if (_cortexhp*_liverhp*_boneshp*_hearthp*_veneralhp*_cardiovascularhp <= 0)
		return false;
	else
		return true;
}

int RandomEnc()
{
	return rand() % 10;
}

void Rockstar::encounter()
{
	int n = RandomEnc();

	printf("Zdarzenie: \n%s\n", encounters[n].text.c_str());

	_cortexhp += encounters[n].cortexvalue;
	_liverhp += encounters[n].livervalue;
	_boneshp += encounters[n].bonesvalue;
	_hearthp += encounters[n].heartvalue;
	_veneralhp += encounters[n].veneralvalue;
	_cardiovascularhp += encounters[n].cardiovascularvalue;
	_bank += encounters[n].bankvalue;
	_popularity += encounters[n].popularityvalue;
	_skill += encounters[n].skillvalue;

}

int Rockstar::choosingactivity()
{
	for (int i = 0; i <= 6; i++)
	{
		if (_bank < activities[i].cost)
			i++;
		else
			return i;
	}
}

void Rockstar::activity()
{
	int m = choosingactivity();
	printf("Aktywno��: \n%s\n", activities[m].text.c_str());

	_cortexhp += activities[m].cortexvalue;
	_liverhp += activities[m].livervalue;
	_boneshp += activities[m].bonesvalue;
	_hearthp += activities[m].heartvalue;
	_veneralhp += activities[m].veneralvalue;
	_cardiovascularhp += activities[m].cardiovascularvalue;
	_bank -= activities[m].cost;

}

void Rockstar::increasepop()
{
	_popularity++;
}

void Rockstar::decreasepop()
{
	_popularity--;
}

void Rockstar::death()
{
	if (_cortexhp <= 0)
		printf("Nadszed� Tw�j koniec. Narkotyki zbieraj� swoje �niwo. Przyczyna zgonu: Zapalenie rdzenia kr�gowego. \n");
	if (_liverhp <= 0)
		printf("Nadszed� Tw�j koniec. W�troba to najszybciej zu�ywaj�cy si� organ gwiazdy Rocka. Przyczyna zgonu: Rak w�troby. \n");
	if (_boneshp <= 0)
		printf("Nadszed� Tw�j koniec. Tw�j w�asny szkielet podda� si� wyniszczeniu. Przyczyna zgonu: Rak szpiku kostnego. \n");
	if (_hearthp <= 0)
		printf("Nadszed� Tw�j koniec. Serce nie nad��y�o z twoim trybem �ycia. Przyczyna zgonu: Zawa�. \n");
	if (_veneralhp <= 0)
		printf("Nadszed� Tw�j koniec. Czas zap�aci� za igraszki w czasach m�odo�ci. Przyczyna zgonu: AIDS. \n");
	if (_cardiovascularhp <= 0)
		printf("Nadszed� Tw�j koniec. Zanieczy�ci�e� swoj� w�asn� krew ponad miar�. Przyczyna zgonu: Bia�aczka. \n");
}

Rockstar::Rockstar()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];

	_cortexhp = RandomizeStats();
	_liverhp = RandomizeStats();
	_boneshp = RandomizeStats();
	_hearthp = RandomizeStats();
	_veneralhp = RandomizeStats();
	_cardiovascularhp = RandomizeStats();

	_bank = 0;
	_popularity = 0;
	_skill = 0;
}

string Rockstar::description()
{
	return _name +
		"\n\tRdzen kregowy: " + to_string(cortexhp()) +
		"\n\tWatroba: " + to_string(liverhp()) +
		"\n\tKosci i szpik: " + to_string(boneshp()) +
		"\n\tSerce: " + to_string(hearthp()) +
		"\n\tDrogi weneryczne: " + to_string(veneralhp()) +
		"\n\tUklad Krwionosny: " + to_string(cardiovascularhp()) +
		"\n\tPieniadze: " + to_string(bank()) +
		"\n\tFani: " + to_string(popularity()) +
		"\n\tMoc Rocka: " + to_string(skill()) +
		"\n";
}
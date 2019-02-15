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
	{ "Odwiedzasz lekarza. Ten robi Ci badania i zastanawia siê, jakim cudem jeszcze ¿yjesz. +5 do wszystkich hp ",
	5,5,5,5,5,5,0,0,0 },
	{ "Wdajesz siê w bójkê w barze. Dajesz lokalnym gazetom masê materia³u o tym, ¿e rock to Z£O. -5 do hp koœci i szpiku ",
	0,0,-5,0,0,0,0,0,0 },
	{ "Do Twojej przyczepy zawita³y groupies. Czujesz, ¿e to bêdzie dobry dzieñ. -5 do hp dróg wenerycznych ",
	0,0,0,0,-5,0,0,0,0 },
	{ "Zepsu³ siê sprzêt, koncert zostaje opóŸniony. Fani powoli szykuj¹ wid³y i pochodnie. -1 do popularnoœci ",
	0,0,0,0,0,0,0,-1,0 },
	{ "Mened¿er za³atwi³ Ci ca³¹ górê towaru 'na poprawê kreatywnoœci'. Masz ochotê braæ siê za nastêpny kawa³ek, ale drogê do studia zagradza Ci smok. -5 do hp rdzenia krêgowego ",
	-5,0,0,0,0,0,0,0,0 },
	{ "Na scenê wpada nietoperz. Myœlisz, ¿e to zabawka rzucona przez fanów. Odgryzasz mu g³owê. Czujesz krew w ustach. To by³ prawdziwy nietoperz. Coœ ty narobi³?! -5 do hp uk³adu krwionoœnego ",
	0,0,0,0,0,-5,0,0,0 },
	{ "Upijasz siê i postanawiasz oddaæ honor ¿o³nierzom poleg³ym pod Alamo. Poprzez odlanie siê na pomnik. To nie tak mia³o byæ! Spêdzasz kilka nocy w areszcie. -1 do umiejêtnoœci ",
	0,0,0,0,0,0,0,0,-1 },
	{ "Ostatnie miesi¹ce spêdzi³eœ na nagrywaniu p³yty. Padasz ze zmêczenia, ale warto by³o. +10 000 $ ",
	0,0,0,0,0,0,10000,0,0 },
	{ "Pieczesz ciasto z hashu. Przychodzi Twoja ¿ona i czêstuje nim pastora. Boisz siê, ¿e pastor nie prze¿yje gigantycznej dawki. Ufff... Prze¿y³. Jesteœcie teraz najlepszymi przyjació³mi z pastorem. -5 do hp serca ",
	0,0,0,-5,0,0,0,0,0 },
	{ "Idziecie z ca³ym zespo³em siê napiæ. Budzisz siê przy basenie wype³nionym czekolad¹ i ¿elkami. Nic nie pamiêtasz, ale strasznie boli Ciê brzuch. -10 do hp w¹troby ",
	0,-10,0,0,0,0,0,0,0 }

};

act activities[7] =
{
	{ "Kupujesz heroinê za 10 000 $. Nowy materia³ sam siê nie napisze! -5 do hp rdzenia krêgowego ",
	-5,0,0,0,0,0,10000 },
	{ "Nie ma to jak odetchn¹æ po koncercie z LSD. Koszt - 5 000 $. Wra¿enia? Bezcenne! -5 do hp koœci i szpiku ",
	0,0,-5,0,0,0,5000 },
	{ "Kocham wiersze Stachury... i stary dobry hash od wietnamczyka za rogiem za 1000 $. -5 do hp serca ",
	0,0,0,-5,0,0,1000 },
	{ "Pragniesz z kumplami uczyniæ ho³d najstarszej profesji na œwiecie za jedyne 500 $ za noc! -5 do hp dróg wenerycznych ",
	0,0,0,0,-5,0,500 },
	{ "Spotykasz Boba Marleya za scen¹ po koncercie. Spêdzasz wieczór po jamajsku po czym szturmujesz lokalny fast-food. Zastanawiasz siê jak zjad³eœ równowartoœæ 200 $ w burgerach. -5 do hp uk³adu krwionoœnego -2 do hp w¹troby ",
	0,-2,0,0,0,-5,200 },
	{ "Spêdzasz wieczór szukaj¹c dna butelki. Kupujesz zapas taniej wódki dla siebie i zespo³u za 100 $. -5 do hp w¹troby ",
	0,-5,0,0,0,0,100 },
	{ "Wracasz do przyczepy i œpisz jak zabity. Czujesz jak twój organizm oddycha z ulg¹. +1 do wszystkich hp",
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
	printf("Aktywnoœæ: \n%s\n", activities[m].text.c_str());

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
		printf("Nadszed³ Twój koniec. Narkotyki zbieraj¹ swoje ¿niwo. Przyczyna zgonu: Zapalenie rdzenia krêgowego. \n");
	if (_liverhp <= 0)
		printf("Nadszed³ Twój koniec. W¹troba to najszybciej zu¿ywaj¹cy siê organ gwiazdy Rocka. Przyczyna zgonu: Rak w¹troby. \n");
	if (_boneshp <= 0)
		printf("Nadszed³ Twój koniec. Twój w³asny szkielet podda³ siê wyniszczeniu. Przyczyna zgonu: Rak szpiku kostnego. \n");
	if (_hearthp <= 0)
		printf("Nadszed³ Twój koniec. Serce nie nad¹¿y³o z twoim trybem ¿ycia. Przyczyna zgonu: Zawa³. \n");
	if (_veneralhp <= 0)
		printf("Nadszed³ Twój koniec. Czas zap³aciæ za igraszki w czasach m³odoœci. Przyczyna zgonu: AIDS. \n");
	if (_cardiovascularhp <= 0)
		printf("Nadszed³ Twój koniec. Zanieczyœci³eœ swoj¹ w³asn¹ krew ponad miarê. Przyczyna zgonu: Bia³aczka. \n");
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
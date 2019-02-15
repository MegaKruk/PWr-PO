#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include "Slav.h"
#include <iterator>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)
using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);
void containers(Slav *, int);
void adapters(Slav *, int);
void sexMap(Slav *, int);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int n = 2 * atoi(argv[1]);

	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
		for (int i = 0; i < n; ++i)
			cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);
	sexMap(slavs, n);
	delete [] slavs;
}

void sexMap(Slav * slavs, int n)
{
	map < sex, vector <Slav *> > mapOfSex;

	for (int i=0; i<n; i++)
	{
		if (slavs[i].whatSex() == male)
			mapOfSex[male].push_back(slavs + i);
		else
			mapOfSex[female].push_back(slavs + i);
	}

	cout<<"Faceci\n";

		for (vector <Slav *> :: iterator vec_it = mapOfSex[male].begin(); vec_it != mapOfSex[male].end(); vec_it++)
		cout << (*vec_it)->description();

	cout<<"Laseczki\n";

		for (vector <Slav *> :: iterator vec_it = mapOfSex[female].begin(); vec_it != mapOfSex[female].end(); vec_it++)
		cout << (*vec_it)->description();

	cout<<"\n\n";
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

		for(int i = 0; i < n; i++)
			vectorOfSlavs.push_back(&slavs[i]);

	random_shuffle(vectorOfSlavs.begin(), vectorOfSlavs.end());

		for (vector <Slav *> :: iterator vec_it = vectorOfSlavs.begin(); vec_it != vectorOfSlavs.end(); vec_it++)
		cout << (*vec_it)->description() << endl;

	REPORT_CONTAINERS;
	printf("## set\n");

		for (vector <Slav *> :: iterator vec_it = vectorOfSlavs.begin(); vec_it != vectorOfSlavs.end(); vec_it++)
			setOfSlavs.insert(*vec_it);
	
	REPORT_CONTAINERS;
	printf("## map\n");

		for (set <Slav *> :: iterator set_it = setOfSlavs.begin(); set_it != setOfSlavs.end(); set_it++)
			mapOfSlavs[*(set_it)] = *(++set_it);

	setOfSlavs.clear();

		for (map <Slav *, Slav *> :: iterator map_it = mapOfSlavs.begin(); map_it != mapOfSlavs.end(); map_it++)
			cout << setw(20) << left << (*map_it).first->description()  << setw(20) << left << (*map_it).second->description() << endl;
	
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

		for(int i = 0; i < n; i++)
			queueOfSlavs.push(slavs+i);
	REPORT_ADAPTERS;

	printf("## stack\n");
	while (!queueOfSlavs.empty())
	{
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();
	}
	REPORT_ADAPTERS;

	while (!stackOfSlavs.empty())
	{
		cout << stackOfSlavs.top()->description();
		stackOfSlavs.pop();
	}
	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
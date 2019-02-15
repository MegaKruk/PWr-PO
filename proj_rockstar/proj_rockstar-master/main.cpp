#include "Rockstar.h"
#include "Concert.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <unistd.h>
#define INTERVAL 3000000

#include <thread>

using namespace std;


int main()
{

	Rockstar rockstar;

	printf("\nWitaj mlody rockmanie. Wlasnie podpisales pierwszy kontakt z wytwórnia i jestes gotów na podbój sceny. \n");

		int i = 0;

	while (rockstar.isalive())
	{
		printf("Dane: \n%s\n", rockstar.description().c_str());
		//usleep(INTERVAL);
		this_thread::sleep_for(chrono::milliseconds(3000000));
		i++;

		if (i % 3 == 0)
		{
			rockstar.encounter();
		}

		if (i % 3 == 1)
		{
			Concert concert(rockstar);
			rockstar = concert.swap();
			printf("Koncert! \n%s\n",  concert.description().c_str());

		}

		if (i % 3 == 2)
		{
			rockstar.activity();
		}

	}

	rockstar.death();


}
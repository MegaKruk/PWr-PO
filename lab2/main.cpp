#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <assert.h>


struct fraction 
{
 	int nominator;
 	int denominator;

 	bool is_correct()
	{
 	if(abs(nominator) < abs(denominator) && denominator != 0)
		return true;
	else
		return false;
 	}
  
 	
};

int main(int argc, char **argv) 
{
	
	int n = atoi(argv[1]);
	srand(time(NULL));
	fraction *fractions = new fraction[n];

	for(int i = 0; i < n; i++) 
	{
		do {
		fractions[i].nominator = rand()%19 - 9;
		fractions[i].denominator = rand()%19 - 9;
		} while(fractions[i].is_correct() != false);
	}
	for(int i = 0; i < n; assert(fractions[i++].is_correct())) 
	{
	printf("%d/%d\n", fractions[i].nominator, fractions[i].denominator);
	}

delete []fractions;

}

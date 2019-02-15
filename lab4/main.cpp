#include <stdio.h>
#include <cstdlib>
#include <string>
using namespace std;

bool is01(int n)
{

	while (n > 0)
    {
		if (n % 10 > 1)
            return false;
		n /= 10;
	}
	return true;

}

int seekingk(int n, int k)
{

	while (k > 0)
    {

		if (is01(k*n))
		{
            return k;
            break;
		}
		k++;

    }

}

int liczebnik(int n)
{

string jedn[10] = { "","jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec" };

string nascie[10] = { "dziesięc","jedenascie","dwanascie","trzynascie","czternascie","pietnascie",
"szesnascie","siedemnascie","osiemnascie","dziewietnascie" };

string dzies[10] = { "", "","dwadziescia","trzydziesci","czterdziesci","piecdziesiat","szescdziesiat",
"siedemdziesiat","osiemdziesiat","dziewiêædziesiat" };

string sto[10] = { "", "sto","dwiescie","trzysta","czterysta","piecset","szescset","siedemset","osiemset","dziewiecset" };

string tys[4] = { "", "tysiac","tysiace","tysiecy" };

string mil[2] = { "", "milion" };


int n_1 = n % 10;
n /= 10;
int n_2 = n % 10;
n /= 10;
int n_3 = n % 10;
n /= 10;
int n_4 = n % 10;
n /= 10;
int n_5 = n % 10;
n /= 10;
int n_6 = n % 10;
n /= 10;
int n_7 = n % 10;



printf("%s ",mil[n_7].c_str());

if(n_5 == 1)
    printf("%s %s ",sto[n_6].c_str(), nascie[n_4].c_str());
else printf("%s %s %s ",sto[n_6].c_str(), dzies[n_5].c_str(), jedn[n_4].c_str());

if(n_4)
    {
    if(n_4 > 4)
        printf("%s ",tys[3].c_str());
    if(n_4 >= 2 && n_4 <= 4 && n_5 != 1)
        printf("%s ",tys[2].c_str());
    if(n_4 >= 2 && n_4 <= 4 && n_5 == 1)
        printf("%s ",tys[3].c_str());
    if(n_4 == 1 && n_5 == 0 && n_6 == 0)
        printf("%s ",tys[1].c_str());
    if(n_4 == 0 && n_5 == 0 && n_6 == 0)
        printf("%s ",tys[0].c_str());
    } else printf("%s ",tys[3].c_str());

if(n_2 == 1)
        printf("%s %s ",sto[n_3].c_str(), nascie[n_1].c_str());
    else printf("%s %s %s ",sto[n_3].c_str(), dzies[n_2].c_str(), jedn[n_1].c_str());

}

int main(int argc, char **argv)
{
    int k = 1;
	int n = atoi(argv[1]);
        if(n>1000000)
            exit(1);

	k = seekingk(n, k);
    printf("sprawdzenie n*k = %d\n",n*k);
    printf("k = %d\n",k);

	liczebnik(n);

}
#include <iostream>
#include <cstdlib>
using namespace std;

long int fibo(int ilosc)
{

    long int x = 0,y = 1;
    for(int i = 0; i < ilosc; i++)
        {
        cout << y << ", ";

        y += x;
        x = y-x;
        }

}

void metal(int ilosc)
{
    long long x=6;
    long long y=6;
    for(int j=0; j<ilosc; j++)
        {
        cout << x << ", ";
        y = y*10;
        x += y;
        }


}

int main(int argc, char** argv)
{
    char* znak = argv[1];
    int ilosc = atoi(argv[2]);
    if(*znak=='f')
        fibo(ilosc);
    else
        metal(ilosc);

    return 0;
}

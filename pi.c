#include<iostream>
using namespace std;
int main()
{
    int pi=0;
    for(int i=0;i<10000;i++)
    {
        if(i%2==0)
        pi+=1/(2*i+1);
        else
            pi-=1/(2*i+1);
    }
    cout<<pi;
    return(0);
}

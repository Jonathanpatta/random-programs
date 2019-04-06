#include<iostream>
#include<cstdlib>
using namespace std;
int get(int x,int y)
    {
        if(x==y)
            return(0);
        else
            return(1);
    }
void create()
{
    int x=rand()%2,y=rand()%2,c;

    cout<<"inputs "<<x<<y<<endl;
    c=get(x,y);
    cout<<"output  "<<c<<endl;
}
int main()
{
    for(int i=0;i<10;i++)
    {
        create();
    }
    return(0);
}

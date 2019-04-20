#include<iostream>
using namespace std;
int main()
{
    int data,mod,n=0,bin[1000],tdat,oct[1000];
    struct Hex
    {
        int num,check;
        char let;
    }hex[100];
    cout<<"enter decimal number:";
    cin>>data;cout<<endl;
    tdat=data;
    while(tdat>0)
    {
        mod=tdat%2;
        tdat/=2;
        bin[n]=mod;
        n++;
    }
    cout<<"binary number is:";
    for(int i=n-1;i>=0;i--)
        cout<<bin[i];
    n=0;
    tdat=data;
    while(tdat>0)
    {
        mod=tdat%8;
        tdat/=8;
        oct[n]=mod;
        n++;
    }
    cout<<"\noctal number is:";
    for(int i=n-1;i>=0;i--)
        cout<<oct[i];
    n=0;
    tdat=data;
    while(tdat>0)
    {
        mod=tdat%16;
        tdat/=16;
        if(mod<10)
        {
            hex[n].num=mod;
            hex[n].check=0;
        }
        else
        {
            hex[n].check=1;
            if(mod==10)
                hex[n].let='A';
            if(mod==11)
                hex[n].let='B';
            if(mod==12)
                hex[n].let='C';
            if(mod==13)
                hex[n].let='D';
            if(mod==14)
                hex[n].let='E';
            if(mod==15)
                hex[n].let='F';
        }
        n++;
    }
    cout<<"\nhexadecimal number is:";
    for(int i=n-1;i>=0;i--)
    {
        if(hex[i].check==0)
            cout<<hex[i].num;
        else
            cout<<hex[i].let;
    }
}

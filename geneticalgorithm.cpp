using namespace std;
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<time.h>
string random(int n,string s)
{

    char num;
    for(int i=0;i<n;i++)
    {
        int p=rand()%27;
        if(p!=26)
            num='a'+p;
        else
            num=' ';
        s[i]=num;

    }
    return s;
}
void show_vector(vector<string> s)
{
    int n=0;
    while(n<s.size())
    {
        cout<<s[n]<<"\n";
        n++;
    }
}
int calc_fitness(string s,string target)
{
    int c=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==target[i])
        {
            c++;
        }
    }
    return c;
}
int get_max_fitness(vector<string> s,string target)
{
    int rec=0;
    string show;
    for(int i=0;i<s.size();i++)
    {
        if(rec<calc_fitness(s[i],target))
        {
            rec=calc_fitness(s[i],target);
            show=s[i];
        }
    }
    cout<<show<<" ";
    return rec;
}
vector<string> create_mp(vector<string> s,string target)
{
    vector<string> mp;
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<calc_fitness(s[i],target);j++)
        {
            mp.push_back(s[i]);
        }
    }
    return mp;
}
string crossover(string a,string b)
{
    int mid =rand()%a.size();
    for(int i=0;i<mid;i++)
    {
        b[i]=a[i];
    }
    return b;
}
vector<string> mutate(vector<string> s,float mr)
{
    int n=mr*s.size()*s[0].size();
    for(int i=0;i<n;i++)
    {
        int index1=rand()%s.size();
        int index2=rand()%s[0].size();

        char num;
        int p=rand()%27;
        if(p!=26)
            num='a'+p;
        else
            num=' ';
        s[index1][index2]=num;
    }
    return s;
}
vector<string> reproduce(vector<string> s,vector<string> mp,string target,float mr)
{
    vector<string> c;
    int index1,index2;
    for(int i=0;i<s.size();i++)
    {
        index1=rand()%mp.size();
        index2=rand()%mp.size();
        c.push_back(crossover(mp[index1],mp[index2]));
    }
    c=mutate(c,mr);
    return c;
}
int main()
{
    int avg=0;
    //for(int i=0;i<100;i++)
    //{
        vector <string> population,mating_pool;
        string target="hello world";
        int psize=400,gen=0;
        srand(time(0));
        for(int i=0;i<psize;i++)
        {
            population.push_back(random(target.size(),target));
        }
        mating_pool=create_mp(population,target);
        //show_vector(mating_pool);
        while(get_max_fitness(population,target)!=target.size())
        {
            population=reproduce(population,mating_pool,target,0.01);
            mating_pool=create_mp(population,target);
            cout<<mating_pool.size()<<"\n";
            //system("cls");
            gen++;
        }
        cout<<"\n"<<gen<<" generations!!";
        //avg+=gen;
    //}
    //cout<<avg/10;
}









#include <iostream>
#include <fstream>
#include <string.h>
#include "plants.h"
using namespace std;

void create(const string &file, vector<Plants*> &plants, int &napok)
{
    ifstream f(file);
    if(f.fail())
    {
        cout<<"Wrong file name!\n";
        exit(1);
    }
    int n;
    f>>n;
    plants.resize(n);
    char c;
    string name;
    int food;
    for(int i=0; i<n; i++)
    {
        f>>name>>c>>food;
        switch(c)
        {
        case 'p':
            plants[i] = new Puffancs(name, food);
            break;
        case 'd':
            plants[i] = new Deltafa(name, food);
            break;
        case 'b':
            plants[i] = new Parabokor(name, food);
            break;
        }
        plants[i]->type=c;
    }

    f>>napok;
}

void day(vector<Plants*> &plants, Sugarzas* &h)
{
    int a=0, d=0, n=0;
    for(unsigned int i=0; i<plants.size(); i++)
    {
        plants[i]->react(h);
        if(plants[i]->isAlive())
        {
            if(plants[i]->type=='p')
                a+=10;
            else if(plants[i]->type=='d')
            {
                if(plants[i]->food<5)
                    d+=4;
                else if(plants[i]->food<10)
                    d+=1;
            }
        }
        else {plants[i]=plants.back(); plants.pop_back();}

    }
    if(a>d+3)
        h=Alfa::instance();
    else if(d>a+3)
        h=Delta::instance();
    else h=None::instance();
}

template <typename Item>
void print (const vector<Item*> &vec)
{
    for (Item* ptr : vec)
    {
        cout<<*ptr<<endl;
    }
}

int lastOnes(vector<Plants*> &plants)
{
    int max=0, hol;
    for(unsigned int i=0;i<plants.size();i++)
        if(plants[i]->food>max) {max=plants[i]->food; hol=i;}
    return hol;
}

void days1(vector<Plants*> plants, int &napok)
{
    Sugarzas* h = None::instance();
    for(int i=0;i<napok;i++)
    {
        day(plants, h);
        cout<<i+1<<". nap:"<<endl;
        print(plants);
    }
    int t=lastOnes(plants);
    cout<<"A legerosebb noveny "<<plants[t]->name<<" volt, "<<plants[t]->food<<" kajaja maradt."<<endl;

}

int days(vector<Plants*> plants, int &napok)
{
    Sugarzas* h = None::instance();
    for(int i=0;i<napok;i++)
    {
        day(plants, h);
    }
    int t=lastOnes(plants);
    return t;
}

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    vector<Plants*> plants;
    int napok;
    string fn="t2.txt";
    create(fn, plants, napok);
    if(plants.size()!=0)
    {
    days1(plants, napok);
    }
      return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("2 days, 2 plants", "t1.txt")
{
    vector<Plants*> plants;
    int napok;
    create("t1.txt", plants, napok);
    int t=days(plants, napok);
    CHECK(plants.size()==2);
    CHECK(t==0);
}

TEST_CASE("1 day, no plants", "t2.txt")
{
    vector<Plants*> plants;
    int napok;
    create("t2.txt", plants, napok);
    days(plants, napok);
    CHECK(plants.size()==0);
}

TEST_CASE("10 days, 3 plants", "t3.txt")
{
    vector<Plants*> plants;
    int napok;
    create("t3.txt", plants, napok);
    CHECK(plants.size()==3);
    int t=days(plants, napok);
    CHECK(t==0);
}




#endif

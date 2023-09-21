#ifndef PLANTS_H_INCLUDED
#define PLANTS_H_INCLUDED
#include "sugarzas.h"
#include <string>
#include <ostream>

#include <vector>

class Plants{
public:
    std::string name;
    int food;
    virtual bool isAlive() =0;
    virtual ~Plants() {}
    Plants(){}
    char type;
    Plants(const std::string &nev, int kaja) : name(nev), food(kaja) {}

    virtual void react(Sugarzas* &h) = 0;
    friend std::ostream &operator<<(std::ostream &os,const Plants &a)
    {
        os<<a.name<< " ("<<a.food<<")";
        return os;
    }
};

class Puffancs:public Plants{
public:
    Puffancs(const std::string &nev, int kaja) : Plants(nev, kaja){}
    bool isAlive(){if(food>0 && food<10) return true; else return false;}

    void react(Sugarzas* &h)override{
        if(h->getType()==1)food+=2;
        else if(h->getType()==2)food-=2;
        else food-=1;}
};

class Deltafa:public Plants{
public:
    Deltafa(const std::string &nev, int kaja) : Plants(nev, kaja){}
    bool isAlive(){if(food>0) return true; else return false;}

    void react(Sugarzas* &h){if(h->getType()==1)food-=3; else if(h->getType()==2)food+=4; else food-=1;}
};

class Parabokor:public Plants{
public:
    Parabokor(const std::string &nev, int kaja) : Plants(nev, kaja){}
    bool isAlive(){if(food>0) return true; else return false;}

    void react(Sugarzas* &h){if(h->getType()==1 || h->getType()==2)food+=1; else food-=1;}
};



#endif // PLANTS_H_INCLUDED

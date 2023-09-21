#ifndef SUGARZAS_H_INCLUDED
#define SUGARZAS_H_INCLUDED

class Sugarzas{
public:
    Sugarzas(int t): type(t){}
    Sugarzas(){}
    int getType(){return type;}
    int type;

};

class Alfa:public Sugarzas{
public:
    static Alfa* instance();
    Alfa(int t=1) : Sugarzas(t){}
private:
    static Alfa* _instance;
};

class Delta:public Sugarzas{
public:
    static Delta* instance();
    Delta(int t=2) : Sugarzas(t){}
private:
    static Delta* _instance;
};

class None:public Sugarzas{
public:
    static None* instance();
    None(int t=3) : Sugarzas(t){}
private:
    static None* _instance;
};

#endif // SUGARZAS_H_INCLUDED

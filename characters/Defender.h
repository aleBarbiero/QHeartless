#ifndef DEFENDER_H
#define DEFENDER_H
#include "Heartless.h"
using namespace std;

class Defender:virtual public Heartless{
    private:
        unsigned int shield;
    public:
        //costruttore
        Defender(unsigned int newHP,string n,unsigned int newDam,unsigned int shield=100);
        //metodi
        string print() const;
        string getType() const;
        unsigned int getHP() const;
        unsigned int getAP() const;
        unsigned int getShield() const;
        void setShield(unsigned int);
        unsigned int defend(unsigned int);
        unsigned int attack();
        Defender* clone() const;
        void xml(QXmlStreamWriter& x)const;
};//Defender
#endif//Defender

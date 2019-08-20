#ifndef NOVASHADOW_H
#define NOVASHADOW_H
#include "NeoShadow.h"
using namespace std;

class NovaShadow: public NeoShadow{
    private:
        unsigned int boostAP;
        unsigned int lossHP;
    public:
        //costruttore
        NovaShadow(unsigned int,string,unsigned int,unsigned int);
        //metodi
        string print() const;
        string getType() const;
        unsigned int attack();
        unsigned int defend(unsigned int);
        void xml(QXmlStreamWriter&)const;
        string getName()const;
        unsigned int getHP() const;
        unsigned int getRemainingHP()const;
        unsigned int getShield()const;
        unsigned int getAP()const;
        unsigned int getLevel()const;
        unsigned int getBoostAP() const;
        unsigned int getLossHP() const;
        NovaShadow* clone() const;
};//NeoShadow
#endif//NovaShadow

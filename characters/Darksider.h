#ifndef DARKSIDER_H
#define DARKSIDER_H
#include "NovaShadow.h"
using namespace std;

class Darksider:public NovaShadow{
    public:
        //costruttore
        Darksider(unsigned int,string,unsigned int,unsigned int/*,unsigned int shi=100*/);
        //metodi
        string print() const;
        string getType() const;
        unsigned int getAP() const;
        unsigned int getShield() const;
        unsigned int getLevel() const;
        unsigned int attack();
        unsigned int defend(unsigned int);
        Darksider* clone() const;
        void xml(QXmlStreamWriter& x)const;
};//Darksider

#endif//Darksider

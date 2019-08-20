#ifndef NEOSHADOW_H
#define NEOSHADOW_H
#include "Heartless.h"
using namespace std;

class NeoShadow:virtual public Heartless{
	private:
        unsigned int AP;
	public:
		//costruttore
        NeoShadow(unsigned int,string,unsigned int,unsigned int);
		//metodi
		string print() const;
		string getType() const;
        string getName()const;
        unsigned int getLevel()const;
        unsigned int getHP() const;
        unsigned int getRemainingHP()const;
        unsigned int getShield()const;
        unsigned int getAP()const;
        unsigned int attack();
        unsigned int defend(unsigned int);
        NeoShadow* clone() const;
        void xml(QXmlStreamWriter&)const;
};//NeoShadow
#endif//NeoShadow

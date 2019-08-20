#ifndef ARMEDDEFENDER_H
#define ARMEDDEFENDER_H
#include "Defender.h"
using namespace std;

class ArmedDefender:public Defender{
	private:
		double boostDef;
	public:
		//costruttore
        ArmedDefender(unsigned int,string,unsigned int,unsigned int=100);
		//metodi
		string print() const;
		string getType() const;
        unsigned int defend(unsigned int);
        double getBoost() const;
        void setBoost(double);
        unsigned int getAP()const;
        unsigned int getShield()const;
        ArmedDefender* clone() const;
        void xml(QXmlStreamWriter& x)const;
};//ArmedDefender
#endif//ArmedDefender

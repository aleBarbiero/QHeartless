#include "ArmedDefender.h"
//costruttore
ArmedDefender::ArmedDefender(unsigned int newHP,string newN,unsigned int newDam,unsigned int shi):Heartless(newHP,newN,newDam),Defender(newHP,newN,newDam,shi){
	boostDef=1.0;
}//ArmedDefender

//metodi
string ArmedDefender::print() const{
	ostringstream os;
	string old=Defender::print();
	os<<"Genere: ArmedDefender, evoluzione di "<<old;
	return os.str();
}//print

string ArmedDefender::getType() const{
	return "ArmedDefender";
}//getType

double ArmedDefender::getBoost() const{
    return boostDef;
}//getBoost

void ArmedDefender::setBoost(double b){
    boostDef=b;
}//setBoost

unsigned int ArmedDefender::getShield()const{
    return Defender::getShield();
}//getShield

unsigned int ArmedDefender::getAP()const{
   return Defender::getAP();
}//getAP

unsigned int ArmedDefender::defend(unsigned int d){
    if(isAlive()){
        d=d*boostDef;
        unsigned int effS=0;
        if(getBoost()>0.1)
            setBoost(getBoost()-0.1);
        if(getShield()!=0){
            effS=(getHP()*getShield())/100;
            effS-=d;
            if(effS<=0)
                setShield(0);
            else
                setShield(effS*100/Heartless::getHP());
        }else
            Heartless::shooted(d);
        return d;
    }else return 0;
}//defend

ArmedDefender* ArmedDefender::clone() const{
    return new ArmedDefender(*this);
}//clone

void ArmedDefender::xml(QXmlStreamWriter& x)const{
    x.writeStartElement(QString::fromStdString("ArmedDefender"));
		Defender::xml(x);
	x.writeEndElement();
}//xml
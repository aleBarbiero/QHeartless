#include "Defender.h"
using namespace std;

Defender::Defender(unsigned int newHP,string newN,unsigned int newDam,unsigned int shi):Heartless(newHP,newN,newDam),shield(shi){
    Heartless::setLevel(newHP/5);
}//Defender

string Defender::print() const{
	ostringstream os;
	string old=Heartless::print();
	os<<"Genere: Defender\n"<<old;
    os<<"Percentuale di scudo: "<<getShield()<<"%\n";
	return os.str();
}//print

unsigned int Defender::getHP() const{
    return Heartless::getHP();
}//getHP

string Defender::getType() const{
	return "Defender";
}//getType

unsigned int Defender::getAP() const{
	return 0;
}//getAtt

unsigned int Defender::getShield() const{
	return shield;
}//getShield

void Defender::setShield(unsigned int s){
    if(s>=0 && s<=100)
        shield=s;
}//setShield

unsigned int Defender::defend(unsigned int d){
    if(isAlive()){
        int effS=0;
        if(shield!=0){
            effS=(Heartless::getHP())*shield/100;
            effS-=d;
            if(effS<=0)
                shield=0;
            else
                shield=((effS*100)/Heartless::getHP());
        }else
            Heartless::shooted(d);
        if(getDam()>getHP())
            Heartless::setDam(getHP());
        return d;
    }else return 0;
}//defend

unsigned int Defender::attack(){
	return 0;
}//attack

Defender* Defender::clone() const{
    return new Defender(*this);
}//clone

void Defender::xml(QXmlStreamWriter& x)const{
    x.writeStartElement(QString::fromStdString("Defender"));
		Heartless::xml(x);
		x.writeStartElement("Percentuale_scudo");
		x.writeCharacters(QString::number(getShield()));
		x.writeEndElement();
	x.writeEndElement();
}//xml

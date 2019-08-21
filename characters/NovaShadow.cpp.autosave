#include "NovaShadow.h"
#include "Heartless.h"
using namespace std;

//costruttore
NovaShadow::NovaShadow(unsigned int newHP,string newN,unsigned int newDam,unsigned int newAP):Heartless(newHP,newN,newDam),NeoShadow(newHP,newN,newDam,newAP){
    boostAP=newAP*2;
    lossHP=Heartless::getHP()/newAP;
    NeoShadow::setLevel(boostAP+newHP/5);
}//NovaShadow

//metodi_virtuali
string NovaShadow::print() const{
	ostringstream os;
	string old=NeoShadow::print();
	os<<"Genere: NovaShadow, evoluzione di "<<old;
    os<<"AP incrementati: "<<getBoostAP()<<"\n";
    os<<"Costo di ogni colpo: "<<getLossHP()<<"HP\n";
	return os.str();
}//print

string NovaShadow::getType() const{
	return "NovaShadow";
}//getType

unsigned int NovaShadow::attack(){
    if(isAlive()){
        NeoShadow::defend(lossHP);
        if(getDam()>getHP())
            Heartless::setDam(getHP());
        return boostAP;
    }else return 0;
}//attack

unsigned int NovaShadow::defend(unsigned int n){
    return NeoShadow::defend(n);
}//defend

unsigned int NovaShadow::getBoostAP() const{
	return boostAP;
}//getBoostAP

unsigned int NovaShadow::getLossHP() const{
	return lossHP;
}//getLossHP

NovaShadow* NovaShadow::clone() const{
    return new NovaShadow(*this);
}//clone

unsigned int NovaShadow::getHP() const{
    return NeoShadow::getHP();
}//getHP

string NovaShadow::getName()const{
    return NeoShadow::getName();
}//getName

unsigned int NovaShadow::getRemainingHP() const{
    return NeoShadow::getRemainingHP();
}//getRemainingHP

unsigned int NovaShadow::getLevel() const{
    return NeoShadow::getLevel();
}//getLevel

unsigned int NovaShadow::getShield()const{
    return NeoShadow::getShield();
}//getShield

unsigned int NovaShadow::getAP()const{
   return NeoShadow::getAP();
}//getAP

void NovaShadow::xml(QXmlStreamWriter& x)const{
    x.writeStartElement(QString::fromStdString("NovaShadow"));
        NeoShadow::Heartless::xml(x);
		x.writeStartElement("AP");
        x.writeCharacters(QString::number(getAP()));
		x.writeEndElement();
	x.writeEndElement();
}//xml

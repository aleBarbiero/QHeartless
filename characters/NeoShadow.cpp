#include "NeoShadow.h"

//costruttore
NeoShadow::NeoShadow(unsigned int newHP,string newName,unsigned int newDam,unsigned int newAP):Heartless(newHP,newName,newDam),AP(newAP){
    Heartless::setLevel(newAP + newHP/5);
}//NeoShadow

//implementazione_metodi_virtuali
string NeoShadow::print() const{
    ostringstream os;
	string old=Heartless::print();
	os<<"Genere: NeoShadow\n"<<old;
	os<<"AP: "<<AP<<"\n";
	return os.str();
}//print

string NeoShadow::getType() const{
	return "NeoShadow";
}//getType

unsigned int NeoShadow::getAP() const{
	return AP;
}//getAP

unsigned int NeoShadow::getShield() const{
	return 0;
}//getShield

unsigned int NeoShadow::getHP() const{
    return Heartless::getHP();
}//getHP

string NeoShadow::getName()const{
    return Heartless::getName();
}//getName

unsigned int NeoShadow::getRemainingHP() const{
    return Heartless::getRemainingHP();
}//getRemainingHP

unsigned int NeoShadow::getLevel() const{
    return Heartless::getLevel();
}//getLevel

unsigned int NeoShadow::attack(){
    if(isAlive()){
       return AP;
    }else return 0;
}//attack

unsigned int NeoShadow::defend(unsigned int d){
    if(isAlive()){
        shooted(d);
        if(getDam()>getHP())
            Heartless::setDam(getHP());
        return d;
    }else return 0;
}//defend

NeoShadow* NeoShadow::clone() const{
    return new NeoShadow(*this);
}//clone

void NeoShadow::xml(QXmlStreamWriter& x)const{
    x.writeStartElement(QString::fromStdString("NeoShadow"));
		Heartless::xml(x);
		x.writeStartElement("AP");
        x.writeCharacters(QString::number(getAP()));
		x.writeEndElement();
	x.writeEndElement();
}//xml


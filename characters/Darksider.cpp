#include "Darksider.h"

//costruttore
Darksider::Darksider(unsigned int newHP,string newN,unsigned int newDam,unsigned int newAP/*,unsigned int shield*/):Heartless(newHP,newN,newDam),NovaShadow(newHP,newN,newDam,newAP)/*,Defender(newHP,newN,newDam,shield)*/{
    Heartless::setLevel((newAP+newHP/5)*2);
}//Darksider

//metodi
string Darksider::print() const{
	ostringstream os;
	string old=NeoShadow::print();
	os<<"Genere: Darksider, evoluzione di Genere: Defender e "<<old;
    os<<"Percentuale di scudo: "<<getShield()<<"%\n";
	return os.str();
}//print

string Darksider::getType() const{
	return "Darksider";
}//getType

unsigned int Darksider::getAP() const{
    return NovaShadow::getAP();
}//getAP

unsigned int Darksider::getShield() const{
    return NovaShadow::getShield();
}//getShield

unsigned int Darksider::getLevel() const{
    return Heartless::getLevel();
}//getLevel

unsigned int Darksider::attack(){
    if(isAlive()){
        if(getRemainingHP()>1){
            Darksider::defend(this->getRemainingHP()-1);
        if(getDam()>getHP())
            Heartless::setDam(getHP());}
        return 1000000;
    }else return 0;
}//attack

unsigned int Darksider::defend(unsigned int d){
    if(isAlive()){
        if(getDam()>getHP())
            Heartless::setDam(getHP());
        return NovaShadow::defend(d);
    }else return 0;
}//defend

Darksider* Darksider::clone() const{
    return new Darksider(*this);
}//clone

void Darksider::xml(QXmlStreamWriter& x)const{
    x.writeStartElement(QString::fromStdString("Darksider"));
		Heartless::xml(x);
		x.writeStartElement("AP");
        x.writeCharacters(QString::number(getAP()));
		x.writeEndElement();
	x.writeEndElement();
}//xml

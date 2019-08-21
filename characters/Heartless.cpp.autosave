#include "Heartless.h"
using namespace std;


Heartless::Heartless(unsigned int h,string n,unsigned int d):hp(h),name(n),damage(d),lev(1){};

//operatori
bool Heartless::operator==(Heartless& n){
    return (n.name==name && n.getLevel()==getLevel());
}//==

bool Heartless::operator!=(Heartless& n){
    return (n.name!=name || n.getLevel()==getLevel());
}//!=

bool Heartless::operator>(Heartless& n){
    return (getLevel()>n.getLevel());
}//>

bool Heartless::operator<(Heartless& n){
    return (getLevel()<n.getLevel());
}//<

bool Heartless::operator>=(Heartless& n){
    return (getLevel()>=n.getLevel());
}//>=

bool Heartless::operator<=(Heartless& n){
    return (getLevel()<=n.getLevel());
}//<=

//metodi
unsigned int Heartless::getRemainingHP() const{
	return (hp-damage);
}//getRemainingHP

unsigned int Heartless::getDam() const{
    return damage;
}//getDam

unsigned int Heartless::getHP() const{
	return hp;
}//getHP

string Heartless::getName() const{
	return name;
}//getName

void Heartless::setName(string newN){
	name=newN;
}//setName

void Heartless::setDam(unsigned int newD){
    damage=newD;
}//setDam

unsigned int Heartless::getLevel() const{
    return lev;
}//getLevel

void Heartless::setLevel(unsigned int n){
    lev=n;
}//setLevel

unsigned int Heartless::getShield()const{
    return 0;
}//getShield

unsigned int Heartless::getAP()const{
   return 0;
}//getAP

string Heartless::print() const{
	ostringstream os;
	os<<"Nome: "<<name<<"\n";
    os<<"Livello: "<<getLevel()<<"\n";
	os<<"MAX HP: "<<hp<<"\n";
    os<<"HP rimanenti: "<<getRemainingHP()<<"\n";
	return os.str();
}//print

bool Heartless::isAlive() const{
    return (getRemainingHP()>0);
}//isAlive

void Heartless::shooted(unsigned int dam){
    damage+=dam;
}//shooted

void Heartless::xml(QXmlStreamWriter &x) const{
	x.writeStartElement("Nome");
    x.writeCharacters(QString::fromStdString(Heartless::getName()));
	x.writeEndElement();
	x.writeStartElement("HP");
    x.writeCharacters(QString::number(Heartless::getHP()));
	x.writeEndElement();
    x.writeStartElement("Danno");
    x.writeCharacters(QString::number(Heartless::getDam()));
    x.writeEndElement();
}//xml

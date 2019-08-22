#include "Model.h"
#include "container/Container.cpp"
#include "container/DeepPtr.cpp"

//costruttore/distruttore
Model::Model(){}//Model

Model::~Model(){
    Q.deleteAll();
}//~Model

//carica/salva
void Model::saveF(const QString& file) const{
    MyXml x;
    x.save(file,Q);
}//save

void Model::loadF(const QString& file){
    MyXml x;
    Q=x.load(file);
}//load

//metodi
void Model::insert(Heartless* el){
    Q.pushLast(el);
}//insert

void Model::remove(Heartless* el){
    Q.deleteThis(el);
}//remove

void Model::remove(int i){
    Q.deletePos(Q.begin()+i);
}//remove_int

int Model::count() const{
    return Q.getSize();
}//count

unsigned int Model::att(unsigned int i){
    return (*(Q.begin() + static_cast<int>(i)))->attack();
}//attack

unsigned int Model::def(unsigned int i,int d){
    return (*(Q.begin()+static_cast<int>(i)))->defend(static_cast<unsigned int>(d));
}//def

bool Model::searchS(int i, const QRegExp& r, const QString& s) const{
    if(s=="Nome")
        return (QString::fromStdString((*(Q.begin()+i))->getName()).contains(r));
    else if(s=="Genere")
            return (QString::fromStdString((*(Q.begin()+i))->getType()).contains(r));
    return false;
}//searchS

bool Model::searchV(int i, double lev, bool major) const{
    if(major){
        if((*(Q.begin()+i))->getLevel()>=lev)
            return true;
    else if((*(Q.begin()+i))->getLevel()<=lev)
            return true;
    }//if_else
    return false;
}//searchV

Container<DeepPtr<Heartless>> Model::getQ()const{
    return Q;
}//getQ


#ifndef MODEL_H
#define MODEL_H

#include "container/Container.h"
#include "container/DeepPtr.h"
#include "characters/Heartless.h"
#include "characters/NeoShadow.h"
#include "characters/NovaShadow.h"
#include "characters/Defender.h"
#include "characters/ArmedDefender.h"
#include "characters/Darksider.h"
#include "Myxml.h"
#include <QString>
#include <QRegExp>
using namespace std;

class Model{
    private:
        Container<DeepPtr<Heartless>> Q;
    public:
        //costruttore/distruttore
        Model();
        ~Model();
        //carica/salva
        void saveF(const QString&) const;
        void loadF(const QString&);
        //metodi
        void insert(Heartless*);
        void remove(Heartless*);
        void remove(int i);
        int count() const;
        unsigned int att(unsigned int);
        unsigned int def(unsigned int,int);
        bool searchV(int,double,bool) const;
        bool searchS(int i,const QRegExp&,const QString&) const;
        Heartless& getHeartless(int,string);
        int getIName(string,int) const;
        int getIType(string, int) const;
        Container<DeepPtr<Heartless>> getQ() const;
};//Model

#endif // MODEL_H

#ifndef MYXML_H
#define MYXML_H

#include "container/Container.h"
#include "container/DeepPtr.h"
#include "characters/Heartless.h"
#include "characters/NeoShadow.h"
#include "characters/NovaShadow.h"
#include "characters/Defender.h"
#include "characters/ArmedDefender.h"
#include "characters/Darksider.h"

#include <QFile>
#include <QSaveFile>
#include <QString>

class MyXml{
    public:
        //costruttore/distruttore
        MyXml()=default;
        ~MyXml()=default;
        //metodi
        Container<DeepPtr<Heartless>> load(const QString&) const;
        void save(const QString&,const Container<DeepPtr<Heartless>>&) const;
};//myXml

#endif // MYXML_H

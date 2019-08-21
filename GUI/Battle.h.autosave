#ifndef BATTLE_H
#define BATTLE_H

#include "Model.h"
#include "Insert.h"
#include "../characters/Heartless.h"
#include "../characters/NeoShadow.h"
#include "../characters/NovaShadow.h"
#include "../characters/Defender.h"
#include "../characters/ArmedDefender.h"
#include "../characters/Darksider.h"
#include "MyXml.h"
#include <QWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QString>
#include <QPushButton>
#include <QTableWidget>
#include <QMessageBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>

class Battle:public QWidget{
    Q_OBJECT
    private:
        //elementi_Qt_att
        QVBoxLayout* listinoAtt;
        QTableWidget* tabAtt;
        //elementi_Qt_def
        QVBoxLayout* listinoDef;
        QTableWidget* tabDef;
        //altro
        QPushButton* go;
    public:
        //costruttore
        Battle(QWidget* =nullptr);
        //accessori
        QPushButton* getGoB() const;
        int getIndexAtt() const;
        int getIndexDef() const;
        //aggiornamento_tabelle
        void refreshTabAtt(Model*);
        void refreshTabDef(Model*);
};//removeL

#endif // BATTLE_H

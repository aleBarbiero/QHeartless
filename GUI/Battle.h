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
#include "Myxml.h"
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
        //QHBoxLayout* insertSearchAtt;
        //QPushButton* findBAtt;
        QVBoxLayout* listinoAtt;
        QTableWidget* tabAtt;
        //QLineEdit* searchVAtt;
        //QComboBox* searchForAtt;
        //QList<int> indexAtt;
        //elementi_Qt_def
        //QHBoxLayout* insertSearchDef;
        //QPushButton* findBDef;
        QVBoxLayout* listinoDef;
        QTableWidget* tabDef;
        //QLineEdit* searchVDef;
        //QComboBox* searchForDef;
        //QList<int> indexDef;
        //altro
        QPushButton* go;
    public:
        //costruttore
        Battle(QWidget* =nullptr);
        //accessori
        //QPushButton* getFindBAtt() const;
        //QPushButton* getFindBDef() const;
        QPushButton* getGoB() const;
        void refreshTabAtt(Model*);
        void refreshTabDef(Model*);
        int getIndexAtt() const;
        int getIndexDef() const;
        //QString getSearchAtt() const;
        //QString getSearchDef() const;
};//removeL

#endif // BATTLE_H

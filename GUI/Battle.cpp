#include "Battle.h"
#include <QFormLayout>
#include <QHeaderView>
#include <QLabel>
#include <QIntValidator>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QPixmap>

Battle::Battle(QWidget* q):
    QWidget(q),
    go(new QPushButton("ATTACCA!")){
    //attack
        QLabel* labAtt=new QLabel("Scegli l'attaccante:");
        QLabel* labDef=new QLabel("Scegli il difensore:");
        QVBoxLayout* mainL=new QVBoxLayout(this);
        listinoAtt=new QVBoxLayout();
            //tabella
        tabAtt=new QTableWidget(0,7,this);
        QStringList datiAtt("Genere");
        datiAtt.append("Nome");
        datiAtt.append("Livello");
        datiAtt.append("HP");
        datiAtt.append("HP rimasti");
        datiAtt.append("AP");
        datiAtt.append("% Scudo");
        for(int i=0;i<7;i++)
            tabAtt->setColumnWidth(i,140);
        tabAtt->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tabAtt->setHorizontalHeaderLabels(datiAtt);
        tabAtt->verticalHeader()->setVisible(false);
        tabAtt->setSelectionBehavior(QAbstractItemView::SelectRows);
        listinoAtt->setAlignment(Qt::AlignLeft);
        listinoAtt->addWidget(labAtt);
        listinoAtt->addWidget(tabAtt);
    //defense
        listinoDef=new QVBoxLayout();
            //tabella
        tabDef=new QTableWidget(0,7,this);
        QStringList datiDef("Genere");
        datiDef.append("Nome");
        datiDef.append("Livello");
        datiDef.append("HP");
        datiDef.append("HP rimasti");
        datiDef.append("AP");
        datiDef.append("% Scudo");
        for(int i=0;i<7;i++)
            tabDef->setColumnWidth(i,140);
        tabDef->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tabDef->setHorizontalHeaderLabels(datiDef);
        tabDef->verticalHeader()->setVisible(false);
        tabDef->setSelectionBehavior(QAbstractItemView::SelectRows);
        listinoDef->addWidget(labDef);
        listinoDef->addWidget(tabDef);
            //layout
        mainL->addLayout(listinoAtt);
        mainL->addLayout(listinoDef);
        mainL->addWidget(go);
}//remove

QPushButton* Battle::getGoB() const{
    return go;
}//getGoB

int Battle::getIndexAtt() const{
    return tabAtt->currentRow();
}//getIndex

int Battle::getIndexDef() const{
    return tabDef->currentRow();
}//getIndex

void Battle::refreshTabAtt(Model* modello){
    tabAtt->setRowCount(0);
    for(int i=0;i<modello->count();i++){
        QTableWidgetItem* type=new QTableWidgetItem(QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getType())));
        QTableWidgetItem* name=new QTableWidgetItem(QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getName())));
        QTableWidgetItem* level=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getLevel())));
        QTableWidgetItem* HP=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getHP())));
        QTableWidgetItem* dam=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getRemainingHP())));
        QTableWidgetItem* AP=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getAP())));
        QTableWidgetItem* shield=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getShield())));
        tabAtt->insertRow(i);
        tabAtt->setItem(i,0,type);
        tabAtt->setItem(i,1,name);
        tabAtt->setItem(i,2,level);
        tabAtt->setItem(i,3,HP);
        tabAtt->setItem(i,4,dam);
        tabAtt->setItem(i,5,AP);
        tabAtt->setItem(i,6,shield);
    }//for
}//refreshTab

void Battle::refreshTabDef(Model* modello){
    tabDef->setRowCount(0);
    for(int i=0;i<modello->count();i++){
        QTableWidgetItem* type=new QTableWidgetItem(QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getType())));
        QTableWidgetItem* name=new QTableWidgetItem(QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getName())));
        QTableWidgetItem* level=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getLevel())));
        QTableWidgetItem* HP=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getHP())));
        QTableWidgetItem* dam=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getRemainingHP())));
        QTableWidgetItem* AP=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getAP())));
        QTableWidgetItem* shield=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getShield())));
        tabDef->insertRow(i);
        tabDef->setItem(i,0,type);
        tabDef->setItem(i,1,name);
        tabDef->setItem(i,2,level);
        tabDef->setItem(i,3,HP);
        tabDef->setItem(i,4,dam);
        tabDef->setItem(i,5,AP);
        tabDef->setItem(i,6,shield);
    }//for
}//refreshTab

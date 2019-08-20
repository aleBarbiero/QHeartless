#include "Listino.h"
#include <QFormLayout>
#include <QHeaderView>
#include <QLabel>
#include <QMessageBox>

Listino::Listino(QWidget* q):
    QWidget(q),
    del(new QPushButton("Elimina")){
        QVBoxLayout* mainL=new QVBoxLayout(this);
        list=new QVBoxLayout();
        //tabella
        tab=new QTableWidget(0,7,this);
        QStringList dati("Genere");
        dati.append("Nome");
        dati.append("Livello");
        dati.append("HP totali");
        dati.append("HP rimasti");
        dati.append("AP");
        dati.append("% Scudo");
        tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tab->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tab->setHorizontalHeaderLabels(dati);
        tab->verticalHeader()->setVisible(false);
        tab->setSelectionBehavior(QAbstractItemView::SelectRows);
        tab->setSelectionMode(QAbstractItemView::SingleSelection);
        list->setAlignment(Qt::AlignTop);
        list->addWidget(tab);
        list->addWidget(del);
        //layout
        mainL->addLayout(list);
}//remove


int Listino::getIndex() const{
    return tab->currentRow();
}//getIndex

QPushButton* Listino::getDelB() const{
    return del;
}//getDelB

void Listino::fullTab(Model* modello){
    tab->setRowCount(0);
    for(int i=0;i<modello->count();i++){
        QTableWidgetItem* type=new QTableWidgetItem(QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getType())));
        QTableWidgetItem* name=new QTableWidgetItem(QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getName())));
        QTableWidgetItem* level=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getLevel())));
        QTableWidgetItem* HP=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getHP())));
        QTableWidgetItem* dam=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getRemainingHP())));
        QTableWidgetItem* AP=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getAP())));
        QTableWidgetItem* shield=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getShield())));
        tab->insertRow(i);
        tab->setItem(i,0,type);
        tab->setItem(i,1,name);
        tab->setItem(i,2,level);
        tab->setItem(i,3,HP);
        tab->setItem(i,4,dam);
        tab->setItem(i,5,AP);
        tab->setItem(i,6,shield);
    }//for
}//fullTab

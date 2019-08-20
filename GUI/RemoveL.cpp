#include "RemoveL.h"
#include <QFormLayout>
#include <QHeaderView>
#include <QLabel>
#include <QIntValidator>
#include <QMessageBox>

RemoveL::RemoveL(QWidget* q):
    QWidget(q),
    searchFor(new QComboBox(this)),
    searchV(new QLineEdit(this)),
    find(new QPushButton("Cerca")),
    del(new QPushButton("Elimina")),
    //ok(new QPushButton("Conferma")),
    //ann(new QPushButton("Annulla")),
    msg(new QMessageBox()){
        QVBoxLayout* mainL=new QVBoxLayout(this);
        insertSearch=new QHBoxLayout();
        listino=new QVBoxLayout();
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
        listino->setAlignment(Qt::AlignTop);
        listino->addWidget(tab);
        listino->addWidget(del);
        //ricerca
        searchFor->addItem("Genere");
        searchFor->addItem("Nome");
        insertSearch->setAlignment(Qt::AlignTop);
        insertSearch->addWidget(searchFor);
        insertSearch->addWidget(searchV);
        insertSearch->addWidget(find);
        //layout
        mainL->addLayout(insertSearch);
        mainL->addLayout(listino);
}//remove

QPushButton* RemoveL::getFindB() const{
    return find;
}//getSearchB

QPushButton* RemoveL::getDelB() const{
    return del;
}//getDelB

QString RemoveL::getSearch() const{
    return searchV->text();
}//getSearch

int RemoveL::getIndex() const{
    return index[tab->currentRow()];
}//getIndex

void RemoveL::refreshTab(Model* modello){
    tab->setRowCount(0);
    index.clear();
    if(searchFor->currentIndex()==0){//ricerca_per_tipo
        QString* sType=new QString(searchV->text());
        int i=0,j=0;
        while(i<modello->count()){
            if((QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getType()))).contains(sType,Qt::CaseInsensitive)){
                QTableWidgetItem* type=new QTableWidgetItem(QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getType())));
                QTableWidgetItem* name=new QTableWidgetItem(QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getName())));
                QTableWidgetItem* level=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getLevel())));
                QTableWidgetItem* HP=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getHP())));
                QTableWidgetItem* dam=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getRemainingHP())));
                QTableWidgetItem* AP=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getAP())));
                QTableWidgetItem* shield=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getShield())));
                tab->insertRow(j);
                tab->setItem(j,0,type);
                tab->setItem(j,1,name);
                tab->setItem(j,2,level);
                tab->setItem(j,3,HP);
                tab->setItem(j,4,dam);
                tab->setItem(j,5,AP);
                tab->setItem(j,6,shield);
                index.append(i);
                j++;
            }//if
            i++;
        }//while
    }else if(searchFor->currentIndex()==1){
        QString* sName=new QString(searchV->text());
        int i=0,j=0;
        while(i<modello->count()){
            if((QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getName()))).contains(sName,Qt::CaseInsensitive)){
                QTableWidgetItem* type=new QTableWidgetItem(QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getType())));
                QTableWidgetItem* name=new QTableWidgetItem(QString(QString::fromStdString((((*modello).getQ().begin()+i))->getT().getName())));
                QTableWidgetItem* level=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getLevel())));
                QTableWidgetItem* HP=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getHP())));
                QTableWidgetItem* dam=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getRemainingHP())));
                QTableWidgetItem* AP=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getAP())));
                QTableWidgetItem* shield=new QTableWidgetItem(QString(QString::number((((*modello).getQ().begin()+i))->getT().getShield())));
                tab->insertRow(j);
                tab->setItem(j,0,type);
                tab->setItem(j,1,name);
                tab->setItem(j,2,level);
                tab->setItem(j,3,HP);
                tab->setItem(j,4,dam);
                tab->setItem(j,5,AP);
                tab->setItem(j,6,shield);
                index.append(i);
                j++;
            }//if
            i++;
        }//while
    }//if_else
}//refreshTab

void RemoveL::fullTab(Model* modello){
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



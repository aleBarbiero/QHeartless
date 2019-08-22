#include "Mymainwindow.h"
#include "characters/Heartless.h"
#include "characters/NeoShadow.h"
#include "characters/NovaShadow.h"
#include "characters/Defender.h"
#include "characters/ArmedDefender.h"
#include "characters/Darksider.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>
#include <QCloseEvent>
#include <QLayout>

MyMainWindow::MyMainWindow(QWidget* Q):QWidget(),file(":/qheartless.xml"){
    modello=new Model();
    main=new QVBoxLayout(this);
    menu=new QMenuBar();
    ind=new Index(this);
    ins=new Insert(this);
    search=new RemoveL(this);
    batt=new Battle(this);
    list=new Listino(this);
    //window
    move(QApplication::desktop()->screen()->rect().center()-rect().center());
    setWindowTitle("QHeartless - Alessio Barbiero");
    setWindowIcon(QIcon(":/icon/logo.png"));
    setFixedSize(QSize(1000,600));
    //elementi_menu_bar
    QMenu* fileM=new QMenu("File",menu);
    QAction* indexM=new QAction("Home", menu);
    QAction* insertM=new QAction("Inserisci", menu);
    QAction* removeM=new QAction("Cerca/Rimuovi",menu);
    QAction* battleM=new QAction("Battaglia",menu);
    QAction* listinoM=new QAction("Listino",menu);
    QAction* saveM=new QAction("Salva", fileM);
    QAction* loadM=new QAction("Carica", fileM);
    //azioni_menu_bar
    fileM->addAction(saveM);
    fileM->addAction(loadM);
    menu->addMenu(fileM);
    menu->addAction(indexM);
    menu->addAction(insertM);
    menu->addAction(removeM);
    menu->addAction(battleM);
    menu->addAction(listinoM);
    //home
    main->setMenuBar(menu);
    main->addWidget(ind);
    main->addWidget(ins);
    main->addWidget(search);
    main->addWidget(batt);
    main->addWidget(list);
    indexSet();
    setLayout(main);
    //connect
    connect(saveM,SIGNAL(triggered()),this,SLOT(save()));
    connect(loadM,SIGNAL(triggered()),this,SLOT(load()));
    connect(indexM,SIGNAL(triggered()),this,SLOT(indexSet()));
    connect(insertM,SIGNAL(triggered()),this,SLOT(insertSet()));
    connect(removeM,SIGNAL(triggered()),this,SLOT(removeSet()));
    connect(battleM,SIGNAL(triggered()),this,SLOT(battleSet()));
    connect(listinoM,SIGNAL(triggered()),this,SLOT(listinoSet()));
    connect(batt->getGoB(),SIGNAL(clicked()),this,SLOT(battleNow()));
    connect(ins->getAdd(),SIGNAL(clicked()),this,SLOT(addEl()));
    connect(search->getFindB(),SIGNAL(clicked()),this,SLOT(searchEl()));
    connect(search->getDelB(),SIGNAL(clicked()),this,SLOT(delEl()));
    connect(list->getDelB(),SIGNAL(clicked()),this,SLOT(delEl()));
}//MainWindow

void MyMainWindow::indexSet() const{
    main->setAlignment(Qt::AlignCenter);
    ins->hide();
    search->hide();
    batt->hide();
    list->hide();
    ind->show();
}//indexSet

void MyMainWindow::insertSet() const{
    main->setAlignment(Qt::AlignCenter);
    ind->hide();
    search->hide();
    batt->hide();
    list->hide();
    ins->show();
}//insertSet

void MyMainWindow::removeSet() const{
    main->setAlignment(Qt::AlignCenter);
    ind->hide();
    ins->hide();
    batt->hide();
    list->hide();
    search->show();
    search->fullTab(modello);
    search->setIndex(modello);
}//insertSet

void MyMainWindow::battleSet() const{
    main->setAlignment(Qt::AlignCenter);
    ind->hide();
    ins->hide();
    search->hide();
    list->hide();
    batt->show();
    batt->refreshTabAtt(modello);
    batt->refreshTabDef(modello);
}//battleSet

void MyMainWindow::listinoSet()const{
    main->setAlignment(Qt::AlignCenter);
    ind->hide();
    ins->hide();
    batt->hide();
    search->hide();
    list->show();
    list->fullTab(modello);
}//listSet

void MyMainWindow::load(){
    file=(QFileDialog::getOpenFileName(this,"Carica","","Documento XML (*.xml);;All Files (*)"));
    modello->loadF(file);
    search->fullTab(modello);
    search->setIndex(modello);
    batt->refreshTabAtt(modello);
    batt->refreshTabDef(modello);
    list->fullTab(modello);
}//load

void MyMainWindow::save(){
    file=QFileDialog::getSaveFileName(this,"Seleziona un file .xml","","XML (*.xml)");
    modello->saveF(file);
}//save

void MyMainWindow::closeEvent(QCloseEvent* x){
    QMessageBox::StandardButton exit=QMessageBox::question(this,"QHeartless","Salvare le modifiche prima di uscire?",QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,QMessageBox::Yes);
    if(exit==QMessageBox::No)
        x->accept();
    else if(exit==QMessageBox::Cancel)
            x->ignore();
         else{
            MyMainWindow::save();
            x->accept();
    }//if_else
}//close

void MyMainWindow::addEl(){
    string type=ins->getType();
    if(ins->getName()==""){
        QMessageBox msg;
        msg.critical(nullptr,"Errore","Inserisci un nome valido");
        msg.setFixedSize(500,200);
        return;
    }//if
    if(ins->getHP()<=0 || ins->getHP()>10000){
        QMessageBox msg;
        msg.critical(nullptr,"Errore","Il valore degli HP deve essere compreso tra 1 e 10.000");
        msg.setFixedSize(500,200);
        return;
    }//if
    if((type=="NeoShadow" || type=="NovaShadow" || type=="Darksider")&& (ins->getAP()<=0 || ins->getAP()>100)){
        QMessageBox msg;
        msg.critical(nullptr,"Errore","Il valore degli AP deve essere compreso tra 1 e 100");
        msg.setFixedSize(500,200);
        return;
    }//if
    if((type=="Defender" || type=="ArmedDefender")&& (ins->getShield()<=0 || ins->getShield()>100)){
        QMessageBox msg;
        msg.critical(nullptr,"Errore","Il valore dello scudo deve essere compreso tra 0 e 100");
        msg.setFixedSize(500,200);
        return;
    }//if
    string newname=ins->getName();
    unsigned int newhp=ins->getHP();
    if(type=="NeoShadow")
        modello->insert(new NeoShadow(newhp,newname,0,ins->getAP()));
    if(type=="NovaShadow")
        modello->insert(new NovaShadow(newhp,newname,0,ins->getAP()));
    if(type=="Defender")
        modello->insert(new Defender(newhp,newname,0,ins->getShield()));
    if(type=="ArmedDefender")
        modello->insert(new ArmedDefender(newhp,newname,0,ins->getShield()));
     if(type=="Darksider")
        modello->insert(new Darksider(newhp,newname,0,ins->getAP()));
    ins->delElement();
    list->fullTab(modello);
    search->fullTab(modello);
    batt->refreshTabAtt(modello);
    batt->refreshTabDef(modello);
    search->setIndex(modello);
}//addEl

void MyMainWindow::searchEl(){
    search->refreshTab(modello);
}//searchEl

void MyMainWindow::delEl(){
    if(sender()==list->getDelB() && list->getIndex()!=-1){//richiamata_da_listino
        modello->remove(list->getIndex());
        list->fullTab(modello);
    }else if(sender()==search->getDelB() && search->getIndex()!=-1){//richiamato_da_ricerca(cambia_il_calcolo_dell'indice)
        modello->remove(search->getIndex());
        search->refreshTab(modello);
    }//if_else
    search->setIndex(modello);
}//delEL

void MyMainWindow::battleNow(){
    if(batt->getIndexAtt()!=batt->getIndexDef()){
        if(batt->getIndexAtt()!=-1 && batt->getIndexDef()!=-1){
            unsigned int iA=static_cast<unsigned int>(batt->getIndexAtt());
            unsigned int iD=static_cast<unsigned int>(batt->getIndexDef());
            unsigned int d=modello->att(iA);
            modello->def(iD,static_cast<int>(d));
            batt->refreshTabAtt(modello);
            batt->refreshTabDef(modello);
        }else{
            QMessageBox msg;
            msg.critical(nullptr,"Errore","Seleziona entrambi i personaggi!");
            msg.setFixedSize(500,200);
            return;
        }//if_else_internal
    }else{
        QMessageBox msg;
        msg.critical(nullptr,"Errore","Non puoi attaccare e difendere con lo stesso personaggio!");
        msg.setFixedSize(500,300);
        return;
    }
}//battleNow


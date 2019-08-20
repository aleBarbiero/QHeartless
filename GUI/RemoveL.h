#ifndef REMOVE_H
#define REMOVE_H

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

class RemoveL:public QWidget{
    Q_OBJECT
    private:
        //elementi_Qt
        QHBoxLayout* insertSearch;
        QVBoxLayout* listino;
        QTableWidget* tab;
        QLineEdit* searchV;
        QComboBox* searchFor;
        QPushButton* find;
        QPushButton* del;
        QMessageBox* msg;
        //ricerca
        QList<int> index;
    public:
        //costruttore
        RemoveL(QWidget* =nullptr);
        //accessori
        QPushButton* getFindB() const;
        QPushButton* getDelB() const;
        QString getSearch() const;
        int getIndex() const;
        void refreshTab(Model*);
        void fullTab(Model*);
};//removeL

#endif // REMOVE_H

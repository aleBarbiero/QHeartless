#ifndef LISTINO_H
#define LISTINO_H

#include "Model.h"
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

class Listino:public QWidget{
    Q_OBJECT
    private:
        //elementi_Qt
        QVBoxLayout* list;
        QTableWidget* tab;
        QPushButton* del;
    public:
        //costruttore
        Listino(QWidget* =nullptr);
        //accessori
        QPushButton* getDelB() const;
        int getIndex() const;
        void fullTab(Model*);
        void cancelElement(Model*);
};

#endif // LISTINO_H

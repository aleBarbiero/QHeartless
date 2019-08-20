#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GUI/Insert.h"
#include "GUI/Index.h"
#include "GUI/RemoveL.h"
#include "GUI/Battle.h"
#include "GUI/Model.h"
#include "GUI/Listino.h"
#include <QMainWindow>
#include <QWidget>
#include <QMenuBar>
#include <QCloseEvent>
#include <QLayout>

class MyMainWindow:public QWidget{
    Q_OBJECT
    private:
        Model* modello;
        QMenuBar* menu;
        QVBoxLayout* main;
        QString file;
        Index* ind;
        Insert* ins;
        RemoveL* search;
        Battle* batt;
        Listino* list;
        virtual void closeEvent(QCloseEvent*) override;
    public:
        //costruttore/distruttore
        explicit MyMainWindow(QWidget* =nullptr);
        ~MyMainWindow()=default;
    public slots:
        void indexSet() const;
        void insertSet() const;
        void removeSet() const;
        void battleSet() const;
        void listinoSet() const;
        void addEl();
        void delEl();
        void searchEl();
        void save();
        void load();
        void battleNow();
    signals:
        void refresh();
};//mainWindow

#endif // MAINWINDOW_H

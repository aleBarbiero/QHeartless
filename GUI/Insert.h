#ifndef INSERT_H
#define INSERT_H

#include <QWidget>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QString>
using namespace std;

class Insert:public QWidget{
    Q_OBJECT
    private:
        QFormLayout* qfl;
        QGroupBox* qgb;
        QHBoxLayout* img;
        QHBoxLayout* button;
        //etichette
        QLabel* typeL;
        QLabel* nameL;
        QLabel* hpL;
        QLabel* apL;
        QLabel* shieldL;
        //QLabel* levL;
        //acquisizione_valori
        QComboBox* typeValue;
        QLineEdit* nameValue;
        QLineEdit* hpValue;
        QLineEdit* apValue;
        QLineEdit* shieldValue;
        //QLineEdit* levValue;
        QLabel* imgL;
        //bottoni
        QPushButton* add;
        QPushButton* del;
    public:
        //costruttore
        Insert(QWidget* =nullptr);
        //accessori
        string getType() const;
        string getName() const;
        unsigned int getHP() const;
        unsigned int getAP() const;
        unsigned int getShield() const;
        //unsigned int getLevel() const;
        QPushButton* getAdd() const;
        QPushButton* getDel() const;
        //modificatori
        void setType(QString);
        void setName(QString);
        void setHP(QString);
        void setAP(QString);
        void setShield(QString);
        //void setLevel(QString);
    public slots:
        void modify(QString);
        void delElement() const;
        void delForm() const;
};//insert

#endif // INSERT_H

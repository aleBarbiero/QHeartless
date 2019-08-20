#include "Mymainwindow.h"
#include "GUI/Model.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MyMainWindow w;
    w.show();
    QFile File(":/GUI/style.qss");
    File.open(QFile::ReadOnly);
    QString ss = QLatin1String(File.readAll());
    qApp->setStyleSheet(ss);
    return a.exec();
}//main

#include "MyXml.h"
#include "container/Container.cpp"
#include "container/DeepPtr.cpp"

void MyXml::save(const QString& name, const Container<DeepPtr<Heartless>>& cont) const{
    QSaveFile saveF(name);
    saveF.setFileName(name);
    if(saveF.open(QIODevice::WriteOnly)){
        QXmlStreamWriter streamW(&saveF);
        streamW.setAutoFormatting(true);
        streamW.writeStartDocument();
        streamW.writeStartElement(QString::fromStdString("Heartless"));
        //variabile_tipo_auto_definito_C++11
        for(auto el=cont.begin();el!=cont.end();++el){
            (*el)->xml(streamW);
        }//for
        streamW.writeEndElement();
        streamW.writeEndDocument();
        saveF.commit();
    }//if
}//save

Container<DeepPtr<Heartless>> MyXml::load(const QString& file) const{
    Container<DeepPtr<Heartless>> temp;
    QFile saveFile(file);
    if(saveFile.open(QIODevice::ReadOnly)){//1
      QXmlStreamReader read(&saveFile);
      if(read.readNextStartElement() && read.name()=="Heartless"){//2
        while(read.readNextStartElement()){
          QStringRef type=read.name();
          read.readNextStartElement();
          std::string name=read.readElementText().toStdString();
          read.readNextStartElement();
          unsigned int hp=read.readElementText().toInt();
          read.readNextStartElement();
          unsigned int dam=read.readElementText().toInt();
          if (type==QString::fromStdString("Defender")){
            read.readNextStartElement();
            unsigned int shield=read.readElementText().toInt();
            Defender def(hp,name,dam,shield);
            temp.pushLast(&def);
          }else if(type==QString::fromStdString("NeoShadow")){
                    read.readNextStartElement();
                    unsigned int ap=read.readElementText().toInt();
                    NeoShadow neo(hp,name,dam,ap);
                    temp.pushLast(&neo);
                  }else if(type == QString::fromStdString("NovaShadow")){
                            read.readNextStartElement();
                            unsigned int ap=read.readElementText().toInt();
                            NovaShadow nova(hp,name,dam,ap);
                            temp.pushLast(&nova);
                         }else if(type==QString::fromStdString("ArmedDefender")){
                                   read.readNextStartElement();
                                   unsigned int shield=read.readElementText().toInt();
                                   ArmedDefender armd(hp,name,dam,shield);
                                   temp.pushLast(&armd);
                               }else if(type==QString::fromStdString("Darksider")){
                                       read.readNextStartElement();
                                       unsigned int ap=read.readElementText().toInt();
                                       Darksider drk(hp,name,dam,ap);
                                       temp.pushLast(&drk);
                                }//internal_if_else
                read.skipCurrentElement();
            }//while
        }//external_if_2
    }//external_if_1
    saveFile.close();
    return temp;
}//load

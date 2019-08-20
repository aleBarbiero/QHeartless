#ifndef HEARTLESS_H
#define HEARTLESS_H

#include <sstream>
#include <QXmlStreamWriter>
using namespace std;

class Heartless{
	private:
        unsigned int hp;
        string name;
        unsigned int damage;
        unsigned int lev;
	public:
        //costruttori/distruttore
        //Heartless();
        Heartless(unsigned int=0,string="",unsigned int=0);
        Heartless(const Heartless&)=default;
        virtual ~Heartless()=default;
		
		//operatori
        virtual Heartless& operator=(const Heartless&)=default;
		bool operator==(Heartless&);
		bool operator!=(Heartless&);
		bool operator>(Heartless&);
		bool operator<(Heartless&);
		bool operator>=(Heartless&);
		bool operator<=(Heartless&);
		
		//metodi_accessori_e_modificatori
        unsigned int getRemainingHP() const;//vita_rimanente
        unsigned int getHP() const;//vita_totale
        string getName() const;//nome
        void setName(string newName);//modifica_nome
        void setDam(unsigned int);
        unsigned int getDam()const;
        virtual string print() const;//stampa_descrizione
        virtual string getType() const=0;//tipo
		
        //altri_metodi
		bool isAlive() const;//controlla_se_HP>0
        void shooted(unsigned int dam);
        virtual Heartless* clone() const=0;//clona_l'oggetto_corrente
        virtual unsigned int getAP() const;//valore_attacco
        virtual unsigned int getShield() const;//valore_scudo
        virtual unsigned int attack()=0;//attacca
        virtual unsigned int defend(unsigned int)=0;//difenditi
        unsigned int getLevel() const;//livello_del_personaggio
        void setLevel(unsigned int l);//modifica_livello
		//XML
        virtual void xml(QXmlStreamWriter&)const;
};//Heartless

#endif//Heartless

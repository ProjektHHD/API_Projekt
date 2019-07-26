#include <iostream>	
#include <iomanip>
using namespace std;

bool aktionstag=false;
double rabatt(double eingabe)		//Funktion fuer Rabattaktionen
{
	if(aktionstag==true)
	{return 0.8*eingabe;}
	else
	{return eingabe;}
}
/*
   Die Funktion "rabatt" bestimmt den tatsächlichen Preis eines Angebotes, je nachdem, ob zur Zeit eine Rabattaktion laeuft oder nicht.
   Der Eingabeparameter ist ein double-Wert, der den Preis einer Speise bestimmt, wenn keine Rabbataktion laeuft.
   Der Ausgabeparameter ist ein double-Wert, der den aktuellen Preis bestimmt.
   Wenn eine Rabbataktion laeuft, ist der bool-Wert "aktionstag" wahr. In dem Fall wird der Eingabewert mit 0.8 multipliziert und ausgegeben.
   Wenn keine Rabbataktion laeuft, ist "aktionstag" falsch. In diesem Fall wird einfach der Eingabewert ausgegeben.
*/

class essen			// Klassendeklaration
{
	private:
	char name[100]={0};
	double preis=0;
	public:
	char* nameEin(void);
	char* nameAus(void);
	double preisEin(void);
	double preisAus(void);
};
//Funktionsdeklaration
char* essen::nameEin(void)		//Eingabe eines neuen Namens
{
	cout << "Bitte geben Sie den neuen Namen ein." << endl;
	cin >> name;
}

char* essen::nameAus(void)		//Ausgabe des Namens
{
	return name;
}

double essen::preisEin(void)	//Eingabe eines neuen Preises
{
	cout << "Bitte geben Sie den neuen Preis ein." << endl;
	cin >> preis;
}

double essen::preisAus(void)	//Ausgabe des Preises
{
	return rabatt(preis); 
}

int main()														// Anfang des Hauptprogramms			
{
	char passwort[100]={"passwort"}, passworteingabe[100];   	//Deklaration der Passwortsvariablen
	bool passwortrichtig=true;
	int eingabe, auswahl, auswahl2, auswahl3;
	essen essen1, essen2, essen3, essen4, essen5;
	do
	{
		passwortrichtig=true;
		cout << "Bitte geben Sie das Passwort ein." << endl;			//Passwortsabfrage
		cout << "(Das Passwort lautet " << passwort << ")" << endl;		//<- Diese Zeile ist nur dafuer da, dass Sie mein Programm verwenden koennen. In
		cin >> passworteingabe;											//   dem eigentlichen Programm, wuerde sie natuerlich geloescht werden.
		for(int i=0; passworteingabe[i]!=0 || passwort[i]!=0; i++)
		{
			if(passwort[i]!=passworteingabe[i])
			{
				passwortrichtig=false;
			}
		}
		if(passwortrichtig==false)
		{cout << "Das Passwort ist nicht korrekt." << endl;}
	}
	while(passwortrichtig==false);

	do
	{
		cout << "Was wollen Sie tun?" << endl;
		cout << "(1) Menue anzeigen\n(2) Menue bearbeiten\n(3) Passwort aendern\n(4) Aktionstag einstellen\n(5) Beenden" << endl;			
		cin >> eingabe;
		if(eingabe==1)
		{
				cout << endl << "Preis       Name" << endl;
			cout << fixed << setprecision(2) << essen1.preisAus() << "Euro    " << essen1.nameAus() << endl;	//Ausgabe des Menues
			cout << fixed << setprecision(2) << essen2.preisAus() << "Euro    " << essen2.nameAus() << endl;
			cout << fixed << setprecision(2) << essen3.preisAus() << "Euro    " << essen3.nameAus() << endl;
			cout << fixed << setprecision(2) << essen4.preisAus() << "Euro    " << essen4.nameAus() << endl;
			cout << fixed << setprecision(2) << essen5.preisAus() << "Euro    " << essen5.nameAus() << endl;
			cout << endl;
		}
		else if(eingabe==2)																																										
		{
			do
			{
				cout << "Was moechten Sie bearbeiten?" << endl << "(1) Name\n(2) Preis\n(3) Zurueck\n";			//Name oder Preis auswaehlen
				cin >> auswahl;
				if(auswahl==1)
				{
					cout << "Welchen Namen moechten Sie aendern?" << endl;			//Namen bearbeiten
					cin >> auswahl2;												//Auswahl des zu bearbeitenden Namen
					if(auswahl2==1)
					{essen1.nameEin();}
					else if(auswahl2==2)
					{essen2.nameEin();}
					else if(auswahl2==3)
					{essen3.nameEin();}
					else if(auswahl2==4)
					{essen4.nameEin();}
					else if(auswahl2==5)
					{essen5.nameEin();}
				}
				else if(auswahl==2)
				{
					cout << "Welchen Preis moechten Sie aendern?" << endl;			//Preis bearbeiten
					cin >> auswahl2;												//Auswahl des zu bearbeitenden Preises
					if(auswahl2==1)
					{essen1.preisEin();}
					if(auswahl2==2)
					{essen2.preisEin();}
					if(auswahl2==3)
					{essen3.preisEin();}
					if(auswahl2==4)
					{essen4.preisEin();}
					if(auswahl2==5)
					{essen5.preisEin();}
				}
			}
			while(auswahl!=3);
		}
		else if(eingabe==3)															//Passwort aendern																					
		{
			do
			{
				passwortrichtig=true;												//erneute Passwortabfrage
				cout << "Bitte geben Sie das alte Passwort ein." << endl;
				cin >> passworteingabe;
				for(int i=0; passworteingabe[i]!=0 || passwort[i]!=0; i++)
				{
					if(passwort[i]!=passworteingabe[i])
					{passwortrichtig=false;}
				}
				if(passwortrichtig==false)
				{cout << "Das Passwort ist nicht korrekt." << endl;}
			}
			while(passwortrichtig==false);
			cout << "Bitte geben Sie das neue Passwort ein." << endl;
			cin >> passwort;												 		//Eingabe des neuen Passwortes
			cout << "Das Passwort wurde geaendert." << endl;
		}
		else if(eingabe==4)                          								//Rabattaktion veraendern
		{
			if(aktionstag==false)													//Rabattaktion aktivieren
			{
				cout << "Moechten Sie eine Rabattaktion aktivieren?" << endl << "(1) Ja, (2) Nein" << endl;
				cin >> auswahl3;
				if(auswahl3==1)
				{
					aktionstag=true;
				}
			}
			else if(aktionstag==true)												//Rabattaktion deaktivieren
			{
				cout << "Moechten Sie die Rabattaktion deaktivieren?" << endl << "(1) Ja, (2) Nein" << endl;
				cin >> auswahl3;
				if(auswahl3==1)
				{
					aktionstag=false;
				}
			}
		}
	}
	while(eingabe!=5);
	
	return 0;
}
#include <iostream> 
#include <iomanip>										//Ein- und Ausgabebibliothek

using namespace std;
double preis1=1, preis2=1, preis3=1, preis4=1, preis5=1, preis, Gesamtpreis=0;
int menge1=0, menge2=0, menge3=0, menge4=0, menge5=0;

// Preis Funktion
/*Die Funktion "Preis" bestimmt den tatsächlichen Gesamtpreis, je nachdem, was der Kunde bestellt hat.
Die Eingabeparameter sind zwei int-werte, die Preis und Menge einer Speise bestimmen.
Der Ausgabeparameter ist ein double-wert, der den Gesamtpreis der Bestellung bestimmt.
Wenn eine Preisfunktion läuft, ist der richtige Gesamtpreis der Bestellung gegeben. */
double preis_fkt (int Auswahl, int menge) 
{
	if(Auswahl ==1) {
			menge1+=menge;
			preis=preis1*menge;}
		else if(Auswahl ==2){
			menge2+=menge;
			preis=preis2*menge;}
		else if(Auswahl ==3) {
			menge3+=menge;
			preis=preis3*menge;}
		else if(Auswahl ==4) {
			menge4+=menge;
			preis=preis4*menge;}
		else if(Auswahl ==5) {
			menge5+=menge;
			preis=preis5*menge;	}
			Gesamtpreis += preis;
			return Gesamtpreis;
		}

		
//KLASSENDEFINITION
class bestellung {
	private : //Attribute
		int zahl_essen[5]; // 5 verschiedene Essen werden auf ein Feld zahl_essen gespeichert.
		int zustand=1; //Jedes Bestellung Objekt hat einen Zustandszahl.
	public : 
		int nr; //Jedes Bestellung Objekt hat ein Bestellungsnummer als public Attribute.
	
	public :
		void setzeBestellungsnummer (int ein);
		void setzeStueckzahl (int index, int ein);
		int zeigStueckzahl (int index);
		void zustandAendern (int zustand);
		int zeigZustand (void);
		void zeigListe(void);
		bestellung& operator=(bestellung& orig);
};

// METHODENDEFINITION
void bestellung:: setzeBestellungsnummer (int ein) {//Bestellungsnummer setzen
	this->nr = ein; }
void bestellung:: setzeStueckzahl (int index, int ein) {//Stueckzahl setzen
	this -> zahl_essen[index]=ein; }
int bestellung:: zeigStueckzahl (int index) {//Stueckzahl zeigen
	return zahl_essen[index]; }

void bestellung:: zustandAendern (int zustand) {//Status aendern
	this-> zustand = zustand; }
int bestellung::zeigZustand (void) {//Zustand zeigen
	return zustand;}
void bestellung:: zeigListe(void) {//Liste zeigen
	cout << nr<<"            "<<zahl_essen[0]<<"*essen1,  "<< zahl_essen[1]<<"*essen2,  " <<zahl_essen[2]<<"*essen3,  "<<zahl_essen[3]<<"*essen4,  "<<zahl_essen[4]<<"*essen5"<< "   " << zustand<<endl; }


/*Diese Funktion ist eine überladene Zuweisungsoperatormethode, die das aufrufende Objekt mit einem anderen bestellung-Objekt gleichsetzen kann.
Der Eingabeparameter ist eine Referenz mit dem Namen orig vom Datentyp bestellung, mit der das aufrufende Objekt gleichgesetzt werden soll.
Der Ausgabeparameter ist das aufrufende bestellung-Objekt.
Die Methode setzt alle Attribute des aufrufenden Objektes mit Attributen des eingegebenen Objektes orig gleich.*/
bestellung& bestellung:: operator=(bestellung& orig) {
	if(&orig != this) {
		this->zustand = orig.zustand;
		this->nr = orig.nr;
		for(int i=0; i<5; i++) {
			this->zahl_essen[i] = orig.zahl_essen[i];
		}
	}
	return *this;
}

//HAUPTPROGRAMM
int main ()
{  //KUNDE
	int a,b,c,d,e;
	bestellung* Bestellung = new bestellung[5];// Instanzierung Objekte (Dynamische Datenverwaltung) -> man kann hier beliebige Anzahl an Bestellungen einstellen!!!
	char name1[20]={"essen1"}, name2[20]={"essen2"}, name3[20]={"essen3"}, name4[20]={"essen4"}, name5[20]={"essen5"};
	int Auswahl, menge;
	
	
	char choice='y';
	for( int i=0; i<5; i++) {// Bestellung Schleife läuft hier 5 mal
		menge1=0; menge2=0; menge3=0; menge4=0; menge5=0;
		Gesamtpreis=0;
																																/*Das Menü wird ausgegeben*/
		cout << "\n------------M E N U---------------" << endl;
		cout <<fixed<<setprecision(2)<<"1. "<< preis1<<" Euro  "<<name1<< endl;
		cout <<fixed<<setprecision(2)<<"2. "<< preis2<<" Euro  "<<name2<< endl;
		cout <<fixed<<setprecision(2)<<"3. "<< preis3<<" Euro  "<<name3<< endl;
		cout <<fixed<<setprecision(2)<<"4. "<< preis4<<" Euro  "<<name4<< endl;
		cout <<fixed<<setprecision(2)<<"5. "<< preis5<<" Euro  "<<name5<< endl;
		cout <<"6. Beenden"<<endl;
	
		do{
			do
			{
				cout << "\nWas moechten Sie bestellen?" << endl;							/*Der Kunde wird gefragt, was er bestellen will.*/
				cin >> Auswahl; 													
				if (Auswahl !=6){
				cout << "Wie viele moechten Sie davon kaufen?" << endl;			/*Die Stückzahl wird gefragt.*/
				cin >> menge; 										
				preis_fkt (Auswahl, menge); } 
			}
			while(Auswahl !=6); 
		
			cout << "Bestellte Produkte:" << endl;												/*Bestellte Speisen werden mit der Stückzahl angezeigt.*/
			if (menge1 !=0){
				cout << name1 << " " << menge1 << " Stueck"<<endl;}
			if (menge2!=0){
				cout << name2 << " " << menge2 << " Stueck"<<endl;}
			if (menge3!=0){
				cout << name3 << " " << menge3 << " Stueck"<<endl;}
			if (menge4!=0){
				cout << name4 << " " << menge4 << " Stueck"<<endl;}
			if (menge5!=0){
			cout << name5 << " " << menge5 << " Stueck"<<endl;} 
			cout<< "Gesamtpreis = "<<Gesamtpreis<<endl; 								/*Der Gesamtpreis wird berechnet und angezeigt.*/

			do {
				cout<< "Haben Sie alles richtig bestellt?(Y/N)" << endl;
				cin >> choice;
			}while(choice !='y' && choice!='Y' && choice !='n' && choice!='N');		/*Es besteht die Wahl zwischen Y oder y und N oder n.*/
			
		}while (choice !='y' && choice!='Y');														/*Wenn N oder n eingegeben wird, wird das Programm immer wieder ausgeführt bis Y oder y eingegeben wird.
																													Wenn Y oder y eingegeben wird, wird das Programm nicht wieder gelaufen und eine Aussage gegeben.*/
		cout << " Vielen Dank fuer Ihre Bestellung :) " << endl;
		
		Bestellung[i].setzeStueckzahl(0, menge1);     //Jede Bestellungen werden auf den Temp_bestellung Klassen gespeichert. 
		Bestellung[i].setzeStueckzahl(1, menge2);
		Bestellung[i].setzeStueckzahl(2, menge3);
		Bestellung[i].setzeStueckzahl(3, menge4);
		Bestellung[i].setzeStueckzahl(4, menge5);
	}
	
	//KOCH
	int x, y;  //Bei Zustandsänderung x: wie vielte Bestellung, y: in welchem Zustand
	int z_aendern;
	
	for( int i=0; i<5; i++) {
		Bestellung[i].setzeBestellungsnummer(i+100);//Bestellungsnummer wird bei der Bestellung durch Automat aufgeteilt, damit Kunden ihre Bestellungen auf einem Blick erkennen können
	}
	
	cout <<"\nBestellungszustand : " <<endl;//Zustand
	cout <<"(1) Bestellt  , (2) in Bearbeitung,  (0) Fertig! Abholbar \n";
	cout << "\n<Bestellungsliste>\n";//Bestellungsliste
	cout << "Bestellung     Stueckzahl                                             Zustand\n";
	for(int i=0; i<5; i++) {
		Bestellung[i].zeigListe();
	}
	
	//Zustandsänderung Schleife
	do {
		cout << "\nZustand aendern?\n";
		cout << "(1) Yes         (2) No\n";
		cin >> z_aendern; // Wenn man den Zustand ändern will, drückt man 1, sonst 2.
		if(z_aendern == 1) {                                                                       
			cout << "Wie vielte Bestellung moechten Sie aendern?\n";
			cin >> x;
			cout << "In welchem Zustand ist die " << x<<". Bestellung?\n";
			cin >> y;
			if (x == 1) Bestellung[0].zustandAendern(y); //Zustand ändern
			else if (x ==2) Bestellung[1].zustandAendern(y);
			else if (x ==3) Bestellung[2].zustandAendern(y);
			else if (x ==4) Bestellung[3].zustandAendern(y);
			else if (x ==5) Bestellung[4].zustandAendern(y);
			cout << "\n<Bestellungsliste>\n";
			cout << "Bestellung     Stueckzahl                                             Zustand\n";
			for(int i=0; i<5; i++) {
			Bestellung[i].zeigListe();
			}
		}	
	}while(z_aendern !=2); //Koch wird wieder gefragt, ob er noch einen anderen Zustand ändern will, bis er "nein" wählt.
	
	for(int i=0; i<5; i++) {
		if(Bestellung[0].zeigZustand() < Bestellung[1].zeigZustand()) {        //Bestellung1<->Bestellung2
			bestellung neu;																										//wenn Bestellungszustand von Bestellung2 höher als 1.
			neu = Bestellung[0];                                           								//Bestellung1(mit einem höchsten Zustandsnummer) steht immer ganz vorne!!
			Bestellung[0] = Bestellung[1];
			Bestellung[1] = neu;
		}
		if(Bestellung[1].zeigZustand() < Bestellung[2].zeigZustand()) {        //Bestellung2<->Bestellung3
			bestellung neu;	
			neu = Bestellung[1];
			Bestellung[1] = Bestellung[2];
			Bestellung[2] = neu;
		}	
		if(Bestellung[2].zeigZustand() < Bestellung[3].zeigZustand()) {        //Bestellung3<->Bestellung4
			bestellung neu;
			neu = Bestellung[2];
			Bestellung[2] = Bestellung[3];
			Bestellung[3] = neu;
		}			
		if(Bestellung[3].zeigZustand() < Bestellung[4].zeigZustand()) {        //Bestellung4<->Bestellung5
			bestellung neu;
			neu = Bestellung[3];
			Bestellung[3] = Bestellung[4];
			Bestellung[4] = neu;
		}
	}		
	
	cout << "\n<Bestellungsliste>\n";
	cout << "Bestellung     Stueckzahl                                             Zustand\n";
	for(int i=0; i<5; i++) {
		Bestellung[i].zeigListe();
	}
		
	if(Bestellung[4].zeigZustand() == 0) {
		if(Bestellung[3].zeigZustand() == 0) {
			if(Bestellung[2].zeigZustand() == 0) {
				if(Bestellung[1].zeigZustand() == 0) {
					if(Bestellung[0].zeigZustand() == 0) {//Wenn alle Bestellungen fertig sind.
						cout << "\n<Bestellungsliste>\n";
						cout << "Bestellung     Stueckzahl                                             Zustand\n";
						cout << "\nAlle Bestellungen sind ABHOLBAR!" <<endl;
					}
					else {// Wenn alle Bestellungen außer 1 fertig sind.
						cout << "\n<Bestellungsliste>\n";
						cout << "Bestellung     Stueckzahl                                             Zustand\n";
						Bestellung[0].zeigListe();
						cout << "\nBestellungsnummer "<< Bestellung[1].nr<< ", "<< Bestellung[2].nr<< ", "<< Bestellung[3].nr<<", "<< Bestellung[4].nr<< " sind ABHOLBAR!"<<endl;
					}
				}
				else {//Wenn Bestellung3,4,5 fertig sind.
					cout << "\n<Bestellungsliste>\n";
					cout << "Bestellung     Stueckzahl                                             Zustand\n";
					Bestellung[0].zeigListe();
					Bestellung[1].zeigListe();
					cout << "\nBestellungsnummer "<< Bestellung[2].nr<< ", "<< Bestellung[3].nr<<", "<< Bestellung[4].nr<< " sind ABHOLBAR!"<<endl;
				}
			}
			else {//Wenn Bestellung 4,5 fertig sind.
				cout << "\n<Bestellungsliste>\n";
				cout << "Bestellung     Stueckzahl                                             Zustand\n";
				Bestellung[0].zeigListe();
				Bestellung[1].zeigListe();
				Bestellung[2].zeigListe();
				cout << "\nBestellungsnummer "<< Bestellung[3].nr<<", "<< Bestellung[4].nr<< " sind ABHOLBAR!"<<endl;
			}
		}
		else {//Wenn Bestellung 5 fertig ist.
			cout << "\n<Bestellungsliste>\n";
			cout << "Bestellung     Stueckzahl                                             Zustand\n";
			Bestellung[0].zeigListe();
			Bestellung[1].zeigListe();
			Bestellung[2].zeigListe();
			Bestellung[3].zeigListe();
			cout << "\nBestellungsnummer "<< Bestellung[4].nr<< " ist ABHOLBAR!"<<endl;
		}
	}
	else {//Wenn alle Bestellungen nicht fertig sind.
		cout << "\n<Bestellungsliste>\n";
		cout << "Bestellung     Stueckzahl                                             Zustand\n";
		Bestellung[0].zeigListe();
		Bestellung[1].zeigListe();
		Bestellung[2].zeigListe();
		Bestellung[3].zeigListe();
		Bestellung[4].zeigListe();
	}
	return 0;
}

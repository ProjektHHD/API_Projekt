#include <iostream>
using namespace std;

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
int main (void) {
	int x, y;  //Bei Zustandsänderung x: wie vielte Bestellung, y: in welchem Zustand
	int z_aendern;
	bestellung Bestellung1, Bestellung2, Bestellung3, Bestellung4, Bestellung5;// Instanzierung Objekte
	
	for( int i=0; i<5; i++) {                //Für TEST; alle Bestellungsstückzahl 1,2,3,4,5 setzen
		Bestellung1.setzeStueckzahl(i,1);
		Bestellung2.setzeStueckzahl(i,2);
		Bestellung3.setzeStueckzahl(i,3);
		Bestellung4.setzeStueckzahl(i,4);
		Bestellung5.setzeStueckzahl(i,5);
	}
	
	Bestellung1.setzeBestellungsnummer(111);//Bestellungsnummer wird bei der Bestellung durch Automat aufgeteilt, damit Kunden ihre Bestellungen auf einem Blick erkennen können
	Bestellung2.setzeBestellungsnummer(112);
	Bestellung3.setzeBestellungsnummer(113);
	Bestellung4.setzeBestellungsnummer(114);
	Bestellung5.setzeBestellungsnummer(115);
	
	cout <<"\nBestellungszustand : " <<endl;//Zustand
	cout <<"(1) Bestellt  , (2) in Bearbeitung,  (0) Fertig! Abholbar \n";
	cout << "\n<Bestellungsliste>\n";//Bestellungsliste
	cout << "Bestellung     Stueckzahl                                             Zustand\n";
	Bestellung1.zeigListe();
	Bestellung2.zeigListe();
	Bestellung3.zeigListe();
	Bestellung4.zeigListe();
	Bestellung5.zeigListe();
	
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
			if (x == 1) Bestellung1.zustandAendern(y); //Zustand ändern
			else if (x ==2) Bestellung2.zustandAendern(y);
			else if (x ==3) Bestellung3.zustandAendern(y);
			else if (x ==4) Bestellung4.zustandAendern(y);
			else if (x ==5) Bestellung5.zustandAendern(y);
			cout << "\n<Bestellungsliste>\n";
			cout << "Bestellung     Stueckzahl                                             Zustand\n";
			Bestellung1.zeigListe();
			Bestellung2.zeigListe();
			Bestellung3.zeigListe();
			Bestellung4.zeigListe();
			Bestellung5.zeigListe();
			}	
	}while(z_aendern !=2); //Koch wird wieder gefragt, ob er noch einen anderen Zustand ändern will, bis er "nein" wählt.
	
	for(int i=0; i<5; i++) {
		int j, k;
		if(Bestellung1.zeigZustand() < Bestellung2.zeigZustand()) {        //Bestellung1<->Bestellung2
			bestellung neu;                                                                      //wenn Bestellungszustand von Bestellung2 höher als 1.
			neu = Bestellung1;                                           						//Bestellung1(mit einem höchsten Zustandsnummer) steht immer ganz vorne!!
			Bestellung1 = Bestellung2;
			Bestellung2 = neu;
		}
		if(Bestellung2.zeigZustand() < Bestellung3.zeigZustand()) {        //Bestellung2<->Bestellung3
			bestellung neu;
			neu = Bestellung2;
			Bestellung2 = Bestellung3;
			Bestellung3 = neu;
		}	
		if(Bestellung3.zeigZustand() < Bestellung4.zeigZustand()) {        //Bestellung3<->Bestellung4
			bestellung neu;
			neu = Bestellung3;
			Bestellung3 = Bestellung4;
			Bestellung4 = neu;
		}			
		if(Bestellung4.zeigZustand() < Bestellung5.zeigZustand()) {        //Bestellung4<->Bestellung5
			bestellung neu;
			neu = Bestellung4;
			Bestellung4 = Bestellung5;
			Bestellung5 = neu;
		}
	}		
	
	cout << "\n<Bestellungsliste>\n";
	cout << "Bestellung     Stueckzahl                                             Zustand\n";
	Bestellung1.zeigListe();
	Bestellung2.zeigListe();
	Bestellung3.zeigListe();
	Bestellung4.zeigListe();
	Bestellung5.zeigListe();
		
	if(Bestellung5.zeigZustand() == 0) {
		if(Bestellung4.zeigZustand() == 0) {
			if(Bestellung3.zeigZustand() == 0) {
				if(Bestellung2.zeigZustand() == 0) {
					if(Bestellung1.zeigZustand() == 0) {//Wenn alle Bestellungen fertig sind.
						cout << "\n<Bestellungsliste>\n";
						cout << "Bestellung     Stueckzahl                                             Zustand\n";
						cout << "\nAlle Bestellungen sind ABHOLBAR!" <<endl;
					}
					else {// Wenn alle Bestellungen außer 1 fertig sind.
						cout << "\n<Bestellungsliste>\n";
						cout << "Bestellung     Stueckzahl                                             Zustand\n";
						Bestellung1.zeigListe();
						cout << "\nBestellungsnummer "<< Bestellung2.nr<< ", "<< Bestellung3.nr<< ", "<< Bestellung4.nr<<", "<< Bestellung5.nr<< " sind ABHOLBAR!"<<endl;
					}
				}
				else {//Wenn Bestellung3,4,5 fertig sind.
					cout << "\n<Bestellungsliste>\n";
					cout << "Bestellung     Stueckzahl                                             Zustand\n";
					Bestellung1.zeigListe();
					Bestellung2.zeigListe();
					cout << "\nBestellungsnummer "<< Bestellung3.nr<< ", "<< Bestellung4.nr<<", "<< Bestellung5.nr<< " sind ABHOLBAR!"<<endl;
				}
			}
			else {//Wenn Bestellung 4,5 fertig sind.
				cout << "\n<Bestellungsliste>\n";
				cout << "Bestellung     Stueckzahl                                             Zustand\n";
				Bestellung1.zeigListe();
				Bestellung2.zeigListe();
				Bestellung3.zeigListe();
				cout << "\nBestellungsnummer "<< Bestellung4.nr<<", "<< Bestellung5.nr<< " sind ABHOLBAR!"<<endl;
			}
		}
		else {//Wenn Bestellung 5 fertig ist.
			cout << "\n<Bestellungsliste>\n";
			cout << "Bestellung     Stueckzahl                                             Zustand\n";
			Bestellung1.zeigListe();
			Bestellung2.zeigListe();
			Bestellung3.zeigListe();
			Bestellung4.zeigListe();
			cout << "\nBestellungsnummer "<< Bestellung5.nr<< " ist ABHOLBAR!"<<endl;
		}
	}
	else {//Wenn alle Bestellungen nicht fertig sind.
		cout << "\n<Bestellungsliste>\n";
		cout << "Bestellung     Stueckzahl                                             Zustand\n";
		Bestellung1.zeigListe();
		Bestellung2.zeigListe();
		Bestellung3.zeigListe();
		Bestellung4.zeigListe();
		Bestellung5.zeigListe();	
	}
	return 0;
}

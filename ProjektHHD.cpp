#include <iostream>
using namespace std;

class bestellung {                            //Klass Definition
	private : 
		int zahl_essen[5];                          //Attribute
		int zustand=1;
	public : 
		int nr;
	
	public :
		void setzeBestellungsnummer (int ein);
		void setzeStueckzahl (int index, int ein);            //Methode
		int zeigStueckzahl (int index);
		void zustandAendern (int zustand);
		int zeigZustand (void);
		void zeigListe(void);
		bestellung& operator=(bestellung& orig);
};

// Methodendefinition
void bestellung:: setzeBestellungsnummer (int ein) {
	this->nr = ein; }
void bestellung:: setzeStueckzahl (int index, int ein) {
	this -> zahl_essen[index]=ein; }
int bestellung:: zeigStueckzahl (int index) {
	return zahl_essen[index]; }

void bestellung:: zustandAendern (int zustand) {       //Statusänderung Methode
	this-> zustand = zustand; }
int bestellung::zeigZustand (void) {
	return zustand;}
void bestellung:: zeigListe(void) {            //Liste Zeigen Methode
	cout << nr<<"            "<<zahl_essen[0]<<"*essen1,  "<< zahl_essen[1]<<"*essen2,  " <<zahl_essen[2]<<"*essen3,  "<<zahl_essen[3]<<"*essen4,  "<<zahl_essen[4]<<"*essen5"<< "   " << zustand<<endl; }

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

int main (void) {
	int x, y;  //Bei Zustandsänderung
	int z_aendern;
	bestellung Bestellung1, Bestellung2, Bestellung3, Bestellung4, Bestellung5;                  // Instanzierung Objekte
	
	for( int i=0; i<5; i++) {                //Für TEST; alle Bestellungsstückzahl 1,2,3,4,5 setzen
		Bestellung1.setzeStueckzahl(i,1);
		Bestellung2.setzeStueckzahl(i,2);
		Bestellung3.setzeStueckzahl(i,3);
		Bestellung4.setzeStueckzahl(i,4);
		Bestellung5.setzeStueckzahl(i,5);
	}
	
	Bestellung1.setzeBestellungsnummer(111);            //Bestellungsnummer wird bei der Bestellung durch Automat aufgeteilt, damit Kunden ihre Bestellungen auf einem Blick erkennen können
	Bestellung2.setzeBestellungsnummer(112);
	Bestellung3.setzeBestellungsnummer(113);
	Bestellung4.setzeBestellungsnummer(114);
	Bestellung5.setzeBestellungsnummer(115);
	
	cout <<"\nBestellungszustand : " <<endl;            //Zustand
	cout <<"(1) Bestellt  , (2) in Bearbeitung,  (0) Fertig! Abholbar \n";
	cout << "\n<Bestellungsliste>\n";                             //Bestellungsliste
	cout << "Bestellung     Stueckzahl                                             Zustand\n";
	Bestellung1.zeigListe();
	Bestellung2.zeigListe();
	Bestellung3.zeigListe();
	Bestellung4.zeigListe();
	Bestellung5.zeigListe();

	do {
		cout << "\nZustand aendern?\n";     //Zustandsänderung Schleife
		cout << "(1) Yes         (2) No\n";
		cin >> z_aendern;
		if(z_aendern == 1) {                                                                       
			cout << "Wie vielte Bestellung moechten Sie aendern?\n";
			cin >> x;
			cout << "In welchem Zustand ist die " << x<<". Bestellung?\n";
			cin >> y;
			if (x == 1) Bestellung1.zustandAendern(y);
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
	}while(z_aendern !=2);        //Koch wird wieder gefragt, ob er noch einen anderen Zustand ändern will, bis er "nein" wählt.
	
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
					if(Bestellung1.zeigZustand() == 0) {
						cout << "\n<Bestellungsliste>\n";
						cout << "Bestellung     Stueckzahl                                             Zustand\n";
						cout << "Alle Bestellungen sind FERTIG!" <<endl;
					}
					else {
						cout << "\n<Bestellungsliste>\n";
						cout << "Bestellung     Stueckzahl                                             Zustand\n";
						Bestellung1.zeigListe();
					}
				}
				else {
					cout << "\n<Bestellungsliste>\n";
					cout << "Bestellung     Stueckzahl                                             Zustand\n";
					Bestellung1.zeigListe();
					Bestellung2.zeigListe();
				}
			}
			else {
				cout << "\n<Bestellungsliste>\n";
				cout << "Bestellung     Stueckzahl                                             Zustand\n";
				Bestellung1.zeigListe();
				Bestellung2.zeigListe();
				Bestellung3.zeigListe();
			}
		}
		else {
			cout << "\n<Bestellungsliste>\n";
			cout << "Bestellung     Stueckzahl                                             Zustand\n";
			Bestellung1.zeigListe();
			Bestellung2.zeigListe();
			Bestellung3.zeigListe();
			Bestellung4.zeigListe();
		}
	}
	else {
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

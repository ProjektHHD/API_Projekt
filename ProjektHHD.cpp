#include <iostream>
using namespace std;

class bestellung {                            //Klass Definition
	private : 
		int zahl_essen1;                          //Attribute
		int zahl_essen2;
		int zahl_essen3;
		int zahl_essen4;
		int zahl_essen5;
		int zustand=1;
	public : 
		int nr;
	
	public :
		void setzeBestellungsnummer (int ein);
		void setzeStueckzahl1 (int ein);            //Methode
		void setzeStueckzahl2 (int ein);
		void setzeStueckzahl3 (int ein);
		void setzeStueckzahl4 (int ein);
		void setzeStueckzahl5 (int ein);
		int zeigStueckzahl1 (void);
		int zeigStueckzahl2 (void);
		int zeigStueckzahl3 (void);
		int zeigStueckzahl4 (void);
		int zeigStueckzahl5 (void);
		void zustandAendern (int zustand);
		int zeigZustand (void);
		void zeigListe(void);
};

// Methodendefinition
void bestellung:: setzeBestellungsnummer (int ein) {
	this->nr = ein; }
void bestellung:: setzeStueckzahl1 (int ein) {
	this -> zahl_essen1=ein; }
void bestellung:: setzeStueckzahl2 (int ein) {
	this -> zahl_essen2=ein; }
void bestellung:: setzeStueckzahl3 (int ein) {
	this -> zahl_essen3=ein; }
void bestellung:: setzeStueckzahl4 (int ein) {
	this -> zahl_essen4=ein; }
void bestellung:: setzeStueckzahl5 (int ein) {
	this -> zahl_essen5=ein; }

int bestellung:: zeigStueckzahl1 (void) {
	return zahl_essen1; }
int bestellung:: zeigStueckzahl2 (void) {
	return zahl_essen2; }
int bestellung:: zeigStueckzahl3 (void) {
	return zahl_essen3; }	
int bestellung:: zeigStueckzahl4 (void) {
	return zahl_essen4; }
int bestellung:: zeigStueckzahl5 (void) {
	return zahl_essen5; }

void bestellung:: zustandAendern (int zustand) {       //Statusänderung Methode
	this-> zustand = zustand; }
int bestellung::zeigZustand (void) {
	return zustand;}
void bestellung:: zeigListe(void) {            //Liste Zeigen Methode
	cout << nr<<"            "<<zahl_essen1<<"*essen1,  "<< zahl_essen2<<"*essen2,  " <<zahl_essen3<<"*essen3,  "<<zahl_essen4<<"*essen4,  "<<zahl_essen5<<"*essen5"<< "   " << zustand<<endl; }
		
int main (void) {
	int a=3, b=4, c=2, d=1, e=5;	 // Bestellung Stückzahl werden von Kunde-Code bekommen. 
	int x, y;  //Bei Zustandsänderung
	int z_aendern;
	bestellung Bestellung1, Bestellung2, Bestellung3, Bestellung4, Bestellung5;                  // Instanzierung Objekte

	Bestellung1.setzeStueckzahl1(1);                //Für TEST; alle Bestellungsstückzahl 1,2,3,4,5 setzen
	Bestellung1.setzeStueckzahl2(1);
	Bestellung1.setzeStueckzahl3(1);
	Bestellung1.setzeStueckzahl4(1);
	Bestellung1.setzeStueckzahl5(1);
	Bestellung1.setzeBestellungsnummer(111);            //Bestellungsnummer wird bei der Bestellung durch Automat aufgeteilt, damit Kunden ihre Bestellungen auf einem Blick erkennen können
	
	Bestellung2.setzeStueckzahl1(2);
	Bestellung2.setzeStueckzahl2(2);
	Bestellung2.setzeStueckzahl3(2);
	Bestellung2.setzeStueckzahl4(2);
	Bestellung2.setzeStueckzahl5(2);
	Bestellung2.setzeBestellungsnummer(112);
	
	Bestellung3.setzeStueckzahl1(3);
	Bestellung3.setzeStueckzahl2(3);
	Bestellung3.setzeStueckzahl3(3);
	Bestellung3.setzeStueckzahl4(3);
	Bestellung3.setzeStueckzahl5(3);
	Bestellung3.setzeBestellungsnummer(113);
	
	Bestellung4.setzeStueckzahl1(4);
	Bestellung4.setzeStueckzahl2(4);
	Bestellung4.setzeStueckzahl3(4);
	Bestellung4.setzeStueckzahl4(4);
	Bestellung4.setzeStueckzahl5(4);
	Bestellung4.setzeBestellungsnummer(114);
	
	Bestellung5.setzeStueckzahl1(5);
	Bestellung5.setzeStueckzahl2(5);
	Bestellung5.setzeStueckzahl3(5);
	Bestellung5.setzeStueckzahl4(5);
	Bestellung5.setzeStueckzahl5(5);
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
			j=Bestellung1.zeigStueckzahl1();                                            //wenn Bestellungszustand von Bestellung2 höher als 1.
			k=Bestellung2.zeigStueckzahl1();                                           //Bestellung1 steht immer ganz vorne!!
			Bestellung1.setzeStueckzahl1(k);
			Bestellung2.setzeStueckzahl1(j);
			
			j=Bestellung1.zeigStueckzahl2(); 
			k=Bestellung2.zeigStueckzahl2();
			Bestellung1.setzeStueckzahl2(k);
			Bestellung2.setzeStueckzahl2(j);
			
			j=Bestellung1.zeigStueckzahl3(); 
			k=Bestellung2.zeigStueckzahl3();
			Bestellung1.setzeStueckzahl3(k);
			Bestellung2.setzeStueckzahl3(j);
			
			j=Bestellung1.zeigStueckzahl4(); 
			k=Bestellung2.zeigStueckzahl4();
			Bestellung1.setzeStueckzahl4(k);
			Bestellung2.setzeStueckzahl4(j);
			
			j=Bestellung1.zeigStueckzahl5(); 
			k=Bestellung2.zeigStueckzahl5();
			Bestellung1.setzeStueckzahl5(k);
			Bestellung2.setzeStueckzahl5(j);
			
			j=Bestellung1.zeigZustand(); 
			k=Bestellung2.zeigZustand();
			Bestellung1.zustandAendern(k);
			Bestellung2.zustandAendern(j);
			
			j=Bestellung1.nr;
			k=Bestellung2.nr;
			Bestellung1.nr = k;
			Bestellung2.nr =j;}
			
		if(Bestellung2.zeigZustand() < Bestellung3.zeigZustand()) {        //Bestellung2<->Bestellung3
			j=Bestellung2.zeigStueckzahl1(); 
			k=Bestellung3.zeigStueckzahl1();
			Bestellung2.setzeStueckzahl1(k);
			Bestellung3.setzeStueckzahl1(j); 
			
			j=Bestellung2.zeigStueckzahl2(); 
			k=Bestellung3.zeigStueckzahl2();
			Bestellung2.setzeStueckzahl2(k);
			Bestellung3.setzeStueckzahl2(j); 
			
			j=Bestellung2.zeigStueckzahl3(); 
			k=Bestellung3.zeigStueckzahl3();
			Bestellung2.setzeStueckzahl3(k);
			Bestellung3.setzeStueckzahl3(j); 
			
			j=Bestellung2.zeigStueckzahl4(); 
			k=Bestellung3.zeigStueckzahl4();
			Bestellung2.setzeStueckzahl4(k);
			Bestellung3.setzeStueckzahl4(j); 
			
			j=Bestellung2.zeigStueckzahl5(); 
			k=Bestellung3.zeigStueckzahl5();
			Bestellung2.setzeStueckzahl5(k);
			Bestellung3.setzeStueckzahl5(j); 
			
			j=Bestellung2.zeigZustand(); 
			k=Bestellung3.zeigZustand();
			Bestellung2.zustandAendern(k);
			Bestellung3.zustandAendern(j);
			
			j=Bestellung2.nr;
			k=Bestellung3.nr;
			Bestellung2.nr = k;
			Bestellung3.nr =j;}
			
		if(Bestellung3.zeigZustand() < Bestellung4.zeigZustand()) {        //Bestellung3<->Bestellung4
			j=Bestellung3.zeigStueckzahl1(); 
			k=Bestellung4.zeigStueckzahl1();
			Bestellung3.setzeStueckzahl1(k);
			Bestellung4.setzeStueckzahl1(j);

			j=Bestellung3.zeigStueckzahl2(); 
			k=Bestellung4.zeigStueckzahl2();
			Bestellung3.setzeStueckzahl2(k);
			Bestellung4.setzeStueckzahl2(j);
			
			j=Bestellung3.zeigStueckzahl3(); 
			k=Bestellung4.zeigStueckzahl3();
			Bestellung3.setzeStueckzahl3(k);
			Bestellung4.setzeStueckzahl3(j);
			
			j=Bestellung3.zeigStueckzahl4(); 
			k=Bestellung4.zeigStueckzahl4();
			Bestellung3.setzeStueckzahl4(k);
			Bestellung4.setzeStueckzahl4(j);
			
			j=Bestellung3.zeigStueckzahl5(); 
			k=Bestellung4.zeigStueckzahl5();
			Bestellung3.setzeStueckzahl5(k);
			Bestellung4.setzeStueckzahl5(j);
			
			j=Bestellung3.zeigZustand(); 
			k=Bestellung4.zeigZustand();
			Bestellung3.zustandAendern(k);
			Bestellung4.zustandAendern(j);
			
			j=Bestellung3.nr;
			k=Bestellung4.nr;
			Bestellung3.nr = k;
			Bestellung4.nr =j;}
			
		if(Bestellung4.zeigZustand() < Bestellung5.zeigZustand()) {        //Bestellung4<->Bestellung5
			j=Bestellung4.zeigStueckzahl1(); 
			k=Bestellung5.zeigStueckzahl1();
			Bestellung4.setzeStueckzahl1(k);
			Bestellung5.setzeStueckzahl1(j); 
			
			j=Bestellung4.zeigStueckzahl2(); 
			k=Bestellung5.zeigStueckzahl2();
			Bestellung4.setzeStueckzahl2(k);
			Bestellung5.setzeStueckzahl2(j); 
			
			j=Bestellung4.zeigStueckzahl3(); 
			k=Bestellung5.zeigStueckzahl3();
			Bestellung4.setzeStueckzahl3(k);
			Bestellung5.setzeStueckzahl3(j); 
			
			j=Bestellung4.zeigStueckzahl4(); 
			k=Bestellung5.zeigStueckzahl4();
			Bestellung4.setzeStueckzahl4(k);
			Bestellung5.setzeStueckzahl4(j); 
			
			j=Bestellung4.zeigStueckzahl5(); 
			k=Bestellung5.zeigStueckzahl5();
			Bestellung4.setzeStueckzahl5(k);
			Bestellung5.setzeStueckzahl5(j); 
			
			j=Bestellung4.zeigZustand(); 
			k=Bestellung5.zeigZustand();
			Bestellung4.zustandAendern(k);
			Bestellung5.zustandAendern(j);
			
			j=Bestellung4.nr;
			k=Bestellung5.nr;
			Bestellung4.nr = k;
			Bestellung5.nr =j;}
		}
	
	cout << "\n<Bestellungsliste>\n";
	cout << "Bestellung     Stueckzahl                                             Zustand\n";
	Bestellung1.zeigListe();
	Bestellung2.zeigListe();
	Bestellung3.zeigListe();
	Bestellung4.zeigListe();
	Bestellung5.zeigListe();
	
	if(Bestellung5.zeigZustand() == 0) {                       //bool funktion
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

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
			j=Bestellung1.zeigStueckzahl(0);                                            //wenn Bestellungszustand von Bestellung2 höher als 1.
			k=Bestellung2.zeigStueckzahl(0);                                           //Bestellung1 steht immer ganz vorne!!
			Bestellung1.setzeStueckzahl(0,k);
			Bestellung2.setzeStueckzahl(0,j);
			
			j=Bestellung1.zeigStueckzahl(1); 
			k=Bestellung2.zeigStueckzahl(1);
			Bestellung1.setzeStueckzahl(1,k);
			Bestellung2.setzeStueckzahl(1,j);
			
			j=Bestellung1.zeigStueckzahl(2); 
			k=Bestellung2.zeigStueckzahl(2);
			Bestellung1.setzeStueckzahl(2,k);
			Bestellung2.setzeStueckzahl(2,j);
			
			j=Bestellung1.zeigStueckzahl(3); 
			k=Bestellung2.zeigStueckzahl(3);
			Bestellung1.setzeStueckzahl(3,k);
			Bestellung2.setzeStueckzahl(3,j);
			
			j=Bestellung1.zeigStueckzahl(4); 
			k=Bestellung2.zeigStueckzahl(4);
			Bestellung1.setzeStueckzahl(4,k);
			Bestellung2.setzeStueckzahl(4,j);
			
			j=Bestellung1.zeigZustand(); 
			k=Bestellung2.zeigZustand();
			Bestellung1.zustandAendern(k);
			Bestellung2.zustandAendern(j);
			
			j=Bestellung1.nr;
			k=Bestellung2.nr;
			Bestellung1.nr = k;
			Bestellung2.nr =j;}
			
		if(Bestellung2.zeigZustand() < Bestellung3.zeigZustand()) {        //Bestellung2<->Bestellung3
			j=Bestellung2.zeigStueckzahl(0);
			k=Bestellung3.zeigStueckzahl(0);
			Bestellung2.setzeStueckzahl(0,k);
			Bestellung3.setzeStueckzahl(0,j);
			
			j=Bestellung2.zeigStueckzahl(1); 
			k=Bestellung3.zeigStueckzahl(1);
			Bestellung2.setzeStueckzahl(1,k);
			Bestellung3.setzeStueckzahl(1,j);
			
			j=Bestellung2.zeigStueckzahl(2); 
			k=Bestellung3.zeigStueckzahl(2);
			Bestellung2.setzeStueckzahl(2,k);
			Bestellung3.setzeStueckzahl(2,j);
			
			j=Bestellung2.zeigStueckzahl(3); 
			k=Bestellung3.zeigStueckzahl(3);
			Bestellung2.setzeStueckzahl(3,k);
			Bestellung3.setzeStueckzahl(3,j);
			
			j=Bestellung2.zeigStueckzahl(4); 
			k=Bestellung3.zeigStueckzahl(4);
			Bestellung2.setzeStueckzahl(4,k);
			Bestellung3.setzeStueckzahl(4,j);
			
			j=Bestellung2.zeigZustand(); 
			k=Bestellung3.zeigZustand();
			Bestellung2.zustandAendern(k);
			Bestellung3.zustandAendern(j);
			
			j=Bestellung2.nr;
			k=Bestellung3.nr;
			Bestellung2.nr = k;
			Bestellung3.nr =j;}
			
		if(Bestellung3.zeigZustand() < Bestellung4.zeigZustand()) {        //Bestellung3<->Bestellung4
			j=Bestellung3.zeigStueckzahl(0);
			k=Bestellung4.zeigStueckzahl(0);
			Bestellung3.setzeStueckzahl(0,k);
			Bestellung4.setzeStueckzahl(0,j);
			
			j=Bestellung3.zeigStueckzahl(1); 
			k=Bestellung4.zeigStueckzahl(1);
			Bestellung3.setzeStueckzahl(1,k);
			Bestellung4.setzeStueckzahl(1,j);
			
			j=Bestellung3.zeigStueckzahl(2); 
			k=Bestellung4.zeigStueckzahl(2);
			Bestellung3.setzeStueckzahl(2,k);
			Bestellung4.setzeStueckzahl(2,j);
			
			j=Bestellung3.zeigStueckzahl(3); 
			k=Bestellung4.zeigStueckzahl(3);
			Bestellung3.setzeStueckzahl(3,k);
			Bestellung4.setzeStueckzahl(3,j);
			
			j=Bestellung3.zeigStueckzahl(4); 
			k=Bestellung4.zeigStueckzahl(4);
			Bestellung3.setzeStueckzahl(4,k);
			Bestellung4.setzeStueckzahl(4,j);
			
			j=Bestellung3.zeigZustand(); 
			k=Bestellung4.zeigZustand();
			Bestellung3.zustandAendern(k);
			Bestellung4.zustandAendern(j);
			
			j=Bestellung3.nr;
			k=Bestellung4.nr;
			Bestellung3.nr = k;
			Bestellung4.nr =j;}
			
		if(Bestellung4.zeigZustand() < Bestellung5.zeigZustand()) {        //Bestellung4<->Bestellung5
			j=Bestellung4.zeigStueckzahl(0);
			k=Bestellung5.zeigStueckzahl(0);
			Bestellung4.setzeStueckzahl(0,k);
			Bestellung5.setzeStueckzahl(0,j);
			
			j=Bestellung4.zeigStueckzahl(1); 
			k=Bestellung5.zeigStueckzahl(1);
			Bestellung4.setzeStueckzahl(1,k);
			Bestellung5.setzeStueckzahl(1,j);
			
			j=Bestellung4.zeigStueckzahl(2); 
			k=Bestellung5.zeigStueckzahl(2);
			Bestellung4.setzeStueckzahl(2,k);
			Bestellung5.setzeStueckzahl(2,j);
			
			j=Bestellung4.zeigStueckzahl(3); 
			k=Bestellung5.zeigStueckzahl(3);
			Bestellung4.setzeStueckzahl(3,k);
			Bestellung5.setzeStueckzahl(3,j);
			
			j=Bestellung4.zeigStueckzahl(4); 
			k=Bestellung5.zeigStueckzahl(4);
			Bestellung4.setzeStueckzahl(4,k);
			Bestellung5.setzeStueckzahl(4,j);
			
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

#include <iostream>
using namespace std;

class essen																																// Klassendeklaration
{
	private:
	char name[100];
	double preis;
	public:
	char* nameEin(void);
	char* nameAus(void);
	double preisEin(void);
	double preisAus(void);
};

char* essen::nameEin(void)																												//Funktionsdeklaration
{
	cout << "Bitte geben Sie den neuen Namen ein." << endl;
	cin >> name;
}

char* essen::nameAus(void)
{
	return name;
}

double essen::preisEin(void)
{
	cout << "Bitte geben Sie den neuen Preis ein." << endl;
	cin >> preis;
}

double essen::preisAus(void)
{
	return preis;
}

int main()																													// Anfang des Hauptprogramms			
{
	char passwort[100]={"passwort"}, passworteingabe[100];																	//Deklaration der Passwortsvariablen
	bool passwortrichtig=true;
	int eingabe, auswahl, auswahl2;
	essen essen1, essen2, essen3, essen4, essen5;
	do
	{
		passwortrichtig=true;
		cout << "Bitte geben Sie das Passwort ein." << endl;																//Passwortsabfrage
		cout << "(Das Passwort lautet " << passwort << ")" << endl;															//<- Diese Zeile ist nur dafuer da, dass Sie mein Programm verwenden koennen. In
		cin >> passworteingabe;																								//     dem eigentlichen Programm, wuerde sie natuerlich geloescht werden.
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
		cout << "(1) Menue anzeigen\n(2) Menue bearbeiten\n(3) Passwort aendern\n(4) Beenden" << endl;			
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
					cout << "Welchen Namen moechten Sie aendern?" << endl;														//Namen bearbeiten
					cin >> auswahl2;
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
					cout << "Welchen Preis moechten Sie aendern?" << endl;															//Preis bearbeiten
					cin >> auswahl2;
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
	}
	while(eingabe!=4);
	
	return 0;
}
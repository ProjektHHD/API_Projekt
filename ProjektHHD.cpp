#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{ int a,b,c,d,e;
	
	double preis1=1, preis2=1, preis3=1, preis4=1, preis5=1, preis, Gesamtpreis=0;
	char name1[20]={"essen1"}, name2[20]={"essen2"}, name3[20]={"essen3"}, name4[20]={"essen4"}, name5[20]={"essen5"};
	int Auswahl, menge;
	int menge1=0, menge2=0, menge3=0, menge4=0, menge5=0;
	
	char choice='y';
	
	cout << "------------M E N U---------------" << endl;
	cout <<fixed<<setprecision(2)<<"1. "<< preis1<<" Euro  "<<name1<< endl;
	cout <<fixed<<setprecision(2)<<"2. "<< preis2<<" Euro  "<<name2<< endl;
	cout <<fixed<<setprecision(2)<<"3. "<< preis3<<" Euro  "<<name3<< endl;
	cout <<fixed<<setprecision(2)<<"4. "<< preis4<<" Euro  "<<name4<< endl;
	cout <<fixed<<setprecision(2)<<"5. "<< preis5<<" Euro  "<<name5<< endl;
	cout <<"6. Beenden"<<endl;
	
	do{
	do
	{
		cout << "Was moechten Sie bestellen?" << endl;
		cin >> Auswahl;
		if (Auswahl !=6){
		cout << "Wie viele moechten Sie davon kaufen?" << endl;
		cin >> menge;
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
			Gesamtpreis += preis;}      //2.4.1           
	}
	while(Auswahl !=6); //2.2.1
	

	cout << "Bestellte Produkte:" << endl;
		if (menge1 !=0){
			cout << name1 << " " << menge1 << " Stueck"<<endl;}
		if (menge2!=0){
			cout << name2 << " " << menge2 << " Stueck"<<endl;}
		if (menge3!=0){
			cout << name3 << " " << menge3 << " Stueck"<<endl;}
		if (menge4!=0){
			cout << name4 << " " << menge4 << " Stueck"<<endl;}
		if (menge5!=0){
			cout << name5 << " " << menge5 << " Stueck"<<endl;} //2.2.2
	cout<< "Gesamtpreis = "<<Gesamtpreis<<endl; //2.4.2

	do {
        cout<< "Haben Sie alles richtig bestellt?(Y/N)" << endl;
        cin >> choice;
	}while(choice !='y' && choice!='Y' && choice !='n' && choice!='N');
		
}while (choice !='y' && choice!='Y');



	return 0;
}
			

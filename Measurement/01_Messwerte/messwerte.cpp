#include <iostream>
#include <random>
#include <algorithm>
#include<functional>
#include<iomanip> 
using namespace std;

int varWahl; //Eingabe 1-8
int const constAnzahl = 100; //Anzahl der Messwerte
double varRandom = 0;	
double a_Zufallswert[constAnzahl];

int main(){

	//Programm
	cout << "--- Statische Kenndaten der Messreihe ---" << endl;
	cout << "[1]\tMinimum der Messwerte\n"
		<< "[2]\tMaximum der Messwerte\n"
		<< "[3]\tMedian der Messwerte\n"
		<< "[4]\tSpannweite der Messwerte\n"
		<< "[5]\tMittelwert der Messwerte\n"
		<< "[6]\tMittlere Abweichung der Messwerte\n"
		<< "[7]\tAnzeigen aller Messwerte\n"
		<< "[8]\tProgrammende\n\n"
		<< "W�hlen Sie :  ";
	cin >> varWahl;

	//Random Generator 
	random_device rd;
	mt19937 generator(rd());
	double minZ = 0.0, maxZ = 20.0;
	uniform_real_distribution<double>verteilung(minZ, maxZ);

	// Messergebnisse
	for (int i = 0; i < constAnzahl; i++)
	{
		varRandom = (verteilung(generator));
		a_Zufallswert[i] = varRandom;
	}

	//Manipulierung von nach kommastellen
	cout.setf(ios::fixed);
	cout << setprecision(2);

	//Sortierung
	sort(a_Zufallswert, a_Zufallswert + constAnzahl, less<double>());
	//for (int i = 0; i < varAnzahl; i++) { cout << a_Zufallswert[i] << "\t"; }

	//Auswahl
	if (varWahl == 1)
	{
	//Minimum
		cout << "Minimalwert der Messreihe:" << a_Zufallswert[0] << endl;
	}
	else if (varWahl == 2)
	{
	//Maximum
		cout << "Maximal der Messreihe:" << a_Zufallswert[constAnzahl -1] << endl;
	}
	else if (varWahl == 3)
	{
	//Median Variablen
		int Zahlen = 0;
		double median = 0;
		int wert;
	//median
		Zahlen = constAnzahl;
		if (Zahlen % 2 == 0) 
		{
			median = (a_Zufallswert[(Zahlen / 2) - 1] + a_Zufallswert[Zahlen / 2]) / 2; 
		}
		else 
		{
			wert = Zahlen / 2 + 0.5;
			median = a_Zufallswert[wert];
		}
		cout << "Median der Messreihe:" << median << endl;
	}
	else if (varWahl == 4)
	{
		//Spannweite Variablen
		double varSpannweite;
		//Spannweite
		varSpannweite = a_Zufallswert[constAnzahl - 1]- a_Zufallswert[0];
		cout << "Spannweite der Messreihe:" << varSpannweite << endl;
	}
	else if (varWahl == 5)
	{
		//Mittelwert variablen
		double rechnung = 0;
		double varMittelwert = 0;
		//Mittelwert
		for (int i = 0; i < constAnzahl; i++) {
			rechnung = rechnung + a_Zufallswert[i];
		}
		varMittelwert = rechnung / constAnzahl;
		cout << "Mittelwert der Messreihe:"<< varMittelwert << endl;
	}
	else if (varWahl == 6)
	{
		//mittlere abweichung variablen
		double rechnung = 0;
		double varAbweichung = 0;
		double a_ergebniss[constAnzahl];
		double varMittelwert;
		for (int i = 0; i < constAnzahl; i++) {
			rechnung = rechnung + a_Zufallswert[i];
		}
		varMittelwert = rechnung / constAnzahl;

		for (int i = 0; i < constAnzahl; i++)
		{
			if (a_Zufallswert[i] > varMittelwert)
			{
				a_ergebniss[i] = a_Zufallswert[i] - varMittelwert;
			}
			else 
			{
				a_ergebniss[i] = varMittelwert - a_Zufallswert[i];
			}
		}
		rechnung = 0;
		for (int i = 0; i < constAnzahl; i++) {
			rechnung = (a_ergebniss[i]) + (rechnung);
		}
		varAbweichung = rechnung / constAnzahl;

		cout << "mittlere Abweichung der Messreihe:" << varAbweichung << endl;
	}
	else if (varWahl == 7)
	{
		cout << "Die komplette Messreihe:" << endl;
		for (int i = 0; i < constAnzahl; i++) { cout << a_Zufallswert[i] << "\t"; }
		cout << "        " << endl;
	}
	else if (varWahl == 8)
	{
		return 0;
	}
	system("pause");
	return 0;
}
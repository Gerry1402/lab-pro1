#include <iostream>
using namespace std;

int main() {
	int hora, minut, temps;
	cin >> hora >> minut >> temps;

	if (temps == 0) {
		cout << 0 << endl;
	}

	int campanes_total = 0;
	int campanes_hora = 10;
	int campanes_dia = 24 * campanes_hora + 12 * 12 + 100;

	int dies = temps / (24 * 60);
	int hores = temps / 60 % 24;

	int quarts = temps % 60 / 15 +
				 ((minut % 15 == 0 && temps % 15 != 0) || (temps % 15 + minut % 15) > 15 ? 1 : 0);
	if (quarts % 4 == 0) {
		hores += quarts / 4;
		quarts = 0;
	} else {
		int quart_inicial = ( minut + temps%15 )/ 15 ;
		int quart_final = (quart_inicial + quarts) % 5;
		int quarts_restants = 4 - quarts;
		if (quart_final > quart_inicial){
			campanes_total += 10 - quarts_restants*(quarts_restants + 1)/2;
		}
	}

	if (hora * 60 + minut <= 12 * 60 && hora * 60 + minut + temps % (24 * 60) > 12 * 60) {
		campanes_total += 100;
	}

	cout << dies << endl << hores << endl << quarts << endl << campanes_total << endl;
}
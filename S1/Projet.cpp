/*
 * Amina DJARFI MELOUAH
 * 
 * 
 * 
 * 
 */

#include "Projet.h"
#include <iostream>
#include <map>
using namespace std;

/*
 * construireParc : procédure permet d'initialiser un parc
 *
 */
void construireParc(Parc&);

/*
 * dab (distrebuteur automatique des billets): procédure
 * qui simule une caisse automatique
 */
void dab(Parc&);

/*
 * dab_paiement -- Fonction permet la gestion du paiement
 * 
 */
double dab_paiement(double);



int main(int argc, char **argv) {

	Parc parc("Parc");

	construireParc(parc);

	dab(parc);

	return 0;
}

double dab_paiement(double tarif){

	int nb_retry(5);
	int billet;
	int tbillet(0);

	cout << "Les billets acceptées: 5€, 10€ et 20€ " << endl;

	while(true){

		cin>>billet;

		tbillet = tbillet + billet;

		if (nb_retry == 0){

			cout << "opération annulée" << endl;
			return tbillet;
		}

		if (tbillet % 5 != 0){
			cout << "Les billets acceptées: 5€, 10€ et 20€ " << endl;
			cout << "La machine n'accepte pas la monnaie " << endl;
			tbillet = 0;

			nb_retry--;
			continue;
		}

		if (tbillet<tarif){

				cout << "Reste à payé : " << tarif - tbillet<< "€ "<< endl;
				//nb_retry--;
				continue;

			} else{
				cout << "Paiement accepté" << endl;
				return tbillet - tarif;

			}
	}


	return 0;
}

/*
 * dab (distrebuteur automatique des billets): procédure
 * qui simule une caisse automatique
 */

void dab(Parc &parc) {

	int select;

	cout << "Bienvenu: choisissez une attraction" << endl;

	int opt_size = parc.options.size();

	if (opt_size > 1) {

		parc.afficherOptions();

		cin >> select;
	} else if (opt_size == 1) {
		select = 1;
	} else {
		return;
	}

	Attraction attraction = parc.SelectOption(select);

	opt_size = attraction.options.size();

	if (opt_size > 1) {

		cout << "Vous avez choisi: " << attraction.nom << endl;

		attraction.afficherOptions();

		cin >> select;
	} else if (opt_size == 1) {
		select = 1;
	} else {
		return;
	}

	Programme prog = attraction.SelectOption(select);

	opt_size = prog.options.size();

	if (opt_size > 1) {

		cout << "Vous avez choisi: " << prog.nom << endl;

		prog.afficherOptions();

		cin >> select;
	} else if (opt_size == 1) {
		select = 1;
	} else {
		return;
	}

	Tarif tarif = prog.SelectOption(select);

	cout << "Vous avez choisi: " << tarif.nom << endl;

	cout << "Entrez la quantité" << endl;

	int quantite(1);

	cin >> quantite;

	double prix = quantite * tarif.tarif;

	cout << "Total à payé:" << prix << "€" << endl;

	cout << "Les billets acceptées: 10, 20 et 5e." << endl;

	cout << "La machine n'accepte pas la monnaie mais en rend." << endl;

	

	cout << "Calcul de rendu de monnaie." << endl;

	double monnaie = dab_paiement(prix);

	cout << "Voici la monnaie: " << monnaie << endl;

}

/*
 * construireParc : procédure permet d'initialiser un parc
 *
 */

void construireParc(Parc &parc) {

	cout << "init" << endl;

	Attraction att1("Jeu");

	Programme p11("manège");
	p11.ajouterOption("Billet de 1-5", 1.3);
	p11.ajouterOption("Carnet de 5 billets", 5.0);

	att1.ajouterOption(p11);

	Programme p12("stand de tire");
	p12.ajouterOption("Billet de 1-5", 1.3);
	p12.ajouterOption("Carnet de 5 billets", 5.0);

	att1.ajouterOption(p12);

	//att1.afficherOptions();

	parc.ajouterOption(att1);

	Attraction att2("Spectacle");

	Programme p21("Spectacle");
	p21.ajouterOption("Billet M", 2.2);
	p21.ajouterOption("Billet S", 2.5);

	att2.ajouterOption(p21);

	parc.ajouterOption(att2);

	//parc.afficherOptions();

}

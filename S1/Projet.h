#ifndef PROJET_H
#define PROJET_H


#include <iostream>
#include <map>
using namespace std;
/*
 * Class Tarif
 */
class Tarif {
public:
	string nom;
	double tarif;

	Tarif(string nom, double tarif) {
		this->nom = nom;
		this->tarif = tarif;
	}

};

class Programme {
public:
	string nom;
	std::map<int, Tarif> options;

	Programme();
	Programme(string nom) {
		this->nom = nom;
	}

	int ajouterOption(string nom, double tarif) {
		int id = this->options.size() + 1;

		this->options.emplace(id, Tarif(nom, tarif));

		return id;
	}

	/*
	 * affichage des options disponible
	 *
	 */
	void afficherOptions() {
		cout << "Tarifs: " << this->nom << endl;
		std::map<int, Tarif>::iterator i;
		for (i = this->options.begin(); i != this->options.end(); ++i) {
			cout << "Choix n° " << i->first << " : [ " << i->second.nom << ": "
					<< i->second.tarif << " € ]" << endl;
		}
	}

	/*
	 * retourne la valeur/l'objet de l'option selectionné
	 */
	Tarif SelectOption(int i) {
		return this->options.at(i);
	}
};

class Attraction {
public:
	string nom;

	std::map<int, Programme> options;
	Attraction();

	Attraction(string nom) {
		this->nom = nom;
	}

	int ajouterOption(Programme option) {
		int id = this->options.size() + 1;

		this->options.emplace(id, option);

		return id;
	}

	void afficherOptions() {
		cout << "Attractions: " << this->nom << endl;
		std::map<int, Programme>::iterator i;
		for (i = this->options.begin(); i != this->options.end(); ++i) {
			cout << "Choix n° " << i->first << " : [ " << i->second.nom << " ]"
					<< endl;
		}
	}

	/*
	 * retourne la valeur/l'objet de l'option selectionné
	 */

	Programme SelectOption(int i) {
		return this->options.at(i);
	}
};

class Parc {
public:
	string nom;
	std::map<int, Attraction> options;
	Parc();

	Parc(string nom) {
		this->nom = nom;
	}

	int ajouterOption(Attraction option) {
		int id = this->options.size() + 1;

		this->options.emplace(id, option);

		return id;
	}
	/*
	 * retourne la valeur/l'objet de l'option selectionné
	 */

	void afficherOptions() {
		cout << "Attractions: " << this->nom << endl;
		std::map<int, Attraction>::iterator i;
		for (i = this->options.begin(); i != this->options.end(); ++i) {
			cout << "Choix n° " << i->first << " : [ " << i->second.nom << " ]"
					<< endl;
		}
	}

	Attraction SelectOption(int i) {

		return this->options.at(i);
	}
};


#endif
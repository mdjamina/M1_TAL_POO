/*
 * sans titre.cxx
 * 

 * 
 * 
 */
#include <iostream>
#include <map>
using namespace std;

class Tarif {
public:
	string nom;
	double tarif;

	Tarif(string nom, double tarif){
		this->nom = nom;
		this->tarif = tarif;
	}

};

class Programme {
public:
	string nom;
	std::map<int, Tarif> options;

	Programme();
	Programme(string nom){
		this->nom = nom;
	}

	int ajouterOption(string nom,double tarif){
		int id = this->options.size() + 1;
		
		this->options.emplace(id,Tarif(nom, tarif));
		
		return id;
	}
	
	void afficherOptions(){
		cout << "Tarifs: " << this->nom <<endl;
		std::map<int,Tarif>::iterator i;
		for ( i=this->options.begin() ;i!=this->options.end(); ++i){
			cout<< "Choix n° " << i->first << " : [ " << i->second.nom << ": " <<  i->second.tarif << " € ]"<< endl;
		}
	}

	Tarif SelectOption(int i){
		return this->options.at(i);
	}
};

class Attraction {
public:
	string nom;

	std::map<int, Programme> options;
	Attraction();
	
	Attraction(string nom){
		this->nom = nom;
	}
	
	int ajouterOption(Programme option){
		int id = this->options.size() + 1;
		
		this->options.emplace(id,option);
		
		return id;
	}
	
	void afficherOptions(){
		cout << "Attractions: " << this->nom <<endl;
		std::map<int,Programme>::iterator i;
		for ( i=this->options.begin() ;i!=this->options.end(); ++i){
			cout<< "Choix n° " << i->first << " : [ " << i->second.nom << " ]"<< endl;
		}
	}

	Programme SelectOption(int i){
		return this->options.at(i);
	}
};

class Parc {
public:
	string nom;
	std::map<int, Attraction> options;
	Parc();

	Parc( string nom){
		this->nom = nom;
	}
	
	int ajouterOption(Attraction option){
		int id = this->options.size() + 1;
		
		this->options.emplace(id,option);
		
		return id;
	}
	
	void afficherOptions(){
		cout << "Attractions: " << this->nom <<endl;
		std::map<int,Attraction>::iterator i;
		for ( i=this->options.begin() ;i!=this->options.end(); ++i){
			cout<< "Choix n° " << i->first << " : [ " << i->second.nom << " ]"<< endl;
		}
	}

	Attraction SelectOption(int i){

		return this->options.at(i);
	}
};

void construireParc(Parc&);

void caisse(Parc& parc){

	int select;

	cout << "Bienvenu: choisissez une attraction" << endl;

	int opt_size = parc.options.size();

	if ( opt_size > 1){

		parc.afficherOptions();

		cin >> select;
	}
	else if (opt_size == 1){
		select = 1;
	}
	else{
		return;
	}

	Attraction attraction = parc.SelectOption(select);
	
	opt_size = attraction.options.size();

	if ( opt_size > 1){
		
		cout << "Vous avez choisi: " << attraction.nom << endl;

		attraction.afficherOptions();

		cin >> select;
	}
	else if (opt_size == 1){
		select = 1;
	}
	else{
		return;
	}

	Programme prog = attraction.SelectOption(select);

	opt_size = prog.options.size();

	if ( opt_size > 1){
		
		cout << "Vous avez choisi: " << prog.nom << endl;

		prog.afficherOptions();

		cin >> select;
	}
	else if (opt_size == 1){
		select = 1;
	}
	else{
		return;
	}

	Tarif tarif = prog.SelectOption(select);
	
	cout << "Vous avez choisi: " << tarif.nom << endl;
	
	cout << "Entrez la quantité" << endl;
	
	int quantite(1);
	
	cin >> quantite;
	
	double prix = quantite * tarif.tarif;
	
	cout << "Total à payé:" << prix << "€" <<endl;
	
	cout << "Les billets acceptées: 10, 20 et 5e." << endl;
	
	cout << "La machine n'accepte pas la monnaie mais en rend." << endl;

	int billet(1);
	
	cin >> billet;
	
	cout << "Calcul de rendu de monnaie." << endl;
	
	double monnaie = billet - prix;
	
	cout << "Voici la monnaie: " << monnaie << endl;

}

int main(int argc, char **argv)
{
	cout << "hello" << endl;

	Parc parc("Parc");

	construireParc(parc);
	
	caisse(parc);

	cout << "fin 3" << endl;
	
	return 0;
}

void construireParc(Parc& parc){

	cout<< "init" <<endl;
	
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

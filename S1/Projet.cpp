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


int main(int argc, char **argv)
{

    cout << "hello" << endl;

	Parc parc("Parc");


	construireParc(parc);
	
	
	parc.afficherOptions();


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

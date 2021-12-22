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

	Programme(string nom){
        this->nom = nom
    }
	
	int ajouterOption(string nom,double tarif){
		int id = this->options.size() + 1;
		
		this->options.emplace(id,new Tarif(nom, tarif));
		
		return id;
	}
	
	void afficherOptions(){
		cout << "Tarifs: " << this->nom <<endl;
		std::map<int,Tarif>::iterator i;
		for ( i=this->options.begin() ;i!=this->options.end(); ++i){

            cout<< "Choix n° " << i->first << " : [" << i->second.nom << ": " <<  i->second.tarif<< endl;
			
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
	
	int ajouterOption(string nom){
		int id = this->options.size() + 1;
		
		this->options.emplace(id,new Programme(nom));
		
		return id;
	}
	
	void afficherOptions(){
		cout << "Attractions: " << this->nom <<endl;
		std::map<int,Programme>::iterator i;
		for ( i=this->options.begin() ;i!=this->options.end(); ++i){

            cout<< "Choix n° " << i->first << " : [" << i->second.nom << " ]"<< endl;
			
	    }
    }

    Programme SelectOption(int i){

        return this->options.at(i);
    
	}
};





int main(int argc, char **argv)
{

    cout << "hello" << endl;


	
	return 0;
}


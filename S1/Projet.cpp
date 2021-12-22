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
        //this->options = new std::map<int, Tarif>();
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
        //this->options = new std::map<int, Programme>::map();


        
    }
	
	int ajouterOption(string nom){
		int id = this->options.size() + 1;
		
		this->options.emplace(id,Programme(nom));
		
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
       // this->options = new std::map<int, Attraction>();

    }
	
	int ajouterOption(string nom){
		int id = this->options.size() + 1;
		
		this->options.emplace(id,Attraction(nom));
		
		return id;
	}
	
	void afficherOptions(){
		cout << "Attractions: " << this->nom <<endl;
		std::map<int,Attraction>::iterator i;
		for ( i=this->options.begin() ;i!=this->options.end(); ++i){

            cout<< "Choix n° " << i->first << " : [" << i->second.nom << " ]"<< endl;
			
	    }
    }

    Attraction SelectOption(int i){

        return this->options.at(i);
    
	}
};




int main(int argc, char **argv)
{

    cout << "hello" << endl;


    Programme p("manège");

    

    p.ajouterOption("Billet de 1-5", 1.3);
		
	p.ajouterOption("Carnet de 5 billets", 5.0);


    p.afficherOptions();


    cout << "fin" << endl;


	
	return 0;
}


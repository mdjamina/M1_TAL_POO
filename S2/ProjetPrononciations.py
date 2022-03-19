#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import re


class Tokenizer:
    """classe Tokenizer pour le français en utilisant des regex
    """

    def __init__(self,text) -> None:
        pattern = r"([A-Za-z]{1,2}\'|[Qq]u\w*\'|(?:\w+\-\w+\-?\w+)+|(?:\w+\'\w+)+|\w+)"
        self.text = text
        self.words = re.findall( pattern,text)

    def tokens(self):
        """transforme un text orthographique en tokens
        """ 
        return  self.words

    def distrib(self):
        """Trier la liste et afficher la distribution
        """
        return sorted({w:self.words.count(w) for w in self.words}.items(), key=lambda x: x[1], reverse=True)


class Prononciation(Tokenizer):


    def load_dict_prono(self,path_dict_file):
        self.dict_prono = {}

        with open(path_dict_file,'r') as fdict:
            for line in fdict:
                row = line.split()
                k = row[0]
                v = row[1]
                if k not in self.dict_prono.keys():
                    self.dict_prono[k] = v
    
    def prononciation(self):
        """retourne la liste des mots prononcés
        """
        for w in set(self.tokens()):
            if w in self.dict_prono.keys():
                yield (w,self.dict_prono[w]) 

    def prononciation_text(self):
        """retourne le texte en prononciation
        """
        return ' '.join([w for _,w in self.prononciation()])



def main():
    """
    Exemple:
    python3 ProjetPrononciations.py basique-pron_dico.dic FRA00101_T2FSL.txt >result.txt
    
    """
    args = sys.argv[1:]

    dict_prono_path = args[0]

    file_path= args[1]


    with open(file_path,'r') as filein:
        text = filein.read()


    pron = Prononciation(text)

    pron.load_dict_prono(dict_prono_path)

    """

    
    for (k,w) in pron.prononciation():
        print('{0} --> {1}'.format(k,w))

    """


    #print(pron.text)    
    print(pron.prononciation_text())

if __name__ == '__main__':

    main()


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



def main():
    args = sys.argv[1:]


    text = """
    veillée nombre innombrable hiver être maison ...  train prêcher petiot — criait-elle dépêcher balayer 
    maison  pomme matin prendre 
    couvet emplis-le habile habile désirer  terluit comme dos citrouille frotte frotte là faire  ménager|ménagère voilà 
     saint-brunelle mirer armoire noyer .
    fieu père roux berger oreille être avis pourtant bassette être raboter genre planche défunt père être charron ne être pas...
    j'ai un porte-feuille
    test quelqu'un et qu'il y'a
    """


    toknzer = Tokenizer(text)


    print(toknzer.distrib())



if __name__ == '__main__':

    main()


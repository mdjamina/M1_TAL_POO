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


    text = "Bonjour! je suis ravi de faire faire ta co-and, merci? J'aime. mots-compo. faire avance-t-il. aujourd'hui. Qu'il y'a"


    toknzer = Tokenizer(text)


    print(toknzer.distrib())



if __name__ == '__main__':

    main()


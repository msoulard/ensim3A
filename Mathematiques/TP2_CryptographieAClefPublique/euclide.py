# -*- coding: utf-8 -*-
"""
Created on Wed Oct 13 2021

@author: e2103704
"""

def euclide(a, b):
    if a < b :
        tempo = a
        a = b
        b= tempo
    r = b
    while r != 0 :
        r = a%b
        a = b
        b = r
    
    return a

pgcd = euclide(9, 2007)
print("Le pgcd de 9 et 2007 est ", pgcd)

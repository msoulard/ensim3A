# -*- coding: utf-8 -*-
"""
Created on Tue Nov  9 10:41:35 2021

@author: e2103704
"""

def erathostene(n) :
    tempo = 2
    i = 0
    tab =  []
    tabFinale = []    
    while tempo <= n :
        #print(tempo)
        tab.append(tempo)
        tempo = tempo + 1                
        #print(" ", tab[i])
        i = i + 1
    taille = len(tab)
    i = 0
    for i in range (0, taille, 1) :
        if tab[i] != 0:
            tempo = tab[i]
            for j in range (i+1, taille, 1):
                if tab[j] != 0 :
                    if tab[j]%tempo == 0 :
                        tab[j] = 0
        print(" ", tab[i])
    j = 0
    for i in range (0, taille, 1) :
        if tab[i] != 0:
            tabFinale.append(tab[i])
            #print(" ", tabFinale[j])
            j = j + 1
    return tabFinale

tab = erathostene(50)
print("Les nombres premiers de 50 sont : ")
for i in range(0, len(tab), 1):
    print(" ", tab[i])
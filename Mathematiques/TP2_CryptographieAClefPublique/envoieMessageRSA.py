# -*- coding: utf-8 -*-
"""
Created on Tue Nov  9 12:18:19 2021

@author: e2103704
"""
from random import randint

def bezout (a, b):
    q = 0
    r = 0
    u0 = 1
    u1 = 0
    v0 = 0
    v1 = 1
    """if a < b :
        tempo = a
        a = b
        b = tempo """
    while b != 0 :
        r = a%b
        q = a//b
        a = b
        b = r
        s = u1
        u1 = u0-u1*q
        u0 = s
        s = v1
        v1 = v0 - v1 * q
        v0 = s
    return a, u0, v0

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
        #print(" ", tab[i])
    j = 0
    for i in range (0, taille, 1) :
        if tab[i] != 0:
            tabFinale.append(tab[i])
            #print(" ", tabFinale[j])
            j = j + 1
    return tabFinale

def gen_p(n) :
    tab = erathostene(n)
    p = 0
    q = 0
    while p == q or p < n or q < n:
        p = tab[randint(0, len(tab))]
        q = tab[randint(0, len(tab))]
    return p, q


p,q = gen_p(55)
print("p = ", p)
print("q = ", q)
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 12 14:01:53 2017

@author: maugeais
"""

import numpy as np
import math

# Calcul n**l modulo p
def pw(p, n, l) :
    
    ap =  n

    
    if (l % 2 == 1) :
        a = ap
    else :  
        a = 1
        
    while (l != 0) :
        
        l = l//2
        
        ap =(ap**2)%p
        
        if (l % 2 == 1) :
            a = (ap*a) % p
    
    return(a)
        

# recherche tous les nombres premiers <= N
def eratosthene(N) :
    
    N = int(N)
    
    L = [True for n in range(N+1)]
    L[0] = False
    L[1] = False
    
    for n in range(2, int(math.sqrt(N))+1) :
        
        if (L[n]) :
        
            j = 2*n 
        
            while(j <= N) :
                L[j] = False
                j += n
            
    return(np.where(L)[0])
    
    
# Calcul une décomposition en facteurs premiers de n   
def factor(n):
    
    L = eratosthene(n)
    
    F = []
    
    for p in L :
        
        power = 0
        
        while ( n % p  == 0) :
            n = n//p
            power+=1
            
        if (power > 0):
            F.append([p, power])
            
    return(F)

# Teste si g est un générateur de (Z/pZ)^*
# On "rappelle" que g est un générateur si et seulement si g**((p-1)/q) != 1
# pour chaque diviseur premier q de  p-1
def is_gen(g, p) :
    
    # Calcule une décompposition en facteurs premiers de p-1
    F = factor(p-1)
    
    for d in F :
        
        if ( pw(p, g, (p-1)/d[0]) == 1) :
            return(False)
            
    return(True)

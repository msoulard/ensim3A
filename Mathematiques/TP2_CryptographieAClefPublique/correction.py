# -*- coding: utf-8 -*-
"""
Created on Thu Oct 12 14:01:53 2017

@author: maugeais
"""

import numpy as np
import math
from random import randint

def pgcd(a, b) :
    
    
    while(b != 0) :
        r = a%b
        
        a=b; b=r;
       
    return(a)
    
def bezout(a, b) :
    
    u0 = 1; u1 = 0; v0 = 0; v1 = 1
    
    while(b != 0) :
        q = a//b
        r = a%b
        
        a=b; b=r;
        s=u1; u1=u0-u1*q; u0=s
        s=v1; v1=v0-v1*q; v0=s
        
    return(a, u0, v0)

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
        
# recherche tous les nombres premiers <= N, on enleve tous les nombres pairs
def eratosthene2(N) :
    
    N = int(N)
    
    #L = np.ascontiguousarray([True for n in range(N+1)])
    L = [False, True]*(N//2+1)
    L = L[:N+1]
    L[0] = False
    L[1] = False
    L[2] = True
    
    for n in range(3, int(math.sqrt(N)), 2) :
        
        if (L[n]) :
        
            L[2*n:N+1:n] = [False]*((N-n)//n)
            
    return([i for i, a in enumerate(L) if a])


# recherche tous les nombres premiers <= N
def eratosthene(N) :
    
    N = int(N)
        
    #L = np.ascontiguousarray([True for n in range(N+1)])
    L = [True]*(N+1)
    L[0] = False
    L[1] = False
    
    for n in range(2, int(math.sqrt(N)+1)) :
        
        if (L[n]) :
            
            L[2*n:N+1:n] = [False]*((N-n)//n)

            
    #return(np.where(L)[0])
    return([i for i, a in enumerate(L) if a])
    
# generation de deux nombres premiers, de taille <= 10*N et >= N
def gen_p(N = 1e6) :
    
    L = eratosthene(10*N)
    
    p = L[randint(0, len(L))]
    
    while(p < N) :
        p = L[randint(0, len(L))]

    q = L[randint(0, len(L))]
    
    while(q < N or q == p) :
        q = L[randint(0, len(L))]

    return(p, q)
    
def clef_rsa():
    
    # FGeneration des premiers
    p, q = gen_p()
    n = p*q
    phi = (p-1)*(q-1)
    
    e = randint(0, phi)
    
    while(pgcd(e, phi) != 1) :
        e = randint(0, phi)

    _, d, _ = bezout(e, phi)
    
    d %= phi
    
    return(n, e, d)
    
def code_rsa(n, e, m) :
    return(pw(n, m, e))
    
def decode_rsa(n, d, M) :
    return(pw(n, M, d))
    

    
    
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

#import time
#
#time.clock()
#print(len(wheel(int(1e8))))
##print(len(eratosthene(int(1e8))))
#print(time.clock())
# -*- coding: utf-8 -*-

import numpy as np

G = np.matrix([[1, 1, 0, 1], [1, 0, 1, 1], [1, 0, 0, 0], [0, 1, 1, 1], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]], dtype = int)

# Calcule la distance de Hamming du code engendré par G
def d_ham(G) :
    n, p = G.shape
    
    D = []
    # Génére tous les vecteurs de F_2^p
    
    for i in range(1, 2**p) :
        b = "{0:b}".format(i)
        b += '0'*(p-len(b))
        X = np.reshape([int(a) for a in b], [p, 1])
                
        D.append((G*X%2).sum())
        
    return(min(D))
    
# Gauss
def gauss(G) :
    
    G = np.matrix.copy(G)
    n, p = G.shape
    
    H = np.matrix(np.eye(n))
    
    # Triangularisation
    for j in range(p) :
        for i in range(j+1, n):
            
            # On suppose que le pivot est toujours non nul
            a = G[i, j]/G[j, j]
            G[i, :] = (G[i, :] + a*G[j, :])%2
            H[i, :] = (H[i, :] + a*H[j, :])%2
            
    # Remontée
            
    for j in reversed(range(p)):
        for i in range(j) :
            
            a = G[i, j]/G[j, j]
            
            G[i, :] = (G[i, :] + a*G[j, :])%2
            H[i, :] = (H[i, :] + a*H[j, :])%2
            
    return(H[:p, :], H[p:, :])
    
# Calcule la table des syndromes
def syndrom(n, t) :
    
    if (n == 0) :
        return([[]])
        
    if (t == 0) :
        return([[0 for a in range(n)]])
        
    # Maintenant, n > 0 et t > 0
    
    L = []

    # On rajoute les syndrome avec premier bit = 0    
    L0 = syndrom(n-1, t)
    
    for S in L0 :
        L += [[0]+S]
        
    # Puis on rajoute les syndrome commençant par 1
        
    L0 = syndrom(n-1, t-1)
    
    for S in L0 :
        L += [[1]+S]
        
    return(L)
            
        
        
        
#d = d_ham(G)
#S = syndrom(6, int((d-1)/2))

gauss(G)
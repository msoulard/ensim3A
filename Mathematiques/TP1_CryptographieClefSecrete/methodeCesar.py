# -*- coding: utf-8 -*-
"""
Created on Wed Oct 13 2021

@author: e2103704
"""
import string

def numDecalage(chaine):
    decalage = 0
    maxi = 0
    nbA = 0
    nbB = 0
    nbC = 0
    nbD = 0
    nbE = 0
    nbF = 0
    nbG = 0
    nbH = 0
    nbI = 0
    nbJ = 0
    nbK = 0
    nbL = 0
    nbM = 0
    nbN = 0
    nbO = 0
    nbP = 0
    nbQ = 0
    nbR = 0
    nbS = 0
    nbT = 0
    nbU = 0
    nbV = 0
    nbW = 0
    nbX = 0
    nbY = 0
    nbZ = 0
    for i in range(0, len(chaine), 1):
        if(chaine[i] == 'a' or chaine[i] =='A'):
            nbA += 1
        elif(chaine[i] == 'b' or chaine[i] == 'B'):
            nbB += 1
        elif(chaine[i] == 'c' or chaine[i] == 'C'):
            nbC += 1
        elif(chaine[i] == 'd' or chaine[i] == 'D'):
            nbD += 1
        elif(chaine[i] == 'e' or chaine[i] == 'E'):
            nbE += 1
        elif(chaine[i] == 'f' or chaine[i] == 'F'):
            nbF += 1
        elif(chaine[i] == 'g' or chaine[i] == 'G'):
            nbG += 1
        elif(chaine[i] == 'h' or chaine[i] == 'H'):
            nbH += 1
        elif(chaine[i] == 'i' or chaine[i] == 'I'):
            nbI += 1
        elif(chaine[i] == 'j' or chaine[i] == 'J'):
            nbJ += 1
        elif(chaine[i] == 'k' or chaine[i] == 'K'):
            nbK += 1
        elif(chaine[i] == 'l' or chaine[i] == 'L'):
            nbL += 1
        elif(chaine[i] == 'm' or chaine[i] == 'M'):
            nbM += 1
        elif(chaine[i] == 'n' or chaine[i] == 'N'):
            nbN += 1
        elif(chaine[i] == 'o' or chaine[i] == 'O'):
            nbO += 1
        elif(chaine[i] == 'p' or chaine[i] == 'P'):
            nbP += 1
        elif(chaine[i] == 'q' or chaine[i] == 'Q'):
            nbQ += 1
        elif(chaine[i] == 'r' or chaine[i] == 'R'):
            nbR += 1
        elif(chaine[i] == 's' or chaine[i] == 'S'):
            nbS += 1
        elif(chaine[i] == 't' or chaine[i] == 'T'):
            nbT += 1
        elif(chaine[i] == 'u' or chaine[i] == 'U'):
            nbU += 1
        elif(chaine[i] == 'v' or chaine[i] == 'V'):
            nbV += 1
        elif(chaine[i] == 'w' or chaine[i] == 'W'):
            nbW += 1
        elif(chaine[i] == 'x' or chaine[i] == 'X'):
            nbX += 1
        elif(chaine[i] == 'y' or chaine[i] == 'Y'):
            nbY += 1
        elif(chaine[i] == 'z' or chaine[i] == 'Z'):
            nbZ += 1
    
    maxi = nbA    
    if maxi < nbB :
        maxi = nbB
    if maxi < nbC :
        maxi = nbC
    if maxi < nbD :
        maxi = nbD
    if maxi < nbE :
        maxi = nbE
    if maxi < nbF :
        maxi = nbF
    if maxi < nbG :
        maxi = nbG
    if maxi < nbH:
        maxi = nbH
    if maxi < nbI :
        maxi = nbI
    if maxi < nbJ :
        maxi = nbJ
    if maxi < nbK :
        maxi = nbK
    if maxi < nbL :
        maxi = nbL
    if maxi < nbM :
        maxi = nbM 
    if maxi < nbN :
        maxi = nbN 
    if maxi < nbO :
        maxi = nbO 
    if maxi < nbP :
        maxi = nbP 
    if maxi < nbQ :
        maxi = nbQ 
    if maxi < nbR :
        maxi = nbR 
    if maxi < nbS :
        maxi = nbS 
    if maxi < nbT :
        maxi = nbT 
    if maxi < nbU :
        maxi = nbU 
    if maxi < nbV:
        maxi = nbV 
    if maxi < nbW:
        maxi = nbW 
    if maxi < nbX:
        maxi = nbX 
    if maxi < nbY:
        maxi = nbY 
    if maxi < nbZ:
        maxi = nbZ
     
    if maxi == nbA :
        decalage = ord('e') - ord ('a')
    if maxi == nbB :
        decalage = ord('e') - ord ('b')
    if maxi == nbC :
        decalage = ord('e') - ord ('c')
    if maxi == nbD :
        decalage = ord('e') - ord ('d')
    if maxi == nbE :
        decalage = ord('e') - ord ('e')
    if maxi == nbF :
        decalage = ord('e') - ord ('f')
    if maxi == nbG :
        decalage = ord('e') - ord ('g')
    if maxi == nbH:
        decalage = ord('e') - ord ('h')
    if maxi == nbI :
        decalage = ord('e') - ord ('i')
    if maxi == nbJ :
        decalage = ord('e') - ord ('j')
    if maxi == nbK :
        decalage = ord('e') - ord ('k')
    if maxi == nbL :
        decalage = ord('e') - ord ('l')
    if maxi == nbM :
        decalage = ord('e') - ord ('m')
    if maxi == nbN :
        decalage = ord('e') - ord ('n')
    if maxi == nbO :
        decalage = ord('e') - ord ('o')
    if maxi == nbP :
        decalage = ord('e') - ord ('p')
    if maxi == nbQ :
        decalage = ord('e') - ord ('q')
    if maxi == nbR :
        decalage = ord('e') - ord ('r')
    if maxi == nbS :
        decalage = ord('e') - ord ('s')
    if maxi == nbT :
        decalage = ord('e') - ord ('t')
    if maxi == nbU :
        decalage = ord('e') - ord ('u')
    if maxi == nbV:
        decalage = ord('e') - ord ('v')
    if maxi == nbW:
        decalage = ord('e') - ord ('w')
    if maxi == nbX:
        decalage = ord('e') - ord ('x')
    if maxi == nbY:
        decalage = ord('e') - ord ('y')
    if maxi == nbZ:
        decalage = ord('e') - ord ('z')
        
    return decalage

chaineTrouvee = ''
chaineCrypptee = "mqa f'weia à bwena wllnajzna qj jkixna qpeha wqt owcao!"
decal = numDecalage(chaineCrypptee)
for i in range(0 , len(chaineCrypptee)-1, 1):
    if (ord(chaineCrypptee[i]) >= 65 and ord(chaineCrypptee[i]) <= 90):
           chaineTrouvee += chr(((ord(chaineCrypptee[i]) - 65 + decal) % 26) + 65)
    elif(ord(chaineCrypptee[i]) >= 97 and ord(chaineCrypptee[i]) <= 122):
                chaineTrouvee += chr(((ord(chaineCrypptee[i]) - 97 + decal) % 26) + 97)
    else:
         chaineTrouvee += chaineCrypptee[i]
            
print("La chaine trouvée est ", chaineTrouvee)    
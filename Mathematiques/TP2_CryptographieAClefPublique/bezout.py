# -*- coding: utf-8 -*-
"""
Created on Tue Nov  9 10:06:13 2021

@author: e2103704
"""

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

a,u,v=bezout(50,190)
print("pgcd(50, 190) = ", a, " = 50 x ", u, "+ 190 x ", v)
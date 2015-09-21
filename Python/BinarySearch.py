# -*- coding: utf-8 -*-
"""
Created on Fri Sep 18 20:41:35 2015

@author: Apurva Pathak
"""

def binary_search(arr,key):
    s=0
    e=len(arr)-1
    while(s<e):
        m=(s+e)/2
        if(arr[m]==key):
            return m
        elif(arr[m]<key):
            s=m+1
        else:
            e=m-1
    return -1


a=[1,2,3,4,5,6]
key=5
print binary_search(a,9)

        
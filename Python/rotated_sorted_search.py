# -*- coding: utf-8 -*-
"""
Created on Fri Sep 18 20:54:41 2015

@author: Apurva Pathak
"""

def rotated_sorted_search(arr,key):
    s=0
    e=len(arr)-1
    while(s<e):
        m=(s+e)/2
        if(arr[m]==key):
            return m
        if(arr[s]<=arr[m]):
            if(arr[s]<=key and arr[m]>key):
                e=m-1
            else:
                s=m+1                
        else:
            if(arr[m]<=key and arr[e]>=key):
                s=m+1
            else:
                e=m-1
    return -1


a=[3,4,5,6,1,2]
key=1
print rotated_sorted_search(a,key)
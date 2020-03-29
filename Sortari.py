import random
import time
import Teste

def BubbleSort(v):
    n = len(v)
    for i in range (n):
        for j in range (n-i-1):
            if v[j]>v[j+1]:
                v[j],v[j+1] = v[j+1],v[j]
    return v

def Partitie(v,mic,mare):
    i = (mic-1)
    pivot = v[mare]
    for j in range(mic, mare):
        if v[j] <= pivot:
            i=i+1
            v[i],v[j]=v[j],v[i]
    v[i+1],v[mare]=v[mare],v[i+1]
    return (i+1)

def QuickSort(v,mic,mare):
    if mic<mare:
        pi=Partitie(v,mic,mare)
        QuickSort(v,mic, pi-1)
        QuickSort(v,pi+1,mare)
    return v

def MergeSort(v):
    if len(v) > 1:
        mid = len(v) // 2
        L = v[:mid]
        R = v[mid:]
        MergeSort(L)
        MergeSort(R)
        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                v[k] = L[i]
                i += 1
            else:
                v[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            v[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            v[k] = R[j]
            j += 1
            k += 1
    return v


def CountSort(v, max):
    c = [0] * (max + 1)
    for i in range(len(v)):
        c[v[i]] = c[v[i]] + 1

    c[0] = c[0] - 1
    for i in range(1, max + 1):
        c[i] = c[i] + c[i - 1]

    result = [None] * len(v)

    for i in reversed(v):
        result[c[i]] = i
        c[i] = c[i] - 1
    for i in range(len(v)):
        v[i]=result[i]
    return v

def CountSort_Radix(v, place):
    size = len(v)
    output = [0] * size
    count = [0] * 10

    for i in range(0, size):
        index = v[i] // place
        count[index % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = size - 1
    while i >= 0:
        index = v[i] // place
        output[count[index % 10] - 1] = v[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(0, size):
        v[i] = output[i]

def RadixSort(v):
    max_element = max(v)
    place = 1
    while max_element // place > 0:
        CountSort_Radix(v, place)
        place *= 10
    return v

def Print(v):
    for i in range(len(v)):
        print(v[i],end=" ")
    print()

def timptestare(sortare):
    f = open("teste.in")
    v = Teste.testt(f)
    start = time.time()
    while v != []:
        if sortare == "CountSort":
            k = max(v)
            v = CountSort(v,k)
        elif sortare == "QuickSort":
            n = len(v)
            v = QuickSort(v,0,n-1)
        elif sortare == "sort":
            v.sort()
        else:
            v = sortare(v)
        v = Teste.testt(f)
        if time.time() - start>7:
            print("Timpul de sortare este prea lung")
            break

    print(time.time() - start)












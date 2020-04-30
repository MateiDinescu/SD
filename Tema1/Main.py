import Sortari
import Teste
a = ""

while a !="stop":
    print("1-Generare Teste, 2-Stergere Teste, 3-Sortare, 4-Numarul testelor, stop-Opreste programul")
    a = input()
    if a=="1":
        print("Numar teste:")
        n = int(input())
        print("Tipul testelor: 1-Numere mari, 2-Multe numere")
        a = input()
        if a=="1":
            Teste.numeremari(n)
        elif a=="2":
            Teste.multenumere(n)
    elif a=="2":
        Teste.clear()
    elif a=="3":
        print("Alege tipul de sortare: \n1-BubbleSort; \n2-QuickSort; \n3-MergeSort; \n4-CountSort; \n5-RadixSort; \n6-Sortare Python; ")
        a = input()
        if a=="1":
            Sortari.timptestare(Sortari.BubbleSort)
        elif a=="2":
            Sortari.timptestare("QuickSort")
        elif a=="3":
            Sortari.timptestare(Sortari.MergeSort)
        elif a=="4":
            Sortari.timptestare("CountSort")
        elif a=="5":
            Sortari.timptestare(Sortari.RadixSort)
        elif a=="6":
            Sortari.timptestare("sort")
    elif a=="4":
        print(sum(1 for line in open('teste.in')))

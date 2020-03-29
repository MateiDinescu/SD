import random
f = open("teste.in", "w")
def clear():
    f.seek(0)
    f.truncate()
def multenumere(n):
    for i in range(n):
        st = ""
        for j in range(random.randrange(10000,20000)):
            x = str(random.randrange(1000))
            st = st + x + ' '
        f.write(st)
        f.write('\n')
def numeremari(n):
    for i in range(n):
        st = ""
        for j in range(random.randrange(100,500)):
            x = str(random.randrange(20000000,200000000))
            st = st + x + ' '
        f.write(st+'\n')
def verificare(v):
    if(all(v[i] <= v[i+1] for i in range(len(v)-1))):
        return "Sunt sortate corect"
    else:
        return "Nu sunt sortate corect"
def testt(f):
    l=[int(x) for x in f.readline().split() if x[0].isdigit]
    return l
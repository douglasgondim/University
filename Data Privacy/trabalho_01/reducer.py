f = open('Dataset_Covid_CE.csv', 'r')
o = open('Dataset_Covid_CE_Reduzido.csv', 'w')

for (idx, x) in enumerate(f):
    if(idx % 1000 == 0):
        o.write(x)
    

f.close()
o.close()
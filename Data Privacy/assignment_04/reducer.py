f = open('../assignment_03/Dataset_Covid_CE.csv', 'r')
o = open('Dataset_Covid_CE_Reduzido.csv', 'w')

for (idx, x) in enumerate(f):
    if(idx % 100 == 0):
        o.write(x)
    

f.close()
o.close()
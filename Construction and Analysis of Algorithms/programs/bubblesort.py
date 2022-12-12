array = [1,6,10,2,3,5,8,4]

for i in range(len(array)):
    for j in range(len(array)-1-i):
        if(array[j] > array[j+1]):
            aux = array[j]
            array[j] = array[j+1]
            array[j+1] = aux

print(array)
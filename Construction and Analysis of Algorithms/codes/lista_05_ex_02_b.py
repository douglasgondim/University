def switch(array, i, j):
    aux = array[i]
    array[i] = array[j]
    array[j] = aux


def order(array):
    i = 0
    j = 0
    count = 0
    for k in range(len(array)):
        if(array[k]["value"] == -1):
            count += 1
    j = count
    while(j < len(array)):
        if(array[i]["value"] == 1):
            switch(array, i, j)
            j += 1
            aux = i
            while(aux < count-1):
                switch(array, aux, aux+1)
                aux += 1
        else:
            i += 1
        



array = []
obj = {
    "id": 0,
    "value": 1
}
array.append(obj)
obj = {
    "id": 1,
    "value": 1
}
array.append(obj)
obj = {
    "id": 2,
    "value": 1
}
array.append(obj)
obj = {
    "id": 3,
    "value": 1
}
array.append(obj)
obj = {
    "id": 4,
    "value": 1
}
array.append(obj)
obj = {
    "id": 5,
    "value": -1
}
array.append(obj)
obj = {
    "id": 6,
    "value": -1
}
array.append(obj)
obj = {
    "id": 7,
    "value": -1
}
array.append(obj)
obj = {
    "id": 8,
    "value": 1
}
array.append(obj)


order(array)
print(array)

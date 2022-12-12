array = [1,6,10,2,3,5,8,4]
print("Unordered array:")
print(array)
print("\n")
for i in range(1,len(array)):
    key = i
    while(array[key] < array[key-1] and key > 0):
        aux = array[key]
        array[key] = array[key-1]
        array[key-1] = aux
        key = key - 1

print("Ordered array:")
print(array)
print("\n")

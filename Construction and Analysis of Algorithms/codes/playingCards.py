def pickCards(cards, i, n):
    global comp1
    comp1 += 1
    if(n < i):
        return {"value": 0, "card": ""}
    elif(n == i):
        return {"value": cards[n], "card": n}
    else:
        temp1 = 0
        temp2 = 0
        if(cards[i+1] > cards[n]):
            temp1 = {"value": cards[i] + pickCards(cards, i+2, n)["value"], "card": i}
        else:
            temp1 = {"value": cards[i] + pickCards(cards, i+1, n-1)["value"], "card": i}
        
        if(cards[i] > cards[n-1]):
            temp2 = {"value": cards[n] + pickCards(cards, i+1, n-1)["value"], "card": n}
        else:
            temp2 = {"value": cards[n] + pickCards(cards, i, n-2)["value"], "card": n}
        
        if(temp1["value"] > temp2["value"]):
            return temp1
        else: 
            return temp2

def pickCardsMem(mem, cards, i, n):
    global comp2
    comp2 += 1
    if(n < i):
        return {"value": 0, "card": ""}
    elif(n == i):
        return {"value": cards[n], "card": n}
    elif(str(cards[i:n]) in mem):
        # print('meming', str(cards[i:n]))
        return mem[str(cards[i:n])]
    else:
        temp1 = 0
        temp2 = 0
        if(cards[i+1] > cards[n]):
            temp1 = {"value": cards[i] + pickCardsMem(mem, cards, i+2, n)["value"], "card": i}
        else:
            temp1 = {"value": cards[i] + pickCardsMem(mem, cards, i+1, n-1)["value"], "card": i}
        
        if(cards[i] > cards[n-1]):
            temp2 = {"value": cards[n] + pickCardsMem(mem, cards, i+1, n-1)["value"], "card": n}
        else:
            temp2 = {"value": cards[n] + pickCardsMem(mem, cards, i, n-2)["value"], "card": n}
        
        if(temp1["value"] > temp2["value"]):
            mem[str(cards[i:n])] = temp1
            return temp1
        else: 
            mem[str(cards[i:n])] = temp2
            return temp2

cards = [5, 10,7,4]

comp1 = 0
comp2 = 0

import random

array1 = []
for i in range(100):
    array1.append(random.randint(1,3000))

print(pickCardsMem({}, array1, 0, len(array1)-1))
print(comp2)
# print(pickCards(array1, 0, len(array1)-1))
# print(comp1)
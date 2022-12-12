import random
from itertools import combinations


def fillKnapsack(n, capacity):
    knapsack = []
    knapsack.append({"weight": 1})
    knapsack.append({"weight": 5})
    knapsack.append({"weight": 8})

    # for i in range(n):
    #     knapsack.append({"weight": random.randint(1,capacity)})
    return knapsack

def initializeResultsArr(n, capacity):
    results = []

    for i in range(n):
        results.append([])
        for j in range(capacity+1):
            results[i].append([])
    return results



def findCombination(knapsack, n, capacity):
    global results
    # if(results[n][capacity]): return results[n][capacity]
    if(n == -1 or capacity == 0):
        result = 0
    elif(knapsack[n]['weight'] > capacity):
        result = findCombination(knapsack, n-1, capacity)
    else:
        tmp1 = findCombination(knapsack, n-1, capacity)
        tmp2 = knapsack[n]['weight'] + findCombination(knapsack, n-1, capacity-knapsack[n]['weight'])
        result = max(tmp1, tmp2)
        # results[n][capacity] = result
    return result
    




counter = 0

n = 3
capacity = 11

knapsack = fillKnapsack(n, capacity)
results = initializeResultsArr(n, capacity)

print(knapsack)
# print(results)
print(findCombination(knapsack, len(knapsack)-1, capacity))
# print(counter)

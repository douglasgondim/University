import random

def testChances(array):
    count = 0
    array.sort()
    game = generateGame()
    while(array != game):
       game = generateGame()
       count += 1
    return count

def generateGame():
    game = random.sample(range(1,61),4)
    game.sort()
    return game

array = [[] for i in range(60)]
for i in range(1000):
    game = generateGame()
    for j in game:
        array[j-1].append(j)
# print(testChances(array))
string = []
for i in array:
    string.append("%d,%array[i]")
print(string)
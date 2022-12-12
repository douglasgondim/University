def buildGasStation(locations, n, d):
    if(n == -1):
        return {0, []}
    else:
        temp1 = buildGasStation(locations, n-1, locations[n-1]["demand"])
        # temp2 = 






locations = [
    {"kilometer": 5, "demand": 2},
    {"kilometer": 12, "demand": 4},
    {"kilometer": 30, "demand": 3},
    {"kilometer": 35, "demand": 10}
]

L = 6

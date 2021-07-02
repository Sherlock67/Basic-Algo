database = [(1, 1), (2, 1), (1, 2), (4, 1), (5, 2), (5, 3)]
centroid = [(2, 1), (5, 3)]

for i in range(len(database)):
    
    data = database[i]
    
    for j in range(len(centroid)):
        
        cent = centroid[j]
        
        dist = abs(data[0] - cent[0]) + abs(data[1] - cent[1])
        
        print("Dist({},S{}) = |{} - {}| + |{} - {}| = ".format(i+1, j+1, data[0], cent[0], data[1], cent[1]), end="")
        
        print(dist)
        
    print()
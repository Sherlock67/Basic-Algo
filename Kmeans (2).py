database = [(1, 1), (2, 1), (1, 2), (4, 1), (5, 2), (5, 3)]
centroid = [(2, 1.25), (5, 2.5)]

for i in range(len(database)):
    
    data = database[i]
    
    for j in range(len(centroid)):
        
        cent = centroid[j]
        
        dist = pow((data[0] - cent[0]),2) + pow((data[1] - cent[1]),2)
        
        print("Dist({},S{}) = square({} - {}) + square({} - {}) = ".format(i+1, j+1, data[0], cent[0], data[1], cent[1]), end="")
        
        print(dist)
        
    print()
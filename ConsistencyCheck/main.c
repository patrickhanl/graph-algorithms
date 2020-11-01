//
//  main.c
//  ConsistencyCheck
//
//  Created by Patrick Hanley on 10/28/20.
//  Copyright © 2020 Patrick Hanley. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int explore(int originalNode, int currentNode, int numNodes, int *visited, int **adjecencyList);

int main(void) {
    
    int numNodes, numEdges, i, *visited, **adjecencyList, result = 0;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &numNodes, &numEdges);

    adjecencyList = (int**)malloc(sizeof(int*) * numNodes);
    for (i = 0; i < numNodes; i++) {
        adjecencyList [i] = (int *)calloc(numNodes, sizeof(int));
    }

    for (i = 0; i < numEdges; i++) {
        int v1, v2;
        
        scanf("%d %d", &v1, &v2);
        
        adjecencyList[v1 - 1][v2 - 1] = 1;
        
    }
    
    for (i = 0; i < numNodes; i++) {
        visited = calloc(numNodes, sizeof(int));
        result = explore(i, i, numNodes, visited, adjecencyList);
        if (result){break;};
    }
    
    printf("%d", result);
    
    return 0;
}

int explore(int originalNode, int currentNode, int numNodes, int *visited, int **adjecencyList) {
    visited[currentNode] = 1;
    
    int i, result = 0;
    
    for (i = 0; i < numNodes; i++) {
        if (i != currentNode && adjecencyList[currentNode][i]) {
            if (i == originalNode) {return 1;}
            else if (!visited[i]) {
                result = explore(originalNode, i, numNodes, visited, adjecencyList);
            }
            if (result) {return result;}
        }
    }
    
    return result;
}

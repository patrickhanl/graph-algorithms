//
//  main.c
//  MazeConnections
//
//  Created by Patrick Hanley on 10/27/20.
//  Copyright © 2020 Patrick Hanley. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void explore(int u, int numNodes, int *visited, int **adjecencyList);

int main(void) {
    int numNodes, numEdges, i, *visited, **adjecencyList, numConnections = 0;
    
    freopen("input.txt", "r", stdin);
    
    scanf("%d %d", &numNodes, &numEdges);
    
    visited = calloc(numNodes, sizeof(int));
    
    adjecencyList = (int**)malloc(sizeof(int*) * numNodes);
    for (i = 0; i < numNodes; i++) {
        adjecencyList [i] = (int *)calloc(numNodes, sizeof(int));
    }
    
    for (i = 0; i < numEdges; i++) {
        int v1, v2;
        
        scanf("%d %d", &v1, &v2);
        
        adjecencyList[v1 - 1][v2 - 1] = 1;
        adjecencyList[v2 - 1][v1 - 1] = 1;
        
    }
    
    for (i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            numConnections++;
            explore(i, numNodes, visited, adjecencyList);
        }
    }
    
    printf("%d", numConnections);
    
    return 0;
}

void explore(int u, int numNodes, int *visited, int **adjecencyList) {
    visited[u] = 1;
    
    int i;
    
    for (i = 0; i < numNodes; i++) {
        if (adjecencyList[u][i] && !visited[i]) {
            explore(i, numNodes, visited, adjecencyList);
        }
    }
}


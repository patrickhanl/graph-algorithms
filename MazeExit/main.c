//
//  main.c
//  MazeExit
//
//  Created by Patrick Hanley on 10/26/20.
//  Copyright © 2020 Patrick Hanley. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/*struct edge {
    int head;
    int tail;
};*/

void explore(int u, int v, int numNodes, int *visited, int **adjecencyList);

int main(void) {
    int numNodes, numEdges, i, u, v, *visited, **adjecencyList;
    //struct edge *edges;
    
    freopen("input.txt", "r", stdin);
    
    scanf("%d %d", &numNodes, &numEdges);
    
    //edges = malloc(sizeof(struct edge) * numEdges);
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
        
        //edges[i].head = v1;
        //edges[i].tail = v2;
    }
    
    scanf("%d %d", &u, &v);
    
    u--;
    v--;
    
    if (u == v || adjecencyList[u][v]) {
        printf("1");
        return 0;
    }
    
    explore(u, v, numNodes, visited, adjecencyList);
    
    if (visited[v]) {printf("1");} else {printf("0");}
    
    return 0;
}

void explore(int u, int v, int numNodes, int *visited, int **adjecencyList) {
    visited[u] = 1;
    
    if (visited[v]) {
        return;
    }
    
    int i;
    
    for (i = 0; i < numNodes; i++) {
        if (adjecencyList[u][i] && !visited[i]) {
            explore(i, v, numNodes, visited, adjecencyList);
        }
    }
}

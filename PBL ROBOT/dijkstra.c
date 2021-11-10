#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "funtzioak.h"
#include "dijkstra.h"

void matrizeaOsatu(char* str) {
    FILE* fp;

    fp = fopen(str, "r");
    if (fp != NULL) {
        memoriaErreserbatu();
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                fscanf(fp, "%d", &kostua[i][j]);
                if (kostua[i][j] == 0)
                    kostua[i][j] = INF;
            }
        }
    }
}

void dijkstra() {
    int nearest;

    init();
    for (int i = 0; i < V; i++) {
        nearest = getNearest();
        bisitatuta[nearest] = 1;

        for (int adj = 0; adj < V; adj++) {
            if (kostua[nearest][adj] != INF && distantzia[adj] > distantzia[nearest] + kostua[nearest][adj]) {
                distantzia[adj] = distantzia[nearest] + kostua[nearest][adj];
                gurasoak[adj] = nearest;
            }
        }
    }
}

void init() {

    for (int i = 0; i < V; i++) {
        bisitatuta[i] = 0;
        distantzia[i] = INF;
        gurasoak[i] = 1;
    }
    distantzia[hasi] = 0;
}

int getNearest() {
    int minValue = INF;
    int minNode = 0;

    if (distantzia != NULL && bisitatuta != NULL) {
        for (int i = 0; i < V; i++) {
            if (distantzia[i] < minValue && bisitatuta[i] == 0) {
                minValue = distantzia[i];
                minNode = i;
            }
        }
    }
    return minNode;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int A[MAX][MAX], completed[MAX], n, cost = 0;

void input() {
    printf("\nEnter the Cost Matrix:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("\nA[%d][%d]:",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
        completed[i] = 0;
    }    
}

int least(int c) {
    int nc = 999;
    int min = 999, kmin;
    for (int i=0; i<n; i++) {
        if ((A[c][i] != 0) && (completed[i] == 0)) {
            if (A[c][i] + A[i][c] < min) {
                min = A[i][0] + A[c][i];
                kmin = A[c][i];
                nc = i;
            }
        }
    }
    if (min != 999) {
        cost += kmin;
    }
    return nc;
}

void minCost(int city) {
    int i, ncity;
    completed[city] = 1;
    printf("%d-->",city+1);
    ncity = least(city);

    if (ncity == 999) {
        ncity = 0;
        printf("%d",ncity+1);
        cost += A[city][ncity];
        return;
    }
    minCost(ncity);
}



int main() {
    int start;
    printf("\n---TRAVELLING SALESMAN PROBLEM---\n");
    printf("\nEnter number of nodes:");
    scanf("%d",&n);
    input();
    printf("\nEnter the start node:");
    scanf("%d",&start);
    printf("\nThe Path is:\n");
    minCost(start);
    printf("\nThe minimum cost is:%d",cost);
    return 0;
}
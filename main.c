#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include<string.h>
#include "Graph.h"
#include "traversal.h"
#define ROWS 15
#define COLS 15
int main() {
    
    FILE *file;
    char line[100];

    // Open the file
    file = fopen("locations.txt", "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    printf("Tourist Location of Rajasthan:\n");
    // Read and print data line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    // Close the file
    fclose(file);
    //
    //FILE *file;
    float matrix1[ROWS][COLS];

    // Open the file in read mode
    file = fopen("weight.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    

    // Read the matrix elements from the file
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(file, "%f", &matrix1[i][j]);
        }
    }
    // Close the file
    fclose(file);

    // Make an array of elements
    int array[15];
    int size = 0;

    printf("Enter the places you wish to visit:\n");
    printf("Enter the location you want to start with as the first one:\n");

    while (size < 15 && scanf("%d", &array[size]) == 1) {
        size++;
        if (getchar() == '\n') {
            break;
        }
    }

    printf("The places you entered are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // g1: Selected locations' matrix
    int h1[15][15];  // Define g1 with appropriate size

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            h1[x][y] = matrix1[array[x]][array[y]];
        }
    }

    // Print g1
    /*for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            printf("%d\t", h1[x][y]);
        }
        printf("\n");
    }*/
    Graph g1 = (Graph)malloc(sizeof(GraphData));
   /* memcpy(g1->arr, h1, sizeof(h1));*/
   for(int i=0;i<size;i++)
   {
        for(int j=0;j<size;j++)
        {
            g1->arr[i][j]=h1[i][j];

        }

   }
    int n = size;
   Graph g2 = spanningTree(g1,n);

    printf("Original Matrix:\n");
    printMatrix(g1->arr, n);
    
    printf("\nSpanning Tree Matrix:\n");
    printMatrix(g2->arr, n);
    printf("final Route of travel:\n");
    int* a=dfs(g2->arr,n);
    int*b=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        int m=a[i];
        b[i]=array[m];
    }
    printarray(b,n);
    int total=sumgraph(g2,size)*12;
    printf("\n");
    printf("The cost of travelling is Rs.%d",total);
    free(g1);
    free(g2);

    return 0;
}



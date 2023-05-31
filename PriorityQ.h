#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 30
typedef struct {
    int arr[MAX_SIZE][3];
    int size;
    int maxSize;
} Heap;
void swap(int arr[][3], int index1, int index2) {
    int temp[3];
    memcpy(temp, arr[index1], sizeof(temp));
    memcpy(arr[index1], arr[index2], sizeof(temp));
    memcpy(arr[index2], temp, sizeof(temp));
}

int empty(Heap* h) {
    return h->size == 0 ? 1 : 0;
}

void heapify(Heap* h, int index) {
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    if (left_child < h->size && h->arr[left_child][0] < h->arr[smallest][0])
        smallest = left_child;

    if (right_child < h->size && h->arr[right_child][0] < h->arr[smallest][0])
        smallest = right_child;

    if (smallest != index) {
        swap(h->arr, index, smallest);
        heapify(h, smallest);
    }
}

void insertMin(Heap* h, int wt, int node, int prevnode) {
    int index = h->size;
    h->arr[index][0] = wt;
    h->arr[index][1] = node;
    h->arr[index][2] = prevnode;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (h->arr[parent][0] > h->arr[index][0]) {
            swap(h->arr, index, parent);
            index = parent;
        } else {
            break;
        }
    }
    h->size = h->size + 1;
}

void deleteMin(Heap* h) {
    if (h->size == 0) {
        return; // Heap is already empty
    }
    swap(h->arr, 0, h->size - 1);
    h->size--;
    heapify(h, 0);
}

int* top(Heap* h) {
    return h->arr[0];
}


void printmat(Heap*h)
 {
    for (int i = 0; i < h->size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t",h->arr[i][j]);
        }
        printf("\n");
        
    }
    return;
 }
 void printtop(int a[3])
{
    for(int i=0;i<3;i++)
    {
        printf("%d\t",a[i]);
    }
}


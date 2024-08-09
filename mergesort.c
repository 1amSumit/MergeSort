#include <stdio.h>

#define MAX_SIZE 100
#define THRESHOLD 15

int a[MAX_SIZE];
int link[MAX_SIZE + 1];

void InsertionSort1(int low, int high);
int MergeSort1(int low, int high);
int Merge1(int q, int r);

int main() {
    int n;
    printf("Enter the value of n :\n");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int sorted_list_start = MergeSort1(1, n);

    int index = sorted_list_start;
    printf("After sorting the element\n");
    while (index != 0) {
        printf("%d ", a[index]);
        index = link[index];
    }
    printf("\n");

    return 0;
}

void InsertionSort1(int low, int high) {
    for (int j = low + 1; j <= high; j++) {
        int item = a[j];
        int i = j - 1;
        while (i >= low && a[i] > item) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = item;
    }

    
    for (int i = low; i < high; i++) {
        link[i] = i + 1;
    }
    link[high] = 0; 
}

int Merge1(int q, int r) {
    int i = q, j = r, k = 0;

    while (i != 0 && j != 0) {
        if (a[i] <= a[j]) {
            link[k] = i;
            k = i;
            i = link[i];
        } else {
            link[k] = j;
            k = j;
            j = link[j];
        }
    }

    link[k] = (i == 0) ? j : i;

    return link[0];
}

int MergeSort1(int low, int high) {
    if (high - low < THRESHOLD) {
        InsertionSort1(low, high);
        return low;
    } else {
        int mid = (low + high) / 2;

        int q = MergeSort1(low, mid);
        int r = MergeSort1(mid + 1, high);

        return Merge1(q, r);
    }
}

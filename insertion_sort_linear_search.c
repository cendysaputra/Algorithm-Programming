#include <stdio.h>

// Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Masukkan jumlah angka: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan angka-angka:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Data setelah diurutkan:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target;
    printf("Masukkan angka yang ingin dicari: ");
    scanf("%d", &target);

    int result = linearSearch(arr, n, target);
    if (result != -1) {
        printf("Angka ditemukan di indeks: %d\n", result);
    } else {
        printf("Angka tidak ditemukan.\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

struct Product {
    char name[50];
    float price;
    int stock;
};

int main() {
    int n;

    printf("Masukkan jumlah produk: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input jumlah produk tidak valid!\n");
        return 1;
    }

    getchar(); // Bersihkan newline dari buffer input

    struct Product products[n];

    for (int i = 0; i < n; i++) {
        printf("\nProduk ke-%d\n", i + 1);

        printf("Nama produk: ");
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strcspn(products[i].name, "\n")] = 0; // Hilangkan newline

        printf("Harga: ");
        scanf("%f", &products[i].price);

        printf("Stok: ");
        scanf("%d", &products[i].stock);

        getchar(); // Bersihkan newline sebelum input string berikutnya
    }

    // Mencari produk dengan harga tertinggi
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (products[i].price > products[maxIndex].price) {
            maxIndex = i;
        }
    }

    printf("\nProduk dengan harga tertinggi:\n");
    printf("Nama: %s\n", products[maxIndex].name);
    printf("Harga: %.2f\n", products[maxIndex].price);
    printf("Stok: %d\n", products[maxIndex].stock);

    return 0;
}

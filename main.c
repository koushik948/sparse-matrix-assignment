#include <stdio.h>

int matrix[100][100];
int lineCount
int wordCount;

struct Item {
    int row;
    int col;
    int value;
};

int main() {
    int i, j;
    printf("Matrix:\n");
    for (i = 0; i < lineCount; i++) {
        for (j = 0; j < wordCount; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    struct Item sparse[1000];
    int n = 0;

    for (i = 0; i < lineCount; i++) {
        for (j = 0; j < wordCount; j++) {
            if (matrix[i][j]) {
                sparse[n].row = i;
                sparse[n].col = j;
                sparse[n].value = matrix[i][j];
                n++;
            }
        }
    }

    printf("Non-zero elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d, %d = %d\n"),
               sparse[i].row,
               sparse[i].col,
               sparse[i].value);
    }

    int fullSize   = lineCount * wordCount * sizeof(int);
    int sparseSize = n * sizeof(struct Item);

    printf("\nMemory usage:\n");
    printf("Full matrix : %d bytes\n", fullSize);
    printf("Sparse form : %d bytes\n", sparseSize);

    if (fullSize > 0) {
        float saved = 100.00f * (fullSize - sparseSize) / fullSize;
        printf("Saved: %.2f%%\n", saved);
    }

    return 0;
}

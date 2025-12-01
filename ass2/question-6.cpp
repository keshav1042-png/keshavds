#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, val;
} Element;

typedef struct {
    int rows, cols, num;
    Element data[MAX];
} Sparse;

// Transpose
Sparse transpose(Sparse s) {
    Sparse t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.num = s.num;
    int k = 0;
    for (int i = 0; i < s.cols; i++) {
        for (int j = 0; j < s.num; j++) {
            if (s.data[j].col == i) {
                t.data[k].row = s.data[j].col;
                t.data[k].col = s.data[j].row;
                t.data[k].val = s.data[j].val;
                k++;
            }
        }
    }
    return t;
}

int main() {
    Sparse s = {3, 3, 3, {{0, 0, 5}, {1, 1, 8}, {2, 2, 9}}};
    Sparse t = transpose(s);
    printf("Transpose of sparse matrix:\n");
    for (int i = 0; i < t.num; i++)
        printf("%d %d %d\n", t.data[i].row, t.data[i].col, t.data[i].val);
    return 0;
}

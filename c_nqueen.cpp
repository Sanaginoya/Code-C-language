#include <stdio.h>
#include <stdlib.h>
int count = 0;
int isSafe(int **board, int row, int col, int n) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1;
}

void solveNQueensUtil(int **board, int col, int n) {
    if (col >= n) {
        count++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            solveNQueensUtil(board, col + 1, n);
            board[i][col] = 0;
        }
    }
}

int solveNQueens(int n) {
    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        board[i] = (int *)calloc(n, sizeof(int));
    }

    solveNQueensUtil(board, 0, n);

    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);

    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int res = solveNQueens(n);
    printf("%d\n", res);
    return 0;
}

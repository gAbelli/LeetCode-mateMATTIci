#include <iostream>
#include <vector>

bool correct(const std::vector<std::vector<char>> &board, int i, int j) {
    // row
    for (int k = 0; k < 9; k++) {
        if (j != k && board[i][k] == board[i][j]) {
            return false;
        }
    }

    // col
    for (int k = 0; k < 9; k++) {
        if (i != k && board[k][j] == board[i][j]) {
            return false;
        }
    }

    // block
    int start_i = (i / 3) * 3;
    int start_j = (j / 3) * 3;
    for (int k = 0; k < 3; k++) {
        for (int h = 0; h < 3; h++) {
            if ((start_i + k != i || start_j + h != j) &&
                board[i][j] == board[start_i + k][start_j + h]) {
                return false;
            }
        }
    }

    return true;
}

std::pair<int, int> next(int i, int j) {
    i++;
    if (i < 9) {
        return std::pair<int, int>{i, j};
    }
    i = 0;
    j++;
    if (j < 9) {
        return std::pair<int, int>{i, j};
    }
    return std::pair<int, int>{-1, -1};
}

bool solve_from(std::vector<std::vector<char>> &board, int i, int j) {
    if (i < 0) {
        return true;
    }

    std::pair<int, int> next_pair = next(i, j);
    int next_i = next_pair.first;
    int next_j = next_pair.second;

    if (board[i][j] != '.') {
        return solve_from(board, next_i, next_j);
    }

    for (int k = 1; k <= 9; k++) {
        board[i][j] = '0' + k;
        if (correct(board, i, j)) {
            bool ok = solve_from(board, next_i, next_j);
            if (ok) {
                return true;
            }
        }
    }
    board[i][j] = '.';
    return false;
}

void solveSudoku(std::vector<std::vector<char>> &board) {
    solve_from(board, 0, 0);
}

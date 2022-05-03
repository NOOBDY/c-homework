#include <stdio.h>
#include <string.h>

typedef int Cube[6][9];

void init(Cube cube) {

    /* unwrapped cube color to id correspondence
     *
     *   1
     * 5 4 2 3
     *   6
     *
     */

    int i, j;

    memset(cube, 0, sizeof(Cube));

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 9; j++) {
            cube[i][j] = i + 1;
        }
    }
}

void output(const Cube cube) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", cube[0][3 * i + j]);

        printf("\n");
    }
}

void vertical(Cube cube, const int col) {
    int i, j;
    Cube tmp;

    int trans[6] = {3, 1, 0, 5, 4, 2};

    for (i = 0; i < 9; i++) {
        if (i % 3 == col) {
            for (j = 0; j < 6; j++)
                tmp[j][i] = cube[trans[j]][i];

        } else {
            for (j = 0; j < 6; j++)
                tmp[j][i] = cube[j][i];

        }
    }

    if (col == 0) {
        tmp[4][0] = cube[4][2];
        tmp[4][1] = cube[4][5];
        tmp[4][2] = cube[4][8];
        tmp[4][3] = cube[4][1];
        tmp[4][4] = cube[4][4];
        tmp[4][5] = cube[4][7];
        tmp[4][6] = cube[4][0];
        tmp[4][7] = cube[4][3];
        tmp[4][8] = cube[4][6];
    }

    if (col == 2) {
        tmp[1][0] = cube[1][6];
        tmp[1][1] = cube[1][3];
        tmp[1][2] = cube[1][0];
        tmp[1][3] = cube[1][7];
        tmp[1][4] = cube[1][4];
        tmp[1][5] = cube[1][1];
        tmp[1][6] = cube[1][8];
        tmp[1][7] = cube[1][5];
        tmp[1][8] = cube[1][2];
    }

    memcpy(cube, tmp, sizeof(Cube));
}

void horizontal(Cube cube, const int row) {
    int i, j;
    Cube tmp;

    int trans[6] = {0, 2, 4, 1, 3, 5};

    for (i = 0; i < 9; i++) {
        if (i / 3 == row) {
            for (j = 0; j < 6; j++) {
                tmp[j][i] = cube[trans[j]][i];
            }
        } else {
            for (j = 0; j < 6; j++) {
                tmp[j][i] = cube[j][i];
            }
        }
    }

    if (row == 0) {
        tmp[0][0] = cube[0][6];
        tmp[0][1] = cube[0][3];
        tmp[0][2] = cube[0][0];
        tmp[0][3] = cube[0][7];
        tmp[0][4] = cube[0][4];
        tmp[0][5] = cube[0][1];
        tmp[0][6] = cube[0][8];
        tmp[0][7] = cube[0][5];
        tmp[0][8] = cube[0][2];
    }

    if (row == 2) {
        tmp[5][0] = cube[5][2];
        tmp[5][1] = cube[5][5];
        tmp[5][2] = cube[5][8];
        tmp[5][3] = cube[5][1];
        tmp[5][4] = cube[5][4];
        tmp[5][5] = cube[5][7];
        tmp[5][6] = cube[5][0];
        tmp[5][7] = cube[5][3];
        tmp[5][8] = cube[5][6];
    }

    memcpy(cube, tmp, sizeof(Cube));
}

int main() {
    int i, count, op;
    Cube cube;

    init(cube);

    scanf("%d", &count);
    getchar();

    for (i = 0; i < count; i++) {
        scanf("%d", &op);
        getchar();

        switch (op / 10) {
            case 1:
                vertical(cube, op % 10);
                break;

            case 2:
                horizontal(cube, op % 10);
                break;
        }

    }
    output(cube);

    return 0;
}

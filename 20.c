#include <stdio.h>

typedef struct{
    int up;
    int front;
    int right;
} Dice;

void print_dice(const Dice dice) {
    printf("  %d \n", 7 - dice.up);
    printf("  %d \n", 7 - dice.front);
    printf("%d %d %d %d\n", 7 - dice.right, dice.up, dice.right, 7 - dice.up);
    printf("  %d \n", dice.front);
}

void front(Dice *dice) {
    int tmp = dice->up;
    dice->up = dice->front;
    dice->front = 7 - tmp;
}

void back(Dice *dice) {
    int tmp = dice->up;
    dice->up = 7 - dice->front;
    dice->front = tmp;
}

void right(Dice *dice) {
    int tmp = dice->up;
    dice->up = 7 - dice->right;
    dice->right = tmp;
}

void left(Dice *dice) {
    int tmp = dice->up;
    dice->up = dice->right;
    dice->right = 7 - tmp;
}

int score(const Dice dices[]) {
    int i, sum = 0, has_pair = 0, count[6] = {0};

    for (i = 0; i < 4; i++) {
        count[dices[i].up - 1]++;
        sum += dices[i].up;
    }

    for (i = 0; i < 6; i++) {
        if (count[i] == 4)
            return 18;

        if (count[i] == 3)
            return 0;

        if (count[i] == 2 && has_pair)
            return (i + 1) * 2;

        if (count[i] == 2 && !has_pair)
            has_pair = i + 1;
    }

    if (has_pair)
        return sum - 2 * has_pair;

    return 0;
}

int main() {
    int i, j, count, arr[4];
    Dice dices[4];
    void (*roll[4])(Dice *) = {front, back, right, left};

    scanf("%d", &count);

    for (i = 0; i < 4; i++) {
        dices[i].up = 1;
        dices[i].front = 4;
        dices[i].right = 2;
    }

    for (i = 0; i < count; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &arr[j]);
        }
        getchar();

        for (j = 0; j < 4; j++) {
            roll[arr[j] - 1](&dices[j]);
        }
    }

    printf("%d\n", score(dices));

    return 0;
}

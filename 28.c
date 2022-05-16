#include <stdio.h>
#include <string.h>

typedef struct {
    int pos;
    int hit;
    int score;
    char stats[5];
} Player;

void init(Player *p) {
    int i, count;

    memset(p, 0, sizeof(Player));

    scanf("%d", &count);
    getchar();

    for (i = 0; i < count; i++) {
        p->stats[i] = getchar();
        getchar();
    }
}

void output(const Player player, const int id) {
    printf("%d %d %d\n", id, player.hit, player.score);
}

void run(Player *players, int batter_index, const int n) {
    int i;

    for (i = 0; i < 9; i++) {
        if (players[i].pos || i == batter_index)
            players[i].pos += n;
    }

    for (i = 0; i < 9; i++) {
        if (players[i].pos > 3) {
            players[i].pos = 0;
            players[i].score++;
        }
    }
}

int main() {
    int i, j, out_count = 0, out_total, score_total = 0;
    char ch;

    Player players[9];

    for (i = 0; i < 9; i++) {
        init(&players[i]);
    }

    scanf("%d", &out_total);
    getchar();

    i = 0;
    while (out_count < out_total) {
        ch = players[i % 9].stats[i / 9];

        switch(ch) {
            case 'H':
                players[i % 9].hit++;

                run(players, i % 9, 4);
                break;

            case 'O':
                out_count++;

                if (out_count % 3 == 0)
                    for (j = 0; j < 9; j++)
                        players[j].pos = 0;

                break;

            default:
                players[i % 9].hit++;

                run(players, i % 9, ch - '0');
                break;

        }

        i++;
    }

    for (i = 0; i < 9; i++)
        score_total += players[i].score;

    printf("%d\n", score_total);

    for (i = 0; i < 9; i++) {
        output(players[i], i + 1);
    }
    return 0;
}

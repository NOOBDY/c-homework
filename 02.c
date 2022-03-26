#include <stdio.h>


int main() {
    int out = 0, player_index = 0, i, j;
    int player_pos[5] = {-1, -1, -1, -1, -1};
    int base[3] = {0, 0, 0};
    char status;

    for (i = 0; i < 5; i++) {
        scanf("%c", &status);
        getchar();

        switch (status) {
            case 'O':
                out++;

                if (out >= 3) {
                    for (j = 0; j < 5; j++) {
                        player_pos[1] = -1;
                    }

                    player_index++;
                }

                break;

            case 'H':
                for (j = 0; j < 5; j++) {
                    player_pos[j] = -1;
                }

                player_index++;

                break;

            default:
                for (j = 0; j < 5; j++) {
                    if (player_pos[j] != -1)
                        player_pos[j] += status - '0';

                    if (player_pos[j] >= 3)
                        player_pos[j] = -1;

                }

                player_pos[player_index] += status - '0';
                player_index++;

                break;
        }
    }

    for (i = 0; i < 5; i++)
        if (player_pos[i] != -1)
            base[player_pos[i]] = 1;


    for (i = 0; i < 3; i++)
        printf("%d\n", base[i]);


    return 0;
}

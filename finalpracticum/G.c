#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} POINT;

void solve(char map[][100], int P, int Q) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    POINT start, end;
    int foundStart = 0, foundEnd = 0;

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < Q; j++) {
            if (map[i][j] == 'S') {
                start.x = i;
                start.y = j;
                foundStart = 1;
            } else if (map[i][j] == 'E') {
                end.x = i;
                end.y = j;
                foundEnd = 1;
            }
        }
    }

    if (!foundStart || !foundEnd) {
        printf("tujuan tidak ditemukan\n");
        return;
    }

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < Q; j++) {
            if (map[i][j] == '.' || map[i][j] == 'S' || map[i][j] == 'E') {
                printf("%c", map[i][j]);
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    if (start.x == end.x && start.y == end.y) {
        return;
    }

    map[start.x][start.y] = 'S';
    map[end.x][end.y] = 'E';

    int i = 0;
    while (i < 4) {
        int newX = start.x + dx[i];
        int newY = start.y + dy[i];

        if (newX >= 0 && newX < P && newY >= 0 && newY < Q && map[newX][newY] == '.') {
            map[newX][newY] = 'S';
            break;
        }

        i++;
    }

    int j = 0;
    while (j < 4) {
        int newX = end.x + dx[j];
        int newY = end.y + dy[j];

        if (newX >= 0 && newX < P && newY >= 0 && newY < Q && map[newX][newY] == '.') {
            map[newX][newY] = 'E';
            break;
        }

        j++;
    }
}

int main() {
    int P, Q;
    scanf("%d %d", &P, &Q);

    char map[100][100];
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < Q; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    solve(map, P, Q);

    return 0;
}
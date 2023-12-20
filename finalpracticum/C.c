#include <stdio.h>
#include <limits.h>
#define ll long long

int main() {
    int tc;
    scanf("%d", &tc);

    for (int t = 0; t < tc; t++) {
        int s;
        scanf("%d", &s);
        ll duek[s];
        ll genap = 0, ganjil = 0, max = INT_MIN;

        for (int i = 0; i < s; i++) {
            scanf("%lld", &duek[i]);
            if (i % 2 == 0 && duek[i] > 0) {
                genap += duek[i];
            } else if (i % 2 == 1 && duek[i] > 0) {
                ganjil += duek[i];
            } else if (duek[i] > max) {
                max = duek[i];
            }
        }
        printf("Yosh, waktunya menyelamatkan Mob dengan %lld spirit!\n", genap == 0 && ganjil == 0 ? max : genap >= ganjil ? genap : ganjil);
    }

    return 0;
}
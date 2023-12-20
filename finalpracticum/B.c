#include <stdio.h>
#include <stdlib.h>

int counter(int *a, int num) {
    int result = 0;
    for (int i = 0; i < num; i++) {
        result += a[i];
    }
    return result;
}

int main() {
    int n, num = 1000005, result = 0;
    int *a;

    scanf("%d", &n);

    a = (int*)calloc(num, sizeof(int));

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        a[x + 1]++;
        if (a[x + 2] > 0) {
            a[x + 2]--;
        }
    }

    result = counter(a, num);

    printf("%d", result);

    free(a);

    return 0;
}
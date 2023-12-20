#include <stdio.h>

long long testcase(long long *a, long long *b, long long *c, long long *d, long long *e) {
    *b = (*a % *b);
    *d = (*c * *d);
    *e = (*b + *d) % *e;
}

int main() {
    int T; 
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        long long a, b, c, d, e;
        scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);

        testcase(&a, &b, &c, &d, &e);

        printf("%lld\n", e);
    }

    return 0;
}

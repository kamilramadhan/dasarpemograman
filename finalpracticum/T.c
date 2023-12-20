#include <stdio.h>
#include <string.h>
#include <math.h>

long long gcd(long long a, long long b) {
    if (!b) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    long long x, y, n, i, j, v[100000];
    scanf("%lld %lld", &x, &y);
    scanf("%lld", &n);
    for (i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    long long a = lcm(x, y);
    long long arr[10000000];
    memset(arr, 1, sizeof(arr));
    for (i = 0; i < n; i++) {
        for (j = v[i]; j < 10000000; j += v[i]) {
            arr[j] = 0;
        }
    }
    long long sum = 0, max1 = 0, max2 = 0, max3 = 0;
    for (i = 1; i < 10000000; i++) {
        if (!arr[i]) {
            sum += i;
            if (max1 < i) {
                max3 = max2;
                max2 = max1;
                max1 = i;
            } else if (max2 < i) {
                max3 = max2;
                max2 = i;
            } else if (max3 < i) {
                max3 = i;
            }
        }
    }
    printf("%lld %lld %lld\n", max1, max2, max3);
    return 0;
}
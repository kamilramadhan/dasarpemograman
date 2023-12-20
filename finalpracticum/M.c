#include <stdio.h>

typedef long long ll;

ll modpow(ll base, ll exponent, ll modulus) {
    ll result = 1;
    base %= modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        exponent >>= 1;
        base = (base * base) % modulus;
    }

    return result;
}

ll fibonacci(ll n, ll modulus) {
    double phi = (1 + sqrt(5)) / 2;
    ll k = (ll)((n * phi) / (1 - phi) + 0.5);

    ll fkmin1 = 1;
    ll fkmin2 = 0;
    ll fk = 1;

    for (ll i = 2; i <= k; i++) {
        fk = (fkmin1 + fkmin2) % modulus;
        fkmin2 = fkmin1;
        fkmin1 = fk;
    }

    return fk;
}

int main() {
    ll l, m, k;
    ll result = 0;
    ll mod = 1e9 + 7;

    scanf("%lld %lld %lld", &l, &m, &k);

    ll n = k - m + 1;
    ll a = m % mod;

    for (ll i = 0; i < n; i++) {
        ll term = modpow(a + i, l, mod);
        ll fib_term = fibonacci(i, mod);
        result = (result + term * fib_term) % mod;
    }

    printf("%lld", result);
    return 0;
}
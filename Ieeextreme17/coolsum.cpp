//
// Created by JOHNSON on 2/20/2024.
//35% score
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

ll exp(ll x, ll n, ll m) {
    x %= m;
    ll result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * x) % m;
        }
        x = (x * x) % m;
        n /= 2;
    }
    return result;
}

/*ll choose(ll n, ll r) {
    if (r > n - r) {
        r = n - r;
    }
    ll num = 1, den = 1;
    for (ll i = 0; i < r; i++) {
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }
    return (num * exp(den, MOD - 2, MOD)) % MOD;
}*/


const int MAXN = 1e6;

ll fac[MAXN + 1];
ll inv[MAXN + 1];


void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
    inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
    for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

ll choose1(int n, int r) { return fac[n] * inv[r] % MOD * inv[n - r] % MOD; }

ll choose(ll n, ll r) {
    if (r > n - r) {
        r = n - r;
    }
    ll num = 1, den = 1;
    for (ll i = 0; i < r; i++) {
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }
    return (num * exp(den, MOD - 2, MOD)) % MOD;
}


int main() {
    factorial();
    inverses();

    ll k, n;
    cin >> k >> n;
    ll mod = 1LL << k;
    for (ll t = 0; t < mod; t++) {
        ll answer = 0;
        for (ll i = 0; i <= n; i++) {
            if (i % mod == t) {
                if (n <= 1e6) answer = (answer + choose1(n, i)) % MOD;
                else answer = (answer + choose(n, i)) % MOD;
            }
        }
        cout << answer << " ";
    }

    return 0;
}

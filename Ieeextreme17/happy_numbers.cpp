#include <bits/stdc++.h>

using namespace std;
// 100% score. my personal favourite ...

long long solve(long long n) {
    long long sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool check(long long n) {
    long long slow, fast;
    slow = fast = n;
    do {
        slow = solve(slow);
        fast = solve(fast);
        fast = solve(fast);
    } while (slow != fast);
    if (slow == 1) return 1;
    else return 0;
}


int mod = 1e9 + 7;
long long dp[2][2][17][200000];

long long solve(int index, bool order, bool started, string &reference, long long sum, int max_sum, int min_sum) {


    if (index == reference.size()) {
        //  cout << sum << endl;
        return check(sum);
    } else if (dp[order][started][index][sum] != -1) {
        return dp[order][started][index][sum];
    }
    int bound = order ? 9 : reference[index] - '0';

    long long answer = 0;

    for (int i = 0; i <= bound; i++) {
        bool o = order ? true : i != bound;
        bool s = started ? true : i != 0;
        answer = (answer + solve(index + 1, o, s, reference, sum + 1ll * i * i, max_sum, min_sum));
    }

    return dp[order][started][index][sum] = answer;
}

long long countit(string num1, string num2, int min_sum, int max_sum) {

    memset(dp, -1, sizeof(dp));
    long long f = solve(0, false, false, num2, 0, max_sum, min_sum);

    memset(dp, -1, sizeof(dp));
    long long s = solve(0, false, false, num1, 0, max_sum, min_sum);
    long long b = stoll(num1);
    //cout << b << endl;
    return (f - s + check(b));

}

int main() {
    long long i, n;
    cin >> i >> n;

    string ii = to_string(i), nn = to_string(n);
    cout << countit(ii, nn, 0, 0) << endl;

    return 0;
}

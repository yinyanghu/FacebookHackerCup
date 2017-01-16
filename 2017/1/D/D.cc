#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1000000007;
const int maxN = 2000;

long long factorial[maxN + 1];
long long inv_factorial[maxN + 1];

map<int, int> c[maxN + 1];

int R[maxN];

int pow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    long long x = pow(a, b >> 1);
    long long y = (x * x) % MOD;
    return (b & 1) ? (int)((y * a) % MOD) : (int)y;
}

void preprocessing() {
    factorial[0] = 1;
    for (int i = 1; i <= maxN; ++ i)
        factorial[i] = (factorial[i - 1] * i) % MOD;

    inv_factorial[maxN] = pow(factorial[maxN], MOD - 2);
    for (int i = maxN - 1; i >= 0; -- i)
        inv_factorial[i] = (inv_factorial[i + 1] * (i + 1)) % MOD;
}

int N, M;

int C(int a, int b) {
    if (c[b].count(a)) return c[b][a];
    long long ret = inv_factorial[b];
    for (int i = 0; i < b; ++ i)
        ret = (ret * (a - i)) % MOD;
    c[b][a] = (int)ret;
    return (int)ret;
}

int solve() {
    if (N == 1) return M;

    long long ans = 0;

    int total = 0;
    for (int i = 0; i < N; ++ i)
        total += 2 * R[i];

    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < N; ++ j)
            if (i != j) {
                int slot = M + R[i] + R[j] - 1;
                if (total > slot) continue;
                long long count = C(slot - total + N, N);
                count = (count * factorial[N - 2]) % MOD;
                ans = (ans + count) % MOD;
            }
    return ans;
}

int main() {
    preprocessing();
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++ test) {
        cin >> N >> M;

        for (int i = 0; i < N; ++ i)
            cin >> R[i];

        cout << "Case #" << test << ": " << solve() << endl;
    }
    return 0;
}

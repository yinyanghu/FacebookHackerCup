#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int maxN = 50;

int N, R;

int X[maxN], Y[maxN];

int solve() {
    int ans = 0;

    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < N; ++ j)
            for (int p = i; p < N; ++ p)
                for (int q = j; q < N; ++ q) {
                    int num = 0;
                    for (int k = 0; k < N; ++ k)
                        if (X[i] <= X[k] && X[k] <= X[i] + R && Y[j] <= Y[k] && Y[k] <= Y[j] + R)
                            ++ num;
                        else if (X[p] <= X[k] && X[k] <= X[p] + R && Y[q] <= Y[k] && Y[k] <= Y[q] + R)
                            ++ num;
                    ans = max(ans, num);
                }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++ test) {
        cin >> N >> R;
        for (int i = 0; i < N; ++ i)
            cin >> X[i] >> Y[i];
        cout << "Case #" << test << ": " << solve() << endl;
    }
    return 0;
}

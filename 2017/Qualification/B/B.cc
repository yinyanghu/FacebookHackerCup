#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> W;
int N;

const int limit = 50;

int solve() {
    sort(W.begin(), W.end());
    int l = 0;
    int r = N - 1;
    int ans = 0;
    while (l <= r) {
        int cur = 1;
        while (l < r && cur * W[r] < limit) {
            ++ l; ++ cur;
        }
        if (cur * W[r] >= limit)
            ++ ans;
        else
            break;
        -- r;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++ test) {
        cin >> N;
        W.clear();
        for (int i = 0; i < N; ++ i) {
            int w; cin >> w;
            W.push_back(w);
        }
        cout << "Case #" << test << ": " << solve() << endl;
    }

    return 0;
}

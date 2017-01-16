#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int maxNM = 300;
const int inf = 1000000000;

int N, M;

vector<int> C[maxNM];

int F[maxNM + 1][maxNM + 1];

int solve() {
    for (int i = 0; i < N; ++ i)
        sort(C[i].begin(), C[i].end());
    F[0][0] = 0;
    for (int pie = 1; pie <= N; ++ pie)
        F[0][pie] = inf;
    for (int day = 1; day <= N; ++ day) {
        for (int pie = 0; pie < day; ++ pie)
            F[day][pie] = inf; 
        for (int pie = day; pie <= N; ++ pie) {
            F[day][pie] = F[day - 1][pie];
            int sum = 0;
            for (int buy = 1; buy <= min(M, pie); ++ buy) {
                if (day - 1 > pie - buy) break;
                sum += C[day - 1][buy - 1];
                F[day][pie] = min(F[day][pie], F[day - 1][pie - buy] + sum + buy * buy);
            }
        }
    }
    return F[N][N];
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++ test) {
        cin >> N >> M;
        for (int i = 0; i < N; ++ i) {
            C[i].clear();
            int k;
            for (int j = 0; j < M; ++ j) {
                cin >> k;
                C[i].push_back(k);
            }
        }
        cout << "Case #" << test << ": " << solve() << endl;
    }
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K;

const int maxN = 100;
const int maxM = 5000;
const int inf = 1000000000;

int dist[maxN + 1][maxN + 1];
int S[maxM], D[maxM];

int F[maxM + 1][2];

int solve() {
    for (int k = 1; k <= N; ++ k)
        for (int i = 1; i <= N; ++ i)
            for (int j = 1; j <= N; ++ j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < K; ++ i)
        if (dist[1][S[i]] >= inf || dist[1][D[i]] >= inf) return -1;

    if (K == 1)
        return dist[1][S[0]] + dist[S[0]][D[0]];

    F[0][0] = dist[1][S[0]] + dist[S[0]][D[0]];
    F[0][1] = dist[1][S[0]] + dist[S[0]][S[1]] + dist[S[1]][D[0]];
    for (int i = 1; i < K; ++ i) {
        F[i][0] = min(F[i - 1][0] + dist[D[i - 1]][S[i]] + dist[S[i]][D[i]], F[i - 1][1] + dist[D[i - 1]][D[i]]);
        if (i + 1 < K)
            F[i][1] = min(F[i - 1][0] + dist[D[i - 1]][S[i]] + dist[S[i]][S[i + 1]] + dist[S[i + 1]][D[i]], F[i - 1][1] + dist[D[i - 1]][S[i + 1]] + dist[S[i + 1]][D[i]]);
    }
    return F[K - 1][0];
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++ test) {
        int M;
        cin >> N >> M >> K;
        for (int i = 1; i <= N; ++ i)
            for (int j = 1; j <= N; ++ j)
                dist[i][j] = (i == j ? 0 : inf);
        while (M --) {
            int a, b, g;
            cin >> a >> b >> g;
            dist[a][b] = dist[b][a] = min(dist[a][b], g);
        }
        for (int i = 0; i < K; ++ i)
            cin >> S[i] >> D[i];

        cout << "Case #" << test << ": " << solve() << endl;
    }
    return 0;
}

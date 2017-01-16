#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int H, S;

int X, Y, Z;

double pr[2][401];

double dp() {
    //cout << X << " " << Y << " " << Z << endl;
    double P = 1.0 / double(Y);
    for (int i = 0; i <= X * Y; ++ i)
        pr[0][i] = pr[1][i] = 0.0;
    pr[0][0] = 1.0;
    for (int i = 1; i <= X; ++ i) {
        int cur = i & 1;
        int left = i, right = i * Y;
        for (int j = 0; j <= right; ++ j)
            pr[cur][j] = 0.0;
        for (int j = left; j <= right; ++ j) {
            for (int k = 1; k <= Y; ++ k)
                if (j >= k)
                    pr[cur][j] += P * pr[1 - cur][j - k];
        }
    }
    /*
    double sum = 0.0;
    for (int i = X; i <= X * Y; ++ i) {
        sum += pr[X & 1][i];
        cout << pr[X & 1][i] << " ";
    }
    cout << endl;
    cout << "sum = " << sum << endl;
    */
    double ans = 0.0;
    for (int i = max(H - Z, X); i <= X * Y; ++ i)
        ans += pr[X & 1][i];
    //cout << ans << endl;
    return ans;
}

void input(string &str) {
    //cout << str << endl;
    size_t d = str.find("d");
    size_t plus = str.find("+");
    size_t minus = str.find("-");
    X = Y = Z = 0;
    for (int i = 0; i < d; ++ i)
        X = X * 10 + (str[i] - '0');
    if (plus != string::npos) {
        for (int i = d + 1; i < plus; ++ i)
            Y = Y * 10 + (str[i] - '0');
        for (int i = plus + 1; i < str.size(); ++ i)
            Z = Z * 10 + (str[i] - '0');
    }
    else if (minus != string::npos) {
        for (int i = d + 1; i < minus; ++ i)
            Y = Y * 10 + (str[i] - '0');
        for (int i = minus + 1; i < str.size(); ++ i)
            Z = Z * 10 + (str[i] - '0');
        Z = -Z;
    }
    else {
        for (int i = d + 1; i < str.size(); ++ i)
            Y = Y * 10 + (str[i] - '0');
    }
    //cout << X << " " << Y << " " << Z << endl;
}

void solve() {
    cin >> H >> S;
    string str;
    double ans = 0.0;
    for (int i = 0; i < S; ++ i) {
        cin >> str;
        input(str);
        ans = max(ans, dp());
    }
    printf("%.6lf\n", ans);
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++ test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}

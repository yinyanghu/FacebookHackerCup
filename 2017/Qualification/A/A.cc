#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = atan(1) * 4;

bool cmp(double A, double B) {
    if (abs(A - B) < 1e-6) return true;
    return A > B;
}

bool solve(int P, int X, int Y) {
    if (P == 0) return false;
    if (X == 50 && Y == 50) return true;
    //double degA = (double)P / 100.0;

    double x = (double)X - 50.0;
    double y = (double)Y - 50.0;
    double l = sqrt(x * x + y * y);
    if (l > 50.0) return false;
    x /= l; y /= l;
    double deg = acos(x) / pi * 50.0;
    //cout << deg << endl;
    if (y >= 0.0) {
        if (x >= 0.0) {
            if (P >= 25) return true;
            return cmp(P + deg, 25.0);
        }
        else {
            if (P == 100) return true;
            return cmp(deg - 25.0 + P, 100.0);
        }
    }
    else {
        if (x >= 0.0) {
            if (P >= 50) return true;
            return cmp(P - 25, deg);
        }
        else {
            if (P >= 75) return true;
            return cmp(P - 25, deg);
        }
    }
}

int main() {
    int T;
    cin >> T;
    int P, X, Y;
    for (int test = 1; test <= T; ++ test) {
        cin >> P >> X >> Y;
        cout << "Case #" << test << ": " ;
        cout << (solve(P, X, Y) ? "black" : "white") << endl;
    }
    return 0;
}

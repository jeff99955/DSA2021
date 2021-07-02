#include <iostream>
#include <random>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    random_device rd;
    mt19937 gen(rd());

    int n, m;
    cin >> n >> m;

    cout << n << ' ' << m << '\n';
    uniform_int_distribution<int> dist1(0, n-1);
    uniform_int_distribution<int> dist2(0, 1);
    for(int i = 0; i < m; ++i) {
        int type = dist2(gen);
        if(type == 1) {
            cout << 1 << ' ' << dist1(gen) << ' ' << dist1(gen) << '\n';
        }
        else {
            cout << 2 << ' ' << dist1(gen) << ' ' << dist1(gen) << '\n';
        }
    }
    return 0;
}


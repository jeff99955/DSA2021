#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    random_device rd;
    mt19937 gen(rd());
    vector<char> charset;
    for (char c = 0; c <= 9; ++c) charset.push_back(c);
    for (char c = 'a'; c <= 'z'; ++c) charset.push_back(c);
    for (char c = 'A'; c <= 'Z'; ++c) charset.push_back(c);

    int n;
    cin >> n;
    unordered_set<string> stringset;
    uniform_int_distribution<int> t(0, 10);
    uniform_int_distribution<int> a(0, n-1);
    
    auto s = [](auto &t) { if(t < 3) return "Yes"; return "No";};
    for (int i = 0; i < 10; ++i) {
        cout << s(t(gen)) << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

struct disjoint_set {
    string parent;
    int rank;
    disjoint_set(int i, string s): parent(s), rank(i) {};
};
unordered_map<string, disjoint_set *> ds;

void makeset(string s){
    ds[s] = new disjoint_set(1, s);
}

void init(string s){
    if (ds.find(s) == ds.end())
        makeset(s);
}

string find_set(string s) {
    init(s);
    if (ds[s]->parent != s) {
        ds[s]->parent = find_set(ds[s]->parent);
    }
    return ds[s]->parent;
}

void link(string ra, string rb) {
    string a = find_set(ra), b = find_set(rb);
    if (a == b) return;
    if (ds[a]->rank < ds[b]->rank) 
        ds[a]->parent = ds[b]->parent;
    else {
        if (ds[a]->rank == ds[b]->rank)
            ds[a]->rank++;
        ds[b]->parent = ds[a]->parent;
    }
}

bool same_set(string a, string b) {
    return (find_set(a) == find_set(b));
}

int main(){
    int n;
    cin >> n;
    string cmd, a, b;
    for (int i = 0; i < n; ++i) {
        cin >> cmd >> a >> b;
        if (cmd == "union") {
            init(a); init(b);
            link(a, b); 
        } else {
            int len = a.length() / 4;
            cout << "len of " << a << "= " << a.length();
            bool same = true;
            for (int j = 0; j < len; j++) {
                string ra = a.substr(j * 4, 4), rb = b.substr(j * 4, 4);
                if (not same_set(ra, rb)){
                    same = false;
                    break;
                }
            }
            if(same) cout << "True\n";
            else cout << "False\n";
        }
        for (auto s : ds) {
            cout << s.first << ' ' << find_set(s.first) << '\n';
        }
    }
}
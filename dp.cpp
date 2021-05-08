#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> letterCasePermutation(string S) {
        o_str = S;
        for (int i = 0; i < S.length(); i++) 
            tolower(S[i]);
        for (int i = 0; i < S.length(); i++)
            if (S[i] >= 'a' && S[i] <= 'z')
                r.push_back(i);

        generate_combination(0);
        
        return ret;
    }

   private:
    vector<int> r, t;
    vector<string> ret;
    string o_str;
    void generate_combination(int n) {
        if (n >= r.size()) { 
            string nstr = o_str;
            for (auto i : t)
                nstr[i] += ('A' - 'a');
            ret.push_back(nstr);
            return;
        }
        
        t.push_back(r[n]);
        generate_combination(n + 1);
        t.pop_back();
        generate_combination(n + 1);
    }
};

int main() {
    Solution S;
    string s = "abcd";
    auto vs = S.letterCasePermutation(s);
    for (auto str : vs)
        cout << str << "//";
}
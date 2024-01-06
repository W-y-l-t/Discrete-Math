#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Block {
  double l;
  double r;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    map<char, double> p;
    map<char, Block> blocks;
    for (char i : s) {
        ++p[i];
    }

    double l = 0.0;
    for (auto it : p) {
        blocks[it.first] = {l, l + static_cast<double>(it.second /
                                                        (double)(s.size()))};
        l = blocks[it.first].r;
    }

    l = 0.0;
    double r = 1.0;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        double new_l = l + (r - l) * blocks[c].l;
        double new_r = l + (r - l) * blocks[c].r;
        l = new_l;
        r = new_r;
        cout << "Step " << i + 1 << " " << fixed <<
                        setprecision(16) << l << " " << r << '\n';
    }
}
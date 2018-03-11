#include <bits/stdc++.h>

using namespace std;

string solve(vector<int> &a, const int &n) {
    if (any_of(begin(a), end(a), [&n] (int e) { return e < 1 or e > n; })) {
        return "Ugly";
    }
    
    if (is_sorted(begin(a), end(a))) {
        return "Ugly";
    }
    
    sort(begin(a), end(a));

    if (unique(begin(a), end(a)) != end(a)) {
        return "Ugly";
    }

    return "Beautiful";
}

int main()
{
    int q;
    cin >> q;
    assert(q >= 1 and q <= 100);

    while (q--) {
        int n;
        cin >> n;
        assert(n >= 1 and n <= 1e4);

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            assert(a[i] >= 1 and a[i] <= 1e9);
        }

        cout << solve(a, n) << endl;
    }
}

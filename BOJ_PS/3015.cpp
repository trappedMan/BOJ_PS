#include <bits/stdc++.h>
using namespace std;
int seq[500001];
stack<pair<int, int>> st;
int n;
long long ans = 0;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    int i = 0;
    while (i < n) {
        if (st.empty()) {
            st.push({ seq[i],1 });
            i++;
        }
        else {
            if (st.top().first > seq[i]) {
                ans++;
                st.push({ seq[i],1 });
                i++;
            }
            else if (st.top().first < seq[i]) {
                int tmp = st.top().second;
                ans += tmp;
                st.pop();
            }
            else {
                int val = st.top().second;
                int valf = st.top().first;
                ans += val;
                st.pop();
                if (!st.empty())
                    ans++;
                st.push({ valf,val + 1 });
                i++;
            }

        }
    }
    cout << ans;
    return 0;
}
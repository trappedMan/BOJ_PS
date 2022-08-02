#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll seq[100001];
stack<int> st;
int n;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    for(int i = 0; i <= n; i++){
        while (!st.empty()&&seq[st.top()]>=seq[i]) {
            int k = st.top();
            st.pop();
            ll height = seq[k];
            ll weight = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, height * weight);
        }
        st.push(i);
    }
    cout << ans;
    return 0;
}
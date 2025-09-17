class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x: nums) {
            st.push_back(x);
            while (st.size() > 1) {
                int a = st.back(), b = st[st.size()-2];
                int g = gcd(a,b);
                if (g == 1) break;
                st.pop_back(); st.pop_back();
                st.push_back((long long)a / g * b);
            }
        }
        return st;
    }
};

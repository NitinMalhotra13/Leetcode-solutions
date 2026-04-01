class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        int n = pos.size();
        vector<tuple<int,int,char,int>> robots;

        for (int i = 0; i < n; i++)
            robots.push_back({pos[i], h[i], d[i], i});

        sort(robots.begin(), robots.end());

        stack<int> st; 
        vector<int> health(n);

        for (int i = 0; i < n; i++)
            health[i] = get<1>(robots[i]);

        for (int i = 0; i < n; i++) {
            if (get<2>(robots[i]) == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && health[i] > 0) {
                    int j = st.top();

                    if (health[j] < health[i]) {
                        st.pop();
                        health[i]--;
                        health[j] = 0;
                    } else if (health[j] > health[i]) {
                        health[j]--;
                        health[i] = 0;
                    } else {
                        health[j] = 0;
                        health[i] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<pair<int,int>> res;
        for (int i = 0; i < n; i++) {
            if (health[i] > 0)
                res.push_back({get<3>(robots[i]), health[i]});
        }

        sort(res.begin(), res.end());

        vector<int> ans;
        for (auto &p : res)
            ans.push_back(p.second);

        return ans;
    }
};

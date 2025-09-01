class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };
        priority_queue<pair<double, pair<int,int>>> pq;
        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--) {
            auto [g, pt] = pq.top(); pq.pop();
            int p = pt.first, t = pt.second;
            p++; t++;
            pq.push({gain(p, t), {p, t}});
        }
        double sum = 0.0;
        while (!pq.empty()) {
            auto [g, pt] = pq.top(); pq.pop();
            sum += (double)pt.first / pt.second;
        }
        return sum / classes.size(); 
    }
};

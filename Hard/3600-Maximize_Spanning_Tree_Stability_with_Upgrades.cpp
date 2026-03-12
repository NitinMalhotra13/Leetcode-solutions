#include <vector>
#include <numeric>

using namespace std;

struct DSU {
    vector<int> parent;
    int components;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri != rj) {
            parent[ri] = rj;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {

        DSU must_dsu(n);

        for (auto &e : edges) {
            if (e[3] == 1) {
                if (!must_dsu.unite(e[0], e[1]))
                    return -1;
            }
        }

        auto canAchieve = [&](int X) {

            DSU dsu(n);
            int upgrades = 0;

            for (auto &e : edges) {
                if (e[3] == 1) {
                    if (e[2] < X) return false;
                    dsu.unite(e[0], e[1]);
                }
            }

            for (auto &e : edges) {
                if (e[3] == 0 && e[2] >= X)
                    dsu.unite(e[0], e[1]);
            }

            for (auto &e : edges) {
                if (e[3] == 0 && e[2] < X && 2LL * e[2] >= X) {

                    if (dsu.find(e[0]) != dsu.find(e[1]) && upgrades < k) {
                        dsu.unite(e[0], e[1]);
                        upgrades++;
                    }
                }
            }
            return dsu.components == 1;
        };

        int high = 0;
        for (auto &e : edges)
            high = max(high, e[2]);
        high *= 2;

        int low = 1, ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canAchieve(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

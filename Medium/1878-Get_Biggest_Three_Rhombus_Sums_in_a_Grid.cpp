class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        set<int> sums;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){

                sums.insert(grid[r][c]);

                for(int k=1; r+2*k<m && c-k>=0 && c+k<n; k++){

                    int sum = 0;

                    for(int i=0;i<k;i++) sum += grid[r+i][c-i];
                    for(int i=0;i<k;i++) sum += grid[r+k+i][c-k+i];
                    for(int i=0;i<k;i++) sum += grid[r+2*k-i][c+i];
                    for(int i=0;i<k;i++) sum += grid[r+k-i][c+k-i];

                    sums.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto it=sums.rbegin(); it!=sums.rend() && ans.size()<3; it++)
            ans.push_back(*it);

        return ans;
    }
};

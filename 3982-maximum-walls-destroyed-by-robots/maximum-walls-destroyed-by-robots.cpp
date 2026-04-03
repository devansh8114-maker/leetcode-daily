class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        const int n = robots.size();
        vector<int> idx(n);
        iota(idx.begin() , idx.end() , 0);
        sort(walls.begin() , walls.end());
        sort(idx.begin() , idx.end() , [&robots](int a , int b){
            return robots[a] < robots[b];
        });
        auto query = [&walls](int l, int r)->int{
            if(l > r) return 0;
            return upper_bound(walls.begin() , walls.end() , r) - lower_bound(walls.begin() , walls.end() , l);
        };
        int dpl = 0, dpr = 0;
        for(int i = 0; i < n; ++i){
            int pos = robots[idx[i]], d = distance[idx[i]];
            int prev = i ? robots[idx[i - 1]] : INT_MIN;
            int next = i + 1 < n ? robots[idx[i + 1]] : INT_MAX;
            int left = query(max(pos - d , prev + 1) , pos);
            int prevEnd = min(prev + (i ? distance[idx[i - 1]] : 0) , pos - 1);
            int right = query(max(pos - d , prevEnd + 1) , pos);
            int ndpl = max(dpl + left , dpr + right);
            int ndpr = max(dpl , dpr) + query(pos , min(pos + d , next - 1));
            dpl = ndpl, dpr = ndpr;
        } 
        return max(dpl , dpr);
    }
};
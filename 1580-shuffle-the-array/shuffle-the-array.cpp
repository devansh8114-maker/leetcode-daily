class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n);
        
        int xIndex=0;
        int yIndex=1;
        for(int i=0;i<n;i++){
            ans[xIndex]=nums[i];
            xIndex +=2;

            ans[yIndex]=nums[i+n];
            yIndex +=2;
        }
        return ans;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> numset(nums.begin(), nums.end());
        int length = 0;
        for(auto num : numset){
            if(numset.find(num-1) == numset.end()){
                int currentnum = num;
                int streak = 1;
                while(numset.find(currentnum+1) != numset.end()){
                    currentnum++;
                    streak++;
                }
                length = max(length, streak);
            }
        }
        return length;
    }
};

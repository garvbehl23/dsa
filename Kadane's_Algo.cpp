// It is the algo which we will use to find the max sum of a subarray

//how it works
// Question
//Given an integer array nums, find the subarray with the largest sum, and return its sum.

 
// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Kadane's Algorithm

// we will use two variables maxsum and currentsum = 0
// initially we will keep maxsum as the value of the first element
//Iterate through each element:

// Add the current element to current_sum.

// Update max_sum if current_sum is greater.

// If current_sum becomes negative, reset current_sum to 0 (since it will not help increase future sums).

class Solution{
    public:
    int maximumSum(vector <int> & nums){
        int n = nums.size();
        int maxsum = nums[0];
        int currentsum = 0;
        for (int i = 0; i < n; i++)
        {
            currentsum += nums[i];
            maxsum = max(maxsum, currentsum);
            if(currentsum < 0){
            currentsum = 0;
            }
        }

        return maxsum;
        
    }
}

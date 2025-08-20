/**
 * @brief Solution class for rearranging array elements to alternate positive and negative numbers
 * 
 * This class provides a method to rearrange an array such that positive and negative numbers
 * alternate while maintaining their original relative order. Positive numbers start at index 0.
 */
class Solution {
public:
    /**
     * @brief Rearranges array elements to alternate between positive and negative numbers
     * 
     * The function takes an array with equal numbers of positive and negative integers
     * and rearranges them to alternate, starting with positive at index 0. The relative
     * order of positive and negative numbers is preserved from the original array.
     * 
     * @param nums Reference to vector of integers containing equal positive and negative numbers
     * @return vector<int> Rearranged vector with alternating positive and negative numbers
     * 
     * Time Complexity: O(n) - Single pass through the input array
     * Space Complexity: O(n) - Additional array of same size as input
     * 
     * Example:
     * Input: [3,1,-2,-5,2,-4]
     * Output: [3,-2,1,-5,2,-4]
     * 
     * Input: [-1,1]
     * Output: [1,-1]
     */
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        // positive pointer tracks even indices (0, 2, 4, ...) for positive numbers
        int positive = 0;
        // negative pointer tracks odd indices (1, 3, 5, ...) for negative numbers
        int negative = 1;
        // Traverse the input array once
        for(int i = 0; i < n; i++){
            // If current number is negative, place it at next available odd index
            if(nums[i] < 0){
                arr[negative] = nums[i];
                negative += 2;  // Move to next odd position
            }
            // If current number is positive, place it at next available even index
            else{
                arr[positive] = nums[i];
                positive += 2;  // Move to next even position
            }
        }
        return arr;
    }
};

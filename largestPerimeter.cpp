class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // Sort the vector to facilitate finding the largest perimeter triangle
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = 0;
        long long sum = 0;

        // Calculate the sum of all elements in the vector
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            k++;
        }
        
        // Output the total sum of the elements
        cout << sum;

        // Adjust the sum to exclude elements that cannot form a valid triangle
        for (int i = n - 1; i >= 0; i--) {
            // Check if the current sum minus the current element is still greater than the current element
            if (sum - nums[i] <= nums[i]) {
                sum -= nums[i];
                k--;
            }
        }

        // If less than 3 elements are left, a polygon cannot be formed, return -1
        if (k < 3) return -1;

        // Return the sum of the largest perimeter polygon
        return sum;
    }
};

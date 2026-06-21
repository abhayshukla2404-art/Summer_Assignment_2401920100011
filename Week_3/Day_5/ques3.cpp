class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // stores indices
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Remove indices outside the window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Record maximum for current window
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
class Solution {
public:
    
    vector<int>arr;
    int size;
    vector<int>fake;
    
    Solution(vector<int>& nums) {
        arr=nums;
        size= nums.size();
        fake= arr;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return fake;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int x = rand()%size;
        int y = rand()%size;
        
        swap(arr[x], arr[y]);
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
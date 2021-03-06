1) Two Sum


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>required;
        required[nums[0]] = 0;
            vector<int> result;
        for(int i = 1 ; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if(required.find(diff) != required.end())
            {
                result.push_back(required[diff]);
                result.push_back(i);
            }
            else
            {
                required[nums[i]] = i;
            }
        }
        return result;
    }
};
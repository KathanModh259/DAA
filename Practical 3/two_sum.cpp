#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++)
        {
            int otherNumber = target - nums[i];
            if (hashmap.find(otherNumber) != hashmap.end())
                return {hashmap[otherNumber], i};
            else
                hashmap[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 13;
    std::vector<int> result = solution.twoSum(nums, target);

    for (int index : result)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}

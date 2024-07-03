#include <vector>
#include <iostream>

class Solution 

{
public:
    int subsetXORSum(std::vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        int count = (1 << n);
        for (int i = 0; i < count; ++i) 
        {
            int subset_xor = 0;
            
            for (int j = 0; j < n; ++j)
            {
                if (i & (1 << j))
                {
                    subset_xor ^= nums[j];
                }
            }
            sum += subset_xor;
        }
        
        return sum;
    }
};

int main()
{
    Solution a;
    std::vector<int> vec = {3,4,5,6,7,8};
    std::cout << a.subsetXORSum(vec);
}
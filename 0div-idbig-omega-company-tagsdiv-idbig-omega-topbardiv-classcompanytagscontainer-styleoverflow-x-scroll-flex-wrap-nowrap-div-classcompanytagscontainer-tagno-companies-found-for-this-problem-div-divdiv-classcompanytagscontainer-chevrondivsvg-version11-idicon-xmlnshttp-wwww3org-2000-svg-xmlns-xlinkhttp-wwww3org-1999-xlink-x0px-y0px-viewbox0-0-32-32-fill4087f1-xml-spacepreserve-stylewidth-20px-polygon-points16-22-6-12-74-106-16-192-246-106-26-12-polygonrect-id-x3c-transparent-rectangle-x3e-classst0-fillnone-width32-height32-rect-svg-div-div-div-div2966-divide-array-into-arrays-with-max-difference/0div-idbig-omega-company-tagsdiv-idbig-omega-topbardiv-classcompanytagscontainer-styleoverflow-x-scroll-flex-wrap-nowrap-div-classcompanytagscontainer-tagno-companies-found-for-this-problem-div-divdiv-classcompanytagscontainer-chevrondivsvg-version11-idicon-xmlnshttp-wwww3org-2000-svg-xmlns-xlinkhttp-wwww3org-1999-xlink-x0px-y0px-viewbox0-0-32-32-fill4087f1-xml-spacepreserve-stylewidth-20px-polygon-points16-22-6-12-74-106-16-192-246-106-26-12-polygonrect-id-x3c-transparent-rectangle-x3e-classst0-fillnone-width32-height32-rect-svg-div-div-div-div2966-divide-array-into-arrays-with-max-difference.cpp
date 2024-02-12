class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> v;
        int i = 0;
        while (i + 2 < nums.size()) {    
            std::vector<int> f;      
            bool validGroup = true;    
           int j=i;
            if(nums[j+2]-nums[j]>k || nums[j+2]-nums[j+1]>k || nums[j+1]-nums[j]>k){
                validGroup=0;
            }
            if (validGroup) {
                f.push_back(nums[i]); 
                f.push_back(nums[i + 1]); 
                f.push_back(nums[i + 2]); 
                v.push_back(f);           
                i += 3;                   
            } else {
                return {};
            }
        }
        return v;
    }
};
class Solution {
public:
    void func(int ind,int target,int n,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums){
  if (target == 0) {
    ans.push_back(ds);
    return;
  }

        for(int i=ind;i<n;i++){
		if(i>ind && nums[i]==nums[i-1]) continue;
		if(target<nums[i]) break;
		ds.push_back(nums[i]);
		func(i+1,target-nums[i],n,ds,ans,nums);
		ds.pop_back();
	}return;
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    int n=nums.size();    
    sort(nums.begin(),nums.end());
	vector<int>ds;
	vector<vector<int>>ans;
	func(0,target,n,ds,ans,nums);
	return ans;
    }
};
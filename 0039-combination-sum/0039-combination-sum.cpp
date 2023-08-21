class Solution {
public:
//     void func(int ind,int target,vector<int>&v,vector<vector<int>>&ans,vector<int>&nums){
//         if(ind==-1){
//             if(target==0){
//                 ans.push_back(v);
//             }return;
//         }
//         //pick
//         v.push_back(nums[ind]);
//          if(target>=nums[ind])
//         func(ind,target-nums[ind],v,ans,nums);
//         v.pop_back();
//         func(ind-1,target,v,ans,nums);
//     }
//     vector<vector<int>> combinationSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         vector<int>v;
//         vector<vector<int>>ans;
//         func(n-1,target,v,ans,nums);
//         return ans;
//     }
// };
    
void func(int ind,int target,int n,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums){
  if (target == 0) {
    ans.push_back(ds);
    return;
  }

        for(int i=ind;i<n;i++){
		 if(i>ind && nums[i]==nums[i-1]) continue;
		 if(target<nums[i]) break;
		ds.push_back(nums[i]);
		func(i,target-nums[i],n,ds,ans,nums);
		ds.pop_back();
	}return;
}
    
vector<vector<int>> combinationSum(vector<int>& nums, int target) {
     int n=nums.size();    
    sort(nums.begin(),nums.end());
	vector<int>ds;
	vector<vector<int>>ans;
	func(0,target,n,ds,ans,nums);
	return ans;
}
};
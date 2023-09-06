class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(int i=0;i<nums1.size();i++){
            int num=nums1[i];
            int c;
            for(int j=0;j<nums2.size();j++){
                if(num==nums2[j])
                    c=j;
            }int d=-1;
            for(int k=c+1;k<nums2.size();k++){
                if(nums2[k]>nums2[c]){
                    d=nums2[k];
                    break;
                }
            }if(d==-1) v.push_back(-1);
            else v.push_back(d);
        }return v;
    }
};
class Solution {
public:
    int longestMountain(vector<int>& height) {
        int n=height.size();
         int maxi=0;
    for(int i=1;i<=n-2;){
        if(height[i]>height[i+1] && height[i]>height[i-1]){
            int cnt=1;
            int j=i;
            while(j>0 && height[j]>height[j-1]){
                cnt++;
                j--;
            }
            while (i < n - 1 && height[i] > height[i + 1]) {
                cnt++;
                i++;
            }
            maxi = max(maxi, cnt);
        }
        else{
            i++;
        }
    }return maxi;
    }
};
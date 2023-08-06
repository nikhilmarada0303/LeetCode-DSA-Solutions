class Solution {
public:
    long func(vector<int>&v,int h){
    long totalHours=0;
    for(int i=0;i<v.size();i++){
        totalHours+=ceil((double)v[i]/(double)h);
    }
    return totalHours;
}
    int minEatingSpeed(vector<int>& v, int h) {
    sort(v.begin(),v.end());
    long maxEatable=v[v.size()-1];
    long low=1;
    long high=maxEatable;
    int ans=-1;
    while(low<=high){
        long long mid=(low+high)/2;
        long totalH=func(v,mid);
        if(totalH<=h){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;

    }return ans;
    }
};
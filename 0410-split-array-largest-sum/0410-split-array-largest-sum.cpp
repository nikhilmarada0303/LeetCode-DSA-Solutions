class Solution {
public:
    int func(vector<int>a,int k,int num){
    int sub=1;
    int sum=0;
    for(int i=0;i<a.size();i++){
        if(sum+a[i]<=num){
            sum=sum+a[i];
        }
        else{
            sub++;
            sum=a[i];
        }
    }return sub;
}
    int splitArray(vector<int>& a, int k) {
         int low=*max_element(a.begin(),a.end());
    int high=accumulate(a.begin(),a.end(),0);
    if(k>a.size()) return -1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        int sub=func(a,k,mid);
        if(sub>k) low=mid+1;
        else high=mid-1;
        }return low;   
    }
};
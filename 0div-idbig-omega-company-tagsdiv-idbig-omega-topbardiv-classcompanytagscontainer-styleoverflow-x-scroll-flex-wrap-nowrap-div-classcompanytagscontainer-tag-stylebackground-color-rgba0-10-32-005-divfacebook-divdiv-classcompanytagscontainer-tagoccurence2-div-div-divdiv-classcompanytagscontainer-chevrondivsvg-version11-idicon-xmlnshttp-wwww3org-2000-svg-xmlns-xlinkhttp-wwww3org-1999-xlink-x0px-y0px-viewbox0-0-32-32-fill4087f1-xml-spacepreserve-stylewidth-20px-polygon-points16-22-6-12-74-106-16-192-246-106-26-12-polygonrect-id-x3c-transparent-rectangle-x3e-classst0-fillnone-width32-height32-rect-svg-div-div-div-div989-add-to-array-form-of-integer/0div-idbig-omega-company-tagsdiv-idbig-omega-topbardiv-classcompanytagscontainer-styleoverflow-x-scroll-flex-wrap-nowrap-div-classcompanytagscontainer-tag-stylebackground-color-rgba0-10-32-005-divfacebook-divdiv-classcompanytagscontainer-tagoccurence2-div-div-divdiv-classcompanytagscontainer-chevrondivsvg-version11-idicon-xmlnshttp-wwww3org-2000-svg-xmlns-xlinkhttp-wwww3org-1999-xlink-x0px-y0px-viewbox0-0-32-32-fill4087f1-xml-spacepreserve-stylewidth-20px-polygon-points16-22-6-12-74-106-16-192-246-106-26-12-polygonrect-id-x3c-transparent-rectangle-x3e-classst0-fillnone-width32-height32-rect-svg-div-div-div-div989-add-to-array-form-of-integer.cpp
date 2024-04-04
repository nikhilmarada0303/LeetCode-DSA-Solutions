class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>v;
        int carry=0;
        
        int i=num.size()-1;
        while(i>=0 || k>0 || carry!=0){
            int sum=carry;
            if(i>=0){
                sum=sum+num[i];
                i--;
            }
            if(k>0){
                sum=sum+(k%10);
                k=k/10;
            }
            v.push_back(sum%10);
            carry=sum/10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
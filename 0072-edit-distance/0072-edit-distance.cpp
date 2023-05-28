class Solution {
public:
    int minDistance(string s, string t) {
         int n=s.size();
        int m=t.size();
         vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=0;i<=m;i++)
            prev[i]=i;
            
        for(int ind1=1;ind1<=n;ind1++){
            curr[0]=ind1;
            for(int ind2=1;ind2<=m;ind2++){
                 if(s[ind1-1]==t[ind2-1])
                     curr[ind2]=prev[ind2-1];
                else
                 curr[ind2]=1+min(curr[ind2-1],
                    min(prev[ind2],prev[ind2-1]));
            }
            prev=curr;
        }
        return prev[m];
    }
};
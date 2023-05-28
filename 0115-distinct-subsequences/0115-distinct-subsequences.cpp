class Solution{
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
      vector<double>prev(m+1,0),curr(m+1,0);
       prev[0]=curr[0]=1;

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                 if(s[ind1-1]==t[ind2-1])
                  curr[ind2]=prev[ind2-1]+prev[ind2];
                else
                 curr[ind2]=prev[ind2];
            }prev=curr;
        }return (int)prev[m];
    }
};
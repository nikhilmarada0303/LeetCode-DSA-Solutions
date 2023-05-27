class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int x=s1.size();
	int y=s2.size();
       vector<int>prev(y+1,0),curr(y+1,0);
        for(int i=0;i<=y;i++)
            prev[i]=0;
        for(int ind1=1;ind1<=x;ind1++){
            for(int ind2=1;ind2<=y;ind2++){
                 if(s1[ind1-1]==s2[ind2-1])
                    curr[ind2]= 1+prev[ind2-1];
                else{
                curr[ind2]=max(prev[ind2],curr[ind2-1]);}
            }prev=curr;
        }return prev[y];
      
    
    }
};
class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n=a.size();
	a.push_back(1);
	a.insert(a.begin(),1);
	vector<vector<int>>dp(n+2,vector<int>(n+2,0));
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			if(i>j) continue;
			int maxi=INT_MIN;
			for(int k=i;k<=j;k++){
				int cost=(a[i-1]*a[k]*a[j+1])+dp[i][k-1]+dp[k+1][j];
				maxi=max(cost,maxi);
			} dp[i][j]=maxi;
		}
	}return dp[1][n];
    }
};
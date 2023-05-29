class Solution {
public:
    int maxProfit(int k, vector<int>& price) {
        int n=price.size();
       vector<int>curr(2*k+1,0);
        vector<int>ahead(2*k+1,0);
        // base cases are inititated to zero
        for(int ind=n-1;ind>=0;ind--){
            for(int transaction=(2*k)-1;transaction>=0;transaction--){
                int profit=0;
                if(transaction%2==0)
                profit=max(-price[ind]+ahead[transaction+1],ahead[transaction]);
                else
                  profit=max(price[ind]+ahead[transaction+1],ahead[transaction]);
                  curr[transaction]=profit;
            }ahead=curr;
        }return ahead[0];
    }
};
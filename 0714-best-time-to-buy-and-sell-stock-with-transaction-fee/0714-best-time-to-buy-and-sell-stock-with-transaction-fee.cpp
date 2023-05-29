class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
         int curr_buy,curr_notbuy,ahead_buy,ahead_notbuy;
         ahead_notbuy=ahead_buy=0;
        
        for(int ind=n-1;ind>=0;ind--){
            
            curr_buy=max(-prices[ind]+ahead_notbuy,0+ahead_buy);
                
            curr_notbuy=max(prices[ind]-fee+ahead_buy,0+ahead_notbuy);
                    
            ahead_buy=curr_buy;
            ahead_notbuy=curr_notbuy;
            
        }return ahead_buy;
    }
};
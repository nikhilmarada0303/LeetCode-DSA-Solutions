class Solution {
public:
    int maxProfit(vector<int>& price) {
        
         int n=price.size();
   vector<vector<int>>after(2,vector<int>(3,0));
     vector<vector<int>>curr(2,vector<int>(3,0));
     
    // base cases are already zeros
        //when cnt==0 ind and buy can be anything
        //when ind==n cnt and buy can be anything 
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
              for (int cnt = 1; cnt <= 2; cnt++) {
                if (buy)
                  curr[buy][cnt] = max(-price[ind] + after[0][cnt],
                                          after[1][cnt]);
                else
                 curr[buy][cnt] = max(price[ind] + after[1][cnt - 1],
                                          after[0][cnt]);
              }after=curr;
            }
        }return after[1][2];
    }
};
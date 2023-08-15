class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
       map<int,int>mp;
        for(auto it:hand){
            mp[it]++;
        }
        
       for(auto p=mp.begin();p!=mp.end();)
		{
           cout<<p->first;
			if(p->second>0)
			{
                p->second--;
                // cout<<p->first<<endl;
				for(int i=1;i<k;i++)
				{
					if(mp[p->first+i]>0)
					{
                        // cout<<p->first+1;
						mp[p->first+i]--;
					}
					else
						return false;
				}
			}
			else
				p++;
		}return 1;
    }
};
class Solution {
public:
    // void func(vector<string>&v,string g,string s,vector<int>&vis){
    //     if(g.size()==s.size()){
    //         v.push_back(g);
    //         return;
    //     }
    //     for(int i=0;i<s.size();i++){
    //         if(!vis[i]){
    //             vis[i]=1;
    //             func(v,s[i]+g,s,vis);
    //             vis[i]=0;
    //         }
    //     }return ;
    // }
    string reorganizeString(string s) {
//         vector<string>v;
//         string g="";
//         vector<int>vis(s.size(),0);
//         func(v,g,s,vis);
        
//         for(auto it:v){
//             bool c=0;
//             for(int i=1;i<it.size();i++){
//                 if(it[i-1]==it[i]){
//                     c=1;
//                     break;
//                     }
//             }if(c==0) return it;
//         }
//         return "";
      map<char,int>mp;
        for(auto it:s)
            mp[it]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
            pq.push({it.second,it.first});
        string ans="";
        while(pq.size()>=2){
            auto it1=pq.top(); pq.pop();
            auto it2=pq.top();  pq.pop();
            ans+=it1.second;
            ans+=it2.second;
            
            if(it1.first>1) pq.push({it1.first-1,it1.second});
            if(it2.first>1) pq.push({it2.first-1,it2.second});
        }
        
        if(pq.size()){
            auto it=pq.top(); 
            if(it.first>1) return "";
            ans+=it.second;
        }
        return ans;
        
    }
};
class Solution {
public:
    int romanToInt(string s) {
        map<string,int>mp;
        mp["I"]=1;   //1
        mp["IV"]=4;  //4               //
        mp["V"]=5;     //5
        mp["IX"]=9;   //9              //
        mp["X"]=10;   //10
        mp["XL"]=40;   //40              //
        mp["L"]=50;      //50
        mp["XC"]=90;       //90
        mp["C"]=100;   //100
        mp["CD"]=400;    //400             //
        mp["D"]=500;      //500
        mp["CM"]=900;      //900           //
        mp["M"]=1000;       //1000
        
//         int ans=0;
        
//         for(int i=0;i<s.size();){
//             if(i+1<s.size()){
//              string f=to_string(s[i])+to_string(s[i+1]);
//                 if(f=="IV" || f=="IX" || f=="XL" || f=="CD" || f=="CM"){
//                 ans=ans+mp[f];
//                 i=i+2;
//                 }
//                 else{
//                  string g=to_string(s[i]);
//                 ans=ans+mp[g];
//                 i++;
//                 }
//             }
//             else{
//                 string g=to_string(s[i]);
//                 ans=ans+mp[g];
//                 i++;
//             }
//         }
//         return ans;
          int ans = 0;

        for (int i = 0; i < s.size();) {
            if (i + 1 < s.size()) {
                string twoChars = s.substr(i, 2);
                if (mp.find(twoChars) != mp.end()) {
                    ans += mp[twoChars];
                    i += 2;
                    continue;
                }
            }

            string oneChar = s.substr(i, 1);
            ans += mp[oneChar];
            i++;
        }

        return ans;

    }
};

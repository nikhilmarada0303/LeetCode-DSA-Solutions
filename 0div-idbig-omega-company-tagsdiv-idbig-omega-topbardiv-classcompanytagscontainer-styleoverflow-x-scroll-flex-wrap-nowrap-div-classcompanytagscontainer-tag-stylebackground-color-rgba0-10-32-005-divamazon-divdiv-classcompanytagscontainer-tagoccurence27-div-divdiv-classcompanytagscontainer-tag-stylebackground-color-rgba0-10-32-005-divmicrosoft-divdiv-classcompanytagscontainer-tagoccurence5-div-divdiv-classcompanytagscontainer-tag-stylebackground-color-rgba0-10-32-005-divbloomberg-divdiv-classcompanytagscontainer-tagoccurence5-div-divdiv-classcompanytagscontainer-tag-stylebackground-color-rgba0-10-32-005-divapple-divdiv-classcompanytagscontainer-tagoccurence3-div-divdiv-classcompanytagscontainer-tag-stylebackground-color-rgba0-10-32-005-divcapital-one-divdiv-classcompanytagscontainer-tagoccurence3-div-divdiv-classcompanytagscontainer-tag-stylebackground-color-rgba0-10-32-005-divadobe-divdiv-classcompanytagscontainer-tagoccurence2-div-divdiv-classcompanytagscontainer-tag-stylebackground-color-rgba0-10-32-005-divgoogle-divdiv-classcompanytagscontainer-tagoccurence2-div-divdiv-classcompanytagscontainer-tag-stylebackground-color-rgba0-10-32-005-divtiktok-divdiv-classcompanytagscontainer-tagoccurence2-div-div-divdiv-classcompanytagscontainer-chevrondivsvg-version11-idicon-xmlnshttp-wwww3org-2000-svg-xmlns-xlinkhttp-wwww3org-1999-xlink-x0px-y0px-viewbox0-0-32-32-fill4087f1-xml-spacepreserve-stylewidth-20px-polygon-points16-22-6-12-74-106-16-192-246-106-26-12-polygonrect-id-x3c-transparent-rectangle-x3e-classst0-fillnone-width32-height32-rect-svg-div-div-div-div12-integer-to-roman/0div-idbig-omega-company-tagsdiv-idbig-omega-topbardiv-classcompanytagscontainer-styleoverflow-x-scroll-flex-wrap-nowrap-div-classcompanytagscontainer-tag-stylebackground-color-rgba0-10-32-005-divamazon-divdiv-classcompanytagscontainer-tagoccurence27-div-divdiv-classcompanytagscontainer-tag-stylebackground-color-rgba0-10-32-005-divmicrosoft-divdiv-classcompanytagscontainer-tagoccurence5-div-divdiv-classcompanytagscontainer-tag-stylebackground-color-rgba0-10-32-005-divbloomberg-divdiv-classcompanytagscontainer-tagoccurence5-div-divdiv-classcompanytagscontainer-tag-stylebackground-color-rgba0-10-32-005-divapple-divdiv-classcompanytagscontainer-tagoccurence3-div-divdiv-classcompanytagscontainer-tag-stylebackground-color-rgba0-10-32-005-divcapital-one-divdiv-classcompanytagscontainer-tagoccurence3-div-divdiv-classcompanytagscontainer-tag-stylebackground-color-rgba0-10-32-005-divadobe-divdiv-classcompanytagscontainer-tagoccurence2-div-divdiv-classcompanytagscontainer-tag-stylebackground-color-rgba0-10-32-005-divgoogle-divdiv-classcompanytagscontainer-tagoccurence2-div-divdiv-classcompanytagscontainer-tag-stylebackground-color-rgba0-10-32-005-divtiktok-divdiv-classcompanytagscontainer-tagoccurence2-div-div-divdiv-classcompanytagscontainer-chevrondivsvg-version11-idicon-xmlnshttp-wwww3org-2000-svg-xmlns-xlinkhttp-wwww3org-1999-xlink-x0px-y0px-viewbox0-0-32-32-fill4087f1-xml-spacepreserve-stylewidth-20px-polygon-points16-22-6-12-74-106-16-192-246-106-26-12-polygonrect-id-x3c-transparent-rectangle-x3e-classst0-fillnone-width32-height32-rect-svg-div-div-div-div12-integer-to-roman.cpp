class Solution {
public:
    string intToRoman(int num) {
       string ans="";
     
        map<int,string>mp;
        mp[1]="I";   //1
        mp[2]="IV";  //4
        mp[3]="V";
        mp[4]="IX";   //9
        mp[5]="X";   //10
        mp[6]="XL";   //40
        mp[7]="L";      //50
        mp[8]="XC";       //90
        mp[9]="C";   //100
        mp[10]="CD";    //400
        mp[11]="D";      //500
        mp[12]="CM";      //900
        mp[13]="M";       //1000
        int v[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        
        int j=12;
        
        while(j>=0){
            while(v[j]<=num){
                ans=ans+mp[j+1];
                num=num-v[j];
            }j--;
        }return ans;
    }
};
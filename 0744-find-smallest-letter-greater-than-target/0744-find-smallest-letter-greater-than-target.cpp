class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
    
    int l=0;
    int h=letters.size()-1;
    while(l<=h){
        int mid=(l+h)/2;
         if(mid<letters.size()-1 && letters[mid]<= target && letters[mid+1]>target)   
                return letters[mid+1];
         if((letters[mid])<=(target))
             l=mid+1;
          else
           h=mid-1;
    }
    return letters[0];
    }
};
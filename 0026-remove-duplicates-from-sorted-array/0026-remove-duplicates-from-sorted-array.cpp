class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        int first=0;
	for(int i=1;i<n;i++){
                  if (arr[first] != arr[i]) {
                    arr[first+1]=arr[i];
                      first++;
                    
                  } 
        }return first+1;
    }
};
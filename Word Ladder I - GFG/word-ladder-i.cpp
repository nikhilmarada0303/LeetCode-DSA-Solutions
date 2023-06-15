//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
       // bfs traversal
       queue<pair<string,int>>q;
       unordered_set<string>st;
       for(int i=0;i<wordList.size();i++){
           st.insert(wordList[i]);
       }
       st.erase(startWord);
       q.push({startWord,1});
       while(!q.empty()){
           int steps=q.front().second;
           string word=q.front().first;
           q.pop();
           if(word==targetWord) return steps;
           for(int i=0;i<word.size();i++){
               char original=word[i];
               for(char ch='a';ch<='z';ch++){
                   word[i]=ch;
                   if(st.find(word)!=st.end()) {      // if exists
                   st.erase(word);
                    q.push({word,steps+1});
                   }
               }word[i]=original;
           }
       }
       return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
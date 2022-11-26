#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict);

bool wordBreak(string s, vector<string>& wordDict) {
        // string s_copy(s);
        bool ans = false;
        // a vector to store the lengths
        vector<int> length;
        int l;
        string sub;
        for (string word: wordDict){
            length.push_back(word.length());
            // cout << word.length() << endl;
        }

        while(! s.empty()){
            cout << "print s " << s << endl;
            for (int i=0; i<length.size(); ++i){
                l=length[i];
                cout << "print l " << l << endl;
                if (s.length()<l) continue;
                cout << 1 << endl;
                sub = s.substr(0,l);
                cout << "print sub " << sub << endl;
                if (sub.compare(wordDict[i])==0){
                    bool ans = wordBreak(s.substr(l), wordDict);
                    if (ans) return ans;
                } 
                cout << 2 << endl;
                if (i==length.size()-1) return ans;
                cout << 3 << endl;
            }
            if (s.length()<l) return ans;
            s = s.substr(l);
            cout << 4 << endl;
        }
        ans = true;
        return ans;
    }

int main(){
    string s = "Leetcode";
    vector<string> wordDict = {"Leet", "code"};
    bool ans = wordBreak(s, wordDict);
    cout << ans << endl;
    // string s = "catsandog";
    // vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    // bool ans = wordBreak(s, wordDict);
    // cout << ans << endl;
}

// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         string lastStr;
//         lastStr.assign(s);
//         string curStr = "";
//         while(true){
//             curStr = "";
//             for(const char c: lastStr) {
//                 if (c==store.top() || store.empty()) {
//                     store.push(c);
//                 }
//                 else {
//                     if (store.size()==k) {
//                         for (int i=0; i<k; ++i) store.pop();
//                     }
//                     else {
//                         for (int i=0; i<k; ++i) {
//                             const char val = store.top();
//                             store.pop();
//                             curStr+=val;
//                         }
//                     }
//                     store.push(c);
//                 }
//             }
//             if (lastStr.compare(curStr)==0) break;
//             lastStr = curStr;
//         }
//         return curStr;
//     }

// private:
//     stack<char> store;
// };


class Solution {
 public:
  string removeDuplicates(const string& s, int k) {
      
      string ans;
      vector<pair<char, int>> stack;
      
      for (const char c: s){
          if (stack.empty() || c != stack.back().first){
              stack.emplace_back(c, 1);
          }
          else if (++stack.back().second==k){
              stack.pop_back();
          }
      }
      
      for (const auto &[c, count]: stack){
          ans.append(count, c);
      }
      
      return ans;
  }
};

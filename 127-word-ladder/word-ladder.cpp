class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        queue<pair<string, int>> q; // word and seq no
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word== endWord){
                return steps;
            }

            for (int i = 0; i < word.size(); i++) {
                int original = word[i]; // to prevent orginal character lost

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    

                    if (st.find(word) != st.end()) { // if found
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> s1{beginWord};
        unordered_set<string> s2{endWord};
        unordered_set<string> m(wordList.begin(), wordList.end());
        if(!m.count(endWord))return 0;
        int word_length = beginWord.length();
        int step = 0;
        while (!s1.empty() && !s2.empty()) {
            ++step;
            //从少的开始扩展
            unordered_set<string> s;
            if (s1.size() > s2.size()) swap(s1, s2);
            for (string w:s1) {
                for (int i = 0; i < word_length; i++) {
                    char ori = w[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        w[i] = c;
                        if (s2.count(w))return step + 1;
                        if (!m.count(w))continue;
                        s.insert(w);
                        m.erase(w);
                    }
                    w[i] = ori;
                }
            }
            swap(s, s1);
        }
        return 0;
    }
};

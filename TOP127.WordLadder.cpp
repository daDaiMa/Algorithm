
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

        bool ok = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            return 0;
        }

        map<string, int> vis1;
        map<string, int> vis2;
        vis1[beginWord] = 1;
        vis2[endWord] = 1;
        queue<string> q1;
        queue<string> q2;
        q1.push(beginWord);
        q2.push(endWord);
//        map<string, bool> check;
//        for (int i = 0; i < wordList.size(); i++) {
//            check[wordList[i]] = true;
//        }

        while (!q1.empty() && !q2.empty()) {
            //先q1
            string tmp = q1.front();
            q1.pop();
            if (vis2.find(tmp) != vis2.end()) {
                return vis1[tmp] + vis2[tmp];
            }
            for (int i = 0; i < wordList.size(); i++) {
                if (vis1.find(wordList[i]) != vis1.end())continue;

                int count = 0;
                for (int j = 0; j < tmp.length(); j++) {
                    if (tmp[j] != wordList[i][j])count++;
                    if (count == 2) {
                        break;
                    }
                }
                if (count == 1) {
                    if (vis2.find(wordList[i]) != vis2.end())return vis2[wordList[i]] + +vis1[tmp];
                    q1.push(wordList[i]);
                    vis1[wordList[i]] = vis1[tmp] + 1;
                }
            }
            tmp = q2.front();
            q2.pop();
            if (vis1.find(tmp) != vis1.end()) {
                return vis1[tmp] + vis2[tmp];
            }
            for (int i = 0; i < wordList.size(); i++) {
                if (vis2.find(wordList[i]) != vis2.end())continue;
                int count = 0;
                for (int j = 0; j < tmp.length(); j++) {
                    if (tmp[j] != wordList[i][j])count++;
                    if (count == 2) {
                        break;
                    }
                }
                if (count == 1) {
                    if (vis1.find(wordList[i]) != vis1.end())return vis1[wordList[i]] + vis2[tmp];
                    q2.push(wordList[i]);
                    vis2[wordList[i]] = vis2[tmp] + 1;
                }
            }
        }

        return 0;
    }
};

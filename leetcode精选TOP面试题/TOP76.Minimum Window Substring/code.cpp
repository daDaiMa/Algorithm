class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tc(150, 0);// 统计T
        vector<int> count(150, 0);// 统计ptr1---ptr2  之间
        for (auto c:t)tc[c]++;
        int ptr1 = 0;
        int ptr2 = 0;
        for (char c:t) {
            while (count[c] < tc[c] && ptr2 < s.length()) {
                if (tc[s[ptr2]]) {
                    count[s[ptr2]]++;
                    ptr2++;
                } else {
                    ptr2++;
                }
            }
            if (count[c] < tc[c])return "";
        }
        int ansptr1 = ptr1, ansptr2 = ptr2, ans = ptr2 - ptr1;
        if (ans == t.length())return s.substr(0, t.size());
        bool shorter = true;
        char missingchar;
        int flag=0;
        cout<<flag++<<endl;
        while (true) {
            if (shorter) {
                cout<<flag++<<endl;
                while (!count[s[ptr1]] || count[s[ptr1]] > tc[s[ptr1]]){
                    if(count[s[ptr1]] > tc[s[ptr1]])count[s[ptr1]]--;
                    ptr1++;
                }// 删除不在t里的字符
                cout<<flag++<<endl;
                if (ptr2 - ptr1 < ans) {
                    ansptr1 = ptr1;
                    ansptr2 = ptr2;
                    ans = ptr2 - ptr1;
                }
                missingchar = s[ptr1++];
                count[missingchar]--;
                cout<<"ptr1:"<<ptr1;
                while (ptr1<s.length()&&(!count[s[ptr1]] || count[s[ptr1]] > tc[s[ptr1]])){
                    if(count[s[ptr1]] > tc[s[ptr1]])count[s[ptr1]]--;
                    ptr1++;
                    cout<<"ptr1:"<<ptr1;
                }// 删除不在t里的字符
                cout<<flag++<<endl;
                shorter = false;
            } else {
                cout<<flag++<<endl;
                while (ptr2 < s.length()) {
                    if (!tc[s[ptr2]]){
                        ptr2++;
                        continue;
                    }
                    count[s[ptr2]]++;
                    ptr2++;
                    if (s[ptr2 - 1] == missingchar) {
                        break;
                    }
                }
                if (count[missingchar] < tc[missingchar])break;
                shorter = true;
            }
        }
        return s.substr(ansptr1, ansptr2 - ansptr1);
    }
};


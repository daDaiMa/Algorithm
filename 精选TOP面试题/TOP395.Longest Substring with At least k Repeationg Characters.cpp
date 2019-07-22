
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k < 2) { return s.length(); }
        if (s.length() < k) {
            return 0;
        }
//        map<char, int> m;
        int m[128] = {0};
        int count = 0;
        for (char c:s) {
            m[c]++;
        }
        int ans = 0;
        bool ok = true;

        int b = 0;
        int e = s.length() - 1;

        while (e - b + 1 >= k && m[s[b]] < k)b++;
        while (e - b + 1 >= k && m[s[e]] < k)e--;

        if (e - b + 1 < k) {
            return 0;
        }

        for (int i = b; i <= e; i++) {
            if (m[s[i]] < k) {
                return max(longestSubstring(s.substr(b, i-b), k), longestSubstring(s.substr(i,e-i+1), k));
            }
        }
        return e-b+1; 
    }
};

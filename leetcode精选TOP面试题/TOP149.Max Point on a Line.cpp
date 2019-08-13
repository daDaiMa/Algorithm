#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        if (points.size() <= 1)return points.size();
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            map<pair<int, int>, set<int>> m;
            int same=0;
            for (int j = i + 1; j < points.size(); j++) {
                int h = points[j][1] - points[i][1];
                int w = points[j][0] - points[i][0];
                if(h==0&&w==0){
                    // 同一个点 记录下来 到时候直接加上就行了
                    same++;
                    continue;
                }
                int _gcd = gcd(h, w);
                if (_gcd) {
                    h /= _gcd;
                    w /= _gcd;
                }
                if (w < 0 && h > 0) {
                    h *= -1;
                    w *= -1;
                }
                auto key = make_pair(h, w);
                // 顺便考虑一下斜率为0 和正无穷的情况
                // 斜率为0 那么
                if (h == 0) {
                    key = make_pair(0, points[i][1]);
                }
                // 斜率无穷
                if (w == 0) {
                    key = make_pair(points[i][0], 0);
                }
                
                m[key].insert(i);
                m[key].insert(j);
            }
            ans=max(ans,same+1);
            for (auto &it:m) {
                if (ans < it.second.size()+same) {
                    ans = it.second.size()+same;
                }
            }
        }

        return ans;
    }

    int gcd(int a, int b) {
        int t;
        while (b != 0) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};





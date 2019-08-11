// 太菜了 本题做法 看了大佬的
// 😂 
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> all;
        vector<vector<int>> res;
       
        vector<int>last={0,0};
        
        for(auto&a:buildings){
            all.insert(make_pair(a[0],-a[2]));
            all.insert(make_pair(a[1],a[2]));
        }

        multiset<int>height({0});

        for(auto&a:all){
            if(a.second<0)height.insert(-a.second);
            else height.erase(height.find(a.second));

            int maxHeight=*height.rbegin();
            
            if (maxHeight!=last[1]){
                last[0]=a.first;
                last[1]=maxHeight;
                res.push_back(last); 
            }
        }
        return res;
    }
};

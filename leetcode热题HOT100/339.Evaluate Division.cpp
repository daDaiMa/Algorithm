
class Solution {
    public:
        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            int node_num=0;
            map<string,int>node_map;
            for(auto&item:equations){
                if(!node_map.count(item[0])){
                    node_map[item[0]]=node_num++;
                }
                if(!node_map.count(item[1])){
                    node_map[item[1]]=node_num++;
                } 
            }

            vector<vector<double>>gragh(node_num,vector<double>(node_num,0));

            int index=0;
            for(auto&item:equations){
                int i=node_map[item[0]];
                int j=node_map[item[1]];
                gragh[i][j]=values[index++];         
                if(gragh[i][j]){
                    gragh[j][i]=1.0/gragh[i][j];
                }
            }

            for(int k=0;k<node_num;k++)
                for(int i=0;i<node_num;i++)
                    for(int j=0;j<node_num;j++){
                        if(i==j)continue;
                        if(gragh[i][j])continue;
                        gragh[i][j]=gragh[i][k]*gragh[k][j];
                        if(gragh[i][j]){
                            gragh[j][i]=1.0/gragh[i][j];
                        }
                    }

            vector<double>ans;

            for(auto&item:queries){
                if(!node_map.count(item[0])||!node_map.count(item[1])){
                    ans.push_back(-1.0);
                    continue;
                }
                int i=node_map[item[0]];
                int j=node_map[item[1]];
                
                if(i==j){
                    ans.push_back(1);
                    continue;
                }

                ans.push_back(gragh[i][j]?gragh[i][j]:-1);
            }

            return ans;
        }
};


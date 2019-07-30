/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<NestedInteger>ls;
    vector<int>index;
    bool has;
    NestedIterator(vector<NestedInteger> &nestedList) {
        has=nestedList.size()!=0;
        if(!has)return;
        index.push_back(0);
        ls.assign(nestedList.begin(),nestedList.end());
        NestedInteger n=ls[0];
        while(!n.isInteger()){
            if(n.getList().size()==0){
                has=false;
                return;
            }
            n=n.getList()[0];
            index.push_back(0);
        }
    }

    int next() {
        // 先寻找
        int ans;
        
        cout<<"查找时:";
        print();
        
        
        NestedInteger n=ls[index[0]];
        for(int i=1;i<index.size();i++)n=n.getList()[index[i]];
        ans=n.getInteger();
        cout<<"答案:"<<ans<<endl;

        while(true){
            index[index.size()-1]++;
            if(index[0]>=ls.size()){
                has=false;
                break;
            }
            n=ls[index[0]];
            if(n.isInteger())break;                
            int i;
            

            cout<<"递增:";
            print();
            
            
            
            for(i=1;i<index.size()-1;i++)n=n.getList()[index[i]];
            // cout<<"1"<<endl;
            
            if(index.size()==1){
                bool flag=false;
                while(!n.isInteger()){
                    if(n.getList().size()==0){
                        flag=true;
                        break;
                    }
                    n=n.getList()[0];
                    index.push_back(0);
                }
                if(flag)continue;
                break;
            }
            
            if(n.getList().size()<=index[i]){
                // cout<<"2"<<endl;
                index.pop_back();
                
                cout<<"越界:";
                print();
                continue;
            }else{
                bool flag=false;
                // cout<<"3"<<endl;
                n=n.getList()[index[i]];
                // cout<<"4"<<endl;
                while(!n.isInteger()){
                    if(n.getList().size()==0){
                        flag=true;
                        break;
                    }
                    n=n.getList()[0];
                    // cout<<"5"<<endl;
                    index.push_back(0);
                }
                 cout<<"变动:";
                print();
                if(flag)continue;
                break;
               // cout<<"6"<<endl;
            }
           
        }
        
         
        
        
        return ans;
    }   

    bool hasNext() {
        return has;
    }
    
    void print(){
        for(int i:index){
            cout<<i<<",";
        }cout<<endl;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

class Trie {
public:
    bool endpoint;
    Trie*[26]next;
public:
    /** Initialize your data structure here. */
    Trie() {
        endpoint=false;
        for(auto t:next){
            t=NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
       if(word.size()==0)return;
       char w=word[0];
       next[w-'a']=new Trie();
       isleaf=false;
       if(word.size()==1){
            next[w-'a'].endpoint=true;  
       }else{
            next[w-'a'].insert(word.substr(1));
       }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       if(word.size()==1){
          return next[word[0]-'a']!=NULL&&next[word[0]-'a'].endpoint;
       }
       return next[word[0]-'a']!=NULL&&next[word[0]-'a'].search(word.substr(1));
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return next[word[0]-'a']!=NULL&&startsWith(word.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


class MagicDictionary {
public:
    /** Initialize your data structure here. */
    struct  trie{
        trie* next[27];
        int end;
    };
    trie *root;
    MagicDictionary() {
      root = new trie();  
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for ( string x : dict){
            trie* temp  = root;
            for ( char  c : x){
                if ( !temp -> next[c -'a'] ) temp->next[c-'a']= new trie();
                temp = temp->next[c-'a'];
            }
            temp->end =1;
        }    
    }
    
    bool get (string word ,trie* temp , int index =0,int change = 1){
        if ( change < 0 ) {
            return false;
        }
        if ( index == word.size()) return ( change == 0 ) && temp->end;
        bool found = false;
        for ( int i = 0; i < 26 ; i ++ ) {
            if ( temp -> next[i] ){
                if ( i == word[index] -'a') 
                    found |= get( word , temp->next[i] , index +1 , change);
                else
                    found |= get( word , temp->next[i] , index +1,  change -1); 
            }
        }
        return found;
        
    }
    
    
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    
    bool search(string word) {
        trie* temp = root;
        return get( word , temp);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */

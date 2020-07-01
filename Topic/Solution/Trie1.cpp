class Solution {
public:
    
    struct trie{
        trie* next[26];
        int end; 
    };
    void insert( string word , trie* root ){
        for ( char c : word){
            if ( !root->next[c-'a'] ) root->next[c-'a'] = new trie();
            root = root->next[c-'a'];
        }
        root->end =1;
    }
    
    void rec( vector<vector<int>> &vis , vector<vector<char>> &board , int x , int y , trie* root ,string curr, set<string> &ans ){
        
        int n = board.size();
        int m = board[0].size();
        
        // base condition for return 
        if (x < 0 || y < 0 || x >= n || y >= m ) return ;
        // already done in current recursion
        if ( vis[x][y] ) return;
        // if no such word exists it is useless to recurse
        if (!root ||  !root -> next[board[x][y] - 'a']) return ;
       
        root = root -> next[board[x][y]-'a'];
        curr.push_back(board[x][y]);
        if ( root->end == 1)
            ans.insert(curr);
            //however we still don't end recursion for words like "end" and "ending"
        
        vis[x][y] =1;
        rec( vis , board , x + 1, y , root ,curr , ans);
        rec( vis , board , x - 1, y , root ,curr , ans);
        rec( vis , board , x , y -1, root ,curr  ,ans);
        rec( vis , board , x , y +1 , root ,curr , ans);
        vis[x][y] =0;
        curr.pop_back();
        
    }
    
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie * root = new trie();
        for ( string word  : words) { 
            insert( word ,  root);
        }
        set<string> ans; 
        string curr;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int> > vis( n , vector<int> ( m , 0 ));
        for ( int i =0 ; i < n ;  i++ )
            for ( int j = 0 ; j < m ;  j++) 
                rec( vis ,board,  i , j , root ,curr, ans);
        vector<string> ret;
        for ( string a : ans)
            ret.push_back(a);
        return ret;
    }
};

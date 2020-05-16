/**
*
*DELETING A NODE
*
*/

Node *deleteNode(Node *root,  int x)
{
    // root can be null
    if (!root) return NULL;
    
    // search for the value
    
    if ( root ->data < x )
        root -> right = deleteNode( root-> right , x);
    else if ( root->data > x) 
        root -> left = deleteNode( root->left , x);
        
    
    //equal
    else{
        // only one child or no child
        if ( !root->left){
            Node* temp = root -> right;
            free(root);
            return temp;
        }
        else if ( !root->right){
            Node* temp = root -> left;
            free(root);
            return temp;
        }
        // both children present
        else{
            
            // find inorder successor
            Node *successor = root-> right;
            while( successor && successor-> left)
                successor = successor-> left;
            //replace the root data
            root->data = successor-> data;
            
            //delete the successor
            root->right =  deleteNode(root-> right , successor->data);
        }
            
    }
    return root;
}


/**
*
*Predecessor and Successor of a node
*
*/

void findPreSuc(Node* root, Node*& pre, Node*& succ, int key)
{
    // preorder traversal
    if (!root) return ;
    findPreSuc( root->left , pre , succ , key);
    // take the last node in the traversal
    if ( root->data < key) pre = root;
    // take the first node more than key 
    if ( root->data > key && !succ) succ = root;
    findPreSuc( root->right , pre, succ , key);
}





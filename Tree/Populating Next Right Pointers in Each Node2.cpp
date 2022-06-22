 Node* findnext(Node* root)
    {
        while(root->next)
        {
            root= root->next;
            if(root->left){return root->left;}
            if(root->right){return root->right;}
        }
        
        return NULL;
    }
    
    Node* connect(Node* root) {
        if(!root){return NULL;}
        
        if(root->left)
        {
            if(root->right){root->left->next = root->right;}   
            else {root->left->next = findnext(root);}
        }
        if(root->right)
        {
            root->right->next = findnext(root);
        }
        
        
        connect(root->right);
        connect(root->left);
        
        return root;
    }
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            queue<Node*> pq;
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left) pq.push(temp->left);
                if(temp->right) pq.push(temp->right);
                
                if(i==n-1){
                    temp->next=NULL;
                }
                else{
                    temp->next=q.front();
                }
            }
            q=pq;
        }
        return root;
    }
};
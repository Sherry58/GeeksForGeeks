/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node *flattenBST(Node *root) {
        if(root == NULL) return NULL;
        
        Node* head1 = flattenBST(root->left);
        if(head1 == NULL){
            head1 = root;
        }
        else{
            root->left = NULL;
            
            Node* temp = head1;
            while(temp and temp->right){
                temp = temp->right;
            }
            temp->right = root;
        }
        Node* head2 = flattenBST(root->right);
        root->right = head2;
        
        return head1;
    }
};
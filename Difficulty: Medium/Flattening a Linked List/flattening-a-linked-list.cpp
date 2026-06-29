/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
    Node* merge(Node* head1, Node* head2){
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        
        Node* result;
        
        if(head1->data < head2->data){
            result = head1;
            result->bottom = merge(result->bottom, head2);
        }
        else{
            result = head2;
            result->bottom = merge(head1, result->bottom);
        }
        return result;
    }
    
    Node *flatten(Node *root) {
        
        if(root == NULL){
            return NULL;
        }
        Node* head = flatten(root->next);
        Node* new_head = merge(root, head);
        
        return new_head;
    }
};
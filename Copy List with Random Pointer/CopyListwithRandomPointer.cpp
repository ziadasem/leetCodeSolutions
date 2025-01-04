#include <map>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
    private:
    std::map<Node*, Node*> original_new;
public:
    Node* copyRandomList(Node* head) {
        Node* head2 ;
        Node* temp = head;
        Node* temp2 = nullptr;
        while (temp != nullptr) {
           if (temp2 == nullptr) {
                temp2 = new Node(temp->val);
                 original_new[temp] = temp2;
           }else{
                temp2->next =  new Node(temp->val);
                original_new[temp] = temp2->next;
                temp2 = temp2->next;
           }
           temp = temp-> next ;
        }
        
        temp = head;
        head2 = original_new[head];
        temp2 = head2;
        while (temp!= nullptr) {
            temp2->random = original_new[temp->random];
            temp2 = temp2->next;
            temp = temp->next;
        }
        return head2 ;
    }
};
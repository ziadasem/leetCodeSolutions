template<class T>
class LinkedNode {
    public:
        T val ;
        LinkedNode<T>* next ;
        LinkedNode(T _val) : val{_val} {}
};

class MinStack {
private:
    LinkedNode<long long>* head ;
    int minVal ;

public:
    MinStack() {
        head = nullptr;
        minVal = 0;
    }
    
    void push(int val) {
        if (head == nullptr){
            minVal = val ;
        }
        long long   l =  ((long long)val)  - ((long long)minVal) ;
        LinkedNode<long long>* temp = new LinkedNode<long long>( l);
        temp->next = head ;
        head = temp;
        
        if (val < minVal){
            minVal = val ;
        }
        
       
    }
    
    void pop() {
        LinkedNode<long long>* temp = head ;
        head = head->next ;
        long long val = temp->val ;
        if (val <0){ //min should be updated
            minVal = minVal - val ;
        }
        delete temp ;
    }
    
    int top() {
        if (head->val < 0){
            return minVal;
        }
        return (int) (head->val + minVal) ;
    }
    
    int getMin() {
        return (int) minVal ;
    }
};


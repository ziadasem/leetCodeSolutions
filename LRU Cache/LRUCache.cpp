#include <unordered_map>
class DLL {
    public:
        DLL* next;
        DLL* prev;
        int key ;
        int value ;
};

class LRUCache {

private:
    int capacity;
    int dll_count;

    DLL* head;
    DLL* tail;

    std::unordered_map<int, DLL*> cache;

public:
    LRUCache(int capacity): head{nullptr}, tail{nullptr}, capacity{capacity}, dll_count{0} {}

    void put(int key, int value) {
        
        if (cache.find(key) != cache.end()){ //update existing
            cache[key]->value = value;
            updateLRULL(cache[key]);
        }else{ //add new value

            if (dll_count == capacity) {
                int key = removeFirst();
                cache.erase(key);
            }

            DLL* element = new DLL;
            element->key = key;
            element->value = value;
            cache[key] = element ;
            insertLastLRULL(cache[key]);
        }
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }  
        // key exists in cache
        updateLRULL(cache[key]);
        return cache[key]->value;
    }
    
private:

    void updateLRULL(DLL* node){
        if (node == tail )
        {
            //most recently used is most recently used
            return; 
        }

        if (node == head){ // [1 2]
            head = head->next;
            head->prev = nullptr ;
        }else{  // [ 1  2  3]
             (node->prev)->next = node->next;  // [1]
             (node->next)->prev = node->prev;
        }
        dll_count -- ;
        insertLastLRULL(node);
    }
    

    void insertLastLRULL(DLL* node){
        if (head == nullptr) {
            node->next = nullptr ;
            node->prev = nullptr ;
            head = node ;
            tail = node ;
            
        }else{
            node->next = nullptr ;
            node->prev = tail ;
            tail->next = node ;
            tail = node ;
        }
        dll_count ++ ;
    }

    int removeFirst(){
        if (head->next == nullptr){
            int key = head->key ;
            delete head ;
            head = nullptr ;
            tail = nullptr ;
            dll_count -- ;
            return key;
        }
        DLL* temp = head ;
        int key = head->key ;
        head = head->next ; 
        head->prev = nullptr ;
        delete temp ;
        dll_count -- ;
        return key ;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

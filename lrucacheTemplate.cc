#include <iostream>
#include <unordered_map>
#include <list>
#include <assert.h>

using namespace std;

template <typename K, typename V>
struct Node {
    Node (K k, V v) : key(k), value(v), prev(NULL), next(NULL) { }
    K key;
    V value;
    struct Node<K, V> *prev;
    struct Node<K, V> *next;
};

template <typename T>
class List {
private:
    T* head;
    T* tail;
    bool addCommon(T *n) {
        assert(n != NULL);
        if (head == NULL) {
            assert(tail == NULL);
            n->prev = NULL;
            n->next = NULL;
            head = tail = n;
            return true;
        }
        return false;
    }
public:
    List() : head(NULL), tail(NULL) {}
    T* getHead() {
        return head;
    }
    T* getTail() {
        return tail;
    }
    void addFront(T *n) {
        if (addCommon(n)) {
            return;
        }
        if (n != head) {
            n->prev = NULL;
            n->next = head;
            head->prev = n;
            head = n;
        }
    }
    void addBack(T *n) {
        if (addCommon(n)) {
            return;
        }
        if (n != tail) {
            n->next = NULL;
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
    }
    void remove(T *n) {
        if (n == head && n == tail) {
            assert(n->prev == NULL);
            assert(n->next == NULL);
            head = tail = NULL;
            return;
        }
        if (n == head) {
            head = head->next;
            head->prev = NULL;
            return;
        }
        if (n == tail) {
            tail = tail->prev;
            tail->next = NULL;
            return;
        }
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    void printList() {
        T *curr = head;
        while(curr != NULL) {
            cout << curr->key << endl;
            curr = curr->next;
        }
    }
};

template <typename K, typename V>
class LRUCache {
private:
    unordered_map<K, Node<K, V> *> keyMap;
    List<Node <K, V> > lruList;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    V get(K key) {
        auto it = keyMap.find(key);
        if (it == keyMap.end()) {
            return V();
        }
        Node<K, V> *n = it->second;
        lruList.remove(n);
        lruList.addFront(n);
        return n->value;
    }

    void put(K key, V value) {
        auto it = keyMap.find(key);
        Node<K, V> *n;
        if (it == keyMap.end()) {
            if (keyMap.size() >= capacity) {
                // Eviction
                Node<K, V> *toEvict = lruList.getTail();
                assert(toEvict != NULL);
                lruList.remove(toEvict);
                keyMap.erase(toEvict->key);
                delete toEvict;
            }
            assert(keyMap.size() < capacity);
            n = new Node<K, V>(key, value);
            keyMap[key] = n;
        } else {
            n = it->second;
            lruList.remove(n);
            n->value = value;
        }
        lruList.addFront(n);
    }

    void printList() {
        lruList.printList();
    }
};

int main() {
    LRUCache<int, int> lru(2);
    lru.put(1, 1);
    lru.printList();
    lru.put(2, 2);
    lru.printList();

    cout << lru.get(1) << endl;

    lru.put(3, 3);
    lru.printList();
    cout << lru.get(1) << endl;
    return 0;
}

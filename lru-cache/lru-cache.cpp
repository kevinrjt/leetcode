#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        _capacity = capacity;
        _head = new Node(-1, -1);
        _head->next = _head->prev = _head;
    }

    ~LRUCache()
    {
        Node *node = _head->next;
        while (node != _head)
        {
            Node *temp = node;
            node = node->next;
            delete temp;
        }

        delete _head;
    }

    int get(int key)
    {
        auto pos = _table.find(key);
        if (pos != _table.end())
        {
            moveNodeToFront(pos->second);
            return pos->second->val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        auto pos = _table.find(key);
        if (pos != _table.end())
        {
            pos->second->val = value;
            moveNodeToFront(pos->second);
            return;
        }

        Node *node = new Node(key, value);
        _table[key] = node;
        insertNodeAtFront(node);
        if (_table.size() > _capacity)
        {
            Node *tail = _head->prev;
            _table.erase(tail->key);
            removeNode(tail);
            delete tail;
        }
    }

private:
    struct Node
    {
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertNodeAtFront(Node *node)
    {
        node->next = _head->next;
        node->next->prev = node;
        _head->next = node;
        node->prev = _head;
    }

    void moveNodeToFront(Node *node)
    {
        if (node != _head->next)
        {
            removeNode(node);
            insertNodeAtFront(node);
        }
    }

    int _capacity;
    Node *_head;
    unordered_map<int, Node *> _table;
};

int main()
{
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class MyHashMap
{
public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        buckets_ = vector<ListNode *>(1024);
    }

    ~MyHashMap()
    {
        for (ListNode *node : buckets_)
        {
            while (node != nullptr)
            {
                ListNode *temp = node;
                node = node->next;
                delete temp;
            }
        }
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int idx = key % buckets_.size();
        ListNode *node = find(buckets_[idx], key);
        if (node == nullptr)
        {
            buckets_[idx] = new ListNode(key, value, buckets_[idx]);
        }
        else
        {
            node->val = value;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int idx = key % buckets_.size();
        ListNode *node = find(buckets_[idx], key);
        return node == nullptr ? -1 : node->val;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int idx = key % buckets_.size();
        ListNode *node = buckets_[idx];
        if (node == nullptr)
        {
            return;
        }

        if (node->key == key)
        {
            buckets_[idx] = node->next;
            delete node;
            return;
        }

        while (node->next != nullptr && node->next->key != key)
        {
            node = node->next;
        }

        if (node->next != nullptr)
        {
            ListNode *temp = node->next;
            node->next = node->next->next;
            delete temp;
        }
    }

private:
    struct ListNode
    {
        ListNode *next;
        int key;
        int val;
        ListNode(int key, int val, ListNode *next) : key(key), val(val), next(next) {}
    };

    ListNode *find(ListNode *node, int key)
    {
        while (node != nullptr && node->key != key)
        {
            node = node->next;
        }

        return node;
    }

    vector<ListNode *> buckets_;
};

int main()
{
    MyHashMap map;
    map.put(1, 1);
    map.put(1024, 1024);
    map.put(2048, 2048);
    cout << map.get(1) << " " << map.get(2) << " " << map.get(1024) << " " << map.get(2048) << endl;
    map.remove(1);
    map.remove(2048);
    cout << map.get(1) << " " << map.get(2) << " " << map.get(1024) << " " << map.get(2048) << endl;
    map.remove(1024);
    cout << map.get(1) << " " << map.get(2) << " " << map.get(1024) << " " << map.get(2048) << endl;
    return 0;
}
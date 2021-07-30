#include <vector>

using namespace std;

class MyHashSet
{
public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        buckets_ = vector<ListNode *>(1024);
    }

    ~MyHashSet()
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

    void add(int key)
    {
        int idx = key % buckets_.size();
        ListNode *node = find(buckets_[idx], key);
        if (node == nullptr)
        {
            buckets_[idx] = new ListNode(key, buckets_[idx]);
        }
    }

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

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int idx = key % buckets_.size();
        ListNode *node = find(buckets_[idx], key);
        return node != nullptr;
    }

private:
    struct ListNode
    {
        int key;
        ListNode *next;
        ListNode(int key, ListNode *next) : key(key), next(next) {}
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
    return 0;
}
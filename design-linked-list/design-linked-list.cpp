class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
    }

    ~MyLinkedList()
    {
        MyNode *node = preHead_.next;
        while (node != nullptr)
        {
            MyNode *temp = node->next;
            delete node;
            node = temp;
        }
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        return index < length_ ? getNode(index)->val : -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        addAtIndex(length_, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index <= length_)
        {
            MyNode *prevNode = getNode(index - 1);
            prevNode->next = new MyNode(val, prevNode->next);
            ++length_;
            if (index == length_ - 1)
            {
                tail_ = prevNode->next;
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < length_)
        {
            MyNode *prevNode = getNode(index - 1);
            MyNode *temp = prevNode->next;
            prevNode->next = temp->next;
            delete temp;
            --length_;
            if (index == length_)
            {
                tail_ = prevNode;
            }
        }
    }

private:
    struct MyNode
    {
        int val;
        MyNode *next;
        MyNode() : val(-1), next(nullptr) {}
        MyNode(int val, MyNode *next) : val(val), next(next) {}
    };

    MyNode *getNode(int index)
    {
        if (index == length_ - 1)
        {
            return tail_;
        }

        MyNode *node = &preHead_;
        for (int i = -1; i < index; ++i)
        {
            node = node->next;
        }

        return node;
    }

    int length_ = 0;
    MyNode preHead_;
    MyNode *tail_ = &preHead_; // Optimize for addAtTail
};

int main()
{
    return 0;
}
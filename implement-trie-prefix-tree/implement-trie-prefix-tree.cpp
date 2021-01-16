#include <string>

using namespace std;

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        _root = new Node();
    }

    ~Trie()
    {
        deleteTrie(_root);
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = _root;
        for (char c : word)
        {
            if (node->children[c - 'a'] == nullptr)
            {
                node->children[c - 'a'] = new Node();
            }

            node = node->children[c - 'a'];
        }

        node->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = getNode(word);
        return node != nullptr && node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return getNode(prefix) != nullptr;
    }

private:
    struct Node
    {
        bool isWord = false;
        Node *children[26] = {nullptr};
    };

    Node *getNode(const string &word)
    {
        Node *node = _root;
        for (char c : word)
        {
            node = node->children[c - 'a'];
            if (node == nullptr)
            {
                return nullptr;
            }
        }

        return node;
    }

    void deleteTrie(Node *node)
    {
        if (node != nullptr)
        {
            for (Node *child : node->children)
            {
                deleteTrie(child);
            }

            delete node;
        }
    }

    Node *_root;
};

int main()
{
    return 0;
}
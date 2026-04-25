#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for(int i = 0; i < 26; i++) children[i] = NULL;
        isEnd = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(node->children[c - 'a'] == NULL)
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(node->children[c - 'a'] == NULL)
                return false;
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            if(node->children[c - 'a'] == NULL)
                return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};

int main() {
    Trie t;
    t.insert("apple");

    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    cout << t.startsWith("app") << endl;
}

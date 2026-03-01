#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;
    void getSuggestionsHelper(TrieNode* node, string prefix, vector<string>& suggestions);

public:
    Trie();
    void insert(string word);
    vector<string> getSuggestions(string prefix);
};

#endif

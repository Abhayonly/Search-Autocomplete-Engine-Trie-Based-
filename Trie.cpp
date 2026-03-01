#include "Trie.h"

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(string word) {
    TrieNode* current = root;

    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }

    current->isEndOfWord = true;
}

void Trie::getSuggestionsHelper(TrieNode* node, string prefix, vector<string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }

    for (auto& pair : node->children) {
        getSuggestionsHelper(pair.second, prefix + pair.first, suggestions);
    }
}

vector<string> Trie::getSuggestions(string prefix) {
    TrieNode* current = root;
    vector<string> suggestions;

    for (char ch : prefix) {
        if (current->children.find(ch) == current->children.end()) {
            return suggestions; 
        }
        current = current->children[ch];
    }

    getSuggestionsHelper(current, prefix, suggestions);
    return suggestions;
}

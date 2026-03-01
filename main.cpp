#include "Trie.h"

int main() {
    Trie trie;

    // Sample words
    vector<string> words = {
        "apple", "app", "april",
        "bat", "ball", "bark",
        "cat", "call", "camera"
    };

    for (string word : words) {
        trie.insert(word);
    }

    string prefix;

    cout << "Search Autocomplete Engine\n";
    cout << "Type a prefix (or 'exit' to quit):\n";

    while (true) {
        cout << "\nEnter prefix: ";
        cin >> prefix;

        if (prefix == "exit") break;

        vector<string> suggestions = trie.getSuggestions(prefix);

        if (suggestions.empty()) {
            cout << "No suggestions found.\n";
        } else {
            cout << "Suggestions:\n";
            for (string word : suggestions) {
                cout << "- " << word << endl;
            }
        }
    }

    return 0;
}

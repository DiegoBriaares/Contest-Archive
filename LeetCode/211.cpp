class WordDictionary {
public:
    /* Usar un trie con procedimientos clasicos de busqueda e insercion. addWord 
       inserta la palabra que recibe  en el trie, y search busca la palabra que 
       recibe en el trie, cuando el caracter siguiente sea un punto, explorar 
       recursivamente y devolver or de lo que devuelvan.
    */
    vector<map<char, int>> Trie;
    vector<bool> end;
    int nodes = 0;
    WordDictionary() {
        Trie.clear();
        Trie.push_back(map<char, int>());
        end.push_back(false);
    }
    
    void addWord(string word) {
       int n = word.size();
       int node = 0;
       for (int i = 0; i < n; i++) {
          if (Trie[node].find(word[i]) == Trie[node].end()) {
            Trie[node][word[i]] = ++nodes;
            Trie.push_back(map<char, int>());
            end.push_back(false);
          }
          assert(Trie[node].find(word[i]) != Trie[node].end());
          node = Trie[node][word[i]];
       }
       end[node] = true; 
    }

    bool Find(string word, int i, int node) {
        if (i >= (int) word.size()) {
            return end[node];
        }
        bool found = false;
        if (word[i] == '.') {
            for (auto& x : Trie[node]) {
                found = found | Find(word, i + 1, x.second);
            }
        }
        else {
            if (Trie[node].find(word[i]) != Trie[node].end()) {
                found = found | Find(word, i + 1, Trie[node][word[i]]);
            }
        }
        return found;
    }
    
    bool search(string word) {
        return Find(word, 0, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

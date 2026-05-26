class PrefixTree {
public:

    struct Trie{
        private:
            Trie* node[26];
            bool end = false;

        public:

          Trie() {
            for (int i = 0; i < 26; i++) {
                node[i] = nullptr;
            }
        }
            bool contains(char ch)
            {
                return node[ch-'a']!=NULL;
            }
            void insert(char ch)
            {
                node[ch-'a'] = new Trie();
            }
            Trie* getNext(char ch)
            {
                return node[ch-'a'];
            }
            void setComplete()
            {
                end = true;
            }

            bool getComplete()
            {
                return end;
            }
    };

    Trie* root;
    PrefixTree() {
        root = new Trie();
    }
    
    void insert(string word) {
        
        auto it = root;
        for(auto & x : word)
        {
            if(!it->contains(x))
            {
                it->insert(x);
            }
            it = it->getNext(x);
        }
        it->setComplete();
    }
    
    bool search(string word) {
        auto it = root;
        for(auto & x : word)
        {
            if(!it->contains(x))
            {
                return false;
            }
            it = it->getNext(x);
        }
        return it->getComplete();
    }
    
    bool startsWith(string word) {
         auto it = root;
        for(auto & x : word)
        {
            if(!it->contains(x))
            {
                return false;
            }
            it = it->getNext(x);
        }
        return true;
    }
};

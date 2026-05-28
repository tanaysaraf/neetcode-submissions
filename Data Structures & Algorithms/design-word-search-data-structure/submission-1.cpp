class WordDictionary {
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

   bool helper(Trie* node, const string& word, int index)

{

    if (node == nullptr)

        return false;

    if (index == word.size())

        return node->getComplete();

    char ch = word[index];

    if (ch == '.')

    {

        for (char c = 'a'; c <= 'z'; c++)

        {

            if (node->contains(c))

            {

                if (helper(node->getNext(c), word, index + 1))

                    return true;

            }

        }

        return false;

    }

    if (!node->contains(ch))

        return false;

    return helper(node->getNext(ch), word, index + 1);

}

    Trie* root;
    WordDictionary() {
         root = new Trie();
    }
    
    void addWord(string word) {
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

        return helper(it, word, 0);
        
    }
};

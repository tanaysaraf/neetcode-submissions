class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        set<string>words(begin(wordList), end(wordList));

        queue<string>q;

        q.push(beginWord);
        int moves = 1;
        
        while(!q.empty())
        {
            int n = q.size();

            while(n--)
            {
                auto it = q.front(); q.pop();
                if(it==endWord)
                {
                    return moves;
                }
                for(auto & x : it)
                {
                    auto actual = x;
                    for(char ch='a'; ch<='z'; ch++)
                    {
                        x = ch;

                        if(words.find(it)!=words.end())
                        {
                            q.push(it);
                            words.erase(it);
                        }
                    }
                    x = actual;
                }
            }
            moves++;
        }
        return 0;
    }
};

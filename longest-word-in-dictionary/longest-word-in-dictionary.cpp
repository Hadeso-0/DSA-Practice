class TrieNode{
    public:
    TrieNode* next[26];
    bool isTerminal;
    TrieNode(){
        this->isTerminal = false;
        for(int i=0; i<26; i++) this->next[i] = NULL;
    }
};
class Trie{
    public: 
    TrieNode* root;
    Trie(vector<string>& words){
        this->root = new TrieNode();
        for(auto word: words){
            this->addWord(word);
        }
    }
    void addWord(string& s){
        TrieNode* rt = root;
        for(int i=0; i<s.size(); i++){
            if(rt->next[s[i]-'a'] == NULL){
                rt->next[s[i]-'a'] = new TrieNode();
            }
            rt = rt->next[s[i]-'a'];
        }
        rt->isTerminal = true;
    }
    string solve(TrieNode* rt){
        string ans = "";
        for(int i=0; i<26; i++){
            if((rt->next[i] != NULL) && (rt->next[i]->isTerminal == true)){
                string temp = solve(rt->next[i]);
                temp.push_back(char('a'+i));
                if(ans.size() < temp.size()) 
                    ans = temp;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* tr = new Trie(words);
        string ans = tr->solve(tr->root);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
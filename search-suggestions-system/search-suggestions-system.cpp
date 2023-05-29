class Node{
    public:
    bool isTerminal;
    string word;
    vector<Node*> next;
    Node(){
        this->isTerminal = false;
        this->word = "";
        this->next.resize(26, NULL);
    }
};
class Solution {
    void addWord(string& s, Node* root){
        Node* tmp = root;
        for(int i=0; i<(s).size(); ++i){
            if(tmp->next[s[i]-'a'] == NULL){
                tmp->next[s[i]-'a'] = new Node();
            }
            tmp = tmp->next[s[i]-'a'];
        }
        tmp->isTerminal = true;
        tmp->word = s;
    }
    void dfs(Node* root, vector<string>& ans){
        if(ans.size() == 3) return;
        if(root == NULL) return;
        if(root->isTerminal){
            ans.push_back(root->word);
        }
        for(int i=0; i<26; ++i){
            if(root->next[i] != NULL)
                dfs(root->next[i], ans);
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Node* root = new Node();
        for(auto& s : products){
           addWord(s, root); 
        }    
        vector<vector<string>> ans;

        Node* tmp = root;
        for(int i=0;i<searchWord.size(); ++i){
            if(tmp->next[searchWord[i]-'a'] == NULL){
                while(i++<searchWord.size()) ans.push_back({});
                break;
            }
            tmp = tmp->next[searchWord[i]-'a'];
            vector<string> temp;
            dfs(tmp, temp);
            ans.push_back(temp);
        }
        return ans;
    }
};
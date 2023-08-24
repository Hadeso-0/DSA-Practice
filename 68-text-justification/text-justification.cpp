class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        int i=0,w=0;
        int n = words.size();
        int spcs = 0;
        int sps = 0;
        string s;

        while(i < n){
            w = i;
            int len = -1;
            while(w < n && (len+words[w].size()+1) <= maxWidth){
                len = len + words[w].size() + 1;
                ++w;
            }
            // cout<<i<<" "<<w-1<<endl;
            spcs = maxWidth - len + w-1-i;
            s = "";
            if(w == n){
                // left justified
                for(int j=i; j<w; ++j){
                    s += words[j];
                    s.push_back(' ');
                    --spcs;
                }
                while(s.size() > maxWidth) s.pop_back();
                while(s.size() < maxWidth) s.push_back(' ');
            }
            else{
                // evenly justified
                for(int j=i; j<w; ++j){
                    s += words[j];
                    if(j==w-1) {while(spcs-- > 0) s.push_back(' '); break;}

                    sps = (spcs+w-j-2)/(w-j-1);
                    for(int k=0; k<sps; ++k) s.push_back(' ');
                    spcs -= sps;
                }
            }
            cout<<s<<endl;
            ans.push_back(s);
            i = w;
        }

        return ans;
    }
};
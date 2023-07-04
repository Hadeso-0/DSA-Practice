class Solution {
    int comp(int v1, int v2){
        if(v1 == v2) return 0;
        if(v1 > v2) return 1;
        else return -1;
    }
public:
    int compareVersion(string version1, string version2) {
        if((version1.size() == 0) && (version2.size() == 0)){ 
            return 0;
        }

        int v1 = 0;
        int v2 = 0;
       
        int i=0;
        while(i < version1.size() && version1[i] != '.'){
            v1 = (v1*10) + (version1[i]-'0');
            ++i;
        }
        if(i == version1.size()) version1 = "";
        else version1 = version1.substr(i+1);
        
        i = 0;
        while(i < version2.size() && version2[i] != '.'){
            v2 = (v2*10) + (version2[i]-'0');
            ++i;
        }
        if(i == version2.size()) version2 = "";
        else version2 = version2.substr(i+1);
        
        if(comp(v1,v2) == 0) 
            return compareVersion(version1, version2);
        
        return comp(v1, v2);
    }
};
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        int i = 0;
        int n = arr.size();

        while(i < (n-1)){
            int j = i+1;
            if(arr[i] != arr[j]){
                bool flg = true;
                
                if(arr[i] > arr[j]){
                    flg = false;
                }

                int len = 2;
                ++j;
                while(j < n){
                    if(flg){
                        if(arr[j] < arr[j-1]){  
                            flg = !flg;
                            ++j; ++len;
                        }
                        else{ break; }
                    }
                    else{
                        if(arr[j] > arr[j-1]){  
                            flg = !flg;
                            ++j; ++len;
                        }
                        else{ break; }
                    }
                }
                ans = max(ans, len);
                --j;
                // cout<<i<<" "<<j<<endl;
            }
            i = j;
        }
        return ans;
    }
};
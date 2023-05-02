/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    stack<NestedInteger> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int sz = nestedList.size();
        for(int i=sz-1; i>=0; i--){
            st.push(nestedList[i]);
        } 
    }
    int next() {
        int ans = (st.top()).getInteger();
        st.pop();
        return ans;
    }
    
    bool hasNext() {
        if(st.empty()) return false;

        while(!st.empty()){
            if((st.top()).isInteger()) return true;
            vector<NestedInteger> nex = (st.top()).getList();
            st.pop();

            int sz = nex.size();
            for(int i=sz-1; i>=0; i--){
                st.push(nex[i]);
            } 
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
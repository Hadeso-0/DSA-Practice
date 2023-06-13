class NumberContainers {
    map<int, int> index_num;
    map<int, set<int>> num_index;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(index_num.find(index) != index_num.end()){
            int old_num = (*index_num.find(index)).second;
            num_index[old_num].erase(index);
        }
        num_index[number].insert(index);
        index_num[index] = number;
    }
    
    int find(int number) {
        if(num_index.find(number) == num_index.end()) return -1;
        if((num_index[number]).size() == 0) return -1; 
        return *((num_index[number]).begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
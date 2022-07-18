class MyHashSet {
public:
   vector<list<int>>h;
    int size;
    MyHashSet() {
        size=10;
        h.resize(size);
    }
    
    int hash(int key){
        return key%size;
    }
    list<int>::iterator search(int key){
       int i=hash(key);
        return find(h[i].begin(),h[i].end(),key);
    }
    
    void add(int key) {
        if(contains(key)) return;
        int i=hash(key);
        h[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i=hash(key);
        h[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key)==h[i].end()) return false;
        else return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

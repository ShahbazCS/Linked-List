class MyHashMap {
public:
    vector<list<pair<int,int>>> h;
    int size;
    
    //constructor to assign memory
    MyHashMap() {
        size=100;
        h.resize(size);
    }
    //hash function
    int hash(int key){
        return key%size;
    }
    
    list<pair<int,int>> ::iterator search(int key){
        int i=hash(key);
        auto it=h[i].begin(); //or list<pair<int,int>>::iterator it=h[i].begin()
        while(it!=h[i].end()){
            if(it->first==key) return it;
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
       int i=hash(key);
        auto it=search(key);
        if(it!=h[i].end()) it->second=value;
        else h[i].push_back({key,value});
    }
    
    int get(int key) {
        int i=hash(key);
        auto it=search(key);
        if(it==h[i].end()) return -1;
        else return it->second;
    }
    
    void remove(int key) {
        int i=hash(key);
        auto it=search(key);
        if(it==h[i].end()) return;
        else h[i].erase(it);
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

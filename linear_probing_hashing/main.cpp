#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

template<typename K, typename V> 

//hash table node
class HashTableEntry{
    
   public:
    K key;
    V value;
    HashTableEntry(K k,V v){
       key = k;value = v;
    }
};

template<typename K, typename V> 


class HashTableMap{
    //array of hashnodes 
    HashTableEntry<K,V> **table;
    int capacity;
    int size;
    
    public: 
    HashTableMap(int initcapacity){
        capacity = initcapacity;
        size = 0;
        table = new HashTableEntry<K,V>*[capacity];
        //intialize table with null values for all the capacity
        for(int  i = 0; i < capacity ;i++)
            table[i] = NULL;
    }
    
    //hash function used for getting the index for a key in hash table 
    int hashFunc(K key){
        return key%capacity;
    }
    
    void insertEntry(K key,V value){
        HashTableEntry<K,V> *newEntery = new HashTableEntry<K,V>(key,value);
        
        int hashIndex  = hashFunc(key);
        
        //find the next empty slot in the table 
        while(table[hashIndex] != NULL && table[hashIndex]->key != key){
            ++hashIndex;
            hashIndex = hashFunc(hashIndex);
        }
        cout<<"the index "<<hashIndex<<endl; 
        if(table[hashIndex] == NULL) size++;
        table[hashIndex] = newEntery;
    }
    
    V deleteEntry(K key){
        V value;
        
        int hashIndex = hashFunc(key);
        
        while(table[hashIndex]->key != key){
            hashIndex++;
            hashIndex = hashFunc(hashIndex);
        }
        
        if(table[hashIndex]->key == key){
            value = table[hashIndex]->value;
            size--;
            table[hashIndex] = NULL;
        }
        return value;
    }
    
    V searchEntry(K key){
        int hashIndex = hashFunc(key);
        int counter = 0 ;
        while(table[hashIndex] != NULL){
            if(table[hashIndex]->key == key) return table[hashIndex]->value;
            counter++;
            if(counter > capacity) return NULL;
            hashIndex++;
            hashIndex = hashFunc(hashIndex);
        }
        
        return NULL;
    }
    
     void display() 
    { 
        for(int i=0 ; i<capacity ; i++) 
        { 
            if(table[i] != NULL) 
                cout << "key = " << table[i]->key  
                     <<"  value = "<< table[i]->value << endl; 
        } 
    } 
    
    int Size(){return size;}
};

int main(int argc, char **argv)
{ 
//    
    HashTableMap<int, int> *h = new HashTableMap<int, int>(10); 
    h->insertEntry(1,1); 
    h->insertEntry(2,2); 
    h->insertEntry(2,3); 
    h->display(); 
    cout << h->Size() <<endl; 
    cout << h->deleteEntry(2) << endl; 
    cout << h->Size() <<endl; 
    cout << h->searchEntry(2); 
	return 0;
}

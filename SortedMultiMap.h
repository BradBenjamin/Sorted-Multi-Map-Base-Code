#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
#include <iostream>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);


class SortedMultiMap {
	friend class SMMIterator;
    private:
        struct Node {
            TKey key;
            vector<TValue> values;
            Node(const TKey& k, const TValue& v) : key(k), values({v}) {}
        };

    vector<Node> elements;
    Relation relation;
    public:

    // constructor
    SortedMultiMap(Relation r);

    void display() const {
        for (const auto& node : elements) {
            cout << "Key: " << node.key << endl;
            for (const auto& value : node.values) {
                cout << "Value: " << value << endl;
            }
        }
    }

	//adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

	//returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;


    int addIfNotPresent(SortedMultiMap& smm);

    bool contains(const TKey& key)const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();
};

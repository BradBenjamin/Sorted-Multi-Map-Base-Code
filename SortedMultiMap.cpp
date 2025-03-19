#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation r): relation(r){}

void SortedMultiMap::add(TKey k, TValue v) {
    for (size_t i = 0; i < elements.size(); ++i) {
        if (elements[i].key == k) {
            // Found a node with the same key, add the value to its list of values
            elements[i].values.push_back(v);
            return; // No need to continue, exit the function
        } else if (relation(elements[i].key, k) > 0) {
            // Found the position to insert the new node
            elements.insert(elements.begin() + i, Node(k, v));
            return; // No need to continue, exit the function
        }
    }

    // If no node with the given key exists and no node with a greater key exists, create a new node and insert it into the multimap
    elements.push_back(Node(k, v));
}

vector<TValue> SortedMultiMap::search(TKey c) const {
    vector<TValue> values;
    // Iterate through the elements to find nodes with the given key
    for (size_t i = 0; i < elements.size(); ++i) {
        if (elements[i].key==c) {
            // Found a node with the same key, add its values to the result vector
            values.insert(values.end(), elements[i].values.begin(), elements[i].values.end());
        }
    }

    return values;
}

bool SortedMultiMap::remove(TKey c, TValue v) {
    bool removed = false;

    // Iterate through the elements vector
    for (size_t i = 0; i < elements.size(); ++i) {
        if (elements[i].key==c) {
            // Found a node with the same key
            auto& values = elements[i].values;
            for (size_t j = 0; j < values.size(); ++j) {
                if (values[j] == v) {
                    // Found the value to remove
                    values.erase(values.begin() + j);
                    removed = true;
                    break;
                }
            }
            // If there are no more values associated with the key, remove the entire node
            if (values.empty()) {
                elements.erase(elements.begin() + i);
            }
            // If a value is removed, stop searching
            if (removed) {
                break;
            }
        }
    }
    return removed;
}

int SortedMultiMap::size() const {
	int size=0;
    for (size_t i = 0; i < elements.size(); ++i) {
        size+=elements[i].values.size();
    }
    return size;
}

bool SortedMultiMap::isEmpty() const {
	return elements.size()==0;
}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

bool SortedMultiMap::contains(const TKey& key) const {
    for (const auto& node : elements) {
        if (node.key == key) {
            return true;
        }
    }
    return false;
}

int SortedMultiMap::addIfNotPresent(SortedMultiMap &smm) {
    int addedPairs = 0;
    for (const auto& node : smm.elements) {
        cout<<node.key<<" ";
        if (!contains(node.key)) {
            // Key is not present in the current SortedMultiMap, add all pairs with this key
            for (const auto& value : node.values) {
                add(node.key, value);
                addedPairs++;
            }
        }
    }
    return addedPairs;
}

SortedMultiMap::~SortedMultiMap() {}

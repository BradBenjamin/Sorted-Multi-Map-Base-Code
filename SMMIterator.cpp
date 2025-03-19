#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator(const SortedMultiMap& map) : map(map) {
    // Initialize iterator state
    first();
}

void SMMIterator::first() {
    currentKeyIndex = 0;
    currentValueIndex = 0;
    while (currentKeyIndex < map.elements.size() && map.elements[currentKeyIndex].values.empty()) {
        currentKeyIndex++;
    }
}

void SMMIterator::next() {
    if (!valid()) {
        throw std::runtime_error("Iterator is not valid.");
    }

    currentValueIndex++;
    if (currentValueIndex >= map.elements[currentKeyIndex].values.size()) {
        currentKeyIndex++;
        currentValueIndex = 0;
        while (currentKeyIndex < map.elements.size() && map.elements[currentKeyIndex].values.empty()) {
            currentKeyIndex++;
        }
    }
}

bool SMMIterator::valid() const {
    return currentKeyIndex < map.elements.size() && currentValueIndex < map.elements[currentKeyIndex].values.size();
}

TElem SMMIterator::getCurrent() const {
    if (!valid()) {
        throw std::runtime_error("Iterator is not valid.");
    }
    TKey key = map.elements[currentKeyIndex].key;
    TValue value = map.elements[currentKeyIndex].values[currentValueIndex];
    return TElem(key, value);
}



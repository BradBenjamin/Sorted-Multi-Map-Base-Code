#pragma once

#include "SortedMultiMap.h"
using namespace std;


class SMMIterator {
    friend class SortedMultiMap;
private:
    const SortedMultiMap& map;
    int currentKeyIndex;
    int currentValueIndex;
    SMMIterator(const SortedMultiMap& map);

public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;
};




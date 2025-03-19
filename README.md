# Sorted MultiMap (C++)

## Overview
A C++ implementation of a **Sorted MultiMap**, storing key-value pairs with a custom sorting relation. Supports adding, searching, removing, and iterating through elements.

## Features
- Vector-based storage with custom sorting.
- Supports multiple values per key.
- Iterator for traversal.
- Basic operations: `add`, `search`, `remove`, `contains`, `size`.

## Compilation & Execution
```bash
g++ -o SortedMultiMap App.cpp SortedMultiMap.cpp SMMIterator.cpp ShortTest.cpp ExtendedTest.cpp -std=c++11
./SortedMultiMap
```

## Usage
```cpp
SortedMultiMap smm(myRelation);
smm.add(1, 10);
smm.search(1);
smm.remove(1, 10);
SMMIterator it = smm.iterator();
while (it.valid()) { it.next(); }
```

## License
MIT License – Free to use and modify.

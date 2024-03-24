# Hash Table
An implementation of an associative array, using hashing. An experimental library.

# Hashing function
Simple. TODO: improve!
```
function hash(string, a, num_buckets):
    hash = 0
    string_len = length(string)
    for i = 0, 1, ..., string_len:
        hash += (a ** (string_len - (i+1))) * char_code(string[i])
    hash = hash % num_buckets
    return hash
```

# Limitations
- only accepts char* and ASCII
- collisions are handled with open addressing with double hashing.
- Handle int/long overflows correctly!
- Hash tables of size ~ million don't have great performance
TODO: change/mitigate these!

# Run unit tests
```
cmake -B build
cmake --build build
ctest --test-dir build
```

# Extensions:
- more customisation? allow user to give hashing function, resize limits, collision resolution method etc
- don't assume on memory alloc? somehow allow user to provide the allocation method
- handle overflows and int/long stuff
- update/improve hash function, provide multiple?
- extend from just ascii to other stuff? Allow different types of hash maps
- improve efficiency? How can I acheive thios?
- utilise the preprocessor more
- make the library platform independent?
- provide size method
- provide iterators?
- abstract structs away?
- clear the hash table method
- header only?
- change the name of the methods, header file
- optionally make the hash table thread-safe?
- improve handling of edge cases, duplicate keys, keys that don't exist, keys too big or too small etc.

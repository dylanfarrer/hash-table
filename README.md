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
TODO: change/mitigate these!

# Run unit tests
```
mkdir build
cd build
cmake .. && make
./tests
```

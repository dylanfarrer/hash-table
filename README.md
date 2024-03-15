
An implementation of an associative array, using hashing (creating a hash map!).

Generic hash algorithm utilised (TODO consider how I can improve this!):

function hash(string, a, num_buckets):
    hash = 0
    string_len = length(string)
    for i = 0, 1, ..., string_len:
        hash += (a ** (string_len - (i+1))) * char_code(string[i])
    hash = hash % num_buckets
    return hash

Limitation:
    only accepts char* and ASCII
    collisions are handled with open addressing with double hashing, TODO, look into alternatives?




TODOs:
    - find segfault that occasionally occurs from input (i think)
    - use a unit testing framework rather than a massive main.c
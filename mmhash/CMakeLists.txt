
set(hash_ring_files hash_ring.cc consistent_hash_map.h hash_ring.h hash_ring_types.h hash_warpper.h murmur_hash2.h murmur_hash2.cc)
add_library(hash_ring STATIC ${hash_ring_files})

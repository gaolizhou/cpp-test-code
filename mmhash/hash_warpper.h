#ifndef HASH_WARPPER_H_
#define HASH_WARPPER_H_

#include "murmur_hash2.h"

namespace udisk {
namespace common {

template <typename Key>
class MurmurHash {
 public:
  typedef uint32_t result_type;
  typedef Key argument_type;

  result_type operator() (const argument_type &arg) const {
    return MurmurHash2(arg.c_str(), arg.size(), 0);
  }
};

}; // end of ns common
}; // end of ns udisk

#endif

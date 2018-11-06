#ifndef HASH_RING_TYPES_H_
#define HASH_RING_TYPES_H_

#include <string>
#include <sstream>
#include <cassert>

namespace udisk {
namespace hash_ring {

typedef uint32_t NODE_ID;

class HashRingVirtualNode {
 public:
  HashRingVirtualNode(NODE_ID id, const std::string &key, int vidx = -1) :
    id_(id),
    vidx_(vidx),
    key_(key) {
  }

  HashRingVirtualNode(const HashRingVirtualNode &vnode) = default;

  HashRingVirtualNode& operator=(const HashRingVirtualNode &vnode) {
    id_ = vnode.id_;
    key_ = vnode.key_;
    vidx_ = vnode.vidx_;
    return *this;
  }

  bool operator == (const HashRingVirtualNode &b) const {
    return key_ == b.key_ && id_ == b.id_ && vidx_ == b.vidx_;
  }

  const std::string& key() const {
    return key_;
  }

  NODE_ID id() const {
    return id_;
  }

  int vidx() const {
    return vidx_;
  }

  std::string to_string() const {
    std::stringstream ss;
    ss << "key : " << key_ << ", id: " << id_ << ", vidx: " << vidx_;
    return ss.str();
  }

  template <template <class HHash> class Hash>
  class Hasher {
   public:
    typedef uint32_t result_type;

    Hasher(uint32_t hash_space) {
      hash_space_ = hash_space;
    }

    result_type operator() (const HashRingVirtualNode & vnode) const {
      std::string key = vnode.key();
      return hash_space_ ? Hash<std::string>()(key) % hash_space_ :
                          Hash<std::string>()(key);
    }
   private:
    uint32_t hash_space_;
  };
 private:
  NODE_ID id_;
  int vidx_;
  std::string key_;
};

}; // end of ns common
}; // end of ns udisk

#endif

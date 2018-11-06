#include "hash_ring.h"
#include <tuple>

namespace udisk {
namespace hash_ring {

uint32_t HashRing::range(const HashRingVirtualNode &vnode) const {
  VirtualNodeContainer::const_iterator it;
  if (impl_.exist(vnode, &it)) {
    VirtualNodeContainer::const_iterator prec;
    if (it == impl_.begin()) {
      VirtualNodeContainer::const_iterator end = impl_.end();
      return (UINT32_MAX - (--end)->first) + it->first;
    } else {
      return (it--)->first - it->first;
    }
  }
  return 0;
}

bool HashRing::exist(const HashRingVirtualNode &vnode) const {
  return impl_.exist(vnode);
}

bool HashRing::add_node(const HashRingVirtualNode &vnode) {
  std::pair<VirtualNodeContainer::iterator, bool> result = impl_.insert(vnode);
  return result.second;
}

bool HashRing::del_node(const HashRingVirtualNode &vnode) {
  if (impl_.erase(vnode)) {
    return true;
  }
  return false;
}

const HashRingVirtualNode & HashRing::hash(uint32_t hash_value) const {
  VirtualNodeContainer::const_iterator it = impl_.find(hash_value);
  assert(it != impl_.end());
  return it->second;
}

const HashRingVirtualNode & HashRing::hash(const std::string &key) const {
  uint32_t hash =  common::MurmurHash<std::string>()(key);
  return this->hash(hash);
}

bool HashRing::advance_nodes(std::size_t hash_value,
    std::vector<HashRingVirtualNode> *nodes) const {
  // TODO
  return false;
}

bool HashRing::advance_nodes(const std::string &key,
    std::vector<HashRingVirtualNode> *nodes) const {
  // TODO
  return false;
}

bool HashRing::backward_nodes(std::size_t hash_value,
    std::vector<HashRingVirtualNode> *nodes) const {
  // TODO
  return false;
}

bool HashRing::backward_nodes(const std::string &key,
    std::vector<HashRingVirtualNode> *nodes) const {
  // TODO
  return false;
}

void HashRing::range_stat(std::tuple<uint32_t, uint32_t, uint32_t> *max_min_avg) const {
  uint32_t hash_space = hash_space_ ? hash_space_ : UINT32_MAX;

  std::map<uint32_t, uint32_t> key_stat;
  VirtualNodeContainer::const_iterator it = impl_.begin();
  for (; it != impl_.end(); ++it) {
    uint32_t range = 0;
    uint32_t id = it->second.id();
    if (it == impl_.begin()) {
      VirtualNodeContainer::const_iterator end = impl_.end();
      range = it->first + (hash_space - (--end)->first);
    } else {
      VirtualNodeContainer::const_iterator curr = it;
      range = it->first - (--curr)->first;
    }
    key_stat[id] = key_stat[id] + range;
  }

  uint32_t max_range = 0, min_range = hash_space;
  uint32_t avg_range = hash_space/key_stat.size();

  for (auto it = key_stat.begin(); it != key_stat.end(); ++it) {
    if (it->second > max_range) {
      max_range = it->second;
    }
    if (it->second < min_range) {
      min_range = it->second;
    }
  }
  *max_min_avg = std::make_tuple(max_range, min_range, avg_range);
}

}; // end of ns common
}; // end of ns udisk


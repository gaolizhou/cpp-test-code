#ifndef CONSISTENT_HASH_MAP_H_
#define CONSISTENT_HASH_MAP_H_

#include <map>
#include <string>
#include <list>
#include <functional> 
#include <algorithm>

namespace udisk {
namespace common {

template <typename T,
          typename Hash,
          typename Alloc = std::allocator<std::pair<const typename Hash::result_type,T > > >
class ConsistentHashMap {
 public:
  typedef typename Hash::result_type size_type;
  typedef std::map<size_type,T,std::less<size_type>,Alloc> map_type;
  typedef typename map_type::value_type value_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename map_type::iterator iterator;
  typedef typename map_type::const_iterator const_iterator;
  typedef typename map_type::reverse_iterator reverse_iterator;
  typedef Alloc allocator_type;

  ConsistentHashMap(Hash hasher) : hasher_(hasher) {
  }

  ConsistentHashMap(const ConsistentHashMap &) = default;
  ConsistentHashMap & operator = (const ConsistentHashMap &) = delete;
  
  ~ConsistentHashMap() = default;

  void clear() { nodes_.clear(); }
  std::size_t size() const {
    return nodes_.size();
  }

  bool empty() const {
    return nodes_.empty();
  }

  bool exist(const T &node, const_iterator *out = nullptr) const {
    size_type hash = hasher_(node);
    const_iterator it = nodes_.find(hash);
    if (it != nodes_.end() && it->second == node) {
      if (out) {
        *out = it;
      }
      return true;
    }
    if (out) {
      *out = nodes_.end();
    }
    return false;
  }

  std::pair<iterator, bool> insert(const T& node) {
    size_type hash = hasher_(node);
    return nodes_.insert(value_type(hash,node));
  }

  void erase(iterator it) {
    nodes_.erase(it);
  }

  std::size_t erase(const T& node) {
    size_type hash = hasher_(node);
    return nodes_.erase(hash);
  }

  iterator find(size_type hash) {
    if (nodes_.empty()) {
      return nodes_.end();
    }

    iterator it = nodes_.lower_bound(hash);

    if (it == nodes_.end()) {
      it = nodes_.begin();
    }
    return it;
  }

  const_iterator find(size_type hash) const {
    if (nodes_.empty()) {
      return nodes_.end();
    }

    const_iterator it = nodes_.lower_bound(hash);

    if (it == nodes_.end()) {
      it = nodes_.begin();
    }
    return it;
  }

  iterator begin() {
    return nodes_.begin();
  }

  const_iterator begin() const {
    return nodes_.begin();
  }

  iterator end() {
    return nodes_.end();
  }

  const_iterator end() const {
    return nodes_.end();
  }

  reverse_iterator rbegin() {
    return nodes_.rbegin();
  }

  reverse_iterator rend() {
    return nodes_.rend();
  }

  const map_type &nodes() const {
    return nodes_;
  }

private:
  Hash hasher_;
  map_type nodes_;
};

}; // end of ns common
}; // end of ns udisk

#endif

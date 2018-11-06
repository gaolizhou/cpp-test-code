#ifndef HASH_RING_H_
#define HASH_RING_H_

#include "hash_ring_types.h"
#include "consistent_hash_map.h"
#include "hash_warpper.h"

namespace udisk {
namespace hash_ring {

class HashRingInterface {
 public:
  /**
   * @brief 判断环是否为空
   * @return 如果为空，返回true,否则返回false
   */
  virtual bool empty() const = 0;
  /**
   * @brief 获取环的节点个数
   * @return 节点个数
   */
  virtual std::size_t size() const = 0;

  /**
   * @brief 获取环上节点的负责范围大小
   */
  virtual uint32_t range(const HashRingVirtualNode &vnode) const = 0;
  /**
   * @brief 判断指定节点是否存在
   * @return 如果存在，则返回true, 否则返回false
   */
  virtual bool exist(const HashRingVirtualNode &vnode) const = 0;
  /**
   * @brief 添加指定节点
   * @param vnode 节点
   * @return 如果冲突，则添加失败，返回false，
   * 否则添加成功，返回true
   */
  virtual bool add_node(const HashRingVirtualNode &vnode) = 0;
  /**
   * @brief 删除指定节点
   * @param vnode 节点
   * @return 如果节点不存在，则删除失败，返回false，
   * 否则删除成功，返回true
   */
  virtual bool del_node(const HashRingVirtualNode &vnode) = 0;
  /**
   * @brief 清空hash环
   */
  virtual void clear() = 0;
  /**
   * @brief 获取指定hash值所在节点
   * @param hash_value hash值
   * @return 所在节点
   */
  virtual const HashRingVirtualNode &hash(uint32_t hash_value) const = 0;
  /**
   * @brief 获取指定key所在节点
   * @param hash_value key
   * @return 所在节点
   */
  virtual const HashRingVirtualNode &hash(const std::string &key) const = 0;

  // do not use those now!, for data migrate
  virtual bool advance_nodes(std::size_t hash_value,
      std::vector<HashRingVirtualNode> *nodes) const = 0;
  virtual bool advance_nodes(const std::string &key,
      std::vector<HashRingVirtualNode> *nodes) const = 0;

  virtual bool backward_nodes(std::size_t hash_value,
      std::vector<HashRingVirtualNode> *nodes) const = 0;
  virtual bool backward_nodes(const std::string &key,
      std::vector<HashRingVirtualNode> *nodes) const = 0;
};

class HashRing : public HashRingInterface {
 public:
  std::size_t size() const override {
    return impl_.size();
  }
  
  bool empty() const override {
    return impl_.empty();
  }

  uint32_t range(const HashRingVirtualNode &vnode) const override;
  
  bool exist(const HashRingVirtualNode &vnode) const override;

  bool add_node(const HashRingVirtualNode &vnode) override;
  bool del_node(const HashRingVirtualNode &vnode) override;
  void clear() override { impl_.clear(); }

  const HashRingVirtualNode &hash(uint32_t hash_value) const override;
  const HashRingVirtualNode &hash(const std::string &key) const override;

  bool advance_nodes(std::size_t hash_value,
      std::vector<HashRingVirtualNode> *nodes) const override;
  bool advance_nodes(const std::string &key,
      std::vector<HashRingVirtualNode> *nodes) const override;

  bool backward_nodes(std::size_t hash_value,
      std::vector<HashRingVirtualNode> *nodes) const override;
  bool backward_nodes(const std::string &key,
      std::vector<HashRingVirtualNode> *nodes) const override;

  static uint32_t conflict(uint32_t alpha, uint32_t dealt, uint32_t key) {
    return alpha * key + dealt;
  }

  void range_stat(std::tuple<uint32_t, uint32_t, uint32_t> *max_min_avg) const;

  // typedef template std::hash Hash;
  typedef HashRingVirtualNode::Hasher<common::MurmurHash> VNodeHasher;

  typedef common::ConsistentHashMap<HashRingVirtualNode, VNodeHasher> VirtualNodeContainer;
  typedef common::ConsistentHashMap<HashRingVirtualNode, VNodeHasher>::map_type VirtualNodeMap;

  const VirtualNodeMap &virtual_node_map() const {
    return impl_.nodes();
  }

  HashRing(uint32_t hash_space = 0) :
    impl_(VirtualNodeContainer(VNodeHasher(hash_space))),
    hash_space_(hash_space) {
  }
 private:
  VirtualNodeContainer impl_;
  uint32_t hash_space_;
};

}; // end of ns hash_ring
}; // end of ns udisk

#endif

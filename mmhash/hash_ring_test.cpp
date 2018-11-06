//
// Created by lizgao on 11/6/18.
//
#include "hash_ring.h"
#include <glog/logging.h>

/*
 * > db.t_cluster_info.find()
{ "_id" : ObjectId("5bda9ce35b68044980c51d68"), "scale_num" : 4000, "version" : 1, "pg_num" : 15, "conflict_a" : 7, "conflict_b" : 3 }
 */
void hash_ring_test() {
  udisk::hash_ring::HashRing ring;

  uint32_t pgnum = 15;
  uint32_t scalenum = 1;
  uint32_t conflicta = 7;
  uint32_t conflictb = 3;
  for (uint32_t i = 0; i < pgnum; ++i) {
    for (uint32_t j = 0; j < scalenum; ++j) {
      std::stringstream ss;
      ss << "pg_" << i << "-" << j;
      udisk::hash_ring::HashRingVirtualNode node(i, ss.str(), j);
      uint32_t base = i;
      while(!ring.add_node(node)) {
        std::stringstream ss;
        base = udisk::hash_ring::HashRing::conflict(conflicta, conflictb, base);
        ss << "pg_" << i << "-" <<  j << "*" << base;
        node = udisk::hash_ring::HashRingVirtualNode(i, ss.str(), j);
      }
    }
  }
  LOG(INFO) << "size=" << ring.size();
}
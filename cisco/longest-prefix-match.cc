//
// Created by lizgao on 2/9/19.
//
#include <glog/logging.h>
#include <vector>
#include <tuple>
namespace {
struct RoutingItem {
  uint32_t prefix;
  uint8_t len;
  uint32_t next_hop;
};

struct Node {
  Node *next[256];
  uint8_t value;
  uint8_t len; //prefix length
};

class RoutingTable {
  RoutingTable() {

  }
  ~RoutingTable() {

  }
 public:
  void InsertItem(const RoutingItem &item);
  void RemoveItem(uint32_t prefix, uint8_t len);
  RoutingItem *FindBestRoute(uint32_t dst_ip);

 private:
  std::vector<RoutingItem> routing_item_list_;
  Node *table_[256];
};


}
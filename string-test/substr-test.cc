//
// Created by lizgao on 1/31/19.
//
#include <glog/logging.h>
#include <string>

void substr_test() {
  std::string device_id = "12-0000:3b:00.0";
  auto pos = device_id.find('-', 0);
  int chunk_id = std::stoi(device_id.substr(0, pos));
  auto nvme_pci_id = device_id.substr(pos+1);
  LOG(INFO) << "pos="<<pos<<", chunk_id="<<chunk_id << ",nvme_pci_id="<<nvme_pci_id << ",chunk-str=" << device_id.substr(0, pos);
}
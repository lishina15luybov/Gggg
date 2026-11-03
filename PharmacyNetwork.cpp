#include "PharmacyNetwork.h"

PharmacyNetwork::PharmacyNetwork(const std::string& networkName) : networkName(networkName) {}

std::string PharmacyNetwork::getNetworkName() const { return networkName; }

void PharmacyNetwork::addBranch(std::shared_ptr<PharmacyBranch> branch) {
    branches.push_back(branch);
}

std::vector<std::shared_ptr<PharmacyBranch>> PharmacyNetwork::getBranches() const {
    return branches;
}

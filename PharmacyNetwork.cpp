#include "PharmacyNetwork.h"

PharmacyNetwork::PharmacyNetwork(const std::string& networkName) : networkName(networkName) {}

PharmacyNetwork::~PharmacyNetwork() {
    for (auto branch : branches) {
        delete branch;
    }
}

std::string PharmacyNetwork::getNetworkName() const { return networkName; }

void PharmacyNetwork::addBranch(PharmacyBranch* branch) {
    branches.push_back(branch);
}

std::vector<PharmacyBranch*> PharmacyNetwork::getBranches() const {
    return branches;
}

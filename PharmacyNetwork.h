#pragma once
#include "PharmacyBranch.h"
#include <vector>
#include <memory>
#include <string>

class PharmacyNetwork {
private:
    std::string networkName;
    std::vector<std::shared_ptr<PharmacyBranch>> branches;

public:
    PharmacyNetwork(const std::string& networkName);
    std::string getNetworkName() const;
    void addBranch(std::shared_ptr<PharmacyBranch> branch);
    std::vector<std::shared_ptr<PharmacyBranch>> getBranches() const;
};

#include "PharmacyNetwork.h"

/**
 * @brief Конструктор сети аптек.
 */
PharmacyNetwork::PharmacyNetwork(const std::string& networkName) : networkName(networkName) {}

/**
 * @brief Получить название сети.
 */
std::string PharmacyNetwork::getNetworkName() const { return networkName; }

/**
 * @brief Добавить филиал в сеть.
 */
void PharmacyNetwork::addBranch(const PharmacyBranch& branch) {
    branches.push_back(branch);
}

/**
 * @brief Получить список всех филиалов.
 */
std::vector<PharmacyBranch> PharmacyNetwork::getBranches() const {
    return branches;
}

#pragma once
#include "PharmacyBranch.h"
#include <vector>
#include <string>

/**
 * @brief Класс, управляющий сетью аптек (несколькими филиалами).
 */
class PharmacyNetwork {
private:
    std::string networkName; /// Название сети
    std::vector<PharmacyBranch*> branches; /// Список филиалов в сети

public:
    /**
     * @brief Конструктор сети аптек.
     * @param networkName Название сети
     */
    PharmacyNetwork(const std::string& networkName);
    

    ~PharmacyNetwork();

    /// @return Название сети
    std::string getNetworkName() const;
    
    /**
     * @brief Добавить филиал в сеть.
     * @param branch Указатель на филиал
     */
    void addBranch(PharmacyBranch* branch);
    
    /// @return Вектор всех филиалов сети
    std::vector<PharmacyBranch*> getBranches() const;
};

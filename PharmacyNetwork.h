#pragma once
#include "PharmacyBranch.h"
#include <vector>
#include <string>

/**
 * @brief Класс, управляющий сетью аптек (несколькими филиалами).
 */
class PharmacyNetwork {
private:
    std::string networkName; ///< Название сети
    std::vector<PharmacyBranch> branches; ///< Список филиалов в сети (хранятся по значению)

public:
    /**
     * @brief Конструктор сети аптек.
     * @param networkName Название сети
     */
    PharmacyNetwork(const std::string& networkName);
    
    /// @brief Деструктор по умолчанию.
    ~PharmacyNetwork() = default;

    /**
     * @brief Получить название сети.
     * @return Название
     */
    std::string getNetworkName() const;
    
    /**
     * @brief Добавить филиал в сеть.
     * @param branch Филиал
     */
    void addBranch(const PharmacyBranch& branch);
    
    /**
     * @brief Получить список всех филиалов.
     * @return Вектор филиалов
     */
    std::vector<PharmacyBranch> getBranches() const;
};

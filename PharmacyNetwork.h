#pragma once

#include "PharmacyBranch.h"
#include <string>
#include <vector>

/**
 * @brief Класс, управляющий сетью аптек (несколькими филиалами).
 */
class PharmacyNetwork {
private:
    /**
     * @brief Название сети аптек.
     */
    std::string networkName;

    /**
     * @brief Список филиалов в сети (хранятся по значению).
     */
    std::vector<PharmacyBranch> branches;

public:
    /**
     * @brief Конструктор сети аптек.
     * @param networkName Название сети.
     */
    PharmacyNetwork(const std::string& networkName);

    /**
     * @brief Деструктор по умолчанию.
     */
    ~PharmacyNetwork() = default;

    /**
     * @brief Получить название сети.
     * @return Название сети аптек.
     */
    std::string getNetworkName() const;

    /**
     * @brief Добавить филиал в сеть.
     * @param branch Филиал для добавления.
     */
    void addBranch(const PharmacyBranch& branch);

    /**
     * @brief Получить список всех филиалов.
     * @return Вектор филиалов сети.
     */
    std::vector<PharmacyBranch> getBranches() const;
};

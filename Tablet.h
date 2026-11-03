#pragma once
#include "Medicine.h"

/**
 * @brief Класс-наследник, описывающий таблетки.
 */
class Tablet : public Medicine {
    int pillsPerPack; ///< Количество таблеток в упаковке
public:
    /**
     * @brief Конструктор таблеток.
     */
    Tablet(const std::string& name, const std::string& manufacturer,
           const std::string& annotation, const std::string& disease,
           int shelfLifeMonths, double price, int pillsPerPack);
           
    /// @return Тип "Таблетки"
    std::string getType() const override;
    
    /// @return Полная информация о таблетках
    std::string getInfo() const override;
};

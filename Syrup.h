#pragma once
#include "Medicine.h"

/**
 * @brief Класс-наследник, описывающий сироп.
 */
class Syrup : public Medicine {
    int volumeMl; /// Объем во флаконе (в мл)
public:
    /**
     * @brief Конструктор сиропа.
     */
    Syrup(const std::string& name, const std::string& manufacturer,
          const std::string& annotation, const std::string& disease,
          int shelfLifeMonths, double price, int volumeMl);
          
    /// @return Тип "Сироп"
    std::string getType() const override;
    
    /// @return Полная информация о сиропе
    std::string getInfo() const override;
};

#pragma once
#include "Medicine.h"

/**
 * @brief Класс-наследник, описывающий сироп.
 */
class Syrup : public Medicine {
    int volumeMl; ///< Объем во флаконе (в мл)
public:
    /**
     * @brief Конструктор сиропа.
     * @param name Название
     * @param manufacturer Изготовитель
     * @param annotation Аннотация
     * @param disease Болезнь
     * @param shelfLifeMonths Срок годности
     * @param price Цена
     * @param volumeMl Объем во флаконе (в мл)
     */
    Syrup(const std::string& name, const std::string& manufacturer,
          const std::string& annotation, const std::string& disease,
          const int shelfLifeMonths, const double price, const int volumeMl);
          
    /**
     * @brief Получить тип лекарства.
     * @return Строка "Сироп"
     */
    std::string getType() const override;
    
    /**
     * @brief Получить полную информацию о сиропе.
     * @return Строка с информацией
     */
    std::string getInfo() const override;
};

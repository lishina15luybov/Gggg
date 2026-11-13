#pragma once
#include <string>
#include <map>

/**
 * @brief Базовый абстрактный класс, описывающий лекарственное средство.
 */
class Medicine {
protected:
    std::string name;          ///< Название лекарства
    std::string form;          ///< Форма выпуска (таблетки, сироп и т.д.)
    std::string manufacturer;  ///< Производитель
    std::string annotation;    ///< Краткая аннотация
    std::string disease;       ///< Болезнь, от которой применяется
    int shelfLifeMonths;       ///< Срок годности в месяцах
    double price;              ///< Цена в рублях
    std::map<int, int> sales;  ///< Статистика продаж: ключ - день года (1-365), значение - количество

public:
    /**
     * @brief Конструктор базового класса Medicine.
     * @param name Название
     * @param form Форма выпуска
     * @param manufacturer Изготовитель
     * @param annotation Аннотация
     * @param disease Болезнь
     * @param shelfLifeMonths Срок годности
     * @param price Цена
     */
    Medicine(const std::string& name, const std::string& form,
             const std::string& manufacturer, const std::string& annotation,
             const std::string& disease, const int shelfLifeMonths, const double price);
             
    /// @brief Виртуальный деструктор.
    virtual ~Medicine() = default;

    /**
     * @brief Получить название лекарства.
     * @return Название
     */
    std::string getName() const;
    
    /**
     * @brief Получить болезнь, от которой помогает лекарство.
     * @return Название болезни
     */
    std::string getDisease() const;
    
    /**
     * @brief Получить цену лекарства.
     * @return Цена в рублях
     */
    double getPrice() const;

    /**
     * @brief Добавить информацию о продажах.
     * @param dayOfYear День года (от 1 до 365)
     * @param qty Количество проданных упаковок
     */
    void addSale(const int dayOfYear, const int qty);
    
    /**
     * @brief Получить количество продаж за определенный период.
     * @param period Период: 1 - неделя, 2 - месяц, 3 - год
     * @return Количество проданных упаковок за период
     */
    int getSalesForPeriod(const int period) const; 

    /**
     * @brief Получить строковое представление информации о лекарстве.
     * @return Строка с информацией
     */
    virtual std::string getInfo() const;
    
    /**
     * @brief Получить тип лекарства.
     * @return Строка с названием типа
     */
    virtual std::string getType() const = 0;
};

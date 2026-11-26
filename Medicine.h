#pragma once
#include <string>
#include <map>

/**
 * @brief Базовый класс, описывающий лекарственное средство.
 * @details Содержит информацию о названии, форме выпуска, изготовителе,
 *          аннотации, болезни, сроке годности, цене и статистике продаж.
 */
class Medicine {
protected:
    /** @brief Название лекарства. */
    std::string name;
    /** @brief Форма выпуска (таблетки, сироп и т.д.). */
    std::string form;
    /** @brief Изготовитель. */
    std::string manufacturer;
    /** @brief Аннотация. */
    std::string annotation;
    /** @brief Болезнь, от которой помогает лекарство. */
    std::string disease;
    /** @brief Срок годности (в месяцах). */
    int shelfLifeMonths;
    /** @brief Цена (в рублях). */
    double price;
    /** @brief Продажи: день года -> количество. */
    std::map<int, int> sales;

public:
    /**
     * @brief Конструктор лекарственного средства.
     * @param name Название
     * @param form Форма выпуска
     * @param manufacturer Изготовитель
     * @param annotation Аннотация
     * @param disease Болезнь
     * @param shelfLifeMonths Срок годности (в месяцах)
     * @param price Цена
     */
    Medicine(const std::string& name, const std::string& form,
             const std::string& manufacturer, const std::string& annotation,
             const std::string& disease, const int shelfLifeMonths, const double price);
             
    /** @brief Виртуальный деструктор. */
    virtual ~Medicine() = default;

    /** @brief Получить название лекарства. */
    std::string getName() const;
    /** @brief Получить болезнь, от которой помогает лекарство. */
    std::string getDisease() const;
    /** @brief Получить цену. */
    double getPrice() const;

    /**
     * @brief Добавить информацию о продажах.
     * @param dayOfYear День года (1–365)
     * @param qty Количество проданных упаковок
     */
    void addSale(const int dayOfYear, const int qty);

    /**
     * @brief Получить продажи за период.
     * @param period 1 — неделя, 2 — месяц, 3 — год
     * @return Суммарное количество проданных упаковок
     */
    int getSalesForPeriod(const int period) const; 

    /** @brief Получить информацию о лекарстве в виде строки. */
    virtual std::string getInfo() const;
    /** @brief Получить тип лекарства (виртуальная). */
    virtual std::string getType() const; 
};

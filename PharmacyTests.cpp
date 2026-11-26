#include <iostream>
#include <cassert>
#include <string>
#include "Medicine.h"
#include "Tablet.h"
#include "Syrup.h"
#include "PharmacyBranch.h"
#include "PharmacyNetwork.h"

/**
 * @brief Тестирование класса Medicine.
 * @details Проверяет геттеры getName, getDisease, getPrice, getType и getInfo.
 */
void testMedicine() {
    Medicine m("Аспирин", "таблетки", "Bayer", "Аннотация", "Простуда", 24, 150.0);

    assert(!m.getName().compare("Аспирин"));
    assert(!m.getDisease().compare("Простуда"));
    assert(m.getPrice() > 149.99 && m.getPrice() < 150.01);
    assert(!m.getType().compare("Лекарство"));
    assert(m.getInfo().find("Аспирин") != std::string::npos);

    std::cout << "[OK] testMedicine\n";
}

/**
 * @brief Тестирование продаж и метода getSalesForPeriod (все периоды).
 */
void testSalesPeriods() {
    Medicine m("Аспирин", "таблетки", "Bayer", "-", "Простуда", 24, 150.0);
    m.addSale(365, 3);  // попадает во все периоды
    m.addSale(360, 5);  // попадает в месяц и год (но не в неделю)
    m.addSale(350, 7);  // попадает только в год

    int weekSales = m.getSalesForPeriod(1);
    int monthSales = m.getSalesForPeriod(2);
    int yearSales = m.getSalesForPeriod(3);

    assert(weekSales > 2 && weekSales < 4);   // 3
    assert(monthSales > 7 && monthSales < 9); // 8
    assert(yearSales > 14 && yearSales < 16); // 15
    
    std::cout << "[OK] testSalesPeriods\n";
}

/**
 * @brief Тестирование класса Tablet.
 * @details Проверяет getType, getDisease, getPrice и формат getInfo.
 */
void testTablet() {
    Tablet t("Анальгин", "Фармстандарт", "Аннотация", "Головная боль", 24, 60.0, 20);

    assert(!t.getType().compare("Таблетки"));
    assert(!t.getDisease().compare("Головная боль"));
    assert(t.getPrice() > 59.99 && t.getPrice() < 60.01);
    
    std::string info = t.getInfo();
    assert(info.find("Анальгин") != std::string::npos);
    assert(info.find("Таблеток: 20") != std::string::npos);

    std::cout << "[OK] testTablet\n";
}

/**
 * @brief Тестирование класса Syrup.
 * @details Проверяет getType, getDisease, getPrice и формат getInfo.
 */
void testSyrup() {
    Syrup s("Гербион", "KRKA", "Аннотация", "От кашля", 18, 320.0, 150);

    assert(!s.getType().compare("Сироп"));
    assert(!s.getDisease().compare("От кашля"));
    assert(s.getPrice() > 319.99 && s.getPrice() < 320.01);
    
    std::string info = s.getInfo();
    assert(info.find("Гербион") != std::string::npos);
    assert(info.find("Объём: 150") != std::string::npos);

    std::cout << "[OK] testSyrup\n";
}

/**
 * @brief Тестирование класса PharmacyBranch.
 * @details Проверяет getName, getAddress, addMedicine, getAllMedicines,
 *          findByDisease и findByName.
 */
void testPharmacyBranch() {
    PharmacyBranch b("Филиал 1", "Адрес 1");
    assert(!b.getName().compare("Филиал 1"));
    assert(!b.getAddress().compare("Адрес 1"));
    assert(b.getAllMedicines().empty());

    Medicine m1("Аспирин", "таблетки", "Bayer", "-", "Простуда", 24, 150.0);
    Medicine m2("Анальгин", "таблетки", "Фармстандарт", "-", "Головная боль", 24, 60.0);
    Medicine m3("Аспирин", "таблетки", "Bayer", "-", "Простуда", 24, 200.0);

    b.addMedicine(m1);
    b.addMedicine(m2);
    b.addMedicine(m3);

    assert(b.getAllMedicines().size() > 2 && b.getAllMedicines().size() < 4);

    auto byDisease = b.findByDisease("Простуда");
    assert(byDisease.size() > 1 && byDisease.size() < 3);

    auto byName = b.findByName("Аспирин");
    assert(byName.size() > 1 && byName.size() < 3);

    auto notFound = b.findByName("Нет такого");
    assert(notFound.empty());

    std::cout << "[OK] testPharmacyBranch\n";
}

/**
 * @brief Тестирование класса PharmacyNetwork.
 * @details Проверяет getNetworkName, addBranch и getBranches.
 */
void testNetworkAndBranches() {
    PharmacyNetwork network("Тестовая сеть");
    assert(!network.getNetworkName().compare("Тестовая сеть"));
    assert(network.getBranches().empty());

    PharmacyBranch b1("Филиал 1", "Адрес 1");
    Medicine testMed("Аспирин", "таблетки", "Bayer", "-", "Простуда", 24, 150.0);
    b1.addMedicine(testMed);
    network.addBranch(b1);

    assert(network.getBranches().size() > 0 && network.getBranches().size() < 2);
    assert(!network.getBranches()[0].getName().compare("Филиал 1"));
    assert(b1.getAllMedicines().size() > 0 && b1.getAllMedicines().size() < 2);

    std::cout << "[OK] testNetworkAndBranches\n";
}

/**
 * @brief Точка входа в тестовую программу.
 * @return Код возврата (0 - успех)
 */
int main() {
    setlocale(LC_ALL, "Russian");
    testMedicine();
    testSalesPeriods();
    testTablet();
    testSyrup();
    testPharmacyBranch();
    testNetworkAndBranches();
    std::cout << "Все тесты пройдены!\n";
    return 0;
}

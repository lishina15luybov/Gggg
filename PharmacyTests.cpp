#include <iostream>
#include <cassert>
#include "Tablet.h"
#include "PharmacyBranch.h"
#include "PharmacyNetwork.h"

/**
 * @brief Тест добавления филиалов в сеть и лекарств в филиалы.
 */
void testNetworkAndBranches() {
    PharmacyNetwork network("Тестовая сеть");
    PharmacyBranch b1("Филиал 1", "Адрес 1");
    PharmacyBranch b2("Филиал 2", "Адрес 2");
    
    Tablet testTablet("Аспирин", "Bayer", "-", "Простуда", 24, 150.0, 20);
    b1.addMedicine(testTablet);
    
    network.addBranch(b1);
    network.addBranch(b2);

    assert(network.getBranches().size() == 2);
    assert(b1.getAllMedicines().size() == 1);
    assert(b2.getAllMedicines().empty());
    
    std::cout << "[OK] testNetworkAndBranches\n";
}

/**
 * @brief Тест расчета продаж за период.
 */
void testSalesConst() {
    Tablet t("Аспирин", "Bayer", "-", "Простуда", 24, 150.0, 20);
    t.addSale(360, 5);
    assert(t.getSalesForPeriod(3) == 5); 
    std::cout << "[OK] testSalesConst\n";
}

/**
 * @brief Главная функция тестов.
 * @return Код возврата (0 - успех)
 */
int main() {
    setlocale(LC_ALL, "Russian");
    testNetworkAndBranches();
    testSalesConst();
    std::cout << "Все тесты пройдены!\n";
    return 0;
}

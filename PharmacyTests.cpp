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
    PharmacyBranch* b1 = new PharmacyBranch("Филиал 1", "Адрес 1");
    PharmacyBranch* b2 = new PharmacyBranch("Филиал 2", "Адрес 2");
    
    b1->addMedicine(new Tablet("Аспирин", "Bayer", "-", "Простуда", 24, 150.0, 20));
    
    network.addBranch(b1);
    network.addBranch(b2);

    assert(network.getBranches().size() == 2);
    assert(b1->getAllMedicines().size() == 1);
    assert(b2->getAllMedicines().empty());
    
    std::cout << "[OK] testNetworkAndBranches\n";
}

/**
 * @brief Тест расчета продаж за период.
 */
void testSalesConst() {
    Tablet* t = new Tablet("Аспирин", "Bayer", "-", "Простуда", 24, 150.0, 20);
    t->addSale(360, 5);
    assert(t->getSalesForPeriod(3) == 5); 
    delete t;
    std::cout << "[OK] testSalesConst\n";
}

/**
 * @brief Главная функция тестов.
 */
int main() {
    setlocale(LC_ALL, "Russian");
    testNetworkAndBranches();
    testSalesConst();
    std::cout << "Все тесты пройдены!\n";
    return 0;
}

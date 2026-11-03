#include <iostream>
#include <cassert>
#include <memory>
#include "Tablet.h"
#include "PharmacyBranch.h"
#include "PharmacyNetwork.h"

void testNetworkAndBranches() {
    PharmacyNetwork network("Тестовая сеть");
    auto b1 = std::make_shared<PharmacyBranch>("Филиал 1", "Адрес 1");
    auto b2 = std::make_shared<PharmacyBranch>("Филиал 2", "Адрес 2");
    
    b1->addMedicine(std::make_shared<Tablet>("Аспирин", "Bayer", "-", "Простуда", 24, 150.0, 20));
    network.addBranch(b1);
    network.addBranch(b2);

    assert(network.getBranches().size() == 2);
    assert(b1->getAllMedicines().size() == 1);
    assert(b2->getAllMedicines().empty());
    
    std::cout << "[OK] testNetworkAndBranches\n";
}

void testSalesConst() {
    auto t = std::make_shared<Tablet>("Аспирин", "Bayer", "-", "Простуда", 24, 150.0, 20);
    t->addSale(360, 5);
    assert(t->getSalesForPeriod(3) == 5); 
    std::cout << "[OK] testSalesConst\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    testNetworkAndBranches();
    testSalesConst();
    std::cout << "Все тесты пройдены!\n";
    return 0;
}

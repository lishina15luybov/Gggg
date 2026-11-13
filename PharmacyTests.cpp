#include <iostream>
#include <cassert>
#include "Medicine.h"
#include "PharmacyBranch.h"
#include "PharmacyNetwork.h"

void testNetworkAndBranches() {
    PharmacyNetwork network("Тестовая сеть");
    PharmacyBranch b1("Филиал 1", "Адрес 1");
    
    Medicine testMed("Аспирин", "таблетки", "Bayer", "-", "Простуда", 24, 150.0);
    b1.addMedicine(testMed);
    
    network.addBranch(b1);

    assert(network.getBranches().size() == 1);
    assert(b1.getAllMedicines().size() == 1);
    
    std::cout << "[OK] testNetworkAndBranches\n";
}

void testSalesConst() {
    Medicine t("Аспирин", "таблетки", "Bayer", "-", "Простуда", 24, 150.0);
    t.addSale(360, 5);
    assert(t.getSalesForPeriod(3) == 5); 
    std::cout << "[OK] testSalesConst\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    testNetworkAndBranches();
    testSalesConst();
    std::cout << "Все тесты пройдены!\n";
    return 0;
}

#include <iostream>
#include "Tablet.h"
#include "Syrup.h"
#include "PharmacyBranch.h"
#include "PharmacyNetwork.h"

/**
 * @brief Точка входа в демонстрационную программу.
 */
int main() {
    setlocale(LC_ALL, "Russian");

 
    PharmacyNetwork* network = new PharmacyNetwork("Сеть аптек 'Здоровье+'");

    
    PharmacyBranch* branch1 = new PharmacyBranch("Аптека №1 (Центр)", "ул. Ленина, 10");
    PharmacyBranch* branch2 = new PharmacyBranch("Аптека №2 (Спальный район)", "ул. Мира, 5");

 
    branch1->addMedicine(new Tablet("Аспирин", "Bayer", "Жаропонижающее", "Простуда", 24, 150.0, 20));
    
    branch2->addMedicine(new Syrup("Гербион", "KRKA", "От кашля", "Простуда", 18, 320.0, 150));
    branch2->addMedicine(new Tablet("Анальгин", "Фармстандарт", "Обезболивающее", "Головная боль", 24, 60.0, 10));

   
    branch1->getAllMedicines()[0]->addSale(360, 50);


    network->addBranch(branch1);
    network->addBranch(branch2);


    std::cout << "=== Сеть аптек: " << network->getNetworkName() << " ===\n";
    

    for (auto branch : network->getBranches()) {
        std::cout << "\n[Филиал]: " << branch->getName() << " (" << branch->getAddress() << ")\n";
        
        for (auto med : branch->getAllMedicines()) {
            std::cout << "  " << med->getInfo() << "\n";
        }
    }

 
    std::cout << "\n=== Лекарства от простуды в Аптеке №2 ===\n";
    for (auto med : branch2->findByDisease("Простуда")) {
        std::cout << "  " << med->getInfo() << "\n";
    }


    std::cout << "\n=== Продажи Аспирина за год (Аптека №1) ===\n";
    std::cout << "  Продано: " << branch1->getAllMedicines()[0]->getSalesForPeriod(3) << " шт.\n";


    delete network; 

    return 0;
}

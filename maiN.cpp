#include <iostream>
#include "Tablet.h"
#include "Syrup.h"
#include "PharmacyBranch.h"
#include "PharmacyNetwork.h"

/**
 * @brief Точка входа в демонстрационную программу.
 * @return Код возврата (0 - успех)
 */
int main() {
    setlocale(LC_ALL, "Russian");
    Medicine aspirin("Аспирин", "таблетки", "Bayer", "Жаропонижающее", "Простуда", 24, 150.0);
    Medicine herbion("Гербион", "сироп", "KRKA", "От кашля", "Простуда", 18, 320.0);
    Medicine analgin("Анальгин", "таблетки", "Фармстандарт", "Обезболивающее", "Головная боль", 24, 60.0);

    aspirin.addSale(360, 50);

    // Создаем филиалы
    PharmacyBranch branch1("Аптека №1 (Центр)", "ул. Ленина, 10");
    PharmacyBranch branch2("Аптека №2 (Спальный район)", "ул. Мира, 5");

    // Добавляем лекарства
    branch1.addMedicine(aspirin);
    branch2.addMedicine(herbion);
    branch2.addMedicine(analgin);

    // Создаем сеть
    PharmacyNetwork network("Сеть аптек 'Здоровье+'");
    network.addBranch(branch1);
    network.addBranch(branch2);

    // Вывод
    std::cout << "=== Сеть аптек: " << network.getNetworkName() << " ===\n";
    
    for (const auto& branch : network.getBranches()) {
        std::cout << "\n[Филиал]: " << branch.getName() << " (" << branch.getAddress() << ")\n";
        
        for (const auto& med : branch.getAllMedicines()) {
            std::cout << "  " << med.getInfo() << "\n";
        }
    }

    std::cout << "\n=== Лекарства от простуды в Аптеке №2 ===\n";
    for (const auto& med : branch2.findByDisease("Простуда")) {
        std::cout << "  " << med.getInfo() << "\n";
    }

    std::cout << "\n=== Продажи Аспирина за год ===\n";
    std::cout << "  Продано: " << branch1.getAllMedicines()[0].getSalesForPeriod(3) << " шт.\n";

    return 0;
}

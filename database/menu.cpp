#include <iostream>
#include <string>
#include "database.h"

int main()
{
    baza_pojazdow b;
    int w = 0;
    bool wyjdz = false;
    
    while (wyjdz == false)
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Co chcesz zrobic?\n" << "1.Dodaj dane\n" << "2.Odczytaj dane\n" << "3.Opusc program\n";
        std::cin >> w;

        switch (w)
        {
        case 1:
        {
            std::cout << "\033[2J\033[1;1H";
            std::string dane[columns];
            std::cout << "Podaj dane pojazdu\n";
            std::cout << "Marka: \n";
            std::cin >> dane[0];
            std::cout << "Model: \n";
            std::cin >> dane[1];
            std::cout << "Rok produkcji: \n";
            std::cin >> dane[2];
            std::cout << "Numer VIN: \n";
            std::cin >> dane[3];
            std::cout << "Czy wynajete?: \n";
            std::cin >> dane[4];
            b.add_record(dane);
            w = 0;
            break;
        }
        case 2:
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Odczytaj\n";
            b.read_record();
            std::cin.ignore();
            std::cin.get();
            w = 0;
            break;

        case 3:
            b.update_file();
            wyjdz = true;
            break;
        }

    }

    return 0;
}


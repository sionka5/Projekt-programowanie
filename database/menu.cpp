#include <iostream>
#include <string>
#include "database_handler.h"
#include <vector>

int main()
{
    database pojazdy;
    database osoby;
    pojazdy.init(5, "pojazdy");
    osoby.init(5, "osoby");


    int w = 0;
    bool wyjdz = false;
    std::string selected_database = "pojazdy";
    while (wyjdz == false)
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "------------------------------------------------\n";
        std::cout << "Co chcesz zrobic?" << "   wybrana baza: " << selected_database << "\n1.Wybierz baze\n" << "2.Dodaj dane\n" << "3.Odczytaj dane\n" << "4.Opusc program\n";
        std::cout << "------------------------------------------------\n";
        std::cin >> w;

        switch (w)
        {
        case 1:
        {
            int w1;
            std::cout << "\033[2J\033[1;1H";
            std::cout << "------------------------------------------------\n";
            std::cout << "Wybierz baze:\n" << "1.Pojazdy\n" << "2.Osoby\n";
            std::cout << "------------------------------------------------\n";
            std::cin >> w1;
            switch (w1)
            {
            case 1:
                selected_database = "pojazdy";
                break;
            case 2:
                selected_database = "osoby";
                break;
            }
            break;
        }
        case 2:
        {
            std::cout << "\033[2J\033[1;1H";
            std::vector<std::string> data;
            std::string input;
            if (selected_database == "pojazdy")
            {   
                std::cout << "------------------------------------------------\n";
                std::cout << "Podaj dane pojazdu\n";
                std::cout << "Marka: ";
                std::cin >> input; data.push_back(input);
                std::cout << "Model: ";
                std::cin >> input; data.push_back(input);
                std::cout << "Rok produkcji: ";
                std::cin >> input; data.push_back(input);
                std::cout << "Numer VIN: ";
                std::cin >> input; data.push_back(input);
                std::cout << "Czy wynajete? (Y/N): ";
                std::cin >> input; data.push_back(input);
                std::cout << "------------------------------------------------\n";
                pojazdy.add_record(data);
                pojazdy.save_to_file();
            }
            else if (selected_database == "osoby")
            {
                std::cout << "------------------------------------------------\n";
                std::cout << "Podaj dane osoby\n";
                std::cout << "Imie: ";
                std::cin >> input; data.push_back(input);
                std::cout << "Nazwisko: ";
                std::cin >> input; data.push_back(input);
                std::cout << "Plec (M/K): ";
                std::cin >> input; data.push_back(input);
                std::cout << "Wiek: ";
                std::cin >> input; data.push_back(input);
                std::cout << "Czy wynajmuje? (Y/N): ";
                std::cin >> input; data.push_back(input);
                std::cout << "------------------------------------------------\n";
                osoby.add_record(data);
                osoby.save_to_file();
            }
            
            break;
        }
        case 3:
            std::cout << "\033[2J\033[1;1H";
            std::cout << "------------------------------------------------\n";
            if (selected_database == "pojazdy")
            {
                pojazdy.read_record();
            }
            else if (selected_database == "osoby")
            {
                osoby.read_record();
            }
            std::cout << "------------------------------------------------\n";
            std::cin.ignore();
            std::cin.get();
            w = 0;
            break;

        case 4:
            wyjdz = true;
            break;
        }

    }

    return 0;
}
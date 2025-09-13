#include <iostream>
#include <ctime>
#include <cstdint>

// ----------------- TEXT IN PROGRAM -----------------
void first_text(int text_min, int text_max, const int& global_attempt);
void text_hidden_number(const int& _global_attempt);
void text_lose_win();
void goodbye_text();
void dog();
// ----------------- END TEXT IN PROGRAM -----------------
// ----------------- RANDOM -----------------
// Change RAND FUNC.
int choiseRandom(int _min, int _max) {
    uint64_t srand(time(NULL));
    int Random_numberGuessing = (_min + rand() % (_max - _min + 1));
    return Random_numberGuessing;
}
// ----------------- END RANDOM -----------------
// ----------------- CHECK SIZE STRING -----------------
// Why args so strange? non const string and & to int and const
// Why this func is string type?
std::string string_number_size(std::string& size_number, const int& size_min, const int& size_max) {
    while (size_number.size() > 1) {
        std::cout << "Не корректное значение!!!!" << "\n";
        std::cout << "Выбери число в диапазоне от " << size_min << " до " << size_max << "\n";
        std::cout << "\n";
        std::cout << "Твой выбор : ";
        std::cin >> size_number;
    }
    return size_number;
}
// ----------------- END CHECK SIZE STRING -----------------    
// ----------------- CHECK NUMBER STRING-----------------
// Why args so strange? non const string and & to int and const
// Why this func is string type?
std::string good_min_max(std::string& s_number, const int& min, const int& max) {
    int i_number = (s_number[0] - 48);
    while (((i_number < min) || (i_number > max)) && (s_number.size() == 1)) {
        if (i_number == 65 || i_number == 33) {
            goodbye_text();
            // BAD PRACTICE!!
            exit(0);
        }
        std::cout << "Не корректное значение!!!!" << "\n";
        std::cout << "Выбери число в диапазоне от " << min << " до " << max << "\n";
        std::cout << "\n";
        std::cout << "Твой выбор : ";
        std::cin >> s_number;
        if (s_number.size() > 1) {
            string_number_size(s_number, min, max);
        }
        i_number = (s_number[0] - 48);
    }
    return s_number;
}
// ----------------- END CHEK NUMBER STRING -----------------


int main() {
    setlocale(0, "");
    std::string string_number = "0";   //WHY?
    int min = 1;
    int max = 6;
    int global_attempt = 3;
    int attempt = global_attempt;
    int numberGuessing = choiseRandom(min, max);
    first_text(min, max, global_attempt);
    while (true) {
        if (attempt == global_attempt) {
            text_hidden_number(global_attempt);
        }
        std::cout << "\n";
        std::cout << "Твой выбор : ";
        std::cin >> string_number;
        if (string_number.size() > 1) {
            string_number_size(string_number, min, max);
        }
        good_min_max(string_number, min, max);
        int i_string_number = (string_number[0] - 48);
        //BAD LOGIC STATEMENT
        if ((attempt == 1) && (i_string_number != numberGuessing)) {
            //in loose and win i see the same actions with only 1 string difference is possible to do one func?
            system("cls");  // clearing cmd windows
            std::cout << "\n";
            std::cout << "------------------------------------" << "\n";
            std::cout << "|           Ты проиграл =(         |" << "\n";
            std::cout << "------------------------------------" << "\n";
            dog();
            attempt = global_attempt;
            numberGuessing = choiseRandom(min, max);
            text_lose_win();
        }
        else if (i_string_number > numberGuessing) {
            std::cout << "Загаданное число меньше" << "\n";
            --attempt;
        }
        else if (i_string_number < numberGuessing) {
            std::cout << "Загаданное число больше" << "\n";
            --attempt;
        }
        else {
            system("cls"); // clearing cmd windows
            std::cout << "\n";
            std::cout << "------------------------------------" << "\n";
            std::cout << "|           Ты выиграл =)          |" << "\n";
            std::cout << "------------------------------------" << "\n";
            attempt = global_attempt;
            numberGuessing = choiseRandom(min, max);
            text_lose_win();
        }
    }
}

// ----------------- TEXT IN PROGRAM ----------------- 

void first_text(int text_min, int text_max, const int& global_attempt) {
    std::cout << "\n";
    std::cout << "------------------------------------" << "\n";
    std::cout << "|         Сыграем в игру?          |" << "\n";
    std::cout << "------------------------------------" << "\n";
    std::cout << "|    Я загадал число от " << text_min << " до " << text_max << "     |" << "\n";
    std::cout << "|      попробуй его отгадать       |" << "\n";
    std::cout << "|         У тебя " << global_attempt << " попытки         | " << "\n";
    std::cout << "------------------------------------" << "\n";
    std::cout << "|    Для выхода из игры введи 'q'  |" << "\n";
    std::cout << "------------------------------------" << "\n";
    std::cout << "|           Введи число            |" << "\n";
    std::cout << "------------------------------------" << "\n";
}

void text_hidden_number(const int& _global_attempt) {
    std::cout << "\n";
    std::cout << "------------------------------------" << "\n";
    std::cout << "|       Новое число загадано       |" << "\n";
    std::cout << "|         У тебя " << _global_attempt << " попытки         | " << "\n";
    std::cout << "------------------------------------" << "\n";
}

void text_lose_win() {
    std::cout << "\n";
    std::cout << "------------------------------------" << "\n";
    std::cout << "|           Сыграем ещё?           |" << "\n";
    std::cout << "------------------------------------" << "\n";
    std::cout << "|    Для продолжения введи число   |" << "\n";
    std::cout << "|    Для выхода из игры введи 'q'  |" << "\n";
    std::cout << "------------------------------------" << "\n";
}

void goodbye_text() {
    std::cout << "------------------------------------" << "\n";
    std::cout << "| Ты решил выйти из игры выбрав 'q'|" << "\n";
    std::cout << "|         Спасибо за игру          |" << "\n";
    std::cout << "|            Заходи ещё            |" << "\n";
    std::cout << "------------------------------------" << "\n";
}

void dog() {
    std::cout << "\n";
    std::cout << "  =====+@@@@===========@@@@===@===" << "\n";
    std::cout << "  ====@@@@@@@@+++++++@@@@@@@@@@===" << "\n";
    std::cout << "  ===@@@@===@+@..++.@+@===@@@@+===" << "\n";
    std::cout << "  ===@@@@===+@@.++ @.@+===========" << "\n";
    std::cout << "  ====@@====+@  .++  @+===========" << "\n";
    std::cout << "  =====@===...+ @@@@@+..==========" << "\n";
    std::cout << "  ========.@  @ .@@.@. @.=========" << "\n";
    std::cout << "  ======++.    @   @.    +++======" << "\n";
    std::cout << "  =====+++ .@    @ .. ..@++++=====" << "\n";
    std::cout << "  ====+++@+@   @  .++@++@@++++====" << "\n";
    std::cout << "  ====#+++@+++.   .@++++@++++++===" << "\n";
    std::cout << "  ====#++++++@@@@@+++++++++@+++===" << "\n";
    std::cout << "  =====*+++++++++#++##+++++++++===" << "\n";
    std::cout << "  =====++++++++++@+++++#+++++#====" << "\n";
    std::cout << "  ========###+@+++#+++++#=###=====" << "\n";
    std::cout << "  ========#++###@+++++++#=========" << "\n";
    std::cout << "  ========#+++++++++++++#=========" << "\n";
    std::cout << "\n";
}


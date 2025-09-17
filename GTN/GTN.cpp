#include <iostream>
#include <ctime>
#include <cstdint>
#include <string>
#include <random>

// ----------------- TEXT IN PROGRAM -----------------
void first_text(int ft_min, int ft_max, int ft_global_attempt);
void text_hidden_number(int thn_global_attempt);
void text_uncorected_number(int tun_min, int tun_max);
void text_lose_win(std::string text_s_lose_win);
void goodbye_text();
// ----------------- END TEXT IN PROGRAM -----------------
// ----------------- RANDOM -----------------
int choiseRandom(int _min, int _max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <> distr(_min, _max);
    int Random_numberGuessing = distr(gen);
    return Random_numberGuessing;
}
// ----------------- END RANDOM -----------------
// ----------------- CHECK (INT) NUMBER -----------------
int good_min_max(const int& i_number, int min, int max) {
    if (i_number < min || i_number > max) {
        return 1;
    }
    return 0;
}
// ----------------- END CHEK (INT) NUMBER -----------------

int main() {
    setlocale(0, "");
    std::string string_number = "0";
    int min = 1;
    int max = 6;
    int global_attempt = 3;
    int i_number = 0;
    int ptr = 0;
    int numberGuessing = 0;
    int attempt = global_attempt;
    std::string text_s_lose_win = "0";
    first_text(min, max, global_attempt);
    while (true) {
        if (attempt == global_attempt && ptr == 0) {
            text_hidden_number(global_attempt);
            ++ptr;
            numberGuessing = choiseRandom(min, max);
        }
        std::cout << "\n";
        std::cout << "Твой выбор : ";
        getline(std::cin, string_number);
        // ----------------- CHECK STRIGN SIZE -----------------
        if ((string_number.size()) != 1) {
            text_uncorected_number(min, max);
            continue;
        }
        // ----------------- CHECK QUIT -----------------
        if ((string_number[0] == 'q') || (string_number[0] == 'Q')) {
            goodbye_text();
            exit(0);
        }
        // ----------------- CHECK (INT) NUMBER -----------------
        i_number = (string_number[0] - 48); 
        if (good_min_max(i_number, min, max) == 1) {
            text_uncorected_number(min, max);
            continue;
        }
        if (attempt == 1) {
            text_s_lose_win = "Ты проиграл =(";
            text_lose_win(text_s_lose_win);
            attempt = global_attempt;
            ptr = 0;
        }else if (i_number == numberGuessing) {
            text_s_lose_win = " Ты выиграл =)";
            attempt = global_attempt;
            text_lose_win(text_s_lose_win);
            ptr = 0;
        }else if (i_number > numberGuessing) {
            std::cout << "Загаданное число меньше" << "\n";
            --attempt;
        }else if (i_number < numberGuessing) {
            std::cout << "Загаданное число больше" << "\n";
            --attempt;
        }
    }
}


// ----------------- TEXT IN PROGRAM -----------------
void first_text(int ft_min, int ft_max, int ft_global_attempt) {
    std::cout << "\n";
    std::cout << "--------------------------------------" << "\n";
    std::cout << "|          Сыграем в игру?           |" << "\n";
    std::cout << "--------------------------------------" << "\n";
    std::cout << "|     Я загадал число от " << ft_min << " до " << ft_max << "      |" << "\n";
    std::cout << "|       попробуй его отгадать        |" << "\n";
    std::cout << "|          У тебя " << ft_global_attempt << " попытки          | " << "\n";
    std::cout << "--------------------------------------" << "\n";
    std::cout << "|Для выхода из игры введи 'q' или 'Q'|" << "\n";
    std::cout << "--------------------------------------" << "\n";
    std::cout << "|             Введи число            |" << "\n";
    std::cout << "--------------------------------------" << "\n";
}

void text_hidden_number(int thn_global_attempt) {
    std::cout << "\n";
    std::cout << "--------------------------------------" << "\n";
    std::cout << "|        Новое число загадано        |" << "\n";
    std::cout << "|          У тебя " << thn_global_attempt << " попытки          | " << "\n";
    std::cout << "--------------------------------------" << "\n";
}

void text_uncorected_number(int tun_min, int tun_max) {
    std::cout << "Не корректное значение!!!!" << "\n";
    std::cout << "Выбери число в диапазоне от " << tun_min << " до " << tun_max << "\n";
}

void text_lose_win(std::string text_s_lose_win) {
    system("cls"); // clearing cmd windows
    std::cout << "------------------------------------" << "\n";
    std::cout << "|           " << text_s_lose_win << "          |" << "\n";
    std::cout << "------------------------------------" << "\n";
    std::cout << "\n";
    std::cout << "--------------------------------------" << "\n";
    std::cout << "|            Сыграем ещё?            |" << "\n";
    std::cout << "--------------------------------------" << "\n";
    std::cout << "|     Для продолжения введи число    |" << "\n";
    std::cout << "|Для выхода из игры введи 'q' или 'Q'|" << "\n";
    std::cout << "--------------------------------------" << "\n";
}

void goodbye_text() {
    std::cout << "--------------------------------------" << "\n";
    std::cout << "|  Ты решил выйти из игры выбрав 'q' |" << "\n";
    std::cout << "|          Спасибо за игру           |" << "\n";
    std::cout << "|             Заходи ещё             |" << "\n";
    std::cout << "--------------------------------------" << "\n";
}

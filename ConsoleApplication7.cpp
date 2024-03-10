#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

int main() {
    std::deque<int> player1, player2;

    // Ввод карт первого игрока
    for (int i = 0; i < 5; ++i) {
        int card;
        std::cin >> card;
        player1.push_front(card);
    }

    // Ввод карт второго игрока
    for (int i = 0; i < 5; ++i) {
        int card;
        std::cin >> card;
        player2.push_front(card);
    }

    int moves = 0;
    while (!player1.empty() && !player2.empty() && moves < 1000000) {
        int card1 = player1.back();
        int card2 = player2.back();

        // Сравниваем карты
        if (card1 == 0 && card2 == 9) {
            player1.push_front(card1);
            player1.push_front(card2);
        }
        else if (card1 == 9 && card2 == 0) {
            player2.push_front(card1);
            player2.push_front(card2);
        }
        else if (card1 > card2) {
            player1.push_front(card1);
            player1.push_front(card2);
        }
        else {
            player2.push_front(card1);
            player2.push_front(card2);
        }

        // Удаляем использованные карты
        player1.pop_back();
        player2.pop_back();

        moves++;
    }

    if (moves == 1000000) {
        std::cout << "botva" << std::endl;
    }
    else if (player1.empty()) {
        std::cout << "second " << moves << std::endl;
    }
    else {
        std::cout << "first " << moves << std::endl;
    }

    return 0;
}

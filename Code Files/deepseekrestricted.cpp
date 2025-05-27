//#include <iostream>
//#include <vector>
//#include <array>
//#include <algorithm>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//using namespace std;
//
//const int GRID_SIZE = 5;
//const int INITIAL_HEALTH = 5;
//
//struct Bot {
//    int x, y;
//    int health;
//    char symbol;
//    string name;
//};
//
//void printGrid(const vector<Bot>& bots) {
//    for (int y = 0; y < GRID_SIZE; ++y) {
//        for (int x = 0; x < GRID_SIZE; ++x) {
//            char cell = '.';
//            int count = 0;
//            for (const auto& bot : bots) {
//                if (bot.x == x && bot.y == y) {
//                    count++;
//                    cell = count > 1 ? '*' : bot.symbol;
//                }
//            }
//            cout << cell << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}
//
//void moveBot(Bot& bot) {
//    int dir = rand() % 4;
//    switch (dir) {
//    case 0: bot.x = max(0, bot.x - 1); break;
//    case 1: bot.x = min(GRID_SIZE - 1, bot.x + 1); break;
//    case 2: bot.y = max(0, bot.y - 1); break;
//    case 3: bot.y = min(GRID_SIZE - 1, bot.y + 1); break;
//    }
//}
//
//void processAttacks(vector<Bot>& bots) {
//    array<array<int, GRID_SIZE>, GRID_SIZE> cellCounts{};
//    for (const auto& bot : bots)
//        cellCounts[bot.x][bot.y]++;
//
//    for (auto& bot : bots)
//        bot.health -= cellCounts[bot.x][bot.y] - 1;
//}
//
//int main() {
//    srand(time(0));
//    vector<Bot> bots;
//
//    for (int i = 0; i < 3; ++i) {
//        int x, y;
//        do {
//            x = rand() % GRID_SIZE;
//            y = rand() % GRID_SIZE;
//        } while ([&]() {
//            for (const auto& b : bots)
//                if (b.x == x && b.y == y) return true;
//            return false;
//            }());
//        bots.push_back({ x, y, INITIAL_HEALTH, (char)('A' + i), "Bot" + string(1, 'A' + i) });
//    }
//
//    while (true) {
//        printGrid(bots);
//
//        if (bots.size() == 1) {
//            cout << bots[0].name << " wins!\n";
//            break;
//        }
//        else if (bots.empty()) {
//            cout << "All bots destroyed!\n";
//            break;
//        }
//
//        for (auto& bot : bots) moveBot(bot);
//        processAttacks(bots);
//
//        bots.erase(remove_if(bots.begin(), bots.end(),
//            [](const Bot& b) { return b.health <= 0; }), bots.end());
//
//        cout << "Press Enter to continue...";
//        cin.ignore();
//        cin.get();
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <vector>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//
//const int GRID_SIZE = 5;
//const int BOT_COUNT = 3;
//const int MAX_HEALTH = 10;
//
//struct Bot {
//    string name;
//    int x, y;
//    int health;
//    bool alive;
//};
//
//void initBots(array<Bot, BOT_COUNT>& bots) {
//    array<string, BOT_COUNT> names = { "Alpha", "Bravo", "Charlie" };
//    for (int i = 0; i < BOT_COUNT; ++i) {
//        bots[i] = { names[i], rand() % GRID_SIZE, rand() % GRID_SIZE, MAX_HEALTH, true };
//    }
//}
//
//void moveBot(Bot& bot) {
//    int dir = rand() % 4;
//    if (dir == 0 && bot.x > 0) bot.x--;
//    else if (dir == 1 && bot.x < GRID_SIZE - 1) bot.x++;
//    else if (dir == 2 && bot.y > 0) bot.y--;
//    else if (dir == 3 && bot.y < GRID_SIZE - 1) bot.y++;
//}
//
//void attack(Bot& attacker, Bot& target) {
//    if (attacker.alive && target.alive && attacker.x == target.x && attacker.y == target.y && &attacker != &target) {
//        target.health -= 3;
//        cout << attacker.name << " attacks " << target.name << "!" << endl;
//        if (target.health <= 0) {
//            target.alive = false;
//            cout << target.name << " has been destroyed!" << endl;
//        }
//    }
//}
//
//void printGrid(const array<Bot, BOT_COUNT>& bots) {
//    for (int y = 0; y < GRID_SIZE; ++y) {
//        for (int x = 0; x < GRID_SIZE; ++x) {
//            bool found = false;
//            for (const auto& bot : bots)
//                if (bot.alive && bot.x == x && bot.y == y) {
//                    cout << bot.name[0] << ' ';
//                    found = true;
//                    break;
//                }
//            if (!found) cout << ". ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//bool gameOver(const array<Bot, BOT_COUNT>& bots) {
//    int aliveCount = 0;
//    for (const auto& bot : bots)
//        if (bot.alive) ++aliveCount;
//    return aliveCount <= 1;
//}
//
//void declareWinner(const array<Bot, BOT_COUNT>& bots) {
//    for (const auto& bot : bots)
//        if (bot.alive)
//            cout << bot.name << " wins the battle!" << endl;
//}
//
//int main() {
//    srand(static_cast<unsigned>(time(0)));
//    array<Bot, BOT_COUNT> bots;
//    initBots(bots);
//    while (!gameOver(bots)) {
//        for (auto& bot : bots)
//            if (bot.alive) moveBot(bot);
//        for (auto& attacker : bots)
//            for (auto& target : bots)
//                attack(attacker, target);
//        printGrid(bots);
//        cin.get(); // Pause after each round
//    }
//    declareWinner(bots);
//    return 0;
//}

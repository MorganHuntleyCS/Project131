//#include <iostream>
//#include <vector>
//#include <array>
//#include <cstdlib>
//#include <ctime>
//
//struct Bot {
//    const char* name;
//    int health;
//    int x, y;
//};
//
//const int GRID_SIZE = 5;
//const int MAX_HEALTH = 10;
//
//void initializeBots(std::vector<Bot>& bots) {
//    bots = { {"BotA", MAX_HEALTH, 0, 0}, {"BotB", MAX_HEALTH, 4, 4}, {"BotC", MAX_HEALTH, 2, 2} };
//}
//
//void moveBot(Bot& bot) {
//    int dx = (rand() % 3) - 1;
//    int dy = (rand() % 3) - 1;
//    bot.x = std::max(0, std::min(GRID_SIZE - 1, bot.x + dx));
//    bot.y = std::max(0, std::min(GRID_SIZE - 1, bot.y + dy));
//}
//
//void attack(std::vector<Bot>& bots) {
//    for (auto& bot : bots) {
//        for (auto& target : bots) {
//            if (&bot != &target && bot.x == target.x && bot.y == target.y) {
//                target.health -= (rand() % 3) + 1; // Random attack damage
//            }
//        }
//    }
//}
//
//void display(const std::vector<Bot>& bots) {
//    std::cout << "Grid Status:\n";
//    for (const auto& bot : bots) {
//        std::cout << bot.name << " at (" << bot.x << ", " << bot.y << ") HP: " << bot.health << "\n";
//    }
//}
//
//int countAlive(const std::vector<Bot>& bots) {
//    int alive = 0;
//    for (const auto& bot : bots) alive += (bot.health > 0);
//    return alive;
//}
//
//int main() {
//    srand(time(0));
//    std::vector<Bot> bots;
//    initializeBots(bots);
//
//    while (countAlive(bots) > 1) {
//        for (auto& bot : bots) if (bot.health > 0) moveBot(bot);
//        attack(bots);
//        display(bots);
//        std::cout << "====================\n";
//    }
//
//    for (const auto& bot : bots) if (bot.health > 0) std::cout << bot.name << " wins!\n";
//}

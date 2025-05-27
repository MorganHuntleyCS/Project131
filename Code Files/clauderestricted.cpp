//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//
//const int GRID_SIZE = 5;
//const int MAX_BOTS = 3;
//const int INITIAL_HEALTH = 100;
//
//struct Bot {
//    std::string name;
//    int x, y;
//    int health;
//    bool alive;
//};
//
//void initializeBots(std::vector<Bot>& bots) {
//    bots[0] = { "Alpha", 0, 0, INITIAL_HEALTH, true };
//    bots[1] = { "Bravo", 4, 4, INITIAL_HEALTH, true };
//    bots[2] = { "Charlie", 2, 2, INITIAL_HEALTH, true };
//}
//
//void printGrid(const std::vector<Bot>& bots) {
//    char grid[GRID_SIZE][GRID_SIZE];
//
//    // Initialize empty grid
//    for (int i = 0; i < GRID_SIZE; i++) {
//        for (int j = 0; j < GRID_SIZE; j++) {
//            grid[i][j] = '.';
//        }
//    }
//
//    // Place alive bots on grid
//    for (int i = 0; i < MAX_BOTS; i++) {
//        if (bots[i].alive) {
//            grid[bots[i].y][bots[i].x] = bots[i].name[0];
//        }
//    }
//
//    // Print grid
//    std::cout << "\n--- BotAttack Arena ---\n";
//    for (int i = 0; i < GRID_SIZE; i++) {
//        for (int j = 0; j < GRID_SIZE; j++) {
//            std::cout << grid[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//}
//
//void moveBot(Bot& bot) {
//    if (!bot.alive) return;
//
//    int direction = rand() % 4;
//    int newX = bot.x, newY = bot.y;
//
//    switch (direction) {
//    case 0: newY = (newY > 0) ? newY - 1 : newY; break;           // Up
//    case 1: newY = (newY < GRID_SIZE - 1) ? newY + 1 : newY; break; // Down
//    case 2: newX = (newX > 0) ? newX - 1 : newX; break;           // Left
//    case 3: newX = (newX < GRID_SIZE - 1) ? newX + 1 : newX; break; // Right
//    }
//
//    bot.x = newX;
//    bot.y = newY;
//}
//
//void combatCheck(std::vector<Bot>& bots) {
//    for (int i = 0; i < MAX_BOTS; i++) {
//        if (!bots[i].alive) continue;
//
//        for (int j = i + 1; j < MAX_BOTS; j++) {
//            if (!bots[j].alive) continue;
//
//            // Check if bots are adjacent or on same position
//            int dx = abs(bots[i].x - bots[j].x);
//            int dy = abs(bots[i].y - bots[j].y);
//
//            if ((dx <= 1 && dy <= 1) && (dx + dy > 0)) {
//                // Combat! Both bots take damage
//                int damage = 20 + rand() % 31; // 20-50 damage
//                bots[i].health -= damage;
//                bots[j].health -= damage;
//
//                std::cout << bots[i].name << " and " << bots[j].name
//                    << " fight! Both take " << damage << " damage.\n";
//
//                // Check if bots die
//                if (bots[i].health <= 0) {
//                    bots[i].alive = false;
//                    std::cout << bots[i].name << " is destroyed!\n";
//                }
//                if (bots[j].health <= 0) {
//                    bots[j].alive = false;
//                    std::cout << bots[j].name << " is destroyed!\n";
//                }
//            }
//        }
//    }
//}
//
//void printStatus(const std::vector<Bot>& bots) {
//    std::cout << "Bot Status:\n";
//    for (int i = 0; i < MAX_BOTS; i++) {
//        if (bots[i].alive) {
//            std::cout << bots[i].name << ": Health=" << bots[i].health
//                << " Position=(" << bots[i].x << "," << bots[i].y << ")\n";
//        }
//    }
//    std::cout << std::endl;
//}
//
//int getAliveCount(const std::vector<Bot>& bots) {
//    int count = 0;
//    for (int i = 0; i < MAX_BOTS; i++) {
//        if (bots[i].alive) count++;
//    }
//    return count;
//}
//
//std::string getWinner(const std::vector<Bot>& bots) {
//    for (int i = 0; i < MAX_BOTS; i++) {
//        if (bots[i].alive) return bots[i].name;
//    }
//    return "No one";
//}
//
//int main() {
//    srand(time(nullptr));
//    std::vector<Bot> bots(MAX_BOTS);
//    initializeBots(bots);
//
//    std::cout << "=== BotAttack Game Started! ===\n";
//    std::cout << "3 robots enter the arena. Only one will survive!\n";
//
//    int round = 1;
//    while (getAliveCount(bots) > 1) {
//        std::cout << "\n--- Round " << round++ << " ---\n";
//
//        // Move all alive bots
//        for (int i = 0; i < MAX_BOTS; i++) {
//            moveBot(bots[i]);
//        }
//
//        // Check for combat
//        combatCheck(bots);
//
//        // Display current state
//        printGrid(bots);
//        printStatus(bots);
//
//        // Pause for dramatic effect
//        std::cout << "Press Enter to continue...";
//        std::cin.get();
//    }
//
//    std::cout << "\n=== GAME OVER ===\n";
//    std::cout << "Winner: " << getWinner(bots) << "!\n";
//
//    return 0;
//}
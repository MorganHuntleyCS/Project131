//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstdlib> // For rand() and srand()
//#include <ctime>   // For time()
//
//// Constants
//const int GRID_SIZE = 5;
//const int NUM_BOTS = 3;
//const int INITIAL_HEALTH = 100;
//const int ATTACK_DAMAGE = 10;
//const int MOVE_RANGE = 1; // Bots can move 1 step in any direction
//
//// Struct to represent a bot
//struct Bot {
//    std::string name;
//    int health;
//    int x; // X-coordinate on the grid
//    int y; // Y-coordinate on the grid
//    bool isAlive;
//};
//
//// Function prototypes
//void initializeBots(std::vector<Bot>& bots);
//void printGrid(const std::vector<Bot>& bots);
//void moveBot(Bot& bot);
//void attackBot(Bot& attacker, Bot& target);
//bool isGameOver(const std::vector<Bot>& bots);
//int getAliveBotCount(const std::vector<Bot>& bots);
//int getRandomNumber(int min, int max);
//
//int main() {
//    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
//
//    std::vector<Bot> bots(NUM_BOTS);
//    initializeBots(bots);
//
//    std::cout << "--- BotAttack Game Start ---" << std::endl;
//
//    while (!isGameOver(bots)) {
//        printGrid(bots);
//
//        for (int i = 0; i < NUM_BOTS; ++i) {
//            if (bots[i].isAlive) {
//                // Move phase
//                std::cout << bots[i].name << " (Health: " << bots[i].health << ") is at (" << bots[i].x << ", " << bots[i].y << ")." << std::endl;
//                moveBot(bots[i]);
//                std::cout << bots[i].name << " moved to (" << bots[i].x << ", " << bots[i].y << ")." << std::endl;
//
//                // Attack phase
//                for (int j = 0; j < NUM_BOTS; ++j) {
//                    if (i != j && bots[j].isAlive) {
//                        // Simple attack: if bots are on the same spot, they fight
//                        if (bots[i].x == bots[j].x && bots[i].y == bots[j].y) {
//                            attackBot(bots[i], bots[j]);
//                        }
//                    }
//                }
//            }
//        }
//        std::cout << "\n--- End of Round ---\n" << std::endl;
//    }
//
//    std::cout << "--- Game Over ---" << std::endl;
//    printGrid(bots); // Print final state
//    for (const auto& bot : bots) {
//        if (bot.isAlive) {
//            std::cout << bot.name << " wins with " << bot.health << " health remaining!" << std::endl;
//            break;
//        }
//    }
//
//    return 0;
//}
//
//// Function to initialize bots with names, health, and random positions
//void initializeBots(std::vector<Bot>& bots) {
//    std::string botNames[] = { "Alpha", "Beta", "Gamma" };
//    for (int i = 0; i < NUM_BOTS; ++i) {
//        bots[i].name = botNames[i];
//        bots[i].health = INITIAL_HEALTH;
//        bots[i].x = getRandomNumber(0, GRID_SIZE - 1);
//        bots[i].y = getRandomNumber(0, GRID_SIZE - 1);
//        bots[i].isAlive = true;
//    }
//}
//
//// Function to print the current state of the grid
//void printGrid(const std::vector<Bot>& bots) {
//    std::cout << "Current Grid State:" << std::endl;
//    // Using a 2D array to represent the grid for display
//    char gridDisplay[GRID_SIZE][GRID_SIZE];
//    for (int i = 0; i < GRID_SIZE; ++i) {
//        for (int j = 0; j < GRID_SIZE; ++j) {
//            gridDisplay[i][j] = '.'; // Empty spot
//        }
//    }
//
//    for (const auto& bot : bots) {
//        if (bot.isAlive) {
//            gridDisplay[bot.y][bot.x] = bot.name[0]; // Use first letter of bot's name
//        }
//    }
//
//    for (int i = 0; i < GRID_SIZE; ++i) {
//        for (int j = 0; j < GRID_SIZE; ++j) {
//            std::cout << gridDisplay[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//
//    for (const auto& bot : bots) {
//        std::cout << bot.name << ": Health=" << bot.health << " (" << (bot.isAlive ? "Alive" : "Dead") << ")" << std::endl;
//    }
//    std::cout << std::endl;
//}
//
//
//// Function to move a bot randomly within the grid boundaries
//void moveBot(Bot& bot) {
//    int dx = getRandomNumber(-MOVE_RANGE, MOVE_RANGE);
//    int dy = getRandomNumber(-MOVE_RANGE, MOVE_RANGE);
//
//    int newX = bot.x + dx;
//    int newY = bot.y + dy;
//
//    // Keep bot within grid boundaries
//    if (newX < 0) newX = 0;
//    if (newX >= GRID_SIZE) newX = GRID_SIZE - 1;
//    if (newY < 0) newY = 0;
//    if (newY >= GRID_SIZE) newY = GRID_SIZE - 1;
//
//    bot.x = newX;
//    bot.y = newY;
//}
//
//// Function for one bot to attack another
//void attackBot(Bot& attacker, Bot& target) {
//    if (!target.isAlive) {
//        return; // Cannot attack a dead bot
//    }
//
//    std::cout << attacker.name << " attacks " << target.name << "!" << std::endl;
//    target.health -= ATTACK_DAMAGE;
//
//    if (target.health <= 0) {
//        target.health = 0;
//        target.isAlive = false;
//        std::cout << target.name << " has been defeated!" << std::endl;
//    }
//    else {
//        std::cout << target.name << " now has " << target.health << " health." << std::endl;
//    }
//}
//
//// Function to check if the game is over (only one bot alive)
//bool isGameOver(const std::vector<Bot>& bots) {
//    return getAliveBotCount(bots) <= 1;
//}
//
//// Function to count how many bots are still alive
//int getAliveBotCount(const std::vector<Bot>& bots) {
//    int aliveCount = 0;
//    for (const auto& bot : bots) {
//        if (bot.isAlive) {
//            aliveCount++;
//        }
//    }
//    return aliveCount;
//}
//
//// Function to generate a random number within a range
//int getRandomNumber(int min, int max) {
//    return min + (rand() % (max - min + 1));
//}
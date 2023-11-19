
#include "character_utils.hpp"
#include <random>

std::string CharacterUtils::GenerateName() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, int(possibleNames.size()) - 1);
    int randomIndex = dist(rng);

    return possibleNames[randomIndex];
}

std::vector<std::string> CharacterUtils::possibleNames = {
    "Alden",
    "Elysia",
    "Garrick",
    "Seraphina",
    "Thorne"
};

Stats* CharacterUtils::GenerateStats() {
    Stats* stats = new Stats {10, 11, 12, 13};
    return stats;
}

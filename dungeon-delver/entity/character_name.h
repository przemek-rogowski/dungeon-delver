
#ifndef character_name_h
#define character_name_h

#include <string>
#include <vector>
#include <random>

class CharacterNameGenerator {
public:
    static std::string Generate() {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> dist(0, possibleNames.size() - 1);
        int randomIndex = dist(rng);
        
        return possibleNames[randomIndex];
    }

private:
    static std::vector<std::string> possibleNames;
};

std::vector<std::string> CharacterNameGenerator::possibleNames = {
    "Sarmeth",
    "Thorvald",
    "Thoris",
    "Telmur",
    "Aalmir",
    "Saphone"
};

#endif /* character_name_h */

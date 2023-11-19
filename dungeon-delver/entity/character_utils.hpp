
#ifndef character_utils_hpp
#define character_utils_hpp

#include <string>
#include <vector>
#include "stats.h"

class CharacterUtils {
public:
    static std::string GenerateName();
    static Stats* GenerateStats();
    
private:
    static std::vector<std::string> possibleNames;
};

#endif /* character_utils_hpp */

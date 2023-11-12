#ifndef world_hpp
#define world_hpp

#include <string>
#include <vector>
#include <utility>

using std::string;
using std::vector;
using std::pair;

struct Terrain {
    string name;
    char shortName;
};

struct Position {
    int x;
    int y;
};

struct Location {
    string name;
    Terrain terrain;
    bool isExplored;
};

class World {
public:
    World() = default;
    ~World();
    void Load(string name);
    void display();
private:
    vector<vector<Location>> locations;
    Position curLocation;
};

#endif /* world_hpp */

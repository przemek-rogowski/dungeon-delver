#ifndef menu_hpp
#define menu_hpp

#include <string>
#include <map>
#include <functional>

struct Command {
    std::string name;
    std::string description;
    std::function<void()> action;
};

class MainMenu {
public:
    MainMenu() = default;
    ~MainMenu();
    void Display();
    void AddCommand(Command command);
    void Process(std::string command);
private:
    std::vector<Command> commands;
};

#endif /* menu_hpp */

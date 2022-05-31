#ifndef ADVANCEDMENU_H
#define ADVANCEDMENU_H

#include <fstream>

#include "nlohmann/json.hpp"

class AdvancedMenu
{
public:
    explicit AdvancedMenu();
    ~AdvancedMenu(){};

    bool getStateTabsShortTitle() const;
    bool getStateTabsMovable() const;

protected:
    bool isTabsShortTitle = false;
    bool isTabsMovable = false;

private:
    nlohmann::json config = nullptr;
};

#endif // ADVANCEDMENU_H

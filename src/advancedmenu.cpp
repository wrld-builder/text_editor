#include "advancedmenu.h"

AdvancedMenu::AdvancedMenu() {
    std::ifstream in("config.json", std::ifstream::in);
    if(in.is_open() == true) {
        in >> config;
        in.close();
    }
}

bool AdvancedMenu::getStateTabsShortTitle() const {
    return config["tabs"]["short_title"];
}

bool AdvancedMenu::getStateTabsMovable() const {
    return config["tabs"]["movable"];
}

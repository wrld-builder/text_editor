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

std::string AdvancedMenu::getStateHexBackground() const {
    return config["mainwindow"]["background_color_hex"];
}

std::string AdvancedMenu::getStateHexEdgeTagFormatForeground() const {
    return config["html"]["edge_tag_format_foreground"];
}

std::string AdvancedMenu::getStateHexInsideTagFormatForeground() const {
    return config["html"]["inside_tag_format_foreground"];
}

std::string AdvancedMenu::getStateHexTagsFormatForeground() const {
    return config["html"]["tags_format_foreground"];
}

#ifndef ADVANCEDMENU_H
#define ADVANCEDMENU_H

#include <fstream>
#include <string>
#include "nlohmann/json.hpp"

class AdvancedMenu {
public:
    explicit AdvancedMenu();
    ~AdvancedMenu(){};

    bool getStateTabsShortTitle() const;
    bool getStateTabsMovable() const;

    std::string getStateHexBackground() const;
    std::string getStateHexEdgeTagFormatForeground() const;
    std::string getStateHexInsideTagFormatForeground() const;
    std::string getStateHexTagsFormatForeground() const;

protected:
    bool isTabsShortTitle = false;
    bool isTabsMovable = false;

    std::string hex_background = "";
    std::string edge_tag_format_foreground_hex = "";
    std::string inside_tag_format_foreground_hex = "";
    std::string tags_format_foreground_hex = "";

private:
    nlohmann::json config = nullptr;
};

#endif // ADVANCEDMENU_H

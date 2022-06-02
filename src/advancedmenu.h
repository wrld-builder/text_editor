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

    std::string getStatePythonCycleForegroundColor() const;
    std::string getStatePythonStatementsForegroundColor() const;
    std::string getStatePythonStateWordsForegroundColor() const;

protected:
    bool isTabsShortTitle = false;
    bool isTabsMovable = false;

    std::string hex_background = "";

    std::string edge_tag_format_foreground_hex = "";
    std::string inside_tag_format_foreground_hex = "";
    std::string tags_format_foreground_hex = "";

    std::string python_cycle_foreground_color = "";
    std::string python_statements_foreground_color = "";
    std::string python_state_words_foreground_color = "";

private:
    nlohmann::json config = nullptr;
};

#endif // ADVANCEDMENU_H

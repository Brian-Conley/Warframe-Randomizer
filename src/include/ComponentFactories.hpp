#include "Warframes.hpp"
#include <array>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <string_view>

namespace ComponentFactories {

    using namespace ftxui;

    Component makeChecklist(std::array<std::string_view, Warframes::WARFRAME_COUNT>& names,
                            std::array<bool, Warframes::WARFRAME_COUNT>& checked);

    Component makeControlHints();

    Component makeOutputText(std::array<std::string_view, Warframes::WARFRAME_COUNT>& names, int& idx);

}

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <string_view>

namespace ComponentFactories {

    using namespace ftxui;

    Component makeChecklist(std::array<std::string_view, 65>& names,
                            std::array<bool, 65>& checked);

}

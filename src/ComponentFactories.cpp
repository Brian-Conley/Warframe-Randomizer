#include "include/ComponentFactories.hpp"
#include <vector>

namespace ComponentFactories {

    using namespace ftxui;

    Component makeChecklist(std::array<std::string_view, 65>& names,
                            std::array<bool, 65>& checked) {

        std::vector<Component> boxes;
        boxes.reserve(65);
        for (size_t i = 0; i < 65; ++i) {
            boxes.push_back( Checkbox(names[i], &checked[i]) );
        }

        return Container::Vertical(std::move(boxes));
    }

}

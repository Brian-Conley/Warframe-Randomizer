#include "include/ComponentFactories.hpp"
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
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

    Component makeControlHints() {
        return Renderer([] {
            return window(
                text("Controls"),
                vbox({
                    hbox({ text("↑/↓, j/k"), filler(), text("Move") }),
                    hbox({ text("Space"),    filler(), text("Toggle") }),
                    hbox({ text("r"),        filler(), text("Randomize") }),
                    hbox({ text("a"),        filler(), text("Toggle all on") }),
                    hbox({ text("n"),        filler(), text("Toggle all off") }),
                    hbox({ text("q"),        filler(), text("Quit") }),
                })
            );
        });
    }

    Component makeOutputText(std::array<std::string_view, 65>& names, int& idx) {
        return Renderer([&] {
                return text( idx == -1 ? "None" : names[idx] ) | bold | underlined;
                });
    }

}

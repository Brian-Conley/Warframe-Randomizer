#include "include/ComponentFactories.hpp"
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/elements.hpp>
#include <vector>

namespace ComponentFactories {

    using namespace ftxui;

    Component makeChecklist(std::array<std::string_view, 65>& names,
                            std::array<bool, 65>& checked) {

        std::vector<Component> columns;
        columns.reserve(7);
        for (size_t i = 0; i < 65; ++i) {
            if (i % 12 == 0)
                columns.push_back(Container::Vertical({}));

            columns.back()->Add(Checkbox(names[i], &checked[i]));
        }

        return Container::Horizontal(std::move(columns));
    }

    Component makeControlHints() {
        return Renderer([] {
            return window(
                text("Controls"),
                vbox({
                    hbox({ text("h/j/k/l/Arrows"), filler(), text("Move") }),
                    hbox({ text("Space"),          filler(), text("Toggle") }),
                    hbox({ text("r"),              filler(), text("Randomize") }),
                    hbox({ text("a"),              filler(), text("Toggle all on") }),
                    hbox({ text("n"),              filler(), text("Toggle all off") }),
                    hbox({ text("q"),              filler(), text("Quit") }),
                })
            );
        });
    }

    Component makeOutputText(std::array<std::string_view, 65>& names, int& idx) {
        /*
        return Renderer([&] {
                return text( idx == -1 ? "None" : names[idx] ) | bold;
                });
        */

        return Renderer([&] {
                return window(
                        text("Warframe"),
                        text(idx == -1 ? "None" : names[idx]) | bold
                        );
                });
    }

}

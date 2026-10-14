#include "include/ComponentFactories.hpp"
#include "include/Warframes.hpp"
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/elements.hpp>
#include <vector>

namespace ComponentFactories {

    using namespace ftxui;

    Component makeChecklist(std::array<std::string_view, Warframes::WARFRAME_COUNT>& names,
                            std::array<bool, Warframes::WARFRAME_COUNT>& checked) {

        std::vector<Component> columns;
        columns.reserve(7);
        for (size_t i = 0; i < Warframes::WARFRAME_COUNT; ++i) {
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
                    hbox({ text("num"),            filler(), text("Load preset") }),
                    hbox({ text("shift+num"),      filler(), text("Save preset") }),
                })
            );
        });
    }

    Component makeOutputText(std::array<std::string_view, Warframes::WARFRAME_COUNT>& names, int& idx) {
        return Renderer([&] {
                return window(
                        text("Warframe"),
                        text(idx == -1 ? "None" : names[idx]) | bold
                        );
                });
    }

    Component makeOutput3Text(std::array<std::string_view, Warframes::WARFRAME_COUNT>& names, const std::array<int, 3>& chosen) {
        return Renderer([&] {
                return window(
                        text("Warframe (3)"),
                        vbox({
                            text(chosen[0] == -1 ? "None" : names[chosen[0]]) | bold,
                            text(chosen[1] == -1 ? "None" : names[chosen[1]]) | bold,
                            text(chosen[2] == -1 ? "None" : names[chosen[2]]) | bold
                            })
                        );
                });
    }
}

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
                    hbox({ text("shift+r"),        filler(), text("Randomize 3") }),
                    hbox({ text("a"),              filler(), text("Toggle all on") }),
                    hbox({ text("n"),              filler(), text("Toggle all off") }),
                    hbox({ text("q"),              filler(), text("Quit") }),
                    hbox({ text("num"),            filler(), text("Load preset") }),
                    hbox({ text("shift+num"),      filler(), text("Save preset") }),
                })
            );
        });
    }

    Component makeOutputText(std::array<std::string_view, Warframes::WARFRAME_COUNT>& names, const std::array<int, 3>& idx) {
        return Renderer([&] {
                return window(
                        text("Warframe"),
                        vbox({
                            text(idx[0] == -1 ? "None" : names[idx[0]]) | bold,
                            text(idx[1] == -1 ? "" : names[idx[1]]) | bold,
                            text(idx[2] == -1 ? "" : names[idx[2]]) | bold
                            })
                        );
                });
    }

}

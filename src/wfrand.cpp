#include "include/AppState.hpp"
#include "include/ComponentFactories.hpp"
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/app.hpp>

int main() {
    using namespace ftxui;

    auto state = AppState::makeDefault();
    auto checklist = ComponentFactories::makeChecklist(state.warframeNames, state.checkedWarframes);

    auto layout = Container::Vertical({

            Renderer([] {
                    return text("Warframe Randomizer") | bold | center;
                    }),

            Renderer([] {
                    return separator();
                    }),

            checklist

    });

    auto renderer = Renderer(layout, [&] {
            return layout->Render() | vscroll_indicator | frame;
            });
    auto screen = App::FitComponent();

    screen.Loop(renderer);

    return 0;
}

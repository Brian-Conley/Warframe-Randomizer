#include "include/AppState.hpp"
#include "include/ComponentFactories.hpp"
#include "include/Warframes.hpp"
#include <array>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/app.hpp>
#include <random>
#include <vector>

void toggleAllOff(std::array<bool, Warframes::WARFRAME_COUNT>& states);
void toggleAllOn(std::array<bool, Warframes::WARFRAME_COUNT>& states);
int randomize(std::array<bool, Warframes::WARFRAME_COUNT>& states);

int main() {
    using namespace ftxui;

    auto state = AppState::makeDefault();
    auto checklist = ComponentFactories::makeChecklist(state.warframeNames, state.checkedWarframes);
    auto controlHints = ComponentFactories::makeControlHints();
    auto output = ComponentFactories::makeOutputText(state.warframeNames, state.randomizedIndex);

    auto screen = App::FitComponent();

    auto layout = Renderer(checklist, [&] {
        return vbox({
            text("Warframe Randomizer") | bold | center,
            separator(),
            vbox({
                hbox({
                    controlHints->Render() | size(ftxui::WIDTH, ftxui::GREATER_THAN, 22),

                    output->Render() | size(ftxui::HEIGHT, ftxui::GREATER_THAN, 8)
                }), //| size(ftxui::WIDTH, ftxui::GREATER_THAN, 60),
                checklist->Render()
            })
        });
    });

    auto root = CatchEvent(layout, [&](Event event) {
        if (event == Event::Character('r')) {
            state.randomizedIndex = randomize(state.checkedWarframes);
            return true;
        }

        if (event == Event::Character('q')) {
            screen.ExitLoopClosure()();
            return true;
        }

        if (event == Event::Character('a')) {
            toggleAllOn(state.checkedWarframes);
            return true;
        }

        if (event == Event::Character('n')) {
            toggleAllOff(state.checkedWarframes);
            return true;
        }

        return false;
    });

    screen.Loop(Renderer(root, [&] {
                return root->Render() | vscroll_indicator | frame;
                }));

    return 0;
}

void toggleAllOff(std::array<bool, Warframes::WARFRAME_COUNT>& states) {
    for (size_t i = 0; i < Warframes::WARFRAME_COUNT; ++i)
        states[i] = false;
}

void toggleAllOn(std::array<bool, Warframes::WARFRAME_COUNT>& states) {
    for (size_t i = 0; i < Warframes::WARFRAME_COUNT; ++i)
        states[i] = true;
}

int randomize(std::array<bool, Warframes::WARFRAME_COUNT>& states) {
    std::vector<int> enabledFrames = {};
    for (int i = 0; i < Warframes::WARFRAME_COUNT; ++i) {
        if (states[i]) {
            enabledFrames.push_back(i);
        }
    }

    if (enabledFrames.size() == 0) {
        return -1;
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, enabledFrames.size() - 1);

    return enabledFrames[dist(gen)];
}

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
std::array<int, 3> randomize(std::array<bool, Warframes::WARFRAME_COUNT>& states);
std::array<int, 3> randomize3 (std::array<bool, Warframes::WARFRAME_COUNT>& states);

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
                    controlHints->Render() | size(ftxui::WIDTH, ftxui::GREATER_THAN, 24),
                    output->Render() | size(ftxui::WIDTH, GREATER_THAN, 18)
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

        if (event == Event::Character('R')) {
            state.randomizedIndex = randomize3(state.checkedWarframes);
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

        if (event == Event::Character('1')) {
            AppState::loadState(state, 1);
            return true;
        }

        if (event == Event::Character('!')) {
            AppState::saveState(state, 1);
            return true;
        }

        if (event == Event::Character('2')) {
            AppState::loadState(state, 2);
            return true;
        }

        if (event == Event::Character('@')) {
            AppState::saveState(state, 2);
            return true;
        }

        if (event == Event::Character('3')) {
            AppState::loadState(state, 3);
            return true;
        }

        if (event == Event::Character('#')) {
            AppState::saveState(state, 3);
            return true;
        }

        if (event == Event::Character('4')) {
            AppState::loadState(state, 4);
            return true;
        }

        if (event == Event::Character('$')) {
            AppState::saveState(state, 4);
            return true;
        }

        if (event == Event::Character('5')) {
            AppState::loadState(state, 5);
            return true;
        }

        if (event == Event::Character('%')) {
            AppState::saveState(state, 5);
            return true;
        }

        if (event == Event::Character('6')) {
            AppState::loadState(state, 6);
            return true;
        }

        if (event == Event::Character('^')) {
            AppState::saveState(state, 6);
            return true;
        }

        if (event == Event::Character('7')) {
            AppState::loadState(state, 7);
            return true;
        }

        if (event == Event::Character('&')) {
            AppState::saveState(state, 7);
            return true;
        }

        if (event == Event::Character('8')) {
            AppState::loadState(state, 8);
            return true;
        }

        if (event == Event::Character('*')) {
            AppState::saveState(state, 8);
            return true;
        }

        if (event == Event::Character('9')) {
            AppState::loadState(state, 9);
            return true;
        }

        if (event == Event::Character('(')) {
            AppState::saveState(state, 9);
            return true;
        }

        if (event == Event::Character('0')) {
            AppState::loadState(state, 10);
            return true;
        }

        if (event == Event::Character(')')) {
            AppState::saveState(state, 10);
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

std::array<int, 3> randomize(std::array<bool, Warframes::WARFRAME_COUNT>& states) {
    std::vector<int> enabledFrames = {};
    for (int i = 0; i < Warframes::WARFRAME_COUNT; ++i) {
        if (states[i]) {
            enabledFrames.push_back(i);
        }
    }

    if (enabledFrames.size() == 0) {
        return { -1, -1, -1 };
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, enabledFrames.size() - 1);

    return { enabledFrames[dist(gen)], -1, -1 };
}

std::array<int, 3> randomize3 (std::array<bool, Warframes::WARFRAME_COUNT>& states) {
    std::vector<int> enabledFrames = {};
    for (int i = 0; i < Warframes::WARFRAME_COUNT; ++i) {
        if (states[i]) {
            enabledFrames.push_back(i);
        }
    }

    if (enabledFrames.size() < 3) {
        return {-1, -1, -1};
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::array<int, 3> chosenFrames = {-1, -1, -1};
    for (int i = 0; i < 3; ++i) {
        std::uniform_int_distribution<> dist(0, enabledFrames.size() - 1);
        int idx = dist(gen);
        chosenFrames[i] = enabledFrames[idx];
        enabledFrames.erase(enabledFrames.begin() + idx);
    }

    return chosenFrames;
}

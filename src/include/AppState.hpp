#ifndef APPSTATE_HPP
#define APPSTATE_HPP

#include "Warframes.hpp"
#include <array>
#include <string_view>

namespace AppState {
    struct AppState {
        std::array<std::string_view, Warframes::WARFRAME_COUNT> warframeNames;
        std::array<bool, Warframes::WARFRAME_COUNT> checkedWarframes;
        int randomizedIndex;
        std::array<int, 3> randomized3;
    };

    AppState makeDefault();

    void saveState(AppState& state, int slot);
    void loadState(AppState& state, int slot);

}


#endif

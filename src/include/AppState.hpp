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
    };

    AppState makeDefault();

}


#endif

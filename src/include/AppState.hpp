#ifndef APPSTATE_HPP
#define APPSTATE_HPP

#include <array>
#include <string_view>

namespace AppState {
    struct AppState {
        std::array<std::string_view, 65> warframeNames;
        std::array<bool, 65> checkedWarframes;
        int selectedWarframe;
        int randomizedIndex;
    };

    AppState makeDefault();

}


#endif

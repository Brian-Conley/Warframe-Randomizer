#ifndef APPSTATE_HPP
#define APPSTATE_HPP

#include <array>
#include <string_view>

namespace AppState {
    struct AppState {
        std::array<std::string_view, 65> warframeNames;
        //std::vector<std::string> warframeNames;
        //std::vector<std::shared_ptr<bool>> checkedWarframes;
        std::array<bool, 65> checkedWarframes;
        int selectedWarframe;
    };

    AppState makeDefault();

}


#endif

#include "include/AppState.hpp"

namespace AppState {

    AppState makeDefault() {
        AppState state;

        state.warframeNames = Warframes::WARFRAMES;

        for (size_t i = 0; i < Warframes::WARFRAME_COUNT; ++i)
            state.checkedWarframes[i] = false;

        state.randomizedIndex = -1;

        return state;
    }

}

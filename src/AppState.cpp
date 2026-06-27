#include "include/AppState.hpp"

namespace AppState {

    AppState makeDefault() {
        AppState state;

        state.warframeNames = std::array<std::string_view, 65> {
            "Ash               ",
            "Atlas             ",
            "Banshee           ",
            "Baruuk            ",
            "Caliban           ",
            "Chroma            ",
            "Citrine           ",
            "Cyte-09           ",
            "Dagath            ",
            "Dante             ",
            "Ember            ",
            "Equinox          ",
            "Excalibur        ",
            "Follie           ",
            "Frost            ",
            "Gara             ",
            "Garuda           ",
            "Gauss            ",
            "Grendel          ",
            "Gyre             ",
            "Harrow           ",
            "Hildryn          ",
            "Hydroid          ",
            "Inaros           ",
            "Ivara            ",
            "Jade             ",
            "Khora            ",
            "Koumei           ",
            "Kullervo         ",
            "Lavos            ",
            "Limbo            ",
            "Loki             ",
            "Mag              ",
            "Mesa             ",
            "Mirage           ",
            "Nekros           ",
            "Nezha            ",
            "Nidus            ",
            "Nokko            ",
            "Nova             ",
            "Nyx              ",
            "Oberon           ",
            "Octavia          ",
            "Oraxia           ",
            "Protea           ",
            "Qorvex           ",
            "Revenant         ",
            "Rhino            ",
            "Saryn            ",
            "Sevagoth         ",
            "Sirius and Orion ",
            "Styanax          ",
            "Temple           ",
            "Titania          ",
            "Trinity          ",
            "Uriel            ",
            "Valkyr           ",
            "Vauban           ",
            "Volt             ",
            "Voruna           ",
            "Wisp             ",
            "Wukong           ",
            "Xaku             ",
            "Yareli           ",
            "Zephyr           "
        };

        for (size_t i = 0; i < 65; ++i)
            state.checkedWarframes[i] = false;

        state.randomizedIndex = -1;

        return state;
    }

}

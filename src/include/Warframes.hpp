#ifndef WARFRAMES_HPP
#define WARFRAMES_HPP

#include <array>
#include <string_view>

namespace Warframes {
    constexpr int WARFRAME_COUNT = 65;
    constexpr int WARFRAME_BYTES = (WARFRAME_COUNT + 7) / 8;

    constexpr std::array<std::string_view, WARFRAME_COUNT> WARFRAMES = {
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

}

#endif

#include "include/AppState.hpp"
#include "include/Warframes.hpp"
#include <array>
#include <cstdint>
#include <filesystem>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <string>

namespace AppState {

    AppState makeDefault() {
        AppState state;

        state.warframeNames = Warframes::WARFRAMES;

        for (size_t i = 0; i < Warframes::WARFRAME_COUNT; ++i)
            state.checkedWarframes[i] = false;

        state.randomizedIndex = -1;

        return state;
    }

    std::filesystem::path getPresetPath(int slot) {
        std::filesystem::path homePath;
        if (const char* home = std::getenv("HOME"))
            homePath = std::filesystem::path{home};
        else
            return {};
        homePath /= ".local/share/wfrand";
        homePath /= ("preset" + std::to_string(slot) + ".wfr");

        std::filesystem::create_directories(homePath.parent_path());
        return homePath;
    }

    void setBit(std::array<std::uint8_t, Warframes::WARFRAME_BYTES>& p, int i, bool value) {
        std::uint8_t& byte = p[i / 8];
        std::uint8_t mask = 1u << (i % 8);

        if (value)
            byte |= mask;
        else
            byte &= ~mask;
    }

    bool getBit(std::array<std::uint8_t, Warframes::WARFRAME_BYTES>& p, int i) {
        return (p[i / 8] >> (i % 8)) & 1u;
    }

    void saveState(AppState& state, int slot) {
        auto presetPath = getPresetPath(slot);
        if (presetPath.empty()) return;

        std::array<std::uint8_t, Warframes::WARFRAME_BYTES> preset;
        for (int i = 0; i < Warframes::WARFRAME_COUNT; ++i)
            setBit(preset, i, state.checkedWarframes[i]);

        std::ofstream file(presetPath, std::ios::binary);
        if (!file) return;
        file.write(reinterpret_cast<const char*>(preset.data()), preset.size());
    }

    void loadState(AppState& state, int slot) {
        auto presetPath = getPresetPath(slot);
        if (presetPath.empty()) return;

        std::array<std::uint8_t, Warframes::WARFRAME_BYTES> preset{};

        std::ifstream file(presetPath, std::ios::binary);
        if (!file) return;
        file.read(reinterpret_cast<char*>(preset.data()), preset.size());

        // If the file is too small, don't trust it.
        if (file.gcount() != static_cast<std::streamsize>(preset.size()))
            return;

        state.randomizedIndex = -1;
        for (int i = 0; i < Warframes::WARFRAME_COUNT; ++i)
            state.checkedWarframes[i] = getBit(preset, i);
    }

}

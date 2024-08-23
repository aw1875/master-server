#pragma once

#include "utils/info_string.hpp"

enum class game_type
{
	unknown = 0,
	iw4,
	iw5,
	iw6,
	iw7,
	s1,
	t7,
    h2m,
};

inline const std::string& resolve_game_type_name(const game_type game)
{
	static const std::unordered_map<game_type, std::string> names =
	{
		{game_type::unknown, "Unknown"},
		{game_type::iw4, "IW4"},
		{game_type::iw5, "IW5"},
		{game_type::iw6, "IW6"},
		{game_type::iw7, "IW7"},
		{game_type::s1, "S1"},
		{game_type::t7, "T7"},
		{game_type::h2m, "H2M"},
	};

	return names.at(game);
}

inline game_type resolve_game_type(const std::string& game_name)
{
    static const std::unordered_map<std::string, game_type> names =
    {
        {"IW4", game_type::iw4},
        {"IW5", game_type::iw5},
        {"IW6", game_type::iw6},
        {"IW7", game_type::iw7},
        {"S1", game_type::s1},
        {"T7", game_type::t7},
        {"H2M", game_type::h2m},
    };

    auto it = names.find(game_name);
    if (it != names.end()) return it->second;

    return game_type::unknown;
}

struct game_server
{
	enum class state
	{
		can_ping = 0,
		needs_ping,
		pinged,
		dead,
	};

	state state{state::can_ping};
	bool registered{false};

	game_type game{game_type::unknown};
	int protocol{};
	uint32_t clients{};
	std::string name{};
	std::string challenge{};
	utils::info_string info_string{};
	std::chrono::high_resolution_clock::time_point heartbeat{};
};

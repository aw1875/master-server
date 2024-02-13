#include <std_include.hpp>
#include "getbots_command.hpp"

#include "../console.hpp"

const char* getbots_command::get_command() const
{
	return "getbots";
}

void getbots_command::handle_command(const network::address& target, const std::string_view&)
{
	static const std::array bot_names
	{
		"6arelyhuman",
		"aerosoul",
		"All Night",
		"Another World",
		"Ash",
		"asmjit",
		"avail",
		"Barack Obama",
		"barbie slut",
		"Barbie Whore",
		"Berlusconi",
		"Bimbo Suicide",
		"bimbo",
		"Blow Up!",
		"Boston",
		"Bubbles",
		"Caliber",
		"CAPTAINJERKFACE",
		"Catalyst",
		"Cenote",
		"Chicago",
		"clang",
		"Cressi",
		"Cypress",
		"DANCE! Till We Die",
		"David Guetta",
		"Death city",
		"Debian",
		"Devil's Spring",
		"Diamante",
		"Diavolo",
		"Disgusting",
		"DKo5",
		"Do U Luv Me",
		"Do U",
		"Don't Like Anybody",
		"don't touch my hair",
		"Donald Trump",
		"drama queenz",
		"Dsso",
		"Eagle's Nest",
		"Eat Me",
		"Eldor",
		"Evan",
		"Eve",
		"Eyelashes on",
		"feeling nothing",
		"Flex190",
		"FOURZEROTWO",
		"FragsAreUs",
		"FryTechTip",
		"Furry",
		"FutureRave",
		"Ginnie Springs",
		"Girl",
		"GMFU",
		"Go Crazy",
		"gsc-tool",
		"H3X1C",
		"Hands up!",
		"Helium",
		"Hey Dj",
		"Higher",
		"Hinder",
		"homura",
		"Horizon - SCR",
		"Hypocrite",
		"INeedBots",
		"INeedGames",
		"Infamous",
		"Inferno",
		"InfinityScript",
		"Jack Back",
		"Jebus3211",
		"JetFins",
		"JezuzLizard",
		"Jimbo",
		"Joe Biden",
		"Joel",
		"JTAG",
		"King Crimson",
		"KiraFoxAF",
		"KonaFuzzButt",
		"Kordhell",
		"Laupetin",
		"Level Up!",
		"Lifeline",
		"Like a G6",
		"llvm-project",
		"Loba",
		"Loona",
		"Loudward",
		"Louvenarde",
		"Mares",
		"Mattarella",
		"momo5502",
		"Montreal",
		"MSVC",
		"MUPP",
		"mxve",
		"My Flaws",
		"Neapolis",
		"New York",
		"Nightzy",
		"Non-binary Jesus",
		"OneFourOne",
		"OpenAssetTools",
		"Parking Lot",
		"PeterG",
		"pgriffin69x",
		"Poker Face",
		"Portobello",
		"Portofino",
		"PottyMouth",
		"quaK",
		"RaidMax",
		"ramzi1337hak0r",
		"rapidjson",
		"Read Sea",
		"RektInator",
		"Resxt",
		"rEvoRebreather",
		"RezTech",
		"Roxie",
		"Santi Diving",
		"Sass",
		"saysupshelly",
		"Scarlxrd",
		"scene high",
		"SCUBAPRO",
		"Serious",
		"Sestriere",
		"Slay Everyday",
		"Sloth",
		"SLUT SZN",
		"Slykuiper",
		"Snake",
		"Sparky",
		"Squirrel",
		"st0rm",
		"Stalk Me",
		"StarBerry",
		"Titanium",
		"Trimix",
		"turn it up",
		"TwinLeaf",
		"Ubuntu",
		"ur my heroin",
		"Ur Vampire",
		"Valkyrie",
		"Violence",
		"Vore",
		"Wanted",
		"Wattson",
		"Wereric",
		"X Party",
		"xensik",
		"XOXO (Kisses Hugs)",
		"xoxor4d",
		"XXXTENSIONS",
		"You & Me",
		"Yummy",
		"ZoneBuilder",
		"ZoneTool",
	};

	std::stringstream stream{};
	for (const auto& bot : bot_names)
	{
		stream << bot << std::endl;
	}

	this->get_server().send(target, "getbotsResponse", stream.str());
	console::log("Sent bot names: %s", target.to_string().data());
}

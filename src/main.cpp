#include <std_include.hpp>

#include "console.hpp"
#include "server.hpp"
#include "crypto_key.hpp"

#include <utils/config.hpp>

namespace
{
	void unsafe_main(const uint16_t port)
	{
		crypto_key::get();

		console::log("Creating socket on port %hu", port);

		network::address a{"0.0.0.0"};
		a.set_port(port);
		server s{a};

		console::signal_handler handler([&s]()
		{
			s.stop();
		});

		s.run();

		console::log("Terminating server...");
	}
}


int main(const int argc, const char** argv)
{
    utils::config& config = utils::config::instance();

	console::set_title(config.get_title());
	console::log(config.get_title().c_str());
    console::log("Stats will be saved to %s", config.get_stats_path().c_str());

	try
	{
		unsafe_main(argc > 1 ? static_cast<uint16_t>(std::strtol(argv[1], nullptr, 10)) : config.get_port());
	}
	catch (std::exception& e)
	{
		console::error("Fatal error: %s\n", e.what());
		return -1;
	}

	return 0;
}

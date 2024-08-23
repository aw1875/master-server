#pragma once

#include <string>

#include "io.hpp"
#include <json.hpp>

// This is a singleton class
namespace utils
{
    class config
    {
        public:
            config(const config&) = delete;
            config& operator=(const config&) = delete;

            static config& instance()
            {
                static config instance;
                return instance;
            }

            std::string get_title() const { return this->title; }
            std::string get_stats_path() const { return this->stats_path; }

        private:
            config() { this->parse_config(); }

            void parse_config()
            {
                std::string data{};
                if (!utils::io::read_file("./config.json", &data)) return;

                nlohmann::json config{};
                try {
                    config = nlohmann::json::parse(data);
                } catch (const nlohmann::json::parse_error& e) {
                    console::warn("Failed to parse config: %s", e.what());
                    return;
                }


                if (config.contains("title")) config.at("title").get_to(this->title);
                if (config.contains("stats_path")) config.at("stats_path").get_to(this->stats_path);
            }

            std::string title = "AlterWare Master";
            std::string stats_path = "/var/www/server.alterware.dev/html/stats.json";
    };
}

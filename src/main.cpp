///
/// @file main.cpp
/// @brief Entry point of the Country Engine application.
///

#include <string>

import hello_world;
import logger;

// #include <iostream>
// #include <string>
// import std;
// #include <yaml-cpp/yaml.h>

// YAML::Node loadYamlFile(const std::string &filePath) {
//   return YAML::LoadFile(filePath);
// }

using Logger = CountryEngine::Utills::Logger;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

    Logger::init("/home/damon/Documents/2026/CPP/"
                 "Microsoft-cpp-programming-essentials/country-engine/app.log",
        true); // Initialize logger with file output

    if (argc != 2) {

        Logger::log(
            Logger::Level::Error, "Usage: {} <path_to_yaml_file>", argv[0]);
        return 1;
    }

    std::string filePath{argv[1]};
    Logger::log(Logger::Level::Info, "Processing YAML file: {}", filePath);



    // // Prints "Hello, World!" to the console.
    // hello_world();

    // Loads the country data from the YAML file and prints it to the console.
    // The load_country_data function is declared in the country_data module,
    // which is imported by the hello_world module.
    // load_country_data();

    // YAML::Node root = loadYamlFile(filePath);
    // if (!root) {
    //   std::cerr << "Failed to load YAML file: " << filePath << "\n";
    //   return 1;
    // }

    // // Example: access values
    // if (root["name"]) {
    //   std::cout << "name: " << root["name"].as<std::string>() << "\n";
    // }

    return 0;
}

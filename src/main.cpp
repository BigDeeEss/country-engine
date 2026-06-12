import hello_world;
// import logger;

#include <iostream>
// #include <string>
// import std;
// #include <yaml-cpp/yaml.h>

// YAML::Node loadYamlFile(const std::string &filePath) {
//   return YAML::LoadFile(filePath);
// }

int main(int argc, char *argv[]) {
  std::string filePath;
  if (argc > 1) {
    filePath = argv[1];
  }

  // Prints "Hello, World!" to the console.
  hello_world();

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

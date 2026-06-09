# CountryEngine

A small C++23 module-based project that reads country data from YAML and provides an output.

## Structure

- `src/` contains module source units.
- `CMakeLists.txt` builds the executable and module library.

## Obtaining the code

- `git clone --recurse-submodules https://github.com/BigDeeEss/country-engine.git`
- On older git systems,
    - `git clone --recurse https://github.com/BigDeeEss/country-engine.git`
- If already cloed withtout the flag, 
    - `git submodule init`
    - `git submodule update --recursive`

## Build

- `cmake -B build -G Ninja`
- `cmake --build build`
- `cmake --install build`


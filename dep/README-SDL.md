### Easy Button SDL2
 1. Download [SDL2 Development Libraries](https://www.libsdl.org/download-2.0.php).
 2. Extract the archive.
 3. Set the environmental variable `SDL2DIR` to the extraction directory.

### MinGW Build
 1. Download [SDL2 Source Code](https://www.libsdl.org/download-2.0.php).
 2. Extract the zip archive.
 3. Make a `build` directory in the extracted directory.
 4. From inside the `build` directory run `cmake -G "MinGW Makefiles ../`.
 5. Next run `cmake --build ./`
 6. Next run `mingw32-make install`.
 7. Set the environmental variable `SDL2DIR` to the install directory.

### Visual Studio 2013 Build
 1. Download [SDL2](https://www.libsdl.org/download-2.0.php).
 2. Extract the zip archive.
 3. Make a `build` directory in the extracted directory.
 4. From inside the `build` directory run `cmake ../`.
 5. Next run `cmake --build ./ --config Release`
 6. Assemble your build (`bin`, `include`, & `lib`).
 7. Set the environmental variable `SDL2DIR` to the install directory.
 
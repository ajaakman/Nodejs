emcc -std=c++11 "main.cpp" -s USE_SDL=2 -s EXPORTED_FUNCTIONS='["_StartAudio", "_GetAmplitude"]' -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]'
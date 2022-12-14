#!/usr/bin/env sh

mkdir -p docs
cd docs

em++ ../src/*.cpp -Wall -o demo.js \
    -D RUNTIME_BASE_PATH="" \
    -sUSE_SDL=2 -sUSE_SDL_IMAGE=2 -sUSE_SDL_TTF=2 -sUSE_SDL_MIXER=2 \
    -sSDL2_IMAGE_FORMATS="['png']" -sNO_DISABLE_EXCEPTION_CATCHING \
    --preload-file ../assets@assets \
    -sEXPORTED_FUNCTIONS=_main,_save --js-library mine.js \
    "$@"

#!/bin/bash

# meson
if ! command -v meson >/dev/null 2>&1; then
  echo "meson is not installed on the system"
  if ! command -v pip >/dev/null 2>&1 || ! command -v pip3 >/dev/null 2>&1; then
    echo "pip/3 is not installed\naborting"
  else
    echo "installing meson with pip"
    pip3 install --user meson
  fi
  exit 1
else 
  echo "meson is installed, creating ./build/"
fi
meson setup build
cd builddir

# compiling
if ! command -v ninja >/dev/null 2>&1; then
  echo "ninja is not installed on the system"
  pip install ninja
else
  echo "starting compilation"
  ninja
fi

echo "DONE"
echo "to execute run ./unchained"

# later add check for dependencies such
# as freetype, or glm

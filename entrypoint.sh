#!/bin/bash

export XDG_RUNTIME_DIR=/tmp/xdg
mkdir -p $XDG_RUNTIME_DIR
chmod 1777 $XDG_RUNTIME_DIR

export WAYLAND_DISPLAY="/tmp/wayland-0"

eclipse -data /workspace

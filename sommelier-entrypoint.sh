#!/bin/bash

export XDG_RUNTIME_DIR=/tmp/xdg
mkdir -p $XDG_RUNTIME_DIR
chmod 1777 $XDG_RUNTIME_DIR

export WAYLAND_DISPLAY="/tmp/wayland-0"

sommelier --noop-driver --xwayland-path=/usr/bin/Xwayland --display=/tmp/wayland-0 -X sh -c "WAYLAND_DISPLAY=/tmp/wayland-0 eclipse -data /workspace"

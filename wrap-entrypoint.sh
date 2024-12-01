#!/bin/bash

sommelier --noop-driver --xwayland-path=/usr/bin/Xwayland --display=/tmp/wayland-0 -X sh -c "WAYLAND_DISPLAY=/tmp/wayland-0 /entrypoint.sh $@"

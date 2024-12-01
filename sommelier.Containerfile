FROM ubuntu AS sommelier
RUN apt-get update && apt-get install -y \
    pkg-config \
    build-essential \
    curl \
    git \
    make \
    xwayland \
    libwayland-dev \
    libgbm-dev \
    gcc \
    libx11-xcb-dev \
    libsystemd-dev \
    libxcb-composite0-dev \
    libxkbcommon-dev \
    libxrender-dev \
    libxtst-dev \
    libpixman-1-dev \
    meson \
    ninja-build \
    python3 \
    python3-jinja2 \
    libdrm-dev \
    libgtest-dev

RUN curl -L -o /tmp/sommelier.tar.gz https://chromium.googlesource.com/chromiumos/platform2/+archive/refs/heads/main/vm_tools/sommelier.tar.gz && \
    mkdir -p /tmp/build-sommelier && \
    tar -xzf /tmp/sommelier.tar.gz -C /tmp/build-sommelier && \
    cd /tmp/build-sommelier && \
    meson build && \
    ninja -C build && \
    ninja -C build install

FROM ubuntu AS eclipse
COPY eclipse-cpp.tar.gz /tmp/eclipse-cpp.tar.gz
RUN tar --no-same-owner -xzf /tmp/eclipse-cpp.tar.gz -C /opt && chmod +x /opt/eclipse/eclipse

FROM ubuntu AS final
COPY --from=eclipse /opt/eclipse /opt/eclipse
ENV PATH="/opt/eclipse:$PATH"
RUN apt-get update && apt-get install -y \
    default-jre \
    build-essential \
    gdb \
    curl \
    libxcb-composite0 \
    xwayland \
    libboost-all-dev

COPY --from=sommelier /usr/local/bin/sommelier /usr/local/bin/sommelier

COPY sommelier-entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]

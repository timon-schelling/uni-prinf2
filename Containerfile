FROM ubuntu
RUN apt-get update && apt-get install -y default-jre build-essential gdb
COPY eclipse-cpp.tar.gz /tmp/eclipse-cpp.tar.gz
RUN tar --no-same-owner -xzf /tmp/eclipse-cpp.tar.gz -C /opt && chmod +x /opt/eclipse/eclipse
ENV WAYLAND_DISPLAY="/tmp/wayland-0"
ENV PATH="/opt/eclipse:$PATH"

RUN apt-get install -y libboost-all-dev

RUN apt-get install -y  xwayland-run

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]

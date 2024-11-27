FROM mrcolorrain/vnc-browser:debian
RUN apt-get update && apt-get install -y default-jre build-essential gdb
COPY eclipse-cpp.tar.gz /tmp/eclipse-cpp.tar.gz
RUN tar --no-same-owner -xzf /tmp/eclipse-cpp.tar.gz -C /opt && chmod +x /opt/eclipse/eclipse
ENV PATH="/opt/eclipse:$PATH"

RUN apt-get install -y libboost-all-dev

RUN mkdir -p /.eclipse && chmod 777 /.eclipse

RUN apt-get install -y sudo
RUN echo 'ALL ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

COPY entrypoint.sh /custom/entrypoint.sh
RUN chmod +x /custom/entrypoint.sh
ENV CUSTOMIZE="true"
ENV CUSTOM_ENTRYPOINTS_DIR="/custom"
ENV VNC_PASSWORD="passwd"
ENV AUTO_START_BROWSER="false"
ENV AUTO_START_XTERM="false"
ENV VNC_RESOLUTION="1035x850"
# ENTRYPOINT ["/entrypoint.sh"]

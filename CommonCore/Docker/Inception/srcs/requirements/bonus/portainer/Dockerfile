FROM        debian:bookworm

RUN apt update && apt install -y wget tar

RUN wget https://github.com/portainer/portainer/releases/download/2.19.0/portainer-2.19.0-linux-arm64.tar.gz \
    && tar xvzf portainer-2.19.0-linux-arm64.tar.gz \
    && rm -rf portainer-2.19.0-linux-arm64.tar.gz

EXPOSE 9000

CMD ["/portainer/portainer"]

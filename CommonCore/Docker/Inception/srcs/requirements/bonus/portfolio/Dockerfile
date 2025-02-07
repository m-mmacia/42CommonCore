FROM        debian:bookworm

RUN apt-get update && apt-get install -y --no-install-recommends git \
    && mkdir -p /var/www/html \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

COPY index.html ./

EXPOSE 80

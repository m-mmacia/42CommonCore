FROM alpine:3.19

RUN apk update && apk upgrade && apk add --no-cache nginx openssl

RUN mkdir /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/self-signed.key \
    -out /etc/nginx/ssl/self-signed.crt  \
    -subj "/C=FR/L=France/O=42/OU=42/CN=mmacia.42.fr"

COPY ./conf/nginx.conf /etc/nginx/http.d/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
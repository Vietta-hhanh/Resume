FROM alpine:3.12
RUN apk update && apk upgrade
RUN apk add -X http://dl-cdn.alpinelinux.org/alpine/edge/community telegraf

RUN mkdir -p /run/nginx
RUN mkdir -p /var/nginx/tmp/ssl
RUN apk add nginx vim openssl supervisor php7-fpm php
RUN rm /etc/nginx/conf.d/default.conf
RUN openssl req -newkey rsa:2048 -nodes -keyout /var/nginx/tmp/ssl/hhanh.key -x509 -days 365 \
-subj '/C=RU/ST=Moscow/L=Moscow/O=School21/OU=School21MSC/emailAddress=hhanh@student.21-school.ru/CN=localhost' \
-out /var/nginx/tmp/ssl/hhanh.crt

COPY nginx.conf .
COPY index.html /var/nginx/tmp
COPY start.sh .
COPY supervisord.conf /etc/
COPY telegraf.conf /etc/

EXPOSE 80 443
CMD /bin/sh start.sh

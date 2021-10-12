FROM alpine:3.12
RUN apk update && apk upgrade &&\
apk add wget nginx supervisor
RUN apk add -X http://dl-cdn.alpinelinux.org/alpine/edge/community telegraf
RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session php7-iconv php7-xml
RUN mkdir -p /run/nginx
RUN mkdir -p /var/nginx/tmp/ssl
RUN rm /etc/nginx/conf.d/default.conf
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-english.tar.gz &&\
tar xzvf phpMyAdmin-5.1.0-english.tar.gz && mv /phpMyAdmin-5.1.0-english /var/nginx/tmp/phpmyadmin && rm phpMyAdmin-5.1.0-english.tar.gz

EXPOSE 5000
COPY	./start.sh .
COPY config.inc.php .
COPY nginx.conf ./hhanh.conf
COPY supervisord.conf .
COPY supervisord.conf /etc/
COPY telegraf.conf /etc/


CMD sh ./start.sh 

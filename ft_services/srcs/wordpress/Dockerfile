FROM alpine:3.12
RUN apk update && apk upgrade &&\
apk add wget nginx supervisor
RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session
RUN apk add -X http://dl-cdn.alpinelinux.org/alpine/edge/community telegraf
RUN mkdir -p /run/nginx
RUN mkdir -p /var/nginx/tmp/ssl
RUN rm /etc/nginx/conf.d/default.conf
RUN wget http://wordpress.org/latest.tar.gz && tar xzvf latest.tar.gz &&\
rm latest.tar.gz && mv wordpress /var/nginx/tmp

EXPOSE 5050

COPY	./start.sh .
COPY wp-config.php .
COPY nginx.conf ./hhanh.conf
COPY supervisord.conf .
COPY supervisord.conf /etc/
COPY telegraf.conf /etc/

CMD sh ./start.sh 

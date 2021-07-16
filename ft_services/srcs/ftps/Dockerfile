FROM alpine:3.12
RUN apk update && apk upgrade
RUN apk add vsftpd openrc openssl vim libc6-compat
RUN mkdir -p /run/openrc &&\
touch /run/openrc/softlevel && mkdir /ssl
RUN apk add -X http://dl-cdn.alpinelinux.org/alpine/edge/community telegraf
RUN apk add supervisor
RUN openssl req -newkey rsa:2048 -nodes -keyout /tmp/hhanh.key -x509 -days 365 \
-subj '/C=RU/ST=Moscow/L=Moscow/O=School21/OU=School21MSC/emailAddress=hhanh@student.21-school.ru/CN=localhost' \
-out /tmp/hhanh.crt
RUN		adduser -D hhanh &&  echo "hhanh:hhanh" | chpasswd

EXPOSE 20000 21 

COPY start.sh .
COPY vsftpd.conf .
COPY supervisord.conf /etc/
COPY telegraf.conf /etc/

CMD sh ./start.sh
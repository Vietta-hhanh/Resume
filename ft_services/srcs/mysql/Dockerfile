FROM alpine:3.12

RUN apk update && apk upgrade &&\
        apk add mariadb mariadb-client openrc vim wget 
RUN mkdir -p /run/openrc &&\
touch /run/openrc/softlevel
RUN apk add -X http://dl-cdn.alpinelinux.org/alpine/edge/community telegraf
RUN apk add supervisor

EXPOSE 3306
COPY	./start.sh .
COPY 	./my.cnf .
COPY supervisord.conf /etc/
COPY telegraf.conf /etc/
COPY hhanhbase.sql .


CMD ./start.sh
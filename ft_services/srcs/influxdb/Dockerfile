FROM alpine:3.12

RUN apk update && apk upgrade &&\
        apk add influxdb supervisor &&\
        apk add -X http://dl-cdn.alpinelinux.org/alpine/edge/community telegraf

COPY telegraf.conf /etc/
COPY supervisord.conf /etc/

EXPOSE 8086

CMD supervisord -c /etc/supervisord.conf

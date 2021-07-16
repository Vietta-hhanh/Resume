FROM alpine:3.12

RUN apk update && apk upgrade &&\
	apk add supervisor &&\
    apk add -X http://dl-cdn.alpinelinux.org/alpine/edge/community grafana telegraf
RUN mkdir /usr/share/grafana/conf/dashboards

COPY telegraf.conf /etc/
COPY supervisord.conf /etc/
COPY grafana.db /usr/share/grafana/data/grafana.db

EXPOSE 3000

CMD supervisord -c /etc/supervisord.conf

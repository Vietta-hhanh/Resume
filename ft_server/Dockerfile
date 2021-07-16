FROM debian:buster

RUN apt update
RUN apt-get -y upgrade
RUN apt -y install nginx
RUN apt -y install wget
RUN apt -y install php7.3-fpm 
RUN apt -y install php7.3-mysql
RUN apt -y install php7.3-xml
RUN apt -y install php7.3-mbstring
RUN apt -y install mariadb-server

EXPOSE 80 443

COPY srcs/script.sh .
COPY srcs/wp-config.php .
COPY srcs/nginx.conf .
COPY srcs/config.inc.php .
COPY srcs/ixch.sh .

CMD bash script.sh
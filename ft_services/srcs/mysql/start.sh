#/bin/sh
mv /etc/my.cnf /my
mv ./my.cnf /etc/
openrc
/etc/init.d/mariadb setup
/etc/init.d/mariadb start
mysql -u root -e "CREATE DATABASE hhanhbase; \
				CREATE USER 'hhanh'@'%' IDENTIFIED BY 'hhanh'; \
				GRANT ALL PRIVILEGES ON hhanhbase.* TO 'hhanh'@'%'; \
				FLUSH PRIVILEGES;" 
mysql hhanhbase < hhanhbase.sql
/etc/init.d/mariadb stop
supervisord -c /etc/supervisord.conf

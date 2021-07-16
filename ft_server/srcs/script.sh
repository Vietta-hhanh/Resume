#!/bin/bash
wget http://wordpress.org/latest.tar.gz
echo WORDPRESS УСПЕШНО СКАЧАН
mkdir hhanh
tar xzvf latest.tar.gz
rm latest.tar.gz
mv wordpress ./hhanh
echo WORDPRESS ПЕРЕМЕЩЕН В ПАПКУ /hhanh
mv wp-config.php ./hhanh/wordpress
wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-english.tar.gz
echo PHPMYADMIN УСПЕШНО СКАЧАН
tar xzvf phpMyAdmin-5.1.0-english.tar.gz
mv phpMyAdmin-5.1.0-english /hhanh/phpmyadmin
rm phpMyAdmin-5.1.0-english.tar.gz
mv config.inc.php /hhanh/phpmyadmin/
echo PHPMYADMIN ПЕРЕМЕЩЕН В ПАПКУ /hhanh
service mysql start
mysql -u root -e "CREATE DATABASE hhanhbase; \
				CREATE USER 'hhanh'@'localhost' IDENTIFIED BY 'hhanh'; \
				GRANT ALL PRIVILEGES ON hhanhbase.* TO 'hhanh'@'localhost'; \
				FLUSH PRIVILEGES;" 
echo БАЗА ДАННЫХ УСПЕШНО СОЗДАНА
rm /etc/nginx/sites-available/*
rm /etc/nginx/sites-enabled/*
mv nginx.conf etc/nginx/sites-available/hhanh
ln -s /etc/nginx/sites-available/hhanh /etc/nginx/sites-enabled/hhanh
chown -R www-data:www-data /hhanh/wordpress
find /hhanh/wordpress/ -type d -exec chmod 755 {} \;  #rwxr-xr-x
find /hhanh/wordpress/ -type f -exec chmod 644 {} \;  #rw-r--r--
echo Права выданы
mkdir /etc/nginx/ssl
openssl req -newkey rsa:2048 -nodes -keyout /etc/nginx/ssl/hhanh.key -x509 -days 365 \
-subj '/C=RU/ST=Moscow/L=Moscow/O=School21/OU=School21MSC/emailAddress=hhanh@student.21-school.ru/CN=localhost' \
-out /etc/nginx/ssl/hhanh.crt
echo СЕРТИФИКАТ SSL СОЗДАН
service php7.3-fpm start
echo СЕРВЕР NGINX УСПЕШНО ЗАПУЩЕН
nginx -g "daemon off;"
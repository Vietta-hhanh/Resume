#/bin/sh
mv config.inc.php /var/nginx/tmp/phpmyadmin
mv hhanh.conf /etc/nginx/conf.d/
/usr/bin/supervisord -c /supervisord.conf

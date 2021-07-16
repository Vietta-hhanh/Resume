#/bin/sh
mv wp-config.php /var/nginx/tmp
mv hhanh.conf /etc/nginx/conf.d/
find /var/nginx/tmp/wordpress/ -type d -exec chmod 755 {} \;
find /var/nginx/tmp/wordpress/ -type f -exec chmod 644 {} \; 
/usr/bin/supervisord -c /supervisord.conf
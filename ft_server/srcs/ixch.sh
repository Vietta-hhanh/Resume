#!/bin/bash
IX=$1
if [ "$1" == "on" ]
then
sed -i 's/autoindex.*/autoindex '$IX';/' /etc/nginx/sites-available/hhanh
nginx -s reload
echo ЗНАЧЕНИЕ autoindex ИЗМЕНЕНО НА on
elif [ "$1" == "off" ]
then
sed -i 's/autoindex.*/autoindex '$IX';/' /etc/nginx/sites-available/hhanh
nginx -s reload
echo ЗНАЧЕНИЕ autoindex ИЗМЕНЕНО НА off
else
echo НЕПРАВИЛЬНЫЙ АРГУМЕНТ
fi
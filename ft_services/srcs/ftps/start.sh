#/bin/sh
rm etc/vsftpd/vsftpd.conf
mv vsftpd.conf etc/vsftpd/
supervisord -c /etc/supervisord.conf



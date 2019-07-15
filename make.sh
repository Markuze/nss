NAME=cbn

#nss:
rm -f /tmp/*

gcc -fPIC -shared -o libnss_$NAME.so.2 -Wl,-soname,libnss_$NAME.so.2 cbn_nss.c

sudo install -m 0644 libnss_$NAME.so.2 /lib
sudo /sbin/ldconfig -n /lib /usr/lib


#--------------- TESTING ----------------------
md5sum /lib/libnss_cbn.so.2 ./libnss_cbn.so.2

cp nss_test.sh /tmp/nss_test.sh
strace getent passwd &> /tmp/log_pwd
strace getent passwd `whoami` &> /tmp/log_name
cat /tmp/test.log

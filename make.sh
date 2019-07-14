NAME=cbn

#nss:
gcc -fPIC -shared -o libnss_$NAME.so.2 -Wl,-soname,libnss_$NAME.so.2 cbn_nss.c

sudo install -m 0644 libnss_$NAME.so.2 /lib
sudo /sbin/ldconfig -n /lib /usr/lib
md5sum /lib/libnss_cbn.so.2 ./libnss_cbn.so.2

cp nss_test.sh /tmp/nss_test.sh
strace getent passwd `whoami` &> /tmp/log
cat /tmp/test.log

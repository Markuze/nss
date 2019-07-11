NAME=cbn

#nss:
gcc -fPIC -shared -o libnss_$NAME.so.2 -Wl,-soname,libnss_$NAME.so.2 cbn_nss.c

sudo install -m 0644 libnss_$NAME.so.2 /lib
sudo /sbin/ldconfig -n /lib /usr/lib
cp nss_test.sh /tmp/nss_test.sh

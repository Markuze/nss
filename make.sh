NAME=cbn_nss

#nss:
gcc -fPIC -shared -o libnss_$NAME.so.2 -Wl,-soname,libnss_$NAME.so.2 $NAME.c

sudo install -m 0644 libnss_$NAME.so.2 /lib
sudo /sbin/ldconfig -n /lib /usr/lib


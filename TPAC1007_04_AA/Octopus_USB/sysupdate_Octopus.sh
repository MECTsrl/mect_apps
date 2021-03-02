#!/bin/sh

TARGET=`awk '{if ($1=="Target:") print $2}' /rootfs_version`

echo 100 > /sys/devices/platform/mxs-bl.0/backlight/mxs-bl/brightness

usbdev=/dev/sda
test -e /sys/block/sda/sda1 && usbdev=/dev/sda1
mntpoint=/mnt/floppy
mkdir -p $mntpoint
mount -o sync $usbdev $mntpoint

mntdir=$mntpoint/$TARGET
mkdir -p $mntdir/data
mkdir -p $mntdir/control
mkdir -p $mntdir/etc/sysconfig
mkdir -p $mntdir/root/.ssh

cd /local
rm -f data
rm -f control
rm -f etc
rm -f root

ln -s $mntdir/data    data
ln -s $mntdir/control control
ln -s $mntdir/etc     etc
ln -s $mntdir/root    root

# empty data

# empty control

# etc
echo '
BOOTPROTO0="[none]"
IPADDR0=192.168.5.211
NETMASK0=255.255.255.0
GATEWAY0=192.168.5.10
NAMESERVER01=8.8.8.8
NAMESERVER02=8.8.4.4
' > $mntdir/etc/sysconfig/net.conf
echo '
nameserver 8.8.8.8
nameserver 8.8.4.4
' > $mntdir/etc/resolv.conf
echo '
echo 70 > /sys/devices/platform/mxs-bl.0/backlight/mxs-bl/brightness
' > $mntdir/etc/sysconfig/brightness
echo '[NTP-Server]
serverName=tempo.ien.it
serverOffset=1
serverPeriod=1
serverTimeOut=10' > $mntdir/etc/sysconfig/ntp.ini
/etc/rc.d/init.d/network restart

# root
echo 'ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDGeu4dBYgKfVmHgAbWlU4mOmUiWaGWkp1SrhE3C1mtKUk4QR/LcvtSmLAFxxFwgpPwXkcn8OyFRmqUsN/9p1wHeLTTFCPwMuTTbOuU9pYzcaX4DB6xnaKgESILVbOnnQIk9Dri+JdQxEyOf9hOjD50DRZyIfa0T1fA1yg8P5hZAk8IXEFIlqoVt8/SVCcdjsVx/pLMT3u39ZLcJu/y90waer0oblfMsM+21LesztH+UjLgm/Eupy/m5EtyW5HKfYJ7jZD7c0yIg10bQe6lbX1aDGYDsGWsF79o/CG7HqKX6MZbUn/S1hO0aeoxinwr6hbJyexnUx7oB+mXJSfSps61 root@vpndev.vpn-smily.com
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAACAQDG1i2RQG1JuB1rV7NewZ5PJjxAryC8/NzQHqhJBgL/vdD/y1nV++wCJzFKV8vQEs4tTP0u0orUUJfnzmY7VKNiC0UKb9XXg8b0hx1EYfEajmNIi2BM8gY0hPGywehPgTUqw21jXtOT9Fg6l/1GsOkfUjnYhLrrIAV4LMxBWO+yJSrBNZdt4D5TKjT77PysrJGi0HpFK66ZxgNnZAJme23pDEuwho8kWK0cTuiqnwjpbDNwZBCgnQb70mDdxVNzyYzXcCzkYeuI/LKMTapjqei8W6nxCmsEJCT7dhPloU5fBpgidFH9HGmFg3H1bJAbgWv/nvS2XF8Xfwp/41VoedgEqnQJjbVHjCewaxlsyCIV/efg0RBYh5pvkaO5uvh/BoBX3FHba4GzNlAuHtfYjm3kynVYmDhKg6Q7aR1GUGQ6nU6aunxRubqwwZyUwt6F0AwLeYN0/VHxiaQ4z8aI9+CdO69HZ79+kNPSfr1tahxsuOtfK6AGak3U9ORtwFDPZKwGN7IS8XX5H7+t0lLX420Gge7JeIOzG2wSgajGFGY0qmwZ2G7uF3H/Z2m62npIQvmVe1mIi7BKPf3bcckHEuyiOJ0vazfXHbwGcgjs1v8s/4cOf++yws8dh1Qsh/NM+I2S3PE3sdXs0+aGOyk7suoZe6vww+/lCLxFieeICN3L4w== jolly_key' > $mntdir/root/.ssh/authorized_keys
chmod 700 $mntdir/root/.ssh
chmod 600 mntdir/root/.ssh/authorized_keys
ln -s /usr/bin/fcrts $mntdir/root/fcrts

killall splash
/etc/rc.d/init.d/autoexec start >/dev/null 2>&1

read


#!/bin/bash

if [[ $EUID -ne 0 ]]; then
	echo "This Script Requires ROOT Access"
	exit 1
fi

echo " "
echo "Installing OpenSSH-Server"
echo "*************************************************************************"
apt-get install openssh-server -y

PORT_NUMBER="7171"

# Save last copy of original ssh daemon config file (sshd_config)
cp /etc/ssh/sshd_config /etc/ssh/saved_sshd_config

# Search'n Replace String that contains Port for PORT_NUMBER
sed -i "s/Port .*/Port $PORT_NUMBER/g" /etc/ssh/sshd_config

echo "Default Port changed to: $PORT_NUMBER"

# Restart SSH
/etc/init.d/ssh restart

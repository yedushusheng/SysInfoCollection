#/bin/bash
lspci -nn | grep USB > /opt/sys_info/pci_usb.info
lspci -nn | grep Ether > /opt/sys_info/pci_eth.info
lspci -nn | grep VGA > /opt/sys_info/pci_vga.info

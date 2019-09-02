import spidev
import time
import datetime
import os

spi1=spidev.SpiDev()
spi2=spidev.SpiDev()

spi1.open(0,0)
spi2.open(0,1)

time0 = time.time()
date  = datetime.datetime.now()

fname_first = "/root/" + os.uname()[1] + "_rawdata_" \
                       + date.strftime("%Y-%m-%dT%H:%M:%S") + ".dat"

tid0       = time.time()
first_run  = True
first_file = True
fname      = ""

while True:

	d1=spi1.xfer([0b00010000, 0x0, 0x0])
	d2=spi1.xfer([0b00010001, 0x0, 0x0])
	
	x=( d1[1] << 8 ) + d1[2] >> 5
	y=( d2[1] << 8 ) + d2[2] >> 5
	
	a1=(x-y)/6554.0
	
	d1=spi2.xfer([0b00010000, 0x0, 0x0])
	d2=spi2.xfer([0b00010001, 0x0, 0x0])
	
	x=( d1[1] << 8 ) + d1[2] >> 5
	y=( d2[1] << 8 ) + d2[2] >> 5
	
	a2=(x-y)/6554.0
	
	time1 = time.time()
	elap = time1-time0
	time0 = time1
	
	dstr="%10.5f" % elap + "\t" + "%10.5f" % a1 \
	+ "\t" + "%10.5f" % a2
	
	fname_old = fname
	
	fname = "/home/test/" + os.uname()[1] + "_rawdata_" \
	+ "%4.4i" % date.year + "-" + "%2.2i" % date.month \
	+ "-" + "%2.2i" % date.day + "T" \
	+ "%2.2i" % date.hour + ":00:00.dat"

	if fname == fname_old:
	
		if first_file:
			f = open(fname_first,"a")
		else:
			f = open(fname,"a")
		else:
			if first_file:
				f = open(fname_first,"w")
			else:
				f = open(fname,"w")
			
			f.write("%site_name:'"+os.uname()[1]+"'"+"\n")
			f.write("%timezone:'" \
			+ file("/etc/timezone").read().split("\n")[0] \
			+ "'"+"\n")
			
		f.write(dstr + "\n")
		f.close()
		print dstr

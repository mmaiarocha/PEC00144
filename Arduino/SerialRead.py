import sys
import serial
import numpy  as np
import pandas as pd

#==============================================================================

def readcell():

    err = True
    Ardn.write(b'0')

    while(err):
        try:
            if (Ardn.inWaiting() >= 27):
                bdat = Ardn.readline() 
                sdat = bdat.decode()
                err  = False
        except:
            err = True

    print(sdat)
    sdat = sdat.replace('\n',' ').split()
    return  np.array(sdat[0:3], dtype='uint32')

#==============================================================================
# 1. Acquisition configuration
#------------------------------------------------------------------------------
port  = '/dev/ttyUSB0'
baud  =  9600
Ardn  =  serial.Serial(port, baud, timeout=1)

n     =  8
D     =  np.empty((3,n), dtype='uint32')

#==============================================================================
# 2. Acquisition
#------------------------------------------------------------------------------
try:
    for i in  range(n):
        D[0,i], D[1,i], D[2,i] = readcell()

    Ardn.close()
    print('Acquisition ok!')

except:
    Ardn.close()
    sys.exit('Acquisition failure!')

#==============================================================================
# 3. Save data
#------------------------------------------------------------------------------
data      =  pd.DataFrame(data = D.T)
filename  = 'ReadSerial.xlsx'
excelfile =  pd.ExcelWriter(filename)

data.to_excel(excelfile,filename)
excelfile.save()

#==============================================================================

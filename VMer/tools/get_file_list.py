import os
import getopt
import sys
fp=open(sys.argv[2],"w")
for file_name in os.listdir(sys.argv[1]) :
	fp.write(file_name)
	fp.write('\n')
fp.close()
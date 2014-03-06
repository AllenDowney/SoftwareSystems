"""This file contains code for use with "Think Stats",
by Allen B. Downey, available from greenteapress.com

Copyright 2014 Allen B. Downey
License: GNU GPLv3 http://www.gnu.org/licenses/gpl.html
"""

import sys
import thinkstats2
import thinkplot

def read_file(filename):
    t = []
    for line in open(filename):
        x = float(line.rstrip())
        t.append(x)
    return t

def main(script, filename='data'):
    t = read_file(filename)
    cdf = thinkstats2.MakeCdfFromList(t)
    thinkplot.Cdf(cdf)
    thinkplot.Show()

if __name__ == '__main__':
    main(*sys.argv)

print 'int reverse1[] = {'
for i in range(64):
    s = bin(i)[2:].zfill(6)
    print '%d,' % int(s[::-1], 2),
print '};'

print 'int reverse2[] = {'
for i in [0, 2, 1, 3]:
    print '%d,' % (i * 64),
print '};'


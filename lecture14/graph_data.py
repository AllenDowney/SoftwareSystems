import thinkplot

d = {}
for line in open('data'):
    t = line.split()
    size, stride, time = int(t[1]), int(t[3]), float(t[5])
    d.setdefault(stride, []).append((size, time))


thinkplot.PrePlot(num=7)
for stride in sorted(d.keys()):
    if stride >= 512: continue

    xs, ys = zip(*d[stride])
    thinkplot.plot(xs, ys, label=str(stride))
    print stride, len(d[stride])

thinkplot.show(xscale='log')

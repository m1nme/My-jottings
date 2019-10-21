from __future__ import print_function
import psutil
def cpuinfo():
    dict_temp = {}
    with open('/proc/cpuinfo') as f:
        for line in f:
            line = line.strip()
            if len(line.split(':')) == 2:
                dict_temp[line.split(':')[0].strip()] = line.split(':')[1].strip()
            else:
                dict_temp [line.split(':')[0].strip()] = ''
    return dict_temp
if __name__ == '__main__':
    cpuinfo = cpuinfo()
    Kcpuinfo = list(cpuinfo.keys())
    Vcpuinfo = list(cpuinfo.values())
    cpucores = Vcpuinfo[Kcpuinfo.index('cpu cores')]
    fpu_exception = Vcpuinfo[Kcpuinfo.index('fpu_exception')]
    modelname = Vcpuinfo[Kcpuinfo.index('model name')]
    flags = Vcpuinfo[Kcpuinfo.index('flags')]
    cpuMHz = Vcpuinfo[Kcpuinfo.index('cpu MHz')]
    cachesize = Vcpuinfo[Kcpuinfo.index('cache size')]

    seconds = psutil.boot_time()
    m, s = divmod(seconds, 60)
    h, m = divmod(m, 60)
    print("CPU名称: %s"%(modelname))
    print("CPU核心数: %s" % (cpucores))
    print("CPU二级缓存数: %s" % (cachesize))
    print("CPU当前主频: %sMHz" % (cpuMHz))
    print("CPU特性: %s" % (flags))
    print("系统已启动时长： %02d小时 %02d分钟 %02d秒" % (s, m, h))
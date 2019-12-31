import os
import re
class Net:
    port = 0
    mac  = 0
    name = 0
    def __init__(self,port,mac,name):
        self.name = name
        self.mac = mac
        self.port = port
def set(wlanport,lanport):
    print("0x01 清除原来路由表")
    try:
        p = os.system("route delete 0.0.0.0")
    except:
        print("失败")
    print("0x02 默认网络走无线网络的接口")
    cmd = "route add 0.0.0.0 mask 0.0.0.0 192.168.43.1 metric 1 if " + wlanport
    try:
        p = os.system(cmd)
    except:
        print("失败")
    print("0x03 配置比赛内网的网段走有线端口")
    cmd = "route add 10.0.10.0 mask 255.255.255.0 10.0.10.254 metric 3 if " + lanport
    try:
        p = os.system(cmd)
    except:
        print("失败")
    cmd = "route add " + local_addr + " mask 255.255.255.0 10.0.10.254 metric 3 if " + lanport
    try:
        p = os.system(cmd)
    except:
        print("失败")
def LAN(List):
    for i in List:
        matchObj = re.search(r'GbE Family Controller', i.name)
        if matchObj:
            print("成功 :")
            print("LAN :" + i.name)
            return i.port
    return 0
def WLAN(List):
    for i in List:
        matchObj = re.search(r'Realtek RTL', i.name)
        if matchObj:
            print("成功 :")
            print("WLAN :" + i.name)
            return i.port
    for i in List:
        matchObj = re.search(r'Intel(R) Wireless', i.name)
        if matchObj:
            print("成功 :")
            print("LAN :" + i.name)
            return i.port
    return 0
def hand(local_addr,List):
    wlanport = input("请输入无线网卡端口号 ：")
    lanport  = input("请输入有线网卡端口号 ：")
    set(wlanport, lanport)
def auto(local_addr,List):
    print("尝试自动判断无线网卡")
    wlanport = WLAN(List)
    if wlanport == 0:
        print("无法自动匹配，切换到手动模式")
        hand(List)
    print("尝试自动判断有线网卡")
    lanport = LAN(List)
    if lanport == 0:
        print("无法自动匹配，切换到手动模式")
        hand(List)
    set(wlanport,lanport)
def init():
    #ipc = os.popen("ipconfig")
    rp = os.popen("route print")
    List = []
    end = []
    flag = int(0)
    for i in rp:
        if flag == 1 and i == "===========================================================================\n":
            break
        if flag == 1:
            List.append(i[:-1])
        if i == "接口列表\n":
            flag = 1
    print("网卡列表：")
    for i in List:
        print(i)
        matchObj = re.search(r'(^( )*[0-9]+)*', i)
        matchObj = matchObj.group().replace(" ", "")
        port = matchObj
        matchObj = re.search(r'(\.\.\.)(.*)(\.\.\.\.\.\.)', i)
        matchObj = matchObj.group(2).replace(" ", "")
        mac = matchObj
        matchObj = re.search(r'(\.\.\.\.\.\.)(.*)', i)
        matchObj = matchObj.group(2)
        name = matchObj
        N = Net(port,mac,name)
        end.append(N)
    return end
if __name__ == '__main__':
    List = init()
    local_addr = input("内网平台地址：")
    matchObj = local_addr.split(".")
    matchObj[0] = matchObj[0] + '.'
    matchObj[1] = matchObj[1] + '.'
    matchObj[2] = matchObj[2] + '.'
    matchObj[3] = '0'
    local_addr = ""
    for i in matchObj:
        local_addr += i
    print("内网网段："+local_addr)
    print("尝试自动模式")
    auto(local_addr,List)
#重置路由命令 netsh int ipv4 reset

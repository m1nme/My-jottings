from datetime import datetime
class retxt:
    Mlist = []
    def __init__(self):
        with open('mailAD.txt', 'r') as f1:
            list1 = f1.readlines()
            self.WrLog("读取网页列表成功！")
        for i in range(0, len(list1)):
            self.Mlist.append(list1[i].rstrip('\n'))
            #print(self.Mlist[i])

    def WrLog(self,str2):
        dt = datetime.now()
        str1 = dt.strftime('%Y-%m-%d %H:%M:%S %f')
        str1 = str1  + "  " + str2 + "\n"
        with open('log.txt', 'a') as f:
            f.writelines(str1)
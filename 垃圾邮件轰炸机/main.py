import mail
import crawler
import ReadAD
import threading
import time
from datetime import datetime

class myThread (threading.Thread):
    addr = ""
    def __init__(self, addr):
        threading.Thread.__init__(self)
        self.addr = addr
    def run(self):
        print ("开始线程：" + self.name)
        senthread(self.addr)
        print ("退出线程：" + self.name)

def sentmail():
   while 1:
      time.sleep(1)
      a = ReadAD.retxt()
      for i in a.Mlist:
          try:
              print(i)
              threadT = myThread(i)
              threadT.start()
              #thread1.join()
          except:
              print("Error: 无法启动线程")

def senthread(addr):
    print(addr)
    b = crawler.GetAD(addr)
    c = mail.SentMail(b.ShowAdd())

if __name__ == '__main__':
    with open('log.txt', 'w') as f:
        dt = datetime.now()
        str1 = dt.strftime('%Y-%m-%d %H:%M:%S %f')
        str2 = str1 + " 轰炸机起飞呼~~~~~~~~~~"
        f.writelines(str2)
    sentmail()
    while 1:
        pass
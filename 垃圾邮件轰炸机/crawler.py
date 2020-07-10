import urllib.request
import re
from datetime import datetime

class GetAD:
    _Add = ""
    _URL = ""
    _HTM = b''
    def __init__(self,url):
        self._URL = url
        self._HTM = self.getHtml()
        self.Remod()

    def getHtml(self):
        page = urllib.request.urlopen(self._URL)
        html = page.read()
        return html

    def Remod(self):
        if re.match(r'^[0-9a-zA-Z_]{0,19}@[0-9a-zA-Z.]{1,13}\.[com,cn,net]{1,3}$',self._HTM.decode('utf-8')):
            c = re.compile(r'^[0-9a-zA-Z_]{0,19}@[0-9a-zA-Z.]{1,13}\.[com,cn,net]{1,3}$',re.I)
            self._Add = c.search(self._HTM.decode('utf-8')).group()
            str1 = "Email address is Right! " + "The Email address is " + str(self._Add)
            print(str1)
            self.WrLog(str1)
        else:
            str1 = 'Can\'t match Email address!'
            print(str1)
            self.WrLog(str1)

    def WrLog(self,str2):
        dt = datetime.now()
        str1 = dt.strftime('%Y-%m-%d %H:%M:%S %f')
        str1 = str1  + "  " + str2 + "\n"
        with open('log.txt', 'a') as f:
            f.writelines(str1)

    def ShowAdd(self):
        return self._Add
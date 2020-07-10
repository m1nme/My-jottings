import smtplib
from email.mime.text import MIMEText
from email.header import Header
from datetime import datetime

class SentMail:
    _data = ""
    def __init__(self, data):
        self._data = data
        self.mail2()

    def mail2(self):
        dt = datetime.now()
        str1 = dt.strftime('%Y-%m-%d %H:%M:%S %f')
        # 发信方的信息：发信邮箱，QQ 邮箱授权码
        from_addr = 'xxxxxxxx@qq.com'
        password = 'xxxxxxxxx'
        # 收信方邮箱
        to_addr = self._data
        # 发信服务器
        smtp_server = 'smtp.xxxxxx.com'
        # 邮箱正文内容，第一个参数为内容，第二个参数为格式(plain 为纯文本)，第三个参数为编码
        msg = MIMEText(str1+" send by xxxxxx ", 'plain', 'utf-8')
        # 邮件头信息
        msg['From'] = Header('xxxxxxxxx')
        msg['To'] = Header(to_addr)
        msg['Subject'] = Header(self._data)
        try:
            # 开启发信服务，这里使用的是加密传输
            server = smtplib.SMTP_SSL(smtp_server)
            server.connect(smtp_server, 465)
            # 登录发信邮箱
            server.login(from_addr, password)
            # 发送邮件
            server.sendmail(from_addr, to_addr, msg.as_string())
            # 关闭服务器
            server.quit()
            str1 = "邮件发送成功 发送地址邮箱地址为： " + to_addr
            self.WrLog(str1)
        except smtplib.SMTPException:
            str1 = "Error: 无法发送邮件 " + to_addr
            self.WrLog(str1)

    def WrLog(self,str2):
        dt = datetime.now()
        str1 = dt.strftime('%Y-%m-%d %H:%M:%S %f')
        str1 = str1  + "  " + str2 + "\n"
        with open('log.txt', 'a') as f:
            f.writelines(str1)

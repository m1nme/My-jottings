import json
import ast
import webbrowser
import sys
import time
import os
import sys
from win10toast import ToastNotifier
class Course:
    name = ""
    data = {}
    url = ""
    def __init__(self, name, data, url):
        self.name = name
        self.url = url
        self.data = data
def Check(t1,t2,num):
    if num >= t1 and num <= t2:
        var = 0
    else:
        print('>=',t1,", <=",t2)
        sys.exit(0)
def loadFont(): #打开json
    f = open("params.json", encoding='utf-8')
    params = json.load(f)
    return params
def ToJSON(Courses):
    jsonl = []
    for i in Courses:
        Course = i
        jsons = {}
        jsons["name"] = Course.name
        jsons["data"] = Course.data
        jsons["url"] = Course.url
        json1 = json.dumps(jsons)
        jsonl.append(json1)
    jsons["json"] = jsonl
    jsonl = json.dumps(jsons)
    with open('params.json', 'w') as f:  # 创建一个params.json文件
        f.write(jsonl)  # 将json_str写到文件中
def ExJson():  #解析json
    params = loadFont()
    list = params["json"]
    tmp  = []
    for i in list:
        user_dict = ast.literal_eval(i)
        Courses = Course(user_dict["name"], user_dict["data"], user_dict["url"])
        tmp.append(Courses)
    return tmp
def NOTICE(str):
    toaster = ToastNotifier()
    toaster.show_toast(u'开课了！'+str, u'还点开通知不去上课！')
def Open(URL):
    sys.path.append("libs")
    webbrowser.open(URL)
def IN():
    Courses = []
    num = int(input("请输入课程总数："))
    for i in range(num):
        name = input("请输入课程名称：")
        url  = input("请输入课程地址：")
        cnum = int(input("请输入一周课程天数："))
        Check(1,7,cnum)
        data = {}
        for j in range(cnum):
            week = int(input("请输入星期（阿拉伯数字）："))
            Check(1,7,week)
            time = int(input("请输入开始时间（24）："))
            Check(0,24,time)
            data[week] = time
        Course1 = Course(name, data, url)
        Courses.append(Course1)
    ToJSON(Courses)
def Clean():
    f = open('params.json', "r+")
    f.truncate()
def Run():
    Courses = ExJson()
    while 1:
        today = time.strftime("%u")
        time1  = int(time.strftime("%H"))
        for i in Courses:
            if time1 == i.data[today]:
                NOTICE(i.name)
                Open(i.url)
        time.sleep(60)
if __name__ == '__main__':
    way = input("请选择（1）输入模式（2）清空输入（3）开始运行：")
    if way == "1":
        IN()
    elif way == "2":
        Clean()
    elif way == "3":
        Run()
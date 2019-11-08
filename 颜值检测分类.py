import base64
import os
import shutil
import time
import re
from aip import AipFace

# 配置百度aip参数
APP_ID = 'xxxxxxx'
API_KEY = 'xxxxxxxxx'
SECRET_KEY = 'xxxxxxxxxxx'
a_face = AipFace(APP_ID, API_KEY, SECRET_KEY)
image_type = 'BASE64'

options = {'face_field': 'age,gender,beauty'}

listfilepath = []
MEN = "./MAN"
WOMEN = "./WOMEN"
BESTMAN = "./BEST/MEN"
BESTWOMEN = "./BEST/WOMEN"
PICTUREPATH = "./picture"
def get_file_content(file_path):
    with open(file_path, 'rb') as fr:
        content = base64.b64encode(fr.read())
        return content.decode('utf8')

def listdir(path, list_name):  # 传入存储的list
    for file in os.listdir(path):
        file_path = os.path.join(path, file)
        if os.path.isdir(file_path):
            listdir(file_path, list_name)
        else:
            list_name.append(file_path)

def face_score(file_path):
    """脸部识别分数"""
    reslist = [] #0:age,1:score,2：gender
    result = a_face.detect(get_file_content(file_path), image_type, options)
    #print(result)
    age = result['result']['face_list'][0]['age']
    reslist.append(age)
    beauty = result['result']['face_list'][0]['beauty']
    reslist.append(beauty)
    gender = result['result']['face_list'][0]['gender']['type']
    reslist.append(gender)
    return  reslist

def delpath(path):
    for i in os.listdir(path):
        path_file = os.path.join(path, i)
        if os.path.isfile(path_file):
            os.remove(path_file)
        else:
            for f in os.listdir(path_file):
                path_file2 = os.path.join(path_file, f)
                if os.path.isfile(path_file2):
                    os.remove(path_file2)

if __name__ == '__main__':
    delpath(MEN)
    delpath(WOMEN)
    delpath(BESTMAN)
    delpath(BESTWOMEN)
    listdir(PICTUREPATH,listfilepath)
    max = 0.0
    maxname = ""
    beautiful = []
    tmplist = []
    count = 0
    print("Total Number is : ",len(listfilepath))
    for i in listfilepath:
        bestlist = []
        time.sleep(0.3)
        tmplist = face_score(i)
        searchObj = re.search(r'\\(.*).jpg', i, re.M | re.I)
        if tmplist[1] >= max:
            max = tmplist[1]
            maxname = searchObj.group(1)
        if tmplist[1] >= 70:
            bestlist.append(searchObj.group(1))
            bestlist.append(tmplist[1])
            beautiful.append(bestlist)
            if tmplist[2] == "female":
                shutil.copy(i,BESTWOMEN)
            if tmplist[2] == "male":
                shutil.copy(i,BESTMAN)
        if tmplist[2] == "female":
            shutil.copy(i,WOMEN)
        if tmplist[2] == "male":
            shutil.copy(i, MEN)
        count = count + 1
        print(searchObj.group(1)," : ",tmplist[1]," REMAINDER : ",(len(listfilepath)-count))
    print("maxscore : ",max)
    print("maxnum : ",maxname)
    print("This is the 70 score:")
    for i in  beautiful:
        print(i[0],i[1])

#精准打击版本
import requests
import time
adress="http://59.77.226.32/xszp/"
grade = ""
error = ""
def download_img(img_url,num):
    print(num,end="")
    r = requests.get (img_url,stream=True)
    tmpstr = str(num)+".jpg"
    if r.status_code == 200 and r.content!=error:
        open(tmpstr, 'wb').write(r.content)
        print(" Download Successful",end="")
    print("")
    del r
if __name__ == '__main__':
    r = requests.get("http://59.77.226.32/xszp/18/000000000.jpg")
    error = r.content
    del r
    school = input("请输入学院号：")
    grade = input("请输入年段:")
    word = input("请输入专业代码:")
    img_url = adress + grade+"/"
    flag = 0
    line1 = []
    line2 = []
    tmpstr2 = str(school)+str(grade)+str(word)
    for i in range(1,8):
        tmpstr3 = tmpstr2 + str(i)
        for j in range(1,60):
            tmpstr4 = ""
            if len(str(j)) != 2:
                kb = 2 - len(str(j))
                for k in range(kb):
                    tmpstr4+=str(0)
            tmpstr4+=str(j)
            tmpstr5 = tmpstr3+tmpstr4
            tmpurl = img_url + tmpstr5+".jpg"
            line1.append(tmpurl)
            line2.append(tmpstr5)
    for i in range(len(line1)):
        time.sleep(0.1)
        #if i%50 == 0:
            #time.sleep(2)
        download_img(line1[i],line2[i])
    print("All DownLoad!")

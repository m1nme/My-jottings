#全校版爬虫网路容易赌赛，建议配合sleep使用
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
    # 下载要的图片
    r = requests.get("http://59.77.226.32/xszp/000000000.jpg")
    error = r.content
    del r
    grade = input("请输入年段:")
    img_url = adress + grade+"/"
    flag = 0
    line1 = []
    line2 = []
    count = 0
    for i in range(1,29):
        tmpstr1 = ""
        if len(str(i)) != 2:
            kb = 2 - len(str(i))
            for j in range(kb):
                tmpstr1 += str(0)
        tmpstr1+=str(i)
        tmpstr2 = tmpstr1+str(grade)
        for j in range(1, 29):
            tmpstr3 = ""
            if len(str(j)) != 2:
                kb = 2 - len(str(j))
                for k in range(kb):
                    tmpstr3 += str(0)
            tmpstr3 += str(j)
            tmpstr4 = tmpstr2 + tmpstr3
            for k in range(1,8):
                tmpstr4 = tmpstr4+str(k)
                for j in range(1,60):
                    tmpstr5 = ""
                    if len(str(j)) != 2:
                        kb = 2 - len(str(j))
                        for  l in range(kb):
                            tmpstr5+=str(0)
                    tmpstr5+=str(j)
                    tmpstr6 = tmpstr4+tmpstr5
                    tmpurl = img_url + tmpstr6+".jpg"
                    line1.append(tmpurl)
                    line2.append(tmpstr6)
    for i in range(len(line1)):
        time.sleep(0.5)
        if i%50 == 0:
            time.sleep(2)
        download_img(line1[i],line2[i])
    print("All DownLoad!")

import subprocess
import re
import os
import requests
def clone(url):#CheckClone
    repoFolderRegex = re.compile(r'.*/(.*?)\.git')
    folderName = repoFolderRegex.search(url).group(1)
    if os.path.exists(folderName):
        print('{} has been cloned successfully before!'.format(folderName))
        print('Skipping this repo/gist.\n')
        return
    subprocess.call(['git', 'clone', url])
if __name__ == '__main__':
    usrname = input("Please  usrname:")
    model = input("starred or repos:")
    api_url = "https://api.github.com/users/"+usrname+"/"+model
    print(api_url)
    path = os.listdir(os.getcwd())
    all_info = requests.get(api_url).json()
    first_dic = {}
    starred_clone_url = []
    for i in all_info:
        if i['name'] not in path:
            first_dic[i['id']] = i['updated_at']
            starred_clone_url.append(i['clone_url'])
    for i in starred_clone_url:
        clone(i)
    print(first_dic)

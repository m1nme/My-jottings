import random
import string
import os
import re
#默认关键词表
cpp_keyword = ['cout', '+=', '-=', 'int ', 'goto', 'asm', 'do', 'if', '[', ']',
                'return', 'typedef', 'auto', 'double', 'inline', '{', '}',
                'short', 'typeid', 'bool', 'int ', '(', ')',
                'signed', 'typename', 'break', 'else', '&gt;=', '&lt;=',
                'sizeof', 'union', 'case', 'enum', 'mutable', ';',
                'static', 'unsigned', 'catch', 'explicit', 'try',
                'namespace', 'using', 'char', 'main', 'const',
                'export', 'new', 'struct', 'class', 'switch',
                'false', 'private', 'long', '::', 'void', 'endl',
                'float', 'protected', 'this', 'continue', '++', '--',
                'for', 'public', 'throw', 'while', 'default', 'friend',
                'true', '&lt;&lt;', 'cin', 'printf', '==', '&gt;&gt;', '!=', ]

def random_char():
    r = chr(random.randint(97, 122))
    char, char_r, list_chr = [], [], []
    for i in range(len(cpp_keyword)):
        char.append(r + str(i))
        char_r.append(cpp_keyword[i])
    random.shuffle(char)
    random.shuffle(char_r)
    for i in range(len(char)):
        list_chr.append([char[i], char_r[i]])
    return list_chr

def generate_define(list_chr):
    define = []
    for i in range(len(list_chr)):
        define.append('#define ' + list_chr[i][0] + ' ' + list_chr[i][1])
    return define

def replace(list_char, str):
    confusion = ' /*' + ''.join(random.sample(string.hexdigits, 6)) + '*/ '
    for i in list_char:
        if i[1] in str:
            str = str.replace(i[1], confusion + i[0] + confusion)
    return str

def open_file(list_char,file):
    filenmae = file.split('.')[0] + '_re.cpp'
    with open(file, 'r') as f:
        with open(filenmae, 'w') as m:
            define = generate_define(list_char)
            for i in define:
                m.write(i + '\n')
            for i in f.readlines():
                if '#' in i[0]:
                    m.write(i)
                    continue
                i = i.strip()
                i_replace = replace(list_char, i)
                m.write(i_replace + '\n')
            print("THE MIXED FILE NAME IS : ",filenmae)
if __name__ == '__main__':
    file_list = []
    for g in os.listdir():
        tmp = re.search( r'\.cpp', g, re.M|re.I)
        if tmp :
            file_list.append(g)
            continue
        tmp = re.search(r'\.c', g, re.M | re.I)
        if tmp :
            file_list.append(g)
    print("Total File num : ",len(file_list))
    for i in file_list:
        print("MIXED : ",i)
        open_file(random_char(),i)
    print("All Mixed")

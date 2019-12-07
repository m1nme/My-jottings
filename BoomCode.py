import codecs
def decode(path,codes):
    with codecs.open(path, 'rb') as input_file:
        return input_file.read().decode(codes)
Codes = [ 'ascii', 'big5', 'big5hkscs','cp037', 'cp273', 'cp424','cp437', 'cp500', 'cp720', 'cp737', 'cp775', 'cp850', 'cp852', 'cp855', 'cp858', 'cp860', 'cp861', 'cp862', 'cp863', 'cp865', 'cp866', 'cp870', 'cp875', 'cp1026', 'cp1047', 'cp1140', 'cp1141', 'cp1142', 'cp1143', 'cp1144', 'cp1145', 'cp1146', 'cp1147', 'cp1148', 'cp1149', 'cp1256' 'cp1257', 'cp1258', 'euc_jp', 'euc_jis_2004', 'euc_jisx0213', 'euc_kr', 'gb2312', 'gbk', 'gb18030', 'hz', 'iso2022_jp', 'iso2022_jp_1', 'iso2022_jp_2', 'iso2022_jp_2004', 'iso2022_jp_3', 'iso2022_jp_ext', 'iso2022_kr', 'latin_1', 'iso8859_2', 'iso8859_3', 'iso8859_4', 'iso8859_5', 'iso8859_6', 'iso8859_7', 'iso8859_8', 'iso8859_9', 'iso8859_10', 'iso8859_11', 'iso8859_13', 'iso8859_14', 'iso8859_15', 'iso8859_16', 'johab', 'koi8_r', 'koi8_t', 'koi8_u', 'kz1048', 'mac_cyrillic', 'mac_greek', 'mac_iceland', 'mac_latin2', 'mac_roman', 'mac_turkish', 'ptcp154', 'shift_jis', 'shift_jis_2004', 'shift_jisx0213', 'utf_32', 'utf_32_be', 'utf_32_le', 'utf_16', 'utf_16_be', 'utf_16_le', 'utf_7', 'utf_8', 'utf_8_sig']
path = "./724c6e962216407fa5fa1ad7efda2653_misc1_flag.txt"
tmpgp = []
str1 = "ctf"
str2 = "flag"
for i in Codes:
    try:
        tmpstr = decode(path,i)
        print(tmpstr)
        tmpgp.append(tmpstr)
    except:
        continue
print("---------------------------------------------------------------")
print("---------------------------------------------------------------")
for i in tmpgp:
    if str1 in i or str2 in i:
        print(i)

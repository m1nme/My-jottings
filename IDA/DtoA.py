from idaapi import *
data = []
model = "db"
str_addr = 0x00413CD2
end_addr = 0x00413D1C
dat = end_addr - str_addr
i = 0
for i in range(dat):
    if model == "db":
        data.append(Byte(str_addr + i))
    if model == "dw":
        data.append(Word(str_addr + i))
    if model == "dd":
        data.append(Dword(str_addr + i))
print data
auto str_addr,end_addr,dat;
str_addr = 0x00413CD2;
end_addr = 0x00413D1C;
dat = end_addr - str_addr;
auto i = 0;
Message("[");
for(i=0;i<dat;i++){ 
    if(i != dat-1)
    {
        Message("%d ,",Byte(str_addr+i));
    }
    else{
         Message("%d",Byte(str_addr+i));
    }
}
Message("]");
//
//      This file is automatically executed when IDA is started.
//      You can define your own IDC functions and assign hotkeys to them.
//
//      You may add your frequently used functions here and they will
//      be always available.
//
//
#include <idc.idc>
//跳转到光标处函数的开头处
static GotoCursorFuncStart()
{
   auto startaddr;
   startaddr=GetFunctionAttr(ScreenEA(),FUNCATTR_START);
   Jump(startaddr);
}
//跳转到光标处函数的结尾处
static GotoCursorFuncEnd()
{
   auto endaddr;
   endaddr=GetFunctionAttr(ScreenEA(),FUNCATTR_END);
   endaddr=FindCode(endaddr,SEARCH_UP);
   Jump(endaddr);
}

//列举指定函数的所有被调非库函数,如果本函数是叶节点非库函数，就加入全局叶函数数组中
static ListCallees(func,arridCallees,arridCnt)
{
      auto name,end,inst,xref,target,calleescnt; 	
      name=Name(func);
      end=GetFunctionAttr(func,FUNCATTR_END);
      calleescnt=0;
      
      for(inst=func; inst<end; inst=FindCode(inst,SEARCH_DOWN|SEARCH_NEXT))//遍历该函数的所有指令
      {
         for(target=Rfirst(inst); target!=BADADDR; target=Rnext(inst,target))//遍历每条指令的from me引用列表
         {  
            xref=XrefType();
            if(xref==fl_CN || xref==fl_CF) //找到了一个调用的目标函数target
	    {
               //如果调用的不是库函数,也不是xy前缀开头的用户改名后的自定义函数
               auto tgtname;
               tgtname=Name(target);
               if( !(GetFunctionFlags(target) & FUNC_LIB) && strstr(tgtname,"xy")!=0 && strstr(tgtname,"XY")!=0 && strstr(tgtname,"Xy")!=0)
               {
                   calleescnt++;
                   //Message("----called %s----\n",name);   
                   ListCallees(target,arridCallees,arridCnt);
               }
	    } 
         }
      }
      if(calleescnt==0)//将本函数放入全局数组中
      {
         auto cnt;
         //Message("%s is a leaf func-------------------------------------------\n",name);
         cnt=GetArrayElement(AR_LONG,arridCnt,0);
         SetArrayLong(arridCallees,cnt,func);
         cnt++;
         SetArrayLong(arridCnt,0,cnt);
      }            
}
//枚举光标处函数最终调用的所有非库、未重命名的叶节点函数
static ListLeafFuns()
{
   auto func,name;
   func=GetFunctionAttr(ScreenEA(),FUNCATTR_START);
   name=Name(func);
   if(func!=-1)
   {
        auto arridCallees,arridCnt,cnt,i,acnt;//callees数组和全局变量元素个数
        arridCallees=GetArrayId("callees");
        if(arridCallees!=-1)
        {
           Message("DeleteArray \"callees\"\n");
           DeleteArray(arridCallees);
        } 
        arridCallees=CreateArray("callees");

        arridCnt=GetArrayId("cnt");
        if(arridCnt!=-1)
        {
           Message("DeleteArray \"cnt\"\n");
           DeleteArray(arridCnt);
        }
        arridCnt=CreateArray("cnt");
        
        SetArrayLong(arridCnt,0,0);//cnt=0
        
        Message("----------------------------------List %s leaf funcs  begin...------------------------------\n",name);
	ListCallees(func,arridCallees,arridCnt);
        cnt=GetArrayElement(AR_LONG,arridCnt,0);  
        //Message("cnt=%d\n",cnt);
        acnt=0;//实际除去重复的函数个数
        for(i=0;i<cnt;i++)
        {
            auto funcaddr,funcname;
            funcaddr=GetArrayElement(AR_LONG,arridCallees,i);
            funcname=Name(funcaddr);
            if(i==0)
            {
               acnt++;
               Message("%s\n",funcname); 
            }                 
            //忽略数组里面前面重复的函数
            else
            {
	        auto j;
                for(j=0;j<i;j++)
                {
		    if(GetArrayElement(AR_LONG,arridCallees,j) == funcaddr)
                       break;
                }
                if(j==i)
                {
                    acnt++;
                    Message("%s\n",funcname); 
                }                  
                
            }
        }
        Message("(sum: %d)\n",acnt);
        Message("----------------------------------List %s lead funcs  finished------------------------------\n",name);
        DeleteArray(arridCallees);
        DeleteArray(arridCnt);
   }
   else
      Warning("There is no func at current cursor"); 
}





//This function is executed when IDA is started.
static main(void)
{
  auto flagline;
  flagline="---------";
  /////////////////////热键任务/////////////////////////////////////////////////////////////////////////////////
  if( AddHotkey("Ctrl+[","GotoCursorFuncStart")!=IDCHK_OK )
     Message("%sAddHotkey Ctrl+[ failed!%s\n",flagline,flagline);
  else
     Message("%sAddHotkey Ctrl+[ succeed!(goto func start)%s\n",flagline,flagline);
     
  if( AddHotkey("Ctrl+]","GotoCursorFuncEnd")!=IDCHK_OK )
     Message("%sAddHotkey Ctrl+] failed!%s\n",flagline,flagline);
  else
     Message("%sAddHotkey Ctrl+] succeed!(goto func end)%s\n",flagline,flagline);

  if( AddHotkey("Shift+Alt+L","ListLeafFuns")!=IDCHK_OK )
     Message("%sAddHotkey Shift+Alt+L(list all unrenamed leaf funcs) failed!%s\n",flagline,flagline);
  else
     Message("%sAddHotkey Shift+Alt+L(list all unrenamed leaf funcs) succeed!(goto func start)%s\n",flagline,flagline);  

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////
  

  // uncomment this line to remove full paths in the debugger process options:
  // SetCharPrm(INF_LFLAGS, LFLG_DBG_NOPATH|GetCharPrm(INF_LFLAGS));
}

//-----------------------------------------------------------------------
// Get name of the current processor

static get_processor_name(void)
{
  auto i,procname,chr;

  procname = "";
  for ( i=0; i < 8; i++ )
  {
    chr = GetCharPrm(INF_PROCNAME+i);
    if ( chr == 0 ) break;
    procname = procname + chr;
  }
  return procname;
}

//-----------------------------------------------------------------------
// Get signed extended 16-bit value
static SWord(ea)
{
  auto v;
  v=Word(ea);
  if ( v & 0x8000 ) v = v | 0xFFFF0000;
  return v;
}

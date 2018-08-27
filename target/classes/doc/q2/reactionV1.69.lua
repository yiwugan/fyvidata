--By @康也好 20180721 Ver 1.69

         


---------------初始化-----------------
SetVariable("keeppill",0)
SetVariable("autologin",0)
SetVariable("mylog",0)
EnableTimer("robot_monitor",false)
EnableTriggerGroup("reaction",false)
EnableTriggerGroup("checkstatus",false)

local trashlist="|Luoyun zhui|Dart|Blade|Fan|Lian|Wan|Tea pot|Axe|Fried chicken leg|Jing|Dagger|Pill|Wineskin|"



function test()
	if string.find(GetVariable("keeplist"),("岁月如风丹"))
	then
		print("Ok")
  else
  	print("fuck")
  end
end



-----------------------Functions---------------------
function checkstatus(str)
	if string.find(trashlist,str)
	then
		Execute("drop "..string.lower(str))
  end  --endif
end  --endfunc

function mylog(str)
  if str ~= "on" and str ~="off"
  then
  	print("mylog指令：mylog [on/off]")
  	return
  else
  	if str == "on"
  	then
  		print("日志功能已打开！")
  		SetVariable("mylog",1)
  		return
    end	--endif
    if str == "off"
  	then
  		print("日志功能已关闭！")
  		SetVariable("mylog",0)
  		return
    end	--endif
  end	--endif

end	--endfunc
function checkitem(itemcn,itemid)                    --check产品
  --print(itemcn,itemid)
	if GetVariable("mylog") == "1"
	then
		file=io.open(GetVariable("logpath").."reaction.txt","a")
		if string.find(GetVariable("keeplist"),itemcn)
		then
			file:write("※※"..itemcn.."("..itemid..")".."       "..os.date().."\n")
	  else
	  	if string.find(GetVariable("otherlist"),itemcn)
	  	then
	  		file:write("※"..itemcn.."("..itemid..")".."       "..os.date().."\n")
	  	else
	  		file:write(itemcn.."("..itemid..")".."       "..os.date().."\n")
	    end  --endif
	  end  --endif
  	file:close()
  end --endif
	if string.find(GetVariable("keeplist"),itemcn)
	then
		--print("是个特殊丹")
		SetVariable("usecoin",1)
		SetVariable("dan",tonumber(GetVariable("dan"))+1)
		SetVariable("dan_total",tonumber(GetVariable("dan_total"))+1)
		if tonumber(GetVariable("dan")) < tonumber(GetVariable("dan_upper"))
		then
		  DoAfterSpecial(0.5,"hp",10)
		  return
		else
			EnableTriggerGroup("reaction",false)
			EnableTriggerGroup("checkstaus",false)
			EnableTimer("robot_monitor",false)
			SetVariable("autologin",0)
	  end  --endif
		return
	end --endif
	
	if string.find(GetVariable("otherlist"),itemcn)
	then
		SetVariable("trash",tonumber(GetVariable("trash"))+1)
		SetVariable("usecoin",0)
		Execute("hp")
		return
	end  --endif
		
	if itemid =="pill"
	then
		Execute("look pill")
		return
	end --endif
	
	--[[
	if string.find(itemcn,"丸") and itemid ~="wan" 
	then
		print("可能是个未知丹药")
		SetVariable("usecoin",1)
		SetVariable("dan",tonumber(GetVariable("dan"))+1)
		DoAfterSpecial(0.5,"hp",10)
		return
  end  --endif
  ]]
  
	SetVariable("trash",tonumber(GetVariable("trash"))+1)
	SetVariable("usecoin",0)
	Execute("hp")
end --endfunc

function reaction(str)   --reaction指令
  if str ~= "restart" and str ~= "stop"
  then
  	print("reaction指令：reaction [restart/stop]")
  	return
	else
	  if str == "restart"
	  then
	  	EnableTriggerGroup("reaction",false)
	  	EnableTriggerGroup("checkstatus",true)
	  	EnableTriggerGroup("init",false)
	  	EnableTrigger("special",false)
	  	SetVariable("lasttime",os.time())
	  	SetVariable("autologin",1)
	  	EnableTimer("robot_monitor",true)
	  	print("炼丹机器人即将重启！")
	  	DoAfterSpecial(2,"i;set 身上物品检查完毕！",10)
	  	return
	  end --endif
	  if str == "stop"
	  then
	  	EnableTriggerGroup("reaction",0)
	  	EnableTimer("robot_monitor",false)
	  	SetVariable("autologin",0)
	  	print("炼丹机器人彻底关闭！")
	  	return
	  end --endif
	  
  end  --endif

end  --endfunc


function init()    --初始化指令,日志及计数器均清零
	SetVariable("dan",0)
	SetVariable("dan_total",0)
	SetVariable("pill",0)
	SetVariable("trash",0)
	SetVariable("total",0)
	SetVariable("monster",0)
	SetVariable("bomb",0)
	SetVariable("usecoin",0)
	file=io.open("E:\\reaction.txt","w")
	io.write("")
	file:close()
	print("统计数据及日志清零！")
end  --endfunc



function exchangeid(str)   --id英文转换游戏中首字母大写格式
	local newstr
	local firstchar
	
	firstchar=string.upper(string.sub(str,0,1))
	newstr=firstchar..string.sub(str,2)
	return newstr
end	--endfunc

function ismember(unit,group)		       --判断是否在一数组的函数，以后可以直接调用这个函数了
	if type(group) ~= "table"
	then
		print(LINE.."比较对象必须为数组！"..LINE)
		return
	end	--endif
	for key,value in pairs(group) do
		if unit == value or unit==key
		then
			return true
		end	--endif
	end --endfor
	return false
end --endfunc


function getquest(str)          --取消和接任务，会刷屏
    SetVariable("myquest",str)
	if string.find(GetVariable("questlist"),str)
	then
		Queue("ok")
	else
		Queue("quest cancel")
		Queue("quest")
	end	--endif
end	--endfunc

function getarab(str)      --中文单字转阿拉伯数字
	local ch_num={["一"]=1,["二"]=2,["三"]=3,["四"]=4,["五"]=5,
				  ["六"]=6,["七"]=7,["八"]=8,["九"]=9,["零"]=0,}
	for key,value in pairs (ch_num) do
		if str == key
		then
			return tonumber(value)
		end	--endif
	end	--endfor
	return 0
end	--endfunc

function chtoarab(str)                 --中文数字变阿拉伯数字
	local unit={["亿"]=100000000,["万"]=10000,["千"]=1000,["百"]=100,["十"]=10,["零"]=0}
	local result=0
	local bit
	local digit=1
	
	for i=1,string.len(str),2 do
		bit=string.sub(str,i,i+1)
		if ismember(bit,unit)
		then
			for key,value in pairs (unit) do
				if bit == key
				then
					digit=digit*value
					result=result+digit
					break
				end  --endif
			end  --endfor
		else	
			digit=getarab(bit)
		end --endif
	end  --endfor
	if not ismember(bit,unit)
	then
		result=result+digit
		return(tonumber(result))
	else
		return(tonumber(result))
	end  --endif
end	--endfunc







--By @��Ҳ�� 20180721 Ver 1.69

         


---------------��ʼ��-----------------
SetVariable("keeppill",0)
SetVariable("autologin",0)
SetVariable("mylog",0)
EnableTimer("robot_monitor",false)
EnableTriggerGroup("reaction",false)
EnableTriggerGroup("checkstatus",false)

local trashlist="|Luoyun zhui|Dart|Blade|Fan|Lian|Wan|Tea pot|Axe|Fried chicken leg|Jing|Dagger|Pill|Wineskin|"



function test()
	if string.find(GetVariable("keeplist"),("������絤"))
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
  	print("mylogָ�mylog [on/off]")
  	return
  else
  	if str == "on"
  	then
  		print("��־�����Ѵ򿪣�")
  		SetVariable("mylog",1)
  		return
    end	--endif
    if str == "off"
  	then
  		print("��־�����ѹرգ�")
  		SetVariable("mylog",0)
  		return
    end	--endif
  end	--endif

end	--endfunc
function checkitem(itemcn,itemid)                    --check��Ʒ
  --print(itemcn,itemid)
	if GetVariable("mylog") == "1"
	then
		file=io.open(GetVariable("logpath").."reaction.txt","a")
		if string.find(GetVariable("keeplist"),itemcn)
		then
			file:write("����"..itemcn.."("..itemid..")".."       "..os.date().."\n")
	  else
	  	if string.find(GetVariable("otherlist"),itemcn)
	  	then
	  		file:write("��"..itemcn.."("..itemid..")".."       "..os.date().."\n")
	  	else
	  		file:write(itemcn.."("..itemid..")".."       "..os.date().."\n")
	    end  --endif
	  end  --endif
  	file:close()
  end --endif
	if string.find(GetVariable("keeplist"),itemcn)
	then
		--print("�Ǹ����ⵤ")
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
	if string.find(itemcn,"��") and itemid ~="wan" 
	then
		print("�����Ǹ�δ֪��ҩ")
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

function reaction(str)   --reactionָ��
  if str ~= "restart" and str ~= "stop"
  then
  	print("reactionָ�reaction [restart/stop]")
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
	  	print("���������˼���������")
	  	DoAfterSpecial(2,"i;set ������Ʒ�����ϣ�",10)
	  	return
	  end --endif
	  if str == "stop"
	  then
	  	EnableTriggerGroup("reaction",0)
	  	EnableTimer("robot_monitor",false)
	  	SetVariable("autologin",0)
	  	print("���������˳��׹رգ�")
	  	return
	  end --endif
	  
  end  --endif

end  --endfunc


function init()    --��ʼ��ָ��,��־��������������
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
	print("ͳ�����ݼ���־���㣡")
end  --endfunc



function exchangeid(str)   --idӢ��ת����Ϸ������ĸ��д��ʽ
	local newstr
	local firstchar
	
	firstchar=string.upper(string.sub(str,0,1))
	newstr=firstchar..string.sub(str,2)
	return newstr
end	--endfunc

function ismember(unit,group)		       --�ж��Ƿ���һ����ĺ������Ժ����ֱ�ӵ������������
	if type(group) ~= "table"
	then
		print(LINE.."�Ƚ϶������Ϊ���飡"..LINE)
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


function getquest(str)          --ȡ���ͽ����񣬻�ˢ��
    SetVariable("myquest",str)
	if string.find(GetVariable("questlist"),str)
	then
		Queue("ok")
	else
		Queue("quest cancel")
		Queue("quest")
	end	--endif
end	--endfunc

function getarab(str)      --���ĵ���ת����������
	local ch_num={["һ"]=1,["��"]=2,["��"]=3,["��"]=4,["��"]=5,
				  ["��"]=6,["��"]=7,["��"]=8,["��"]=9,["��"]=0,}
	for key,value in pairs (ch_num) do
		if str == key
		then
			return tonumber(value)
		end	--endif
	end	--endfor
	return 0
end	--endfunc

function chtoarab(str)                 --�������ֱ䰢��������
	local unit={["��"]=100000000,["��"]=10000,["ǧ"]=1000,["��"]=100,["ʮ"]=10,["��"]=0}
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







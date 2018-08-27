----------
queue = {}

function queue.push(self, item)
	table.insert(self.list, item)
end

function queue.pop(self)
	return table.remove(self.list, 1)
end

function queue.is_empty(self)
	return #self.list == 0
end

function queue.len(self)
	return #self.list
end

function queue.new()
	return {
		list = {},
		push = queue.push,
		pop = queue.pop,
		is_empty = queue.is_empty,
		len = queue.len,
	}
end


---------------------------------
-- Global Variables
---------------------------------
queueAction=queue.new()
varCurrentAction="";
varLastAction="";
mapReverseAction={}

---------------------------------
-- Constants
---------------------------------
consActionEndCommand="whisper"
consEndCommand="ask"
consActionSequenceLength=8
consActionSequenceBreak="break"
consAutokillAbortCountDefault=200

---------------------------------
-- Utility function
---------------------------------
function splitString (line,sep) 
	local res = {}
	local pos = 1
	sep = sep or ','
	while true do 
		local c = string.sub(line,pos,pos)
		if (c == "") then break end
		if (c == '"') then
			-- quoted value (ignore separator within)
			local txt = ""
			repeat
				local startp,endp = string.find(line,'^%b""',pos)
				txt = txt..string.sub(line,startp+1,endp-1)
				pos = endp + 1
				c = string.sub(line,pos,pos) 
				if (c == '"') then txt = txt..'"' end 
				-- check first char AFTER quoted string, if it is another
				-- quoted string without separator, then append it
				-- this is the way to "escape" the quote char in a quote. example:
				--   value1,"blub""blip""boing",value3  will result in blub"blip"boing  for the middle
			until (c ~= '"')
			table.insert(res,txt)
			assert(c == sep or c == "")
			pos = pos + 1
		else	
			-- no quotes used, just look for the first separator
			local startp,endp = string.find(line,sep,pos)
			if (startp) then 
				table.insert(res,string.sub(line,pos,startp-1))
				pos = endp + 1
			else
				-- no separator found -> use rest of string and terminate
				table.insert(res,string.sub(line,pos))
				break
			end 
		end
	end
	return res
end

function initMapReverseAction()
	mapReverseAction.south="north"
	mapReverseAction.north="south"
	mapReverseAction.east="west"
	mapReverseAction.west="east"
	mapReverseAction.up="down"
	mapReverseAction.down="up"
	mapReverseAction.enter="out"
	mapReverseAction.out="enter"

	mapReverseAction.westup="eastdown"
	mapReverseAction.westdown="eastup"
	mapReverseAction.eastup="westdown"
	mapReverseAction.eastdown="westup"

	mapReverseAction.northup="southdown"
	mapReverseAction.northdown="southup"
	mapReverseAction.southup="northdown"
	mapReverseAction.southdown="northup"

	mapReverseAction.southeast="northwest"
	mapReverseAction.northeast="southwest"
	mapReverseAction.southwest="northeast"
	mapReverseAction.northwest="southeast"
end

function getReverseAction(action)
	if action == nil or action=="" then
		return nil
	end
	if table.getn(mapReverseAction)==0 then
		initMapReverseAction()
	end
	local reverseAction=""
	local steps=splitString(action,";")
	for count,step in ipairs(steps) do
		local rstep=mapReverseAction[step]
		if rstep ~= nil then
			if reverseAction =="" then
				reverseAction=rstep
			else
				reverseAction=reverseAction .. ";" .. rstep
			end
		end
	end
	if reverseAction == "" then
		return nil
	else
		return reverseAction
	end
		
end


---------------------------------
-- Fyvi Functions
---------------------------------
function initGlobal ()
	initActionQueue()
--	queueAction=nil
--	queueAction=queue.new()
--	queueAction=List.new()
	varCurrentAction="";
	varLastAction="";

end

function reloadAllConfig()
	reloadVariables()
	reloadAllAliasTriggersTimers()
end

function reloadConfig()
	reloadAllAliasTriggersTimers()
end


function reloadVariables()
	--delete all variable
	local varlist = GetVariableList()
	if varlist then
	 for vk,vv in ipairs(varlist) do
	  DeleteVariable(vv)
	 end
	end
	Note("---> all variable deleted")
	
	--load variable xml
	local vfile=io.open("z:/work-variables.txt")
	local vars=vfile:read("*a")
	vfile:close()
	ImportXML(vars)
	Note("---> loaded variables from file")
end

function reloadAllAliasTriggersTimers()
	--delete all timers
	local timerlist = GetTimerList()
	if timerlist then
	 for tk,tv in ipairs(timerlist) do
	  DeleteTimer(tv)
	 end
	end
	Note("---> all timers deleted")
	
	--delete all alias
	local aliaslist = GetAliasList()
	if aliaslist then
	 for ak,av in ipairs(aliaslist) do DeleteAlias(av) end
	end
	Note("---> all alias deleted")

	--delete all triggers
	local triggerlist = GetTriggerList()
	if triggerlist then
	 for gk,gv in ipairs(triggerlist) do DeleteTrigger(gv) end
	end
	Note("---> all triggers deleted")
	
	--load timer xml
	local tfile=io.open("z:/work-timers.mci")
	local timers=tfile:read("*a")
	tfile:close()
	ImportXML(timers)
	Note("---> loaded timers from file")

	--load alias xml
	local afile=io.open("z:/work-aliases.mca")
	local alias=afile:read("*a")
	afile:close()
	ImportXML(alias)
	Note("---> loaded aliases from file")
	
	--load trigger xml
	local gfile=io.open("z:/work-triggers.mct")
	local triggers=gfile:read("*a")
	gfile:close()
	ImportXML(triggers)
	Note("---> loaded triggers from file")
end



function initActionQueue ()
	queueAction=nil
--	queueAction=List.new()
	queueAction=queue.new()
end
	
function pushSingleAction (action)
	if action == nil or action == "" then
		Note("---> push single action empty!")
		return
	end
	local steps=splitString(action,";")

	local len=table.getn(steps)
--	Note("step size:" .. len)

	local lastStep=steps[len]
--	Note("last step:" .. lastStep)

	local reverseStep=getReverseAction(lastStep)
--	Note("reverse step:" .. reverseStep)
	if lastStep ~=consActionEndCommand and reverseStep~= nil then
		--need to add action end command
		action=action .. ";" .. consActionEndCommand
	end
	queueAction:push(action)
--	List.pushleft(queueAction, action)
	Note ("------> push single action done:"..action ..", current action queue:"..queueAction:len())
end

function pushSeqAction (action)
	Note ("---> push new sequence: " ..action)
	local steps=splitString(action,";")
--	local totalSteps=table.getn(steps)
	local i=1
	local currentAction=""
	for count,step in ipairs(steps) do
		if step == consActionSequenceBreak then
 			pushSingleAction(string.rep(currentAction,1))	
			i=1
			currentAction=""
		elseif  i == consActionSequenceLength then
			pushSingleAction(string.rep(currentAction,1))	
			i=1
			currentAction=""
		else
			i=i+1
			if currentAction == "" then
				currentAction=step
			else
				currentAction=currentAction .. ";" .. step
			end
		end
	end
	if currentAction ~= "" then
		pushSingleAction(string.rep(currentAction,1))	
	end
	Note ("---> push new sequence done")
end


function popAction()
	if queueAction==nil or queueAction:len()==0 then
		Note ("----> no action!")
	else
		local act=queueAction:pop()
		Note ("----> pop next action: " .. act)
		return act
	end
end


function startAction(showDir)
	if showDir== "false" then
		Execute("noDir")
	else
		Execute("yesDir")
	end
	Send("whisper")
end

function pushBatchAction(action,repeatNum,batch)
	for j=1,batch do
		local act=""
		for i=1,repeatNum do
			if act=="" then
				act=action
			else
				act=act .. ";" .. action
			end
		end
		act=act .. ";" .. consActionEndCommand
		pushSingleAction(act)
	end
end

function generateAutokillPerform(perform)
	if perform == nil then
		local perform=GetVariable("autokillPerformDefault")
		return perform
	else
		local ret=perform:gsub("@"," ")
		return ret
	end
end

function listEquals(o1, o2, ignore_mt)
	if not o1 then return false end
	if not o2 then return false end
	
    for key1, value1 in pairs(o1) do
		local found=false
		for key2,value2 in pairs(o2) do
			if value1 == value2 then found=true end
		end
		if not found then return false end
    end

    for key1, value1 in pairs(o2) do
		local found=false
		for key2,value2 in pairs(o1) do
			if value1 == value2 then found=true end
		end
		if not found then return false end
    end
	return true
end



function initPatternArray()
	if not ArrayExists("looppattern") then ArrayCreate("looppattern") end
	if not ArrayExists("loopendpattern") then ArrayCreate("loopendpattern") end
	ArrayClear("looppattern")
	ArrayClear("loopendpattern")
end

function addLoopEndPattern(pattern)
	ArraySet("loopendpattern",pattern,pattern)
end

function addLoopPattern(pattern)
	ArraySet("looppattern",pattern,pattern);
end

function checkLoopPattern(dir)
--    Note("---> checkLoopPattern:"..dir)

	local moves=splitString(dir,",")
	local patterns=ArrayListKeys("looppattern")
	local ret=listEquals(moves,patterns,true)
--	Note("---> checkLoopPattern:" .. tostring(ret))
	return ret

end

function checkLoopEndPattern(dir)
 --   Note("---> checkLoopEndPattern:"..dir)
	local moves=splitString(dir,",")
	local patterns=ArrayListKeys("loopendpattern")
	local ret=listEquals(moves,patterns,true)
	--Note("---> checkLoopEndPattern:" .. tostring(ret))
	return ret
end


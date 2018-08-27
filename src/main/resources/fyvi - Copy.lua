---------------------------------
-- Queue class
---------------------------------
--[[
List = {}
function List.new ()
      return {first = 0, last = -1}
end
	
function List.pushleft (list, value)
      local first = list.first - 1
      list.first = first
      list[first] = value
end
    
function List.pushright (list, value)
      local last = list.last + 1
      list.last = last
      list[last] = value
end
    
function List.popleft (list)
      local first = list.first
      if first > list.last then error("list is empty") end
      local value = list[first]
      list[first] = nil        -- to allow garbage collection
      list.first = first + 1
      return value
end
    
function List.popright (list)
      local last = list.last
      if list.first > last then error("list is empty") end
      local value = list[last]
      list[last] = nil         -- to allow garbage collection
      list.last = last - 1
      return value
end
]]
--------------------------------------------------------

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







	


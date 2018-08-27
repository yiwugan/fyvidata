-----------------------------------------------------------------------------------------
--load constant file
dofile("C:/Personal/SO/fyvi/fy-constant.lua");

-----------------------------------------------------------------------------------------
-- global value objects
voHP={TableName="My HP"};
voStatus={TableName="My Status"};
voScore={TableName="My Score"};
voSkills={TableName="My Skills"};
voLogin={TableName="My Login"};
voUptime={TableName="Uptime"};

-----------------------------------------------------------------------------------------
--list and queue objects
listAction={TableName="Action List",first = 0, last = -1};
listAction.clear=function()
	for k in pairs (listAction) do
    	listAction[k] = nil
	end	
	listAction=nil;
	listAction={TableName="Action List",first = 0, last = -1};
end
listAction.pushActions=function(acts)
end
listAction.pushAction=function(act)
	if act==nil then
		funcError("action is nil, can't add into action list");
	else
		listAction.pushright (act..varCommandSeperator..varActionCommand);
	end
end
listAction.nextAction=function()
	return listAction.popleft();
end
function listAction.pushleft (value)
	local first = listAction.first - 1;
    listAction.first = first;
	listAction[first] = value;
end
function listAction.pushright (value)
	local last = listAction.last + 1;
    listAction.last = last;
    listAction[last] = value;
end
function listAction.popleft ()
	local first = listAction.first
    if first > listAction.last then 
    	funcDebug("Action List is empty");
    	return nil;
    end
    local value = listAction[first];
	listAction[first] = nil;        -- to allow garbage collection
    listAction.first = first + 1;
	return value;
end
function listAction.popright ()
	local last = listAction.last
    if listAction.first > last then
    	funcDebug("Action List is empty");
    	return nil;
	end
    local value = listAction[last];
    listAction[last] = nil;         -- to allow garbage collection
    listAction.last = last - 1;
    return value;
end

-----------------------------------------------------------------------------------------
--general functions
function initScript()
	-- todo
end

function funcDumpTable(voTable)
	funcDebug("start to dump table "..voTable.TableName);
	for k,v in pairs(voTable) do
		if type(k) ~= 'nil' and type(k) ~= 'function' and type(v) ~= 'nil' and type(v) ~= 'function' and k~='TableName'then
			funcDebug("key="..k..", value="..v);
		end
  	end
	funcDebug("end of table "..voTable.TableName);
end

function funcDebug(info)
	Note("----------> "..info.." <----------");
end

function funcError(info)
	Note("ERROR----------> "..info.." <----------ERROR");
end
-----------------------------------------------------------------------------------------

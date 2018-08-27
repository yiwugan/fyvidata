--
--  取整数部分
--
function GetIntPart(x)
    local rt = math.ceil(x)
if rt>0 and rt~=x then
    rt = rt - 1
end
    return rt
end

--
-- string list处理
--
function ismember(str, list, sep)

  -- This function find str in list which is seperated by sep.
  -- If found, return the index of the str, otherwise return 0
  -- Example:
  -- str = "sky cloth", list = "sky cloth,sky shoes", sep = ","
  -- return 1

    local find = 0
    local idx = 0

    for w in (list .. sep):gmatch("([^" .. sep .. "]*)" .. sep) do
        idx = idx + 1
        if (w == str and find == 0 )then
            find = idx
        end
    end

    return find

end


--
-- 从string list按指定序号取item
--
function item(list, num, sep)

  -- This function returns the specified numbered string in list which is seperated by sep.
  -- If found, return the str, otherwise return an empty string
  -- Example:
  -- num = 3, list = "sky cloth,sky shoes,hu boots", sep = ","
  -- return "hu boots"

  local str = ""
  local idx = 0

  for w in (list .. sep):gmatch("([^" .. sep .. "]*)" .. sep) do
    idx = idx + 1
    if num == idx then
      str = w
    end
  end

  return str

end


--
--    统计以 sep 作为分隔符的字符串数量
--
function num(list, sep)

    local idx = 0

    if list=="" then
        -- 如果字符串为空返回0
        idx = 0
    else
        for w in (list .. sep):gmatch(sep) do
            idx = idx + 1
        end
    end

    return idx

end

--
--  修改字符串指定序号的值
--  modiitem("字符串",序号,"分隔符","值")
function modiitem(list, idx, sep, str)

    local str2 = ""
    local list_new = ""
    local list_len = num(list, sep)

    if idx <= list_len then
        for i = 1, list_len do
            if i == idx then
                str2 = str
            else
                str2 = item(list,i,sep)
            end
            if list_new == "" then
                list_new = str2
            else
                list_new = list_new..sep..str2
            end
        end

        return list_new

    else

        return 0  --没找到指定的序号

    end
end

--
--  删除字符串指定的值
--  delitem("字符串", "删除的值", "分隔符")
function delitem(list, str, sep)
	
	local list_new = ""
	local list_len = num(list, sep)
	
	for i = 1, list_len do
		local str2 = item(list, i, sep)
		if str2 ~= str then
			if list_new == "" then
				list_new = str2
			else
				list_new = list_new..sep..str2
			end
		end
	end -- do
	
	return list_new
	
end --function

--
--    快速遍历1
--
--    例子：bianli("n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n")
function bianli(list)
--    j = 分段数量
    local j = 0
--    steps = 以 ";" 符号分隔的路径总长度
    local steps = num(list, ";")
--    p = 分段路径,默认10步一段
    local p = ""
--    path = 将所有分段路径整合好的完整路径
    local path = ""
    for i = 1, steps do
        if (i % 10 == 0 and i ~= steps) then
--    每10步一个分段,以 "|" 符号分隔,如果最后一分段正好10步则不添加 "|" 符号,避免发出空 DoAfterSpecial
            path = path .. p .. item(list, i, ";") .. "|"
--    添加分段到 path 后置空 p
            p = ""
        else
            if i ~= steps then
--    把每一步添加到分段路径 p 中,以 ; 结尾
                p = p .. item(list, i, ";") .. ";"
            else
--    如果是最后一步,不添加 ";" 分隔符,避免发出空指令
                p = p .. item(list, i, ";")
            end
        end
    end
--    循环结束后,把余下的分段路径添加到 path
    path = path .. p
--    统计分段数量
    j = num(path, "|") - 1
--    显示运算结果,调试用
    Note(path)
--    Note(j)
--    执行不需要延时的第一分段路径
    Execute(item(path, 1, "|"))
--    执行需要延时的余下分段路径
--    i 为延时值, i + 1 为路径 path 对应的分段序号
    if j > 0 then
        for i = 1, j do
            DoAfterSpecial(i,'Execute(item("' .. path .. '", ' .. i + 1 .. ', "|"))', sendto.script)
        end
    end
end

--
--    快速遍历2
--
--    例子：bianli2("n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n")
function bianli2(list)
    local j = 0  -- j = 分段数量
    local steps = num(list, ";")  -- steps = 以 ";" 符号分隔的路径总长度
    local p = ""  -- p = 分段路径,默认10步一段
    local path = ""  -- path = 将所有分段路径整合好的完整路径
    for i = 1, steps do
        if (i % 10 == 0 and i ~= steps) then  -- 每10步一个分段,以 "|" 符号分隔,如果最后一分段正好10步则不添加 "|" 符号,避免发出空 DoAfterSpecial
            path = path .. p .. item(list, i, ";") .. "|"  -- 添加分段到 path 后置空 p
            p = ""
        else
            if i ~= steps then  -- 把每一步添加到分段路径 p 中,以 ; 结尾
                p = p .. item(list, i, ";") .. ";"
            else  -- 如果是最后一步,不添加 ";" 分隔符,避免发出空指令
                p = p .. item(list, i, ";")
            end
        end
    end  -- 循环结束后,把余下的分段路径添加到 path
    path = path .. p  -- 统计分段数量
    j = num(path, "|") -- 显示运算结果,调试用
    SetVariable("bl_path", path)  -- 保存路径
    SetVariable("bl_num", j)  -- 保存路径段数
    Note(path)
    if j > 1 then
        Execute(item(path, 1, "|")..";set tri 快速遍历1")
    else
        Execute(item(path, 1, "|"))
    end
end

--
-- 精简路径
-- 利用dir_1,dir_2列表中对应的序号,对路径中相邻的两个相反方向进行对消,以达到优化最短路径目的
--
function trimpath(path)

    local dir_1 = "n|e|nw|ne|nu|nd|eu|ed|u|en|s|w|se|sw|sd|su|wd|wu|d|o|ct|dt|cu|cd|dash|go down|go east"
    local dir_2 = "s|w|se|sw|sd|su|wd|wu|d|o|n|e|nw|ne|nu|nd|eu|ed|u|en|dt|ct|cd|cu|dash|go up|go west"
    local path_a = path
    local path_b = ""
    local final_path = ""

    while path_a ~= path_b do

        local i = 1
        local path_t = ""
        local pre_dir = ""
        local cur_dir = ""
        local sum = num(path_a,";")
        --Note("sum="..sum)

        while i <= sum do
            --Note("i="..i)
            cur_dir = item(path_a, i, ";")  --当前步
            pre_dir = item(path_a, i+1, ";")  --下一步
            local idx1 = ismember(cur_dir, dir_1, "|")  --取当前步位于序列1中的序号
            local idx2 = ismember(pre_dir, dir_2, "|")  --取下一步位于序列2中的序号
            --Note("cur_dir="..cur_dir.." pre_dir="..pre_dir.." idx1="..idx1.." idx2="..idx2)  
            if idx1 == idx2 and idx1 ~= 0 and idx2 ~= 0 then  --如果当前步和下一步为相反方向即对消掉
                i = i + 2
            else  --如果不是相反方向或者不在序列中的方向则加到path_t
                if path_t == "" then
                    path_t = cur_dir
                else
                    path_t = path_t..";"..cur_dir
                end
                i = i + 1
            end
            --Note("path_t="..path_t)
        end
        path_b = path_a
        path_a = path_t
        final_path = path_t
        --Note("path_a="..path_a)
        --Note("path_b="..path_b)
        --Note("----------")
    end
        --  Note("final_path="..final_path)
    return final_path

end

--
--  根据对照表反转路径
--
function fan(path)

    local dir_1 = "n|e|nw|ne|nu|nd|eu|ed|u|en|s|w|se|sw|sd|su|wd|wu|d|o|ct|dt|cu|cd|dash|go down|go east"
    local dir_2 = "s|w|se|sw|sd|su|wd|wu|d|o|n|e|nw|ne|nu|nd|eu|ed|u|en|dt|ct|cd|cu|dash|go up|go west"
    local path_len = num(path, ";")
    local final_path = ""
    local idx = 0
    
    for i = 1, path_len do
        idx = ismember(item(path, i, ";"), dir_1, "|")
        if idx > 0 then  -- 如果在方向列表中，则反向
            if final_path == "" then
                final_path = item(dir_2, idx, "|")
            else
                final_path = item(dir_2, idx, "|")..";"..final_path
            end
        else  -- 如果不在方向列表中，则保持原向
            if final_path == "" then
                final_path = item(path, i, ";")
            else
                final_path = item(path, i, ";")..";"..final_path
            end
        end
    end

    return final_path

end

--功能：读取文件
--输入：文件名
--输出：屏幕上一行一行显示文件里的内容
function readfile(filename)

    local rfile = io.open(filename, "r") --读取文件(r读取)
    assert(rfile)                    --打开时验证是否出错
    for str in rfile:lines() do        --一行一行的读取
        print(str)                    --显示在屏幕上
    end
    rfile:close()                    --调用结束后记得关闭

end

--功能：写入文件  
--输入：文件名, 内容
--输出：生成的文件里面包含内容
function writefile(filename, info)  

    local wfile = io.open(filename, "a")--写入文件(w覆盖,a追加)
    assert(wfile)           --打开时验证是否出错
    wfile:write(info)       --写入传入的内容
    wfile:write("\n")        --写入换行符(注:mush的trigger和alias似乎不能处理换行符,提示出错,固在此添加)
    wfile:close()           --调用结束后记得关闭

end

--
-- 随机生产"东,南,西,北"4方向
--
function randir()

    local seed = math.ceil(math.random() * 100)
    local dir = ""

    if seed > 0 and seed <= 25 then
        dir = "east"
    elseif seed > 26 and seed <= 50 then
        dir = "south"
    elseif seed > 51 and seed <= 75 then
        dir = "west"
    else
        dir = "north"
    end
    SetVariable("dir", dir)
    --Note(dir)
    Execute(dir)
end

--
-- 中文数字转换为阿拉伯数字
--
function chs2num(s)

    local cur = 0
    local yi = 0
    local sgl = 0
    local len = string.len(s)
    local tt = {}
    tt["零"] = function() end
    tt["一"] = function() sgl = 1   end
    tt["二"] = function() sgl = 2   end
    tt["三"] = function() sgl = 3   end
    tt["四"] = function() sgl = 4   end
    tt["五"] = function() sgl = 5   end
    tt["六"] = function() sgl = 6   end
    tt["七"] = function() sgl = 7   end
    tt['八'] = function() sgl = 8   end
    tt["九"] = function() sgl = 9   end
    tt["十"] = function()
    if sgl == 0 then sgl = 1 end
        cur = cur + sgl * 10
        sgl = 0
    end
    tt["百"] = function()
        cur = cur + sgl * 100
        sgl = 0
    end
    tt["千"] = function()
        cur = cur + sgl * 1000
        sgl = 0
    end
    tt["万"] = function()
        cur = (cur +sgl) * 10000
        sgl = 0
    end
    tt["亿"] = function()
        yi = (cur + sgl) * 100000000
        cur = 0
        sgl = 0
    end
    for i = 1,len,2 do
        k = string.sub(s,i,i+1)
        tt[k]()
    end
    local number = yi + cur +sgl
    --print(number)
   return number
end

--
-- 去除字符串两端空格
--
function trim(s) 
  return (string.gsub(s, "^%s*(.-)%s*$", "%1")) 
end

--
-- 区域代码转换为中文
--
function chs_area(str)

    local area = str
    local area_list = GetVariable("area_list")

    if area == "dmcs1" or area == "dmcs2" or area == "dmcs3" then
        area = "dmcs"
    elseif area == "dq1" or area == "dq2" or area == "dq3" then
        area = "dq"
    elseif area == "khl1" or area == "khl2" then
        area = "khl"
    elseif area == "ss1" or area == "ss2" then
        area = "ss"
    elseif area == "zb1" or area == "zb2" or area == "zb3" then
        area = "zb"
    end

    local idx = tonumber(ismember(area, area_list, "|")) - 1

    if idx >0 then  -- 如果在区域中则转换为中文名,否则返回原区域代码(例:dz,dxc,qs,srz)
        area = item(area_list, idx, "|")
    end

    return area

end

--=============================================================================
--require "getstyle"
--============================================
--Funtions
--============================================
--定义窗口名字
window={
    new=function()
        local w={}
        setmetatable(w,{__index=window})
        return w
    end,
    name="myStatusWin",

    sGoodColor="green",
    sMediumColor="blue",
    sBadColor="red",

    background_colour = 0x000000,
    --定义状态条的属性
    bar_left = 32,
    bar_height = 18,
    bar_right = 319,
    box_colour = 0xD3D3D3,
    --定义显示用的字体属性
    font_id = "myFont",
    font_name = "新宋体",
    font_height = 12,
    font_size = 9,
    vertical = 8,
    items={},
}

function window:init()
    check(WindowCreate (self.name, 0, 0, 331, 297, miniwin.pos_top_right, 0, ColourNameToRGB("yellow")))
    check(WindowFont (self.name, self.font_id, self.font_name, self.font_size, false, false, false, false))
end

--画状态条方法
--sPrompt 状态条前显示的字
--Percent 状态百分比
--sGoodColor 正常时候的颜色
--sMediumColor 当状态小于50%的时候的颜色
--sBadColor 当状态小于50%的时候的颜色
--sText 显示在状态条内的文字
--bTextOnly 当参数等于1的时候不做颜色的填充
function window:showBar (sPrompt, current, max)
    if(type(max)=="number") then
        Percent=math.ceil(current*100/max)
        if(Percent>100) then
            Percent=100
        end
    else
        Percent=-1
    end
    --画框架
    self:drawFrame(sPrompt)

    --当bTextOnly不等于1的时候画状态条
    --画状态条
    self:drawBar(sPrompt, Percent)

    --如果sText存在则显示sText
    if(type(max)=="number") then
        self:drawText(current.."/"..max)
    else
        self:drawText(current..max)
    end

    --计算下一个状态条的位置
    self.vertical = self.vertical + self.font_height
end -- function


--画框框的方法
function window:drawFrame(sPrompt)
    if (sPrompt~= nil) then
        local width = WindowTextWidth (self.name, self.font_id, sPrompt)

        WindowText (self.name, self.font_id, sPrompt, self.bar_left - width + 5, self.vertical+2, 0, 0, 0x00FFFF)

        -- frame rectangle
        WindowRectOp (self.name, 1,
        self.bar_left+5, self.vertical,
        self.bar_right, self.vertical + self.bar_height,
        self.box_colour)
    end
end

--画状态条
function window:drawBar(sPrompt, Percent)
    local colour
    --  Below 33% warn by sBadColor
    --  Below 66% warn by sMediumColor
    if Percent <= 33 then
        colour = self.sBadColor
    elseif Percent <= 66 then
        colour = self.sMediumColor
    else
        colour = self.sGoodColor
    end -- if

    if(Percent==-1) then
        Percent=100
        colour="darkblue"
    end
    local pixels = (self.bar_right - self.bar_left - 1) * Percent / 100

    -- fill rectangle
    WindowRectOp (self.name, 2,
    self.bar_left + 6, self.vertical + 1,
    self.bar_left + pixels, self.vertical + self.bar_height - 1,
    ColourNameToRGB (colour))
end

--显示文字
function window:drawText(sText)
    WindowText (self.name, self.font_id, sText, self.bar_left + 20, self.vertical+2, 0, 0, 0xFFFFFF)
    --计算下一个状态条的位置
    self.vertical = self.vertical + self.font_height
end

--计算各类数值并在窗口中刷新状态条
function window:draw_bar ()
    --清屏,为下次刷新做准备
    check (WindowRectOp (self.name, 2, 0, 0, 0, 0, self.background_colour))

    -- 画边框
    check (WindowRectOp (self.name, 5, 0, 0, 0, 0, 10, 15))

    -- pixel to start at
    self.vertical = 8

    for _,i in ipairs(self.items) do
        if i.label~=nil then
            self:drawText(i.label)
        elseif i.current~=nil then
            self:showBar(i.sPrompt,i.current,i.max)
        end
    end
    WindowShow (self.name, true)
end -- draw_bar

--添加标签
function window:addText(id,text)
    local item={}
    for _,i in ipairs(self.items) do
        if i.id==id then
            --print("text_id:",id)
            item=i
            item.label=text
            return
        end
    end
    item.id=id
    item.label=text
    table.insert(self.items,item)
end
--添加进度条
function window:addBar(id,sPrompt, current, max)
    local item={}
    for _,i in ipairs(self.items) do
        if i.id==id then
            item=i
            item.sPrompt=sPrompt
            item.current=current
            item.max=max
            return
        end
    end
    item.id=id
    item.sPrompt=sPrompt
    item.current=current
    item.max=max
    table.insert(self.items,item)
end

--关闭窗口
function window:close()
    WindowDelete(self.name)
end

function close_byName(win_name)
    WindowDelete(win_name)
end

--开启
function window:refresh()
    self.vertical=8
    self:init()
    self:draw_bar()
end
--=============================================================================

--
--  ȡ��������
--
function GetIntPart(x)
    local rt = math.ceil(x)
if rt>0 and rt~=x then
    rt = rt - 1
end
    return rt
end

--
-- string list����
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
-- ��string list��ָ�����ȡitem
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
--    ͳ���� sep ��Ϊ�ָ������ַ�������
--
function num(list, sep)

    local idx = 0

    if list=="" then
        -- ����ַ���Ϊ�շ���0
        idx = 0
    else
        for w in (list .. sep):gmatch(sep) do
            idx = idx + 1
        end
    end

    return idx

end

--
--  �޸��ַ���ָ����ŵ�ֵ
--  modiitem("�ַ���",���,"�ָ���","ֵ")
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

        return 0  --û�ҵ�ָ�������

    end
end

--
--  ɾ���ַ���ָ����ֵ
--  delitem("�ַ���", "ɾ����ֵ", "�ָ���")
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
--    ���ٱ���1
--
--    ���ӣ�bianli("n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n")
function bianli(list)
--    j = �ֶ�����
    local j = 0
--    steps = �� ";" ���ŷָ���·���ܳ���
    local steps = num(list, ";")
--    p = �ֶ�·��,Ĭ��10��һ��
    local p = ""
--    path = �����зֶ�·�����Ϻõ�����·��
    local path = ""
    for i = 1, steps do
        if (i % 10 == 0 and i ~= steps) then
--    ÿ10��һ���ֶ�,�� "|" ���ŷָ�,������һ�ֶ�����10������� "|" ����,���ⷢ���� DoAfterSpecial
            path = path .. p .. item(list, i, ";") .. "|"
--    ��ӷֶε� path ���ÿ� p
            p = ""
        else
            if i ~= steps then
--    ��ÿһ����ӵ��ֶ�·�� p ��,�� ; ��β
                p = p .. item(list, i, ";") .. ";"
            else
--    ��������һ��,����� ";" �ָ���,���ⷢ����ָ��
                p = p .. item(list, i, ";")
            end
        end
    end
--    ѭ��������,�����µķֶ�·����ӵ� path
    path = path .. p
--    ͳ�Ʒֶ�����
    j = num(path, "|") - 1
--    ��ʾ������,������
    Note(path)
--    Note(j)
--    ִ�в���Ҫ��ʱ�ĵ�һ�ֶ�·��
    Execute(item(path, 1, "|"))
--    ִ����Ҫ��ʱ�����·ֶ�·��
--    i Ϊ��ʱֵ, i + 1 Ϊ·�� path ��Ӧ�ķֶ����
    if j > 0 then
        for i = 1, j do
            DoAfterSpecial(i,'Execute(item("' .. path .. '", ' .. i + 1 .. ', "|"))', sendto.script)
        end
    end
end

--
--    ���ٱ���2
--
--    ���ӣ�bianli2("n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n;n")
function bianli2(list)
    local j = 0  -- j = �ֶ�����
    local steps = num(list, ";")  -- steps = �� ";" ���ŷָ���·���ܳ���
    local p = ""  -- p = �ֶ�·��,Ĭ��10��һ��
    local path = ""  -- path = �����зֶ�·�����Ϻõ�����·��
    for i = 1, steps do
        if (i % 10 == 0 and i ~= steps) then  -- ÿ10��һ���ֶ�,�� "|" ���ŷָ�,������һ�ֶ�����10������� "|" ����,���ⷢ���� DoAfterSpecial
            path = path .. p .. item(list, i, ";") .. "|"  -- ��ӷֶε� path ���ÿ� p
            p = ""
        else
            if i ~= steps then  -- ��ÿһ����ӵ��ֶ�·�� p ��,�� ; ��β
                p = p .. item(list, i, ";") .. ";"
            else  -- ��������һ��,����� ";" �ָ���,���ⷢ����ָ��
                p = p .. item(list, i, ";")
            end
        end
    end  -- ѭ��������,�����µķֶ�·����ӵ� path
    path = path .. p  -- ͳ�Ʒֶ�����
    j = num(path, "|") -- ��ʾ������,������
    SetVariable("bl_path", path)  -- ����·��
    SetVariable("bl_num", j)  -- ����·������
    Note(path)
    if j > 1 then
        Execute(item(path, 1, "|")..";set tri ���ٱ���1")
    else
        Execute(item(path, 1, "|"))
    end
end

--
-- ����·��
-- ����dir_1,dir_2�б��ж�Ӧ�����,��·�������ڵ������෴������ж���,�Դﵽ�Ż����·��Ŀ��
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
            cur_dir = item(path_a, i, ";")  --��ǰ��
            pre_dir = item(path_a, i+1, ";")  --��һ��
            local idx1 = ismember(cur_dir, dir_1, "|")  --ȡ��ǰ��λ������1�е����
            local idx2 = ismember(pre_dir, dir_2, "|")  --ȡ��һ��λ������2�е����
            --Note("cur_dir="..cur_dir.." pre_dir="..pre_dir.." idx1="..idx1.." idx2="..idx2)  
            if idx1 == idx2 and idx1 ~= 0 and idx2 ~= 0 then  --�����ǰ������һ��Ϊ�෴���򼴶�����
                i = i + 2
            else  --��������෴������߲��������еķ�����ӵ�path_t
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
--  ���ݶ��ձ�ת·��
--
function fan(path)

    local dir_1 = "n|e|nw|ne|nu|nd|eu|ed|u|en|s|w|se|sw|sd|su|wd|wu|d|o|ct|dt|cu|cd|dash|go down|go east"
    local dir_2 = "s|w|se|sw|sd|su|wd|wu|d|o|n|e|nw|ne|nu|nd|eu|ed|u|en|dt|ct|cd|cu|dash|go up|go west"
    local path_len = num(path, ";")
    local final_path = ""
    local idx = 0
    
    for i = 1, path_len do
        idx = ismember(item(path, i, ";"), dir_1, "|")
        if idx > 0 then  -- ����ڷ����б��У�����
            if final_path == "" then
                final_path = item(dir_2, idx, "|")
            else
                final_path = item(dir_2, idx, "|")..";"..final_path
            end
        else  -- ������ڷ����б��У��򱣳�ԭ��
            if final_path == "" then
                final_path = item(path, i, ";")
            else
                final_path = item(path, i, ";")..";"..final_path
            end
        end
    end

    return final_path

end

--���ܣ���ȡ�ļ�
--���룺�ļ���
--�������Ļ��һ��һ����ʾ�ļ��������
function readfile(filename)

    local rfile = io.open(filename, "r") --��ȡ�ļ�(r��ȡ)
    assert(rfile)                    --��ʱ��֤�Ƿ����
    for str in rfile:lines() do        --һ��һ�еĶ�ȡ
        print(str)                    --��ʾ����Ļ��
    end
    rfile:close()                    --���ý�����ǵùر�

end

--���ܣ�д���ļ�  
--���룺�ļ���, ����
--��������ɵ��ļ������������
function writefile(filename, info)  

    local wfile = io.open(filename, "a")--д���ļ�(w����,a׷��)
    assert(wfile)           --��ʱ��֤�Ƿ����
    wfile:write(info)       --д�봫�������
    wfile:write("\n")        --д�뻻�з�(ע:mush��trigger��alias�ƺ����ܴ����з�,��ʾ����,���ڴ����)
    wfile:close()           --���ý�����ǵùر�

end

--
-- �������"��,��,��,��"4����
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
-- ��������ת��Ϊ����������
--
function chs2num(s)

    local cur = 0
    local yi = 0
    local sgl = 0
    local len = string.len(s)
    local tt = {}
    tt["��"] = function() end
    tt["һ"] = function() sgl = 1   end
    tt["��"] = function() sgl = 2   end
    tt["��"] = function() sgl = 3   end
    tt["��"] = function() sgl = 4   end
    tt["��"] = function() sgl = 5   end
    tt["��"] = function() sgl = 6   end
    tt["��"] = function() sgl = 7   end
    tt['��'] = function() sgl = 8   end
    tt["��"] = function() sgl = 9   end
    tt["ʮ"] = function()
    if sgl == 0 then sgl = 1 end
        cur = cur + sgl * 10
        sgl = 0
    end
    tt["��"] = function()
        cur = cur + sgl * 100
        sgl = 0
    end
    tt["ǧ"] = function()
        cur = cur + sgl * 1000
        sgl = 0
    end
    tt["��"] = function()
        cur = (cur +sgl) * 10000
        sgl = 0
    end
    tt["��"] = function()
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
-- ȥ���ַ������˿ո�
--
function trim(s) 
  return (string.gsub(s, "^%s*(.-)%s*$", "%1")) 
end

--
-- �������ת��Ϊ����
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

    if idx >0 then  -- �������������ת��Ϊ������,���򷵻�ԭ�������(��:dz,dxc,qs,srz)
        area = item(area_list, idx, "|")
    end

    return area

end

--=============================================================================
--require "getstyle"
--============================================
--Funtions
--============================================
--���崰������
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
    --����״̬��������
    bar_left = 32,
    bar_height = 18,
    bar_right = 319,
    box_colour = 0xD3D3D3,
    --������ʾ�õ���������
    font_id = "myFont",
    font_name = "������",
    font_height = 12,
    font_size = 9,
    vertical = 8,
    items={},
}

function window:init()
    check(WindowCreate (self.name, 0, 0, 331, 297, miniwin.pos_top_right, 0, ColourNameToRGB("yellow")))
    check(WindowFont (self.name, self.font_id, self.font_name, self.font_size, false, false, false, false))
end

--��״̬������
--sPrompt ״̬��ǰ��ʾ����
--Percent ״̬�ٷֱ�
--sGoodColor ����ʱ�����ɫ
--sMediumColor ��״̬С��50%��ʱ�����ɫ
--sBadColor ��״̬С��50%��ʱ�����ɫ
--sText ��ʾ��״̬���ڵ�����
--bTextOnly ����������1��ʱ������ɫ�����
function window:showBar (sPrompt, current, max)
    if(type(max)=="number") then
        Percent=math.ceil(current*100/max)
        if(Percent>100) then
            Percent=100
        end
    else
        Percent=-1
    end
    --�����
    self:drawFrame(sPrompt)

    --��bTextOnly������1��ʱ��״̬��
    --��״̬��
    self:drawBar(sPrompt, Percent)

    --���sText��������ʾsText
    if(type(max)=="number") then
        self:drawText(current.."/"..max)
    else
        self:drawText(current..max)
    end

    --������һ��״̬����λ��
    self.vertical = self.vertical + self.font_height
end -- function


--�����ķ���
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

--��״̬��
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

--��ʾ����
function window:drawText(sText)
    WindowText (self.name, self.font_id, sText, self.bar_left + 20, self.vertical+2, 0, 0, 0xFFFFFF)
    --������һ��״̬����λ��
    self.vertical = self.vertical + self.font_height
end

--���������ֵ���ڴ�����ˢ��״̬��
function window:draw_bar ()
    --����,Ϊ�´�ˢ����׼��
    check (WindowRectOp (self.name, 2, 0, 0, 0, 0, self.background_colour))

    -- ���߿�
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

--��ӱ�ǩ
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
--��ӽ�����
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

--�رմ���
function window:close()
    WindowDelete(self.name)
end

function close_byName(win_name)
    WindowDelete(win_name)
end

--����
function window:refresh()
    self.vertical=8
    self:init()
    self:draw_bar()
end
--=============================================================================

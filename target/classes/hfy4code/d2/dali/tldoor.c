// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������ɽ��");
        set("long", @LONG
��̫�ߴ����¥���Ŷ�������һ����ֵĺ��᷽�ң�

                     ������

LONG
        );
        set("exits", ([ 
  "west"   : __DIR__"dadian",
  "eastdown" : __DIR__"tlroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-950);
        set("coor/y",-800);
        set("coor/z",150);
        setup();
}

int valid_leave(object me, string dir)
{
if(me->query("m_success/������")&&me->query("m_success/��ƿ÷")) return 1;
if(wizardp(me)) return 1;
if(!((me->query("family/family_name") == "����") ||(me->query("family/family_name")=="��͢"))&& dir == "west")
{message_vision("һ�ɴ�����$N���˻�����
һ�����ϵ�����˵�������˴�����£������˵Ȳ������ڣ���\n",me);
return notify_fail("");}
if(!(me->query("title")=="������ү" || me->query("title")=="�����¸�ɮ") && dir == "west")
{message_vision("һ�ɴ�����$N���˻�����
һ�����ϵ�����˵������ľ�λ���������ȵ�����ү�����ɡ�\n",me);
return notify_fail("");}
 return 1;
}
 // pigtest room
#include <pig.h> 
inherit PIGROOM; 
string look_table();
string look_scoreboard();
string look_rules(); 
void create()
{
        set("short", "�Ϲ�����");
        set("long", @LONG
        ����һ��ר��Ϊ�������ر���ƵĹ���������������ƻ�ͨ�����·���
Զ׼����Ϊ�������Ƿ����Ƶġ���������ķ���һ���ð���������ľ�����ƵĹ�
����(table)����Χ�����İ��ľ�����Ρ������ϰ���һ���Ƿֲ�(scoreboard)��
���ߵ�ǽ������һ��ֽ(paper)��
LONG
        );
        set("pigging", 1); 
        set("item_desc", ([
                "table" : (: look_table :),
                "scoreboard" : (: look_scoreboard :),
                "paper" : "����ض� help pig_cmds �� help pig_rules��\n",
        ])); 
        set("exits", ([
        "north": __DIR__"proom",
        ]));
    set("no_magic",1);
    set("no_cast",1);
    set("NONPC",1);
    set("no_spells",1);
        set("coor/x",50);
        set("coor/y",1920);
        set("coor/z",10);    
        setup();
} 
string look_table()
{
        if (this_player()->query_temp("pigging_seat"))
                return table_str(this_player()->query_temp("pigging_seat"));
        return table_str("");
} 
string look_scoreboard()
{
        return scoreboard_str();
} 
int valid_leave(object me, string dir)
{
        if (me->query_temp("pigging_seat"))
                return notify_fail("���뿪�����������ж���\n");
        return ::valid_leave(me, dir);
}       
#include <room.h>
inherit NEWBIE_HELP_ROOM; 
string look_sign(object me); 
void create()
{
        set("short", "ӭ÷��ջ");
        set("long", @LONG
���ǲ�������������һ�ҿ�ջ����˵��ҵ�����һ������������ˡ�������
�￪��ջ����ϣ������������ԭʧɢ�������ܹ�֪�������������������ᡣ��
�ǿ�ջ��ҵ���꣬��ԭ������������������û�д������������˵�һ����Ϣ����Ϊ
�������˺��У���ջ�����嵭������������ϻҲ��������˳������ط��Ƴ�
�����⡣һ����ң��ӣɣǣΣ��������ڡ�
LONG
        );
      
        set("valid_startroom", 1);
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        set("exits", ([
                "west"   : __DIR__"octo1",]) );
        set("objects", ([
                __DIR__"npc/waiter" : 1, 
                "/obj/npc/shusheng" :3,
            //    "/obj/npc/trashcan":1,
                ]) ); 
        set("coor/x",-1190);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
        call_other( "/obj/board/common_a", "???" );
} 
string look_sign(object me)
{
        if( wizardp(me) )
                return "����д������Ϊ��� �Ա�һ��С�֣������⡣\n";
        else
                return "����д������Ϊ����������(rent mache) ����8��\n";
}     

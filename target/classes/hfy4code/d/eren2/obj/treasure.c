#include <ansi.h>
inherit ITEM; 
void create()
{
    int i; 
    string *names = ({
        WHT"����"NOR,RED"���"NOR,MAG"���"NOR
    });
    i = random(3);
    set_name( names[i], ({ "treasure stone" }));
    set("unit", "��");
    set_weight(200);
    set("value",2000000);
    set("lore",1);
    set("long", "�����챦����ֵ���ǣ��������ۺ찡��\n");
                                            
   ::init_item();
}      

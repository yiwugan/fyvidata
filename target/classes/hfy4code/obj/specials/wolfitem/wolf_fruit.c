 inherit ITEM;
inherit F_FOOD;
#include <ansi.h> 
void create()
{
        set_name(RED"Ұ��"NOR,({"wild fruit", "fruit"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һЩ��Ұ��ɼ��Ĺ�ʵ��ɢ���Ű���ɫ�Ĺ�â����������ų�һ����\n");
            set("unit","��");
            set("value", 0);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("no_drop",1);
                set("no_give",1);
                set("material", "food");
        }
        ::init_item();
} 
int finish_eat()
{
        int value;
        int diff;
        object me;
        me=this_player();
        if (me->query("food")<220) me->add("food",10);
        if (me->query("water")<220) me->add("water",10);
                if(me->is_fighting()) {
                 return 1;
        }
        if(me->query_skill_mapped("force") == "wolf-force") {
                tell_object(me,"�㰵�������ķ���˳�ƽ���������һ���졣\n");
                value = 10+me->query_skill("wolf-force",1)*2;
                diff = this_player()->query("max_kee")-this_player()->query("eff_kee");
                if((diff)) {
                        if(value > diff) value = diff;
                        this_player()->add("eff_kee",value);
           }
        }        
        destruct(this_object());
        return 1;
}      

#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
        set_name(HIC"������ͩ"NOR, ({ "phoenix tree", "tree" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","��ɫ�����ɵ�������ƮƮ�ġ�Ҳ������죨����壩Щ������\n");               set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 10000);
                set("base_value", 10);
        }
        set_amount(1);
    ::init_item();
}
void init(){
    if(this_player()==environment()) {
        add_action("do_make","make");
    }
} 
int do_make(){
        object woodcage, me, ptree, mtree, pvine; 
        me = this_player();
    if(me->query("str") < 16)
        return notify_fail("����С�������޷������������\n");
        if( objectp(ptree = present("plum tree", me)) 
                        && objectp(mtree = present("maple tree", me)) 
                        && objectp(pvine = present("purple vine", me))){
                if((int)me->query_encumbrance() + 150000 > (int)me->query_max_encumbrance())
                return notify_fail("��ĸ���̫���޷������������\n");
                seteuid(getuid());
                woodcage = new(__DIR__"woodcage");
                if(objectp(woodcage)) {
                        woodcage->move(me);
                        message_vision("$N�����ɵ�˫������˸���������\n", me);
                }
                if(!me->query("m_success/������")){
            me->set("m_success/������",1);
            me->add("score",300);
           me->add("potential", 2000);
                me->add("combat_exp", 2000);
        }
        destruct(ptree);
        destruct(mtree);
        destruct(pvine);
        destruct(this_object());
        } else {
                return notify_fail("ȱ�������������Ĳ��ϡ�\n");
        }
        return 1;
}    

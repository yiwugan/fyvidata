#include <ansi.h>
#include <combat.h>
inherit ITEM;
void create()
{
        set_name(GRN"��ڵ�ͭ��"NOR, ({ "needle pipe"}) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��СС�ĺ�ɫԲͲ��\n"
);
                set("material", "gold");
                
        } 
        ::init_item(); 
}
void init()
{
        add_action("do_shoot","shoot");
}
int do_shoot(string arg)
{
        object ob;
        object me;
        int dp;
        int damage;
        if (!arg) return notify_fail("��Ҫ��˭��\n");
    if (query("used")) return notify_fail(this_object()->name()+"ֻ����һ�Ρ�\n");
        me=this_player();
    if ( me->query("combat_exp") < 50000 )
                return notify_fail("�㾭��̫���ˣ�û�а취����" + this_object()->name()+"�ķ����ؾ���\n");
    if( environment(me)->query("no_fight") ||
        environment(me)->query("no_magic") ||
        environment(me)->query("no_spells"))
        return notify_fail("���ⲻ��͵Ϯ��\n");
    ob=present(arg,environment(me));
    if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
    if(userp(me))
    message_vision("$Nһ���죬һ�Ժ�ɫ��ϸ��ӿ��е����������\n",me);
    if (ob->query_skill("perception")/10>random(15)) 
        message_vision("$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n",ob);
    else {
    message_vision("ţë����������$N���ϡ�\n",ob);
    ob->receive_damage("kee", 0, me);
        dp = COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
    damage=200000-dp;
    damage/=50;
    if (damage<0) damage=0;
    ob->receive_wound("kee",damage,me);    
    ob->receive_wound("gin",damage,me);    
    ob->receive_wound("sen",damage,me);    
    }
    COMBAT_D->report_status(ob);                                         
    ob->kill_ob(me); 
if (userp(me))
    set("used",1);
    me->start_busy(3);
    return 1;
}   
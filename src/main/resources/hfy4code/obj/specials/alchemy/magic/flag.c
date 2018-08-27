 // neon@fengyun.com
#include <ansi.h>
#include <combat.h>
inherit ITEM; 
void generate_name(); 
void create()
{       generate_name();
        set_weight(10);
        set("unit", "��");
        set("long", "һ����ɫ�����廨���죨shootf����\n");
        set("value", 0);
        set("level", 100);
//        set("no_drop", 1);
        ::init_item();
} 
void init(){
        add_action("do_shoot", "shootf");
        add_action("do_shoot", "shoot");
} 
int do_shoot(string arg){
        object me, target;
        int level, exp, t_exp, damage;
        string msg;
        
        me = this_player();
        if (!arg) return notify_fail("��Ҫ��˭ʹ�÷�����\n");
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ�\n"); 
        target = present(arg,environment(me));
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) ) 
                return notify_fail( this_object()->name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");      
        
        level = (int) query("level");
        damage = 0;
   
        t_exp = (int) target->query("combat_exp");
        exp   = (int) me->query("combat_exp");
   msg  = query("color") + "$N����ԣ�����ϼ������������һ" + query("unit") + name()+query("color")+"��";
        msg += query("color") + "\nֻ�����ز���ӿ��$n����\n\n"NOR;
//      random(exp)*10/4 + exp*2/3 > t_exp 
        if( random(exp)*level/40 + 2*exp/3 > t_exp ) { 
//              damage = 2000, 1000 +random(2000), gin :500+random(1000), kee, 333+random(666)
                damage = me->query_skill("alchemy",1)* level /10;
                damage = damage/2 + random(damage);
                msg +=  query("color") + "$n��û�������У������ͻ�������ţ����ɾ�ƣ������\n" NOR;
                target->add("gin",-damage/2);
                target->add("eff_gin",-damage/2);
//              message_vision("gin damage"+(string)(damage/2)+"\n",me);
                target->receive_wound("kee", damage/3, me);
//              message_vision("kee damage"+(string)(damage/3)+"\n",me);
                if (target->query("force") > damage)
                        target->add("force", 1 - damage);
                else
                        target->set("force", 0);
        } else
                msg += "���Ǳ�$n�㿪�ˡ�\n"; 
        message_vision(msg, me, target);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
           COMBAT_D->win_lose_check(me,target,1);
        }
        me->start_busy(2);
        destruct(this_object());
        return 1;
} 
void generate_name(){
        string *color = ({HIM, HIR, HIY});
        string *action = ({"¾", "��", "��","��"});
        string *kind = ({"��", "��","��"});
        string m_color =(color[random(sizeof(color))]);
        set_name( m_color +(action[random(sizeof(action))]) 
                   + (kind[random(sizeof(kind))])
                   + "�"NOR, ({ "fan" , "flag"}) );
        set("color", m_color);
        
}       

 //silencer@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void get_up(object me,object target);
int perform(object me, object target)
{
        string msg;
        int extra, myexp, enemyexp, lvl;
        object weapon,hisweapon; 
        if(me->query("class")!="beggar" && userp(me))
                return notify_fail("�����־���ֻ���ڸ�ؤ����ӣ�\n");
        
        lvl = (int) me->query_skill("dagou-stick",1);
        if(lvl < 100)
                return notify_fail("��Ĵ򹷰���������������\n");       
        
        if (me->query_skill_mapped("force") != "huntunforce")
                return notify_fail("���־���Ҫ�����ķ�����ϡ�\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        weapon = me->query_temp("weapon");
        hisweapon=target->query_temp("weapon");
        
        if (!hisweapon)
                return notify_fail("�Է�û���������޴�ʹ�á����־�����\n");
                
        if (me->query("force")<100)     
                return notify_fail("�������������\n");
                
        myexp = (int) me->query("combat_exp");
        enemyexp= (int) target->query("combat_exp");
        
        msg = HIY"\n$N"+weapon->name()+HIY"���أ�ʹ��"+NOR CYN"��"+HIY"���־�����ס$n"+HIY"��"+hisweapon->name()+HIY"����˦����\n"NOR;
        message_vision(msg,me,target); 
        if (random(enemyexp*3)<myexp && random(2)) {
           msg = HIG"\n$Nֻ��һ�ɴ������������е�"+hisweapon->name()+"����ס��ֱ�����졣\n\n"NOR;
                if(hisweapon->unequip()) hisweapon->move(environment(target));
        }  else 
                msg = WHT"$N"+WHT"������������"+hisweapon->name()+WHT"����һѹ����"+weapon->name()+WHT"���˿�ȥ��\n\n"NOR;
        
        message_vision(msg,target); 
        me->start_busy(1+random(2));            
        return 1;
}       

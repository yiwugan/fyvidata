 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        
        if ((string)me->query("class") != "wudang")
                return notify_fail(WHT"̫�����־����䵱����֮�ء�\n"NOR);
        
        extra = me->query_skill("taiji-sword",1);
        if ( extra < 150) return notify_fail("���̫���������������죡\n");
        
        if (userp(me) && me->query_skill_mapped("force") != "taijiforce")
                return notify_fail("��̫����������Ҫ��̫���ķ��ݵ���ϣ�\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۲��־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        if(target->is_busy())
                return notify_fail("�Է��Ѿ���æ�����ˡ�\n");
        
        if (target->query("step_less")==2) 
                return notify_fail(HIW"����������������տ�����ᱻ�˽����Ի�ġ�\n"NOR);
        
        myexp = (int) me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        
        if (!userp(target))
        if (hisexp>3500000) 
                hisexp = hisexp*1.5;
        
        message_vision(HIY"$N"HIY"չ��̫������������Բת���⣬������һ����һ��Ȧ�ӡ�\n"NOR,me);
        if(random(hisexp) < myexp*1.2)  {
            message_vision(HIC "$N"HIC"��$n"HIC"�Ľ�����������������������\n"NOR,target,me);
            target->start_busy(2+random(3));
        } else  {
                message_vision(HIW"���Ǳ�$N�㿪�ˣ�\n"NOR,target);        
                me->start_busy(2);
        }
        return 1;
}   

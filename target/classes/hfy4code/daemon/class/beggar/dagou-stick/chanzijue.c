 // xiaolang
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        
        if(me->query("class")!="beggar" && userp(me))
                return notify_fail("�۲��־���ֻ���ڸ�ؤ����ӣ�\n");
        
        extra = me->query_skill("dagou-stick",1);
        if ( extra < 175) return notify_fail("��Ĵ򹷰������������죡\n");
        
        if (userp(me) && me->query_skill_mapped("force") != "huntunforce")
                return notify_fail("�۲��־�����Ҫ�ۻ����ķ��ݵ���ϣ�\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۲��־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        if(target->is_busy())
                return notify_fail("�Է��Ѿ����칷����ǽ�ˣ���Ͳ�Ҫ�ڲ����ˡ�\n");
        
        myexp = (int) me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        
        if (!userp(target))
        if (hisexp>3500000) 
                hisexp = hisexp*2;
        weapon = me->query_temp("weapon");
        message_vision(HIY"$N"HIY"��׼$n��ʽ����������һ�䣬һ�С�"NOR+CYN"��"NOR+HIY"���־������е�"+weapon->name()+"���������$n��Χ��\n"NOR,me,target);
        if(random(hisexp) < myexp*1.2)  {
            message_vision(HIG "$N"HIG"�ۿ�$n�������ܣ��޷����㣬ֻ�ܾ͵�һ����ֻ��"+weapon->name()+"������$N�ڵ��ϲ�ͣ�Ļζ���\n"NOR,target,me);
            target->start_busy(2+random(3));
        } else  {
                message_vision(HIW"����$Nδ��$n��ʽʹ�ϣ���Ȼ��ס�Լ���������ȫ��������и�ɻ���\n"NOR,target,me);        
                me->start_busy(2);
        }
        return 1;
}   

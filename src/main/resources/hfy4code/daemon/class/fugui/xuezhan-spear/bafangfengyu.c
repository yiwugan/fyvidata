#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        extra = me->query_skill("xuezhan-spear",1);
        tmp = me->query_skill("hawk-steps",1); 

        if(me->query("class")!="fugui")
                return notify_fail("ֻ�и���ɽׯ���Ӳ���ʹ�����˷���������ݡ��ľ�����\n");
        if ( extra < 120) 
                return notify_fail("���Ѫսǹ�����������죡\n");
                
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "hawk-steps")
                return notify_fail("�۰˷���������ݣ���Ҫ�����������ݵ���ϣ�\n");
        if ( tmp < 100 )return notify_fail("��ģ����������ݻ��������죡\n");
        
        if ( userp(me) && me->query_skill_mapped("force") != "skyforce")
                return notify_fail("�۰˷���������ݣ���Ҫ�۱̿��ķ��ݵ���ϣ�\n");
        if ( me->query_skill("skyforce",1) < 100 )return notify_fail("��ģ۱̿��ķ��ݻ��������죡\n");
                
        if( extra >= 150 ) extra+=tmp;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۰˷���������ݣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        /*if (me->query_temp("timer/bafang")+10>time())
                return notify_fail("�۰˷���������ݣݲ�������ʹ�á�\n"); */
        me->add_temp("apply/attack",tmp*2);
        me->add_temp("apply/damage",extra*3);
    msg = HIW "\n\n$N���һ��������ìӰ�к�Ȼʹ����Ѫսǹ�����е�����һ����--�˷�--����--������--��!!\n\n\n�����š�\n$N����$w"+HIW"�ɻ�������$n"+HIW"������" NOR;
   COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�����š�\n$N����$w"NOR+HIR",��������ìӰ,���մ���$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIM  "����š�\n$N��$w"NOR+HIM"��������,Ӳ�����㳯$n"NOR+HIM"���˹�����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIY  "�ﾰ�š�\n����$N����$w"NOR+HIY"�û���ǧ��������,�����ܶ�,����$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "�ﾪ�š�\n$N��$w"NOR+HIC"��û�������,����һ����һ��������ˣ�����$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIG  "�￪�š�\n$N��������,����$w"NOR+HIG"�󿪴���,����㳯$n"+HIG"Ϯ�˹�����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIB  "�����š�\n$N�Ϻ�һ��,����$w"NOR+HIB"Ѹ�籼�׿���糸,����ͱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "�����š�\n$w"NOR+HIW"����һ�������κ�����֮���Ļ���,���絶�а㻮��$n"NOR+HIW"�����ţ�" NOR;
        me->add_temp("apply/attack",tmp*2);
        me->add_temp("apply/damage",extra*5);   
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp*4);
        me->add_temp("apply/damage",-extra*8);
        me->set_temp("timer/bafang",time());
        if (me->query_busy()<3) 
                me->start_busy(3);
        return 1;
}   

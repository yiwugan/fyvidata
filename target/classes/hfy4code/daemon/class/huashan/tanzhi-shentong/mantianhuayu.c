#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,bonus;
        int num, j, count;     
        object weapon, *enemy;
        
      if (me->query("class") != "huashan") 
              return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á����컨�꡹��\n");
        
        if((int)me->query_skill("tanzhi-shentong",1) < 50)
                return notify_fail("��ĵ�ָ��ͨ������������\n");
        
        num = (int)(me->query_skill("throwing")/ 100);
        if (num>4) num=4+(me->query_skill("tanzhi-shentong",1)-160)/40;
        weapon = me->query_temp("weapon");
        count = weapon->query_amount();
        if (count < 10)
                return notify_fail("��İ�������̫�١�\n");
                
        enemy=me->query_enemy();
        if(!sizeof(enemy))
                return notify_fail("�����컨���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target)
                return notify_fail("������в���Ҫָ��ʹ�ö��󣡣�\n");
        
        
        if (me->query("class")== "huashan") {
                extra = me->query_skill("throwing");
        }
                        
        me->add_temp("apply/damage", extra);
        me->add_temp("apply/attack", extra);
        msg = YEL  "$N��߳һ��������һ�����"+ weapon->name() +"��Ȼ�����з׷׷ɳ���\n"CYN"����"+HIC"  ��"+HIG"  ��"+HIY"  ��"+HIR"  ��"+NOR CYN" �����ڳ�ÿһ���ˣ�\n" NOR;
        message_vision(msg,me);
        weapon->set_amount(count-1);
        i = 0; 
        for (j=0; j<num;j++)
   {
                msg=HIY"$N���е�$w����$n��$l����"NOR;
                COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
                if (i==sizeof(enemy)-1) i=0;
                        else i++;
        }
        if (me->query("class") == "huashan" && me->query("open_sesame_1")) {
                message_vision(YEL"\n$N����һ��ת�ۣ�����"+weapon->name()+NOR YEL "�������������\n\n"NOR,me);  
                i= sizeof(enemy)-1;
                for ( j = num; j>0; j--)
                {
                        msg=HIY"$N���е�$w����$n��$l����"NOR;
                        COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
                        if (i==0) i=sizeof(enemy)-1;
                                else i--;
                }
        }
        
        
        me->add_temp("apply/damage", -extra); 
        me->add_temp("apply/attack", -extra);
        if (num>2) { 
                if (me->query_busy()<3) 
                        me->start_busy(3);
                }
        else   {
                if (me->query_busy()<2) 
                        me->start_busy(2);
                }
        return 1;
}      

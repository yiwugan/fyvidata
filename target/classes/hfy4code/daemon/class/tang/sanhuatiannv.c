#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,bonus;
        int num, j, count;
        object weapon, *enemy;
        
      
        
        if((int)me->query_skill("mantian-huayu",1) < 50)
                return notify_fail("������컨�껹����������\n");
        
        num = (int)(me->query_skill("throwing")/ 100);
        if (num>4) num=4+(me->query_skill("mantian-huayu",1)-160)/40;
        weapon = me->query_temp("weapon");
        count = weapon->query_amount();
        if( (int)me->query("max_force") < 500 ){
                return notify_fail("�������������û�а취ʹ����ɢ����Ů�ݡ�\n");
        }
                
        enemy=me->query_enemy();
        if(!sizeof(enemy))
                return notify_fail("��ɢ����Ů��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target)
                return notify_fail("������в���Ҫָ��ʹ�ö��󣡣�\n");
        
        
        
        extra = me->query_skill("throwing");
        me->add_temp("apply/damage", extra);
        me->add_temp("apply/attack", extra);
        msg = YEL  "$N�ƺ�һ��������һ�"+ weapon->name() +"�����зɳ�����Ȼը����\n"CYN"���ѳ�ǧǧ�����"+ weapon->name()+"����ͬ��Ůɢ��������\n" NOR;
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
        if (me->query("class") == "tang" && me->query("open_sesame_1")) {
                message_vision(YEL"\n$N����һ��ת�ۣ���������һʽ��ɢ����Ů�ݣ�"+weapon->name()+NOR YEL "�������䡣����\n\n"NOR,me);  
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

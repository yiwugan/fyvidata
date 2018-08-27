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
                return notify_fail("你的满天花雨还不够精纯！\n");
        
        num = (int)(me->query_skill("throwing")/ 100);
        if (num>4) num=4+(me->query_skill("mantian-huayu",1)-160)/40;
        weapon = me->query_temp("weapon");
        count = weapon->query_amount();
        if( (int)me->query("max_force") < 500 ){
                return notify_fail("你的内力不够，没有办法使出［散花天女］。\n");
        }
                
        enemy=me->query_enemy();
        if(!sizeof(enemy))
                return notify_fail("［散花天女］只能对战斗中的对手使用。\n");
        if(target)
                return notify_fail("这个绝招不需要指定使用对象！！\n");
        
        
        
        extra = me->query_skill("throwing");
        me->add_temp("apply/damage", extra);
        me->add_temp("apply/attack", extra);
        msg = YEL  "$N闷哼一声，衣袖一扬，"+ weapon->name() +"从袖中飞出，忽然炸开，\n"CYN"爆裂成千千万万的"+ weapon->name()+"，如同天女散花！！！\n" NOR;
        message_vision(msg,me);
        weapon->set_amount(count-1);
        i = 0; 
        for (j=0; j<num;j++)
   {
                msg=HIY"$N手中的$w射向$n的$l！！"NOR;
                COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
                if (i==sizeof(enemy)-1) i=0;
                        else i++;
        }
        if (me->query("class") == "tang" && me->query("open_sesame_1")) {
                message_vision(YEL"\n$N身形一个转折，回身又是一式［散花天女］，"+weapon->name()+NOR YEL "连连激射。。。\n\n"NOR,me);  
                i= sizeof(enemy)-1;
                for ( j = num; j>0; j--)
                {
                        msg=HIY"$N手中的$w射向$n的$l！！"NOR;
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

 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int extra;
    int tmp,chance;
    extra = me->query_skill("tang-blade",1);
    if ( extra < 70) return notify_fail("你的［五瓣兰刀法］还不够纯熟！\n");
        if (me->query("class")== "huashan") extra = extra * 8;
        if (me->query("class")=="legend") extra = extra * 2;
        if (me->query("class")=="official") extra = extra * 3;
        if (me->query("class")=="beggar") extra = extra * 5;
        
    if( !target ) target = offensive_target(me);
    if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("［瓣兰五式］只能对战斗中的对手使用。\n");
    me->add_temp("apply/attack",extra);
if (me->query("class")=="huashan")   me->add_temp("apply/damage",extra/2);
if (me->query("class")=="beggar")   me->add_temp("apply/damage",extra);
    msg = HIW  "\n$N使出五瓣兰刀法中的——［"+HIC"瓣兰五式"+HIW"］，一招连环五式，有若兰花绽放！！\n\n"NOR;
        msg+=HIC"第一刀！兰花初现" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
   
        msg = HIC"第二刀！兰花巍巍" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

        msg = HIC "第三刀！花开花落" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       
		msg = HIC  "第四刀！日斜星河" NOR;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    
        msg = HIC  "第五刀！兰花五瓣" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
 
    me->start_busy(3);
    me->add_temp("apply/attack",-extra);
if (me->query("class")=="huashan")    me->add_temp("apply/damage",-extra/2);
if (me->query("class")=="beggar")   me->add_temp("apply/damage",-extra);
    return 1;
}  

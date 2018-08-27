//ximen@sxfy
//update by xiaolang 2006-9-14
//铁血是有血性的门派，所以，此招可以减少自己的气血，提高自己的战斗力
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill,n,extra; 
        if (me->query("class") != "tieflag") 
                return notify_fail("只有铁血大旗门弟子才可以使用「"HIR"铁血照丹心"NOR+"」。\n");
        if (me->query("family/master_id")!="master yun" )
                return notify_fail("只有云铮亲传弟子才可以使用「"HIR"铁血照丹心"NOR+"」。\n");
        if( target != me ) 
                return notify_fail("「"HIR"铁血照丹心"NOR"」只能用在自己身上。\n"); 
        if( (int)me->query("force") < 300 )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("tiexue") )
                return notify_fail("你已经在运功中了。\n");
//        if( (int)me->query("kee") >= (int)me->query("max_kee")*2/3)
//        	      return notify_fail("不到万不得已，最好别用这招！\n");
        skill = me->query_skill("tiexue-force", 1);
        if(skill < 100) return notify_fail("你的铁血心法修为还没到家！\n");
        me->add("force", -300);
        message_vision(HIR"$N长啸一声，心中涌起无边斗志，一股白色的"HIW"斗气"HIR"渐渐笼罩全身。\n" NOR, me);
        me->set_temp("tiexue", 1); 
        n = 8 - (int)me->query("kee")*10/(int)me->query("max_kee");
        if(n>=5) n=5;
        if(n<=0) n=1;
        extra = skill*n/5;
        me->add_temp("apply/unarmed", extra);
        me->add_temp("apply/sword", extra);
        me->add_temp("apply/dodge", extra);
        me->add_temp("apply/move", extra);
        me->add_temp("apply/parry", extra);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
extra :), skill/6); 
        return 1;
} 
void remove_effect(object me, int extra)
{
	      if(!objectp(me)) return;//这个最好加上，万一object不再了，会出错的,by xiaolang
        me->delete_temp("apply/unarmed", extra);
        me->delete_temp("apply/sword", extra);
        me->delete_temp("apply/dodge", extra);
        me->delete_temp("apply/move", extra);
        me->delete_temp("apply/parry", extra);
        me->delete_temp("tiexue");
        tell_object(me, "你的心中的斗志渐渐消失，身上的斗气也消散于无形。\n");
}
       
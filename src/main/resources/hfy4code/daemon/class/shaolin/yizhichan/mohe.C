#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int target_perform(object me, object target); 
int perform(object me, object target)
{
    string msg;
    int extra,i,j,lmt,damages,bell;
  //  object weapon;
    object *enemy;
    
    extra = me->query_skill("yizhichan",1);
    if ( extra < 100)
        return notify_fail("你的一指禅还不够纯熟！\n");
        
    enemy=me->query_enemy();
    if(!sizeof(enemy))
                return notify_fail("［摩诃］只能对战斗中的对手使用。\n"); 
        
    if(target)  return notify_fail("［摩诃］不需要指定使用对象！！\n");
    
   
    if (me->query_skill("force",1) > 320)
         extra*=5;
        else extra*=2;
        
   // weapon = me->query_temp("weapon");
    if(extra <= 300)
    {
        damages = extra/6;
        msg = HIY"\n不生不灭，不垢不净，不增不减，$N默念佛号，双手指指点点，顿时气劲激射。" NOR;
        message_vision(msg,me,enemy[0]);
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/str",damages/50);
    }
    else
    {
    if ((me->query_skill("zen",1) > 200) ||	 (me->query_skill("buddhism",1) > 220) || 	 (me->query_skill("chanting",1) > 220)  )
		            damages = extra*3/2;
                else {damages = extra/3;}
         if (query("once_xman")==1)  damages = damages ; else {damages = damages / 2;}
        
       msg = HIY"\n$N默念佛号，身上似乎泛起一片佛光，刺得$n几乎睁不开眼，说时迟那时快，漫天指劲破空而至！" NOR;
        message_vision(msg,me,enemy[0]);
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/str",damages/50);
    }
    lmt = random(5)+3;
         if (extra <= 220 && lmt > 3) lmt= 3;
        	if (extra <= 300 && lmt > 4) lmt= 4;
        		if (extra <= 400 && lmt > 5) lmt= 5;
         
    j=0;
    for(i=1;i<=lmt;i++)
    {
        msg =  HIY "波～罗～僧～揭～谛～菩～提～萨～婆～诃～～" NOR;
        COMBAT_D->do_attack(me,enemy[j],TYPE_PERFORM,msg);
        if (j==sizeof(enemy)-1) j=0;
                        else j++;
    }
    me->add_temp("apply/attack",-damages*3/2);
    me->add_temp("apply/str",-damages/50);
    
    
    if (me->query_busy()<2) 
                me->start_busy(2);
    
    return 1;
}  
int target_perform(object me, object target)
{
    string msg;
    int extra,i,j,lmt,damages,bell;
    //object weapon;
    object *enemy;
            
    extra = me->query_skill("yizhichan",1);
        if (me->query_skill("force",1) > 320)
         extra*=5;
        else extra*=2;
    //weapon = me->query_temp("weapon");
    if(extra <= 300)
    {
       damages = extra/6;
        msg = HIY"\n不生不灭，不垢不净，不增不减，$N默念佛号，双手指指点点，顿时气劲激射。" NOR;
        message_vision(msg,me,enemy[0]);
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/str",damages/50);
    }
    else
    {
        if ((me->query_skill("zen",1) > 200) ||	 (me->query_skill("buddhism",1) > 220) || 	 (me->query_skill("chanting",1) > 220)  )
		            damages = extra*3/2;
                else {damages = extra/3;}
         if (query("once_xman")==1)  damages = damages ; else {damages = damages / 2;}
        
       msg = HIY"\n$N默念佛号，身上似乎泛起一片佛光，刺得$n几乎睁不开眼，说时迟那时快，漫天指劲破空而至！" NOR;
        message_vision(msg,me,enemy[0]);
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/str",damages/50);
    }
    lmt = random(5)+3;
         if (extra <= 220 && lmt > 3) lmt= 3;
        	if (extra <= 300 && lmt > 4) lmt= 4;
        		if (extra <= 400 && lmt > 5) lmt= 5;
         
    for(i=1;i<=lmt;i++)
    {
         msg =  HIY "波～罗～僧～揭～谛～菩～提～萨～婆～诃～～" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);  
    }
    
    me->add_temp("apply/attack",-damages*3/2);
    me->add_temp("apply/str",-damages/50);
  
    if (me->query_busy()<2) 
                me->start_busy(2);
    return 1;
} 

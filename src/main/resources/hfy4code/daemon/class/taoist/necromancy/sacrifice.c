 // sacrifice.c silencer@fy
#include <ansi.h>
inherit SSERVER; 
int cast(object me, object target)
{ 
        object corpse;
        int i, num;
        
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n");
        
        if((int)me->query_skill("necromancy",1) < 150 )
                return notify_fail("���������������ߣ�\n");
        
        if(me->is_fighting()) 
                return notify_fail("ս���в���ʩ�˷�.\n");
        
        if((int)me->query("mana") < 100 )
                return notify_fail("��ķ���������\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("����񲻹���\n");
        
        num = (me->query_skill("necromancy",1)-150)*3/2+10;
        
        if  (me->query("timer/zombie")+600<time()) 
                me->set("timer/zombie_n",0);
        
        if (!me->query("timer/zombie_n")) me->set("timer/zombie",time());
        
        if (me->query("timer/zombie")+600>time() && me->query("timer/zombie_n")>num)
                return notify_fail("���������˥����Ҫ��Ϣһ������ܼ����ٻ���\n");
        
        
        seteuid(getuid());
        corpse = new("/obj/item/mocorpse");   
        corpse->set("name",HIR"��ħ"NOR);
        corpse->set("victim_name",HIR"��ħ"NOR);
        corpse->set("no_burn",1);
        corpse->set("long",
                
"����һ������а����۳ɵĹ��������������������һֻ���ǡ�\n");
        corpse ->move(environment(this_player()));
        me->add("mana", -100);
        me->receive_damage("sen", 100);
        me->add("timer/zombie_n",1);
        me->start_busy(1);
        
        message_vision(HIB"$N�����૵��������ģ�����һ�ӣ���Ȼ��һ�ź��̴ӵ�����ð��\n" NOR,me);
        message_vision(HIB"Ƭ�̣��������۳����Σ�ȴû��һ��������\n"NOR,me);
        return 1;
}
              

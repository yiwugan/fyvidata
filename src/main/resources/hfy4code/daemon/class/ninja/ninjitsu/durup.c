 // void_sense.c
#include <ansi.h> 
inherit SSERVER;
int conjure(object me, object target)
{
        int lvl,i,extra,kee,gin,sen,exp,dur;
        object env, *inv;
        
        
//      if (me->query("class")!="ninja")
//              return notify_fail("ֻ�����߲���������.\n");
        
        if(me->query_temp("ninjitsu_durup")) return notify_fail("�������Ѿ����ھ���ļ��ȿ���״̬�ˡ�\n");
        
        lvl = (int) me->query_skill("magic");
                
        if ( (int) me->query_skill("ninjitsu",1) <= 50)
                return notify_fail("�����������ߣ�\n");
        if( target != me ) 
                return notify_fail("��ֻ�������Լ������ϡ�\n");        
            
        if( me->query("atman") < 300 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 250 )
                return notify_fail("��ľ�������\n");
        me->add("atman", -300);
        me->receive_damage("gin", 250);
        kee = me->query("max_kee");
        sen = me->query("max_sen");
        gin = me->query("max_gin");
        
        extra=lvl/2;
        if (me->query("class")=="shaolin")  extra = extra *5/2;
        me->add_temp("apply/durability",extra);
        
        exp = ((me->query("combat_exp")/1000000) + 1 );
        dur=(me->query("dur")/10);
        if (exp >=10) exp =10;
        if (dur >=5) exp =5;
        	
        
        me->set("max_kee",extra*exp*dur+kee);
        me->set("max_gin",extra*exp*dur+gin);
        me->set("max_sen",extra*exp*dur+sen);
        
        me->set_temp("ninjitsu_durup",1);
        me->set_temp("mark/no_uncon",1);
        message_vision(HIM "$N���۹������룬�ƺ��Ѿ���һ��ǿ��ľ������������ƣ�����\n" NOR, me);
            
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,extra,kee,gin,sen:), lvl/dur);
        if( me->is_fighting() ) me->start_busy(2);
        return 1; 
}
void remove_effect(object me,int extra,int kee,int gin,int sen)

{       
        /*int extra,lvl;
        lvl = (int) me->query_skill("magic");
        extra=lvl/2;
        if (me->query("class")=="shaolin")  extra = extra *5/2;*/
        me->add_temp("apply/durability", - extra);
        
        me->set("max_kee", kee);
        me->set("max_gin", gin);
        me->set("max_sen", sen);
        
        me->delete_temp("ninjitsu_durup");
        me->delete_temp("mark/no_uncon");
        message_vision(HIW"$N������ָ������������Ѿ��ص�������״̬��\n"NOR,me);
        
}     

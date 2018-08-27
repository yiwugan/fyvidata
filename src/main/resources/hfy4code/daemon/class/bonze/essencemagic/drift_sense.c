 // drift_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        
        if(me->query("class")!="bonze" && me->query("class")!="yinshi" )
                return notify_fail("ֻ�еõ���ɮ����������ʿ�ſ���ʹ����ʶ��ͨ��\n");
        
        if((int) me->query_skill("essencemagic",1) < 60)
                return notify_fail("��İ�ʶ��ͨ�������\n");
        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ����ʶ��ͨ��\n");
        if( me->query("atman") < 300 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 100 )
                return notify_fail("��ľ�������\n");
        if( me->is_ghost())
                return notify_fail("����޷�ʹ����ʶ��ͨ��\n");  
        if( me->query("have_mission") )
                return notify_fail("����֯������������ʹ����ʶ��ͨ��\n");  
        if( me->query("mission_over") )
                return notify_fail("��ֻ����������������֯��ȡ������\n");    
        if( target )
                return notify_fail("��ʶ��ֻͨ�ܶ��Լ�ʹ�ã�\n");
        write("��Ҫ�ƶ�����һ������ߣ�");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
} 
void select_target(object me, string name)
{
        object ob; 
        if( !name || name=="" ) {
                write("��ֹʩ����\n");
                return;
        } 
        ob = find_living(name);
        if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)
        || !ob->query("max_force") || !ob->query("force") ||userp(ob)
// the following check start/arrival room.      
        || environment(ob)->query("no_death_penalty")
        || environment(me)->query("no_fly")
        || environment(ob)->query("no_fly")
// the following is the NEW FLY FLAG, all NPCs are non-driftable by default.    
   /*|| !ob->query("fly_target")*/
        ) {
                write("���޷����ܵ������ ....\n");
                write("��Ҫ�ƶ�����һ������ߣ�");
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
        
        if( me->is_fighting() ) {
                write("ս�����޷�ʹ����ʶ��ͨ��\n");
                return;
        } else if( me->query("atman") < 100 ) {
                write("�������������\n");
                return;
        } 
        me->add("atman", -100);
        me->receive_damage("gin", 50);
        
        message_vision( HIY "$N��ͷ��Ŀ����ʼʩչ��ʶ��ͨ ....\n" NOR, me);
        
        if( random(ob->query("max_force")) < (int)me->query("force")/50) {
                write("����ܵ��Է������������ǲ���ǿ�ҡ�\n");
                return;
        }
        
        if( random(80) > me->query_skill("essencemagic",1)){
                write("����Ϊ����������ʧ���ˡ�\n");
                return;
        }
        
        if(environment(ob)->query("no_magic")||environment(ob)->query("no_fly")) {
                write("����Ҫ��ʶ�ĵط�����������ͨ��\n");
                return;
        }
        
        message( "vision", HIY "\nһ��ҫ�۵Ĺ�â��Ȼ��ס" + me->name() 
                + "���������ᣬ��â����һ����ʧ����Ӱ���٣�\n\n" NOR, environment(me), ({ me }) );
        me->move(environment(ob));
        message( "vision", HIY "\n�����ǰͻȻ����һ��ҫ�۵Ĺ�â����â�и��ֳ�һ����Ӱ��\n\n" NOR,
                environment(ob), ({ me }) );
}        

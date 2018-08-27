 // chase.c
#include <ansi.h> 
inherit SSERVER; 
int curse(object me, object target)
{
        string targetname;
        object room,ob;
        int skill,atman,perp;
        int mexp;
        
        if(me->query("class")!="wolfmount")
                return notify_fail("ֻ����ɽ���Ӳ���ʹ�����潵����\n");
        
        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ�������ͷ����\n");
                
        if( me->query("have_mission") )
                return notify_fail("������֯�������������á��潵����\n");
            
        if( me->query("mission_over") )
                return notify_fail("��ֻ����������������֯��ȡ������\n");
 
        if( me->query("kee") <= 100 )
                return notify_fail("�����Ѫ������\n"); 
        if( (skill=me->query_skill("wolf-curse",1)) < 100 )
            return notify_fail("��Ľ�ͷ���������\n"); 
        if( !(ob=me->query_temp("chase_target")))
                return notify_fail("��û���¹��潵���������潵�����Ѿ����ˡ�\n");
        
        if (environment(ob)->query("no_fight")||environment(ob)->query("no_magic")
                ||environment(ob)->query("no_death_penalty"))
                        return notify_fail("�Ǹ��ط������ܵ�����ı�����\n"); 
        if ( environment(me)->query("no_fly") || environment(ob)->query("no_fly"))
                return notify_fail("�˵ز���ʹ���潵��\n");
        
        if( me->is_ghost())
                return notify_fail("����޷�ʹ���潵��\n");     
        
        if(! ob->is_character())
                return notify_fail("׷��������������ǲ��Ǿ��ú����ģ�\n"); 
        
        if( ob->is_ghost())
                return notify_fail("�˹���;���㲻��׷�٣�\n"); 
        
        me->receive_damage("kee", 100);
        mexp=(int)me->query("combat_exp");
       	if( mexp>100000000 )
       		mexp=100000000;
       		
        if( random(mexp/20*skill) <ob->query("combat_exp"))
           {
                 message_vision( HIW "$N��ɫ��Ȼ�����������дʣ���ʲô��Ҳû������\n" NOR, me);
                 return notify_fail("��Ľ�ͷ��������������\n");        
                }
                        
        if (environment(ob)->query("no_fight")||environment(ob)->query("no_magic")||environment(ob)->query("no_fly"))
                return notify_fail("�Ǹ��ط������ܵ�����ı���.\n");
                
        if (me->query_temp("in_chase"))
                return notify_fail("���Ѿ���׷�ٶԷ���");
        
        message_vision( HIW "$N��ɫ��Ȼ�����������дʣ���Ӱ������ģ������ ....\n" NOR, me);
        me->set_temp("in_chase");
        room = environment(ob);
        me->start_busy(2); 
        perp=ob->query_skill("perception",1);
        if (perp/10>random(10)|| random(5)) tell_object(ob,HIW"��ֻ����һ�������ɱ��������Ϯ����\n"NOR);
        
        me->start_call_out( (: call_other, __FILE__, "iam_coming", me,ob,room:), 6);
        return 1;
}  
void iam_coming(object me,object ob,object room)
{
        
        string id_enemy;
        int eff_shen,shen,skill;
        if (me->is_ghost()) {
                tell_object(me,YEL"����ô���˹��ˣ������޷�׷���˵ģ�\n"NOR); 
                me->delete("in_chase");
                return;
                } 
                
        me->move(room); 
        message( "vision", HIW "\n��Ȼһ�����̴ӵ���ð����"+me->query("name")+"�������г��֣�\n\n" NOR,
                room, ({ me }) );
        if ( environment(ob) != environment(me)) {
                        tell_object(me,HIW"̫��ϧ��,"+ob->name()+"�մ������뿪.\n"NOR);
                        return;
                }
        shen=ob->query("sen");
   eff_shen=ob->query("eff_sen");
        if (shen>eff_shen/2+100 && random(me->query("combat_exp"))*10>ob->query("combat_exp"))          
                ob->receive_damage("sen", shen/2, me);
        me->delete("in_chase");
        me->start_busy(2);
        ob->kill_ob(me);
        me->kill_ob(ob);        
}        

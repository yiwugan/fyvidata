 // - by neon
#include <ansi.h>
inherit F_CLEAN_UP;
void move_team(object me,object ob);
int main(object me, string arg)
{
        string what, who;
        object ob, *team;
        int i, delay;
        object where = environment(me);
        if ( me->query("class")!="beggar" )
          return notify_fail("ֻ��ؤ����Ӳ��ܷɸ봫�飡\n"); 
        if( environment(me)->query("no_beg") ||environment(me)->query("no_magic")
                || environment(me)->query("no_fly")
        )
                return notify_fail("�����ǲ��ʺ�ؤ�����ʹ�÷ɸ봫�飡\n"); 
        if( me->is_busy() )
                return notify_fail("����������æ��\n"); 
        if( me->query_temp("inform_in_progress") )
                return notify_fail("����Ÿ����ڽ������ѣ�\n"); 
        if( !arg ) return
                notify_fail("ָ���ʽ��inform <ĳ��>\n"); 
        if ( (int)me->query_skill("begging",1) < 100 
                || me->query("combat_exp")<2000000
                || !me->query("open_sesame") )
        {
                return notify_fail("�����ڻ�û������ʹ�÷ɸ봫�顣\n");
        } 
        if( !pointerp(team = me->query_team()) )  
                return notify_fail("�㲢û���κζ��ѣ�\n");
                
        ob = find_player(arg);
        if (!ob || ob == me) return notify_fail("��Ҫ�ɸ봫���˭��\n");
        for ( i=0; i<sizeof(team); i++) {
                if (team[i]==ob ) break;
        }
        if (i == sizeof(team)) return notify_fail("�ɸ벻�ܴ��������������ˡ�\n");
// Now start to summon 
        if (environment(ob) == environment(me)) return notify_fail(ob->name() + "�Ѿ���������ˣ�\n");
        
        message_vision(WHT"$N��Ȼһ���֣�һֻ��ɫ���Ÿ��ڿն������������з���Զ����\n"NOR, me);
        me->set_temp("inform_in_progress", 1);
        
        if(environment(ob)->query("no_magic")) {
                message_vision(WHT"\n���ǣ��Ÿ���Զ��������һ������ַɻ�$N���\n"NOR, me);   
                me->delete_temp("inform_in_progress", 1) ;
                write("�Ÿ��޷�������Ķ��ѣ�\n");
                return 1;
        }
                        
        if (ob->is_busy() || ob->is_fighting()) {
                message_vision(WHT"\n���ǣ��Ÿ���Զ��������һ������ַɻ�$N���\n"NOR, me);   
                me->delete_temp("inform_in_progress", 1);
                write(ob->name()+"�ƺ�û�п����������Ÿ롣\n");
                return 1;
        }
        message_vision(WHT"һֻ��ɫ���Ÿ��Ȼ��������$Nͷ�����·ɶ���һ����������Զ����ȥ��\n$N��ɫһ�ݣ�����չ���Ṧ��׷��ɸ��ȥ��\n"NOR, ob);        
        tell_object(ob, "\n ... \n��ӿ�Ų������Ÿ�ָ������ǰ������\n");       
        
        delay = 500/ (1 + ob->query_skill("move")) + 1;
        delay = delay >5 ? 5 : delay;
        delay = delay <2 ? 2 : delay;
        ob->start_busy(delay +1);
        me->start_busy(delay +1);
        call_out("move_team",delay, me,ob);     
        return 1;       
}  
void move_team(object me, object ob){
        
        message_vision(WHT"�Ÿ뻮��һ����ɫ�Ļ��ߣ��ɻص�$N���$n�ں���ҴҸϵ���\n"NOR, me, ob);     
        ob->move(environment(me));
        me->delete_temp("inform_in_progress", 1);
} 
int help(object me)
{
write(@HELP
ָ���ʽ : inform <����>
�ɸ봫�飬����һ��ؤ��ר�õ�ָ����Ժ������ѵİ����� 
HELP
    );
    return 1;
}  

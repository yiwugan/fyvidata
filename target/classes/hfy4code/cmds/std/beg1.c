 // TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string what, who;
        object ob, victim;
        mapping myfam, vtfam;
        int sp, dp; 
        object where = environment(me);
        if ( userp(me) && me->query("class")!="beggar" )
          return notify_fail("ֻ��ؤ����Ӳ������֣�\n"); 
        if( environment(me)->query("no_beg")
                || domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("�����ǲ��ʺ�ؤ������ַ��ĵط���\n"); 
        if( me->query_temp("begging") )
                return notify_fail("������������������ˣ�\n"); 
        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
                notify_fail("ָ���ʽ��beg <ĳ��> from <ĳ��>\n"); 
        if ( userp(me) && ((int)me->query_skill("begging",1) < 25 || me->query("combat_exp")<10000))
        {
                return notify_fail("�����ڻ�û���������֡�\n");
        } 
        victim = present(who, environment(me)); 
        if( !victim || victim == me) return notify_fail("�������ֵĶ��������\n"); 
        if( !living(victim) || !objectp(victim))
                return notify_fail("��Ҫ��˭���֣�\n"); 
        if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "ؤ��" )
                return notify_fail("�㲻���򱾰�������֣�\n"); 
        if( !wizardp(me) && wizardp(victim) )
                return notify_fail(victim->name()+"����ʩ������κζ����ġ�\n"); 
        if( me->is_fighting() )
                return notify_fail("������һ�ߴ��һ�����֣�\n"); 
        if( victim->is_fighting() ) 
                return notify_fail(victim->name() + "���ڴ�ܣ�û�����㣡\n");
        
        if((int)me->query_skill("begging",1) < 25)
                return notify_fail(victim->name()+"���󲻻�ʩ������κζ����Ƶġ�\n");
        
        if( !ob = present(what, victim) ) {
           object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + "���Ͽ�����û��ʲ���������Ȥ�Ķ�����\n");
                ob = inv[random(sizeof(inv))];
        } 
        if ( ob->query("equipped") || ob->query("no_drop") || ob->query("owner"))
                return notify_fail(victim->name()+"���󲻻�ʩ������κζ����Ƶġ�\n");
        if(me->query("sen") <= 100 && userp(me))
                return notify_fail("�㾫���㣬�������֡�\n"); 
        if (userp(me)) 
                me->add("sen",-100); 
        sp = (int)me->query_skill("begging",1) * (int)me->query_skill("begging",1) 
     + (int)me->query_kar() * (int)me->query_kar() * (int)me->query_kar() ;
         if(me->query_skill("begging",1)<50)
                sp=sp/3;
        if( sp < 1 ) sp = 1;
        dp = (int)victim->query("bellicosity")-(int)victim->query("score") + 30000;
        tell_object(me, "��һ�������Ͱ͵����ӣ���������" + victim->name() + "�߹�ȥ�����˫�֣���Ҫ"
                        + ob->query("unit") + ob->name() +"...\n\n");
        tell_object(victim, me->name() + "һ�������࣬���������߹���������֣�˵����" + RANK_D->query_respect(victim) + "���кã�����" 
                        + ob->query("unit") + ob->name() + "�� ...��\n\n");
        message("vision", "ֻ��" + me->name() + "װ�������Ͱ͵����ӣ���������" 
                + victim->name() + "�߹�ȥ��\n���˫�֣�˵����"
                + RANK_D->query_respect(victim) + "�����кð� ...\n\n", environment(me), ({ me, victim }) ); 
        me->set_temp("begging", 1);
        call_out( "compelete_beg",random(3)+1, me, victim, ob, sp, dp); 
        return 1;
} 
void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
        int amount;
        object ob1; 
        me->delete_temp("begging");
        if(!victim) {
                tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ������ˡ�\n");
                return;
        }
        if( environment(victim) != environment(me) ) {
                tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ����ˡ�\n");
           return;
        }
// exp limit to stop beggar dummies
        if (userp(me) && victim->query("combat_exp")>me->query("combat_exp")*15) {
                tell_object(me,victim->name()+"��м�ؿ�����һ��˵������ȥ�����ɡ���\n");
                return;
        }
// not a human being    
        if(!victim->query("spi")) {
                tell_object(me,victim->name()+"�������޶����ԣ�\n");
                return;
        }
        if( living(victim) && (random(sp+dp) > dp) && ob->move(me)) 
        {
                message_vision("$N����$n�Ŀ�������̾�˿���������$nһ" 
                                + ob->query("unit") + ob->name() + "��\n",victim,me);
                me->start_busy(3);
        } 
        else 
        {
                if( random(sp+dp) > dp/2 ) {
                message_vision("$NŤ��ͷȥ����$n������\n", victim,me);
                me->start_busy(3);
                        return;
                }
                else
                message_vision("$N�ݺݵص���$nһ�ۣ��ȵ�����л��ӣ������ᣡ�������ˣ�\n", victim,me);
                if(!environment(victim)->query("no_fight"))     
                victim->fight_ob(me);
                me->start_busy(3);
        }
} 
int help(object me)
{
write(@HELP
ָ���ʽ : beg <����> from <����>
����һ��ؤ��ר�õ�ָ� 
HELP
    );
    return 1;
}       

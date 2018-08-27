 // reaction.c
#include <ansi.h>
#include <combat.h> 
inherit SSERVER; 
void reacted(object me, int skill, int extra, int luck, object ding); 
int conjure(object me, object target)
{
        object ding, env;
        int skill, value, extra, luck;
        
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬�ĵ��Ӳſ���������\n");
        if(me->query("gender")!="����")
                return notify_fail("������岻�ʺ��������Ͽỷ����\n");
        if(me->is_fighting())
                return notify_fail("ս�����յ�������Է٣�\n");
        if( !target)
                return notify_fail("��Ҫ��ʲô������\n");
        target = present(target->query("id"), me);
        if( !target)
                return notify_fail("������û���ⶫ����\n");
        if (target->query("id")=="ding")
                return notify_fail("�㲻���������Ʒ��������\n");
                                
        if( living(target) )
                return notify_fail(target->name() + "�����ţ�������յ�����\n"); 
        if( target->query("no_burn") )
                return notify_fail(target->name() + "�����������յ��ˡ�\n"); 
        
        env = environment(me);
        skill = (int) me->query_skill("alchemy",1);
    
        if(skill < 31)
                return notify_fail("����������������\n");
        
        
        if( !objectp(ding = present("ding", env)) && !objectp(ding=present("ding",me)) )
                        return notify_fail("����û�п��������ı�����\n");
                                
        if (strsrch(ding->query_default_object(), "/obj/specials/ding/ding")== -1) 
                   return notify_fail("�����ϡ��Ź֣����»�����������\n");
        
        if (target->query_weight()>10000 && ding->query("small_ding"))
                        return notify_fail("�������̫��̫�أ�С����Ų��¡�\n");
        
        if(ding->query_temp("in_use"))
                    return notify_fail("����������������������㻹�ǵ�һ�Ȱɡ�\n");
        if(ding->query_temp("broken"))
                    return notify_fail("������Ѿ�ʧȥ���񣬲��������ˡ�\n"); 
        if( (int)me->query("atman") < 80 ) return notify_fail("�������������\n");
        if( me->query("sen") <= 60 )
                return notify_fail("����񲻹���\n");
        me->add("atman", -80);
        me->receive_damage("sen", 60);
        message_vision( HIC "$N��$n"HIC"Ͷ��"NOR + ding->name()+ HIC"��\n$N��������ֻ��һƬ����"NOR+ding->name()+HIC"������...\n" NOR, me, target);
        ding->set_temp("in_use", 1);
        
        extra = (int) target->query("value");
        
        target->move(env);
        destruct(target);
        luck = (int) me->query("kar");
        call_out("reacted", 3 ,me, skill, extra, luck , ding); 
        me->start_busy(3);
        return 1;
} 
        
void reacted(object me, int skill, int extra, int luck, object ding)
{
        object dan, devil;
        string to_cure, desc;
        int rand;
        string *cure_type = ({"gin", "kee", "sen", "kee", "gin", "sen", "all"});
        string *trash = ({"blade", "dart", "leg", "skin", "teapot", "axe", "dagger"});
        string *magic = ({"zhui", "mirror", "chain", "flag"});
    // First have to pass a skill*kar related luck test
        if (random(luck*skill - 240)<3) {
        message_vision( NOR MAG"\nһ�ɹ����̴Ӷ���ð��..." , me);
        message_vision( NOR "\n\n"+ding->name()+HIW"������죬�·�ʤ�غ�һ��...\n" NOR YEL "\n��Ȼ��һ������ϼ�������˴Ӷ������𣬹�����Ц�У�������\n" MAG, me);
        message_vision( "\n             ��ʿ��ѧ��\n             �յ�������\n             �������ˮ\n             �ƶ�������\n", me);
        message_vision( HIM"\n���˻���һ��ϼ�⣬�����ȥ��" , me);
        message_vision( HIR"\n\n��¡һ�����죡"NOR+ ding->name() +HIR" ը��һƬ��⣡��\n"NOR, me); 
        call_out("recover_ding", 30 ,ding, ding->name()); 
        ding->set("name", WHT"���ѵ� "NOR+ding->name());
        ding->delete_temp("in_use");
        ding->set_temp("broken", 1);
        me->unconcious();
        return;
    } 
    // Start to lian dan
    
    if ( random(skill)+ ( (skill/2 + extra/1000)*random(luck) )/10 >100) {
        seteuid(getuid());
        if ( random(5)>2 ) {
                dan= new("/obj/specials/alchemy/dan");
                dan->set_temp("to_cure", (cure_type[random(sizeof(cure_type))]) );
                dan->set_temp("cure", 8 + random(2) - 200/(random(skill)+20) );
                to_cure=dan->query_temp("to_cure");
                desc = dan->query("long");
                if ( to_cure =="gin" ) dan->set("long", desc + "��������Ѹ�ٻָ��������ˡ�\n");
                if ( to_cure =="kee" ) dan->set("long", desc + "��������Ѹ�ٻָ���Ѫ���ˡ�\n");
                if ( to_cure =="sen" ) dan->set("long", desc + "��������Ѹ�ٻָ��������ˡ�\n");
                if ( to_cure =="all" ) dan->set("long", desc + "��������Ѹ�ٻָ��������ˡ�\n");
                if ((int) me->query_temp("dan_number")>1 && objectp(present("dan", me))  ) {
                        message_vision( HIY "\n\nһ��"+dan->name()+HIY"��"NOR + ding->name()+ HIY"��Ծ��������һ������ϼ����ʧ�ˡ�\n" NOR, me);
                        tell_object(me, WHT"���ϧ���������Ϊ�����ĵ�̫���ˣ�����������ˡ�\n"NOR);                    
                        destruct(dan);
                }
                else {        
                        dan->move(me);
                        message_vision( HIY "\n\nһ��"+dan->name()+HIY"��"NOR + ding->name()+ HIY"��Ծ��������$N���ġ�\n" NOR, me);
                        me->set_temp("dan_number", 1 + (int )me->query_temp("dan_number"));
                
                }
        }
        else {
            dan= new("/obj/specials/alchemy/magic/"+magic[random(sizeof(magic))]);
            dan->set("level", skill/2);
            dan->move(me);
            message_vision( HIY "\n\nһ����Խ�����죬"NOR+dan->name()+HIY"��"NOR + ding->name()+ HIY"��Ծ��������$N���ġ�\n" NOR, me);
   }
        
    }
    else if ( random(skill)+((random(skill) + extra/1000)*random(luck))/10 <60) {
            
        message_vision( HIB "\n\nֻ����"NOR + ding->name()+ HIB"��һ�������ҽ�...\n" NOR, me);
        seteuid(getuid());
        devil= new("/obj/specials/alchemy/devil");
        devil->move(environment(me));
        message_vision( HIW "\nһֻ$N��"NOR + ding->name()+ HIW"�����˳�����\n" NOR, devil);
        devil->emerge(me, skill);
        devil->set("possessed", me);
    }
    else {
        seteuid(getuid());
        rand = random(5);
        if (rand >3) {
            dan= new("/obj/specials/alchemy/wan");
            dan->move(me);
            message_vision( HIY "\n\nһ��"+dan->name()+HIY"��"NOR + ding->name()+ HIY"��Ծ��������$N���ġ�\n" NOR, me);
        }
        else if (rand >2) {
            dan= new("/obj/specials/alchemy/magic/"+magic[random(sizeof(magic))]);
            dan->set("level", skill/2);
            dan->move(me);
            message_vision( HIY "\n\nһ����Խ�����죬"NOR+dan->name()+HIY"��"NOR + ding->name()+ HIY"��Ծ��������$N���ġ�\n" NOR, me);
        }
        else {
            dan= new("/obj/specials/alchemy/trash/"+trash[random(sizeof(trash))]);
            dan->move(me);
            message_vision( HIY "\n\nһ�����죬"NOR+dan->name()+HIY"��"NOR + ding->name()+ HIY"��Ծ��������$N���ġ�\n" NOR, me);
        }
        
    }
        ding->delete_temp("in_use"); 
} 
void recover_ding(object ding, string ding_name)
{
        message_vision( MAG "\n\nһ���Ƶ����������ӵ���ӿ����Χ����$N"MAG"��Χ��\n��Ȼ������ת��ȫ�����붦�ڡ�\n" NOR, ding);
        ding->set("name", ding_name);
        ding->delete_temp("broken");
        
}      

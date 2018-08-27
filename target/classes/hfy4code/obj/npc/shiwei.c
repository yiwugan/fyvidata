#include <ansi.h>
inherit NPC;
//void backattack();
void create()
{ 
        set_name("����", ({ "shiwei" }) );
        set("long", "����һλ��͢�Ĵ������������ӳ�͢���ٵ�ָ�ӡ�\n");
        set("attitude", "friendly");
        set("title","��͢ ��Ʒ��������");
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("no_fly",1);
        set("no_arrest",1);
        set("str",64);
        set("combat_exp", 1000000);
        set("class","huangshan");
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move", 100);
        set_skill("liuquan-steps",100);
        set_skill("qiusheng-blade",100);
        set_skill("changquan",100);
        set_skill("unarmed",100);
        map_skill("unarmed","changquan");
        map_skill("blade","qiusheng-blade");
        map_skill("parry","qiusheng-blade");
        map_skill("dodge","liuquan-steps");
        map_skill("move","liuquan-steps"); 
            set("chat_chance_combat", 50);
            set("chat_msg_combat", ({
                (: perform_action, "dodge.liushuichanchan"  :),
                (: perform_action, "blade.jingsheng" :),
            }) );

        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();
} 
void leave()
{
        object owner,*pros;
        message_vision(this_object()->name()+"����������ʧ�����ˡ�\n",this_object());
//        message("vision",
//                 name() + "����������ʧ�����ˡ�\n" , environment(this_object()),
//                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
                        pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        destruct(this_object());
}  
void init()
{
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
        add_action("do_kill","kill");
        add_action("do_dismiss","dismiss");     
}  
void heart_beat()
{
        object leader;
        
        ::heart_beat();
             if( !objectp(this_object()) )
        	return;
        if(query_temp("is_unconcious")||is_busy())
                return ;
        if( objectp(leader=this_object()->query("possessed")) )
        {
                if(environment(leader)!=environment(this_object()))
                {
                        message_vision("$N�Ҵ���ȥ��\n",this_object());
                        this_object()->move(environment(leader));
                        message_vision("$N���˹�����\n",this_object());
                        delete("leave_room");
                }
        }
        
        else
        {
                if(!query("leave_room"))
                        set("leave_room",1);
           else
                        add("leave_room",1);
                if(query("leave_room")==5)
                        leave();
        }
} 
int do_dismiss(string arg)
{
        object who,obj;
        
        if(!arg) return 0;
        if(!obj=present(arg,environment(this_object())))
                return 0;
        if(obj!=this_object()) return 0;
        who=this_player();
        if(who->query("sen")<200)
        {
                tell_object(who,"������񲻹����޷��Ա�ʿ�����\n");
                return 1;
        }
        if(who!=query("possessed")) return 0;
        who->add("sen",-200);
        message_vision("$N��$n˵���������ﲻ��Ҫ���ˣ���ȥ�ɡ�������\n",who,obj);
        obj->ccommand("inn "+who->query("id"));
        call_out("leave",1);
        return 1;
}  
int do_kill(string arg)
{
        object victim,who;
        
        who=this_player();
        if(!arg) return 0;
        if(environment()->query("no_fight"))
                return 0;
        victim=present(arg,environment(this_object()));
        if(!victim) return 0;
        if( !victim->is_character() || victim->is_corpse() )
                return 0;
        if(victim==who) return 0;
   if(victim->query("possessed")==who && victim->query("id")=="shiwei")
        {
                tell_object(who,"�㲻��ɱ�Լ��Ļ����������»�������µġ�\n");
                return 1;
        }
        if(victim==query("possessed")||victim->query("possessed")==query("possessed"))
        if(who->query("vendetta_mark")!="authority")
        {
                message_vision("$N�ȵ������󵨷�ͽ����Ȼ�ҼӺ���͢���٣�����\n",this_object());
                kill_ob(who);
        }
        if(who==query("possessed")&&victim->query("vendetta_mark")!="authority")
        {
                message_vision("$N��"+victim->query("name")+"�ȵ������󵨷�ͽ�������������־��ܣ���\n",this_object());
                kill_ob(victim);
        }
        return 0;
} 
string *lname = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��","��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��","˾��",
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","��","˧","��","��","��","��","��","��","��","����","����","����",
    }); 
void invocation(object who, int level)
{
        int i;
        object *enemy,*pros;
        
        set_name(lname[random(sizeof(lname))]+"����",({ "shiwei"}) );
        set("str",30+random(level/12));
        set("agi",10+random(level/8));
        set("cor",20+random(15));
   set("max_kee",1000+random(level*level/40));
        set("eff_kee",query("max_kee"));
        set("kee",query("max_kee"));
        set_skill("blade", 100 + random(level/2));
        set_skill("parry", 100 + random(level/2));
        set_skill("dodge", 100 + random(level/2));
        set_skill("move", 100 + random(level/2));
        set_skill("qiusheng-blade",100+random(level/4));
        set_skill("liuquan-steps",100+random(level/2));
        set_skill("changquan",100+random(level/2));
        set_skill("unarmed",100 + random(level/2));
        
        set("combat_exp", 100000 + level*level*10+random(level*level*level/10));
        set("max_force",3000);
        set("force",query("max_force"));
        set("force_factor",50+random(level/5));
        set("possessed",who);
        pros = who->query_temp("protectors");
        if(sizeof(pros))
                pros += ({ this_object() });
        else
                pros = ({ this_object() });
        who->set_temp("protectors",pros);
}
/*
void backattack()
{
        int i;
        object owner, *enemy;
        if(objectp(owner=this_object()->query("possessed")))
        {
                enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        } 
        } 
}
*/
void die()
{
        object owner,*pros;
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
                        pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        ::die();
} 
/*
        message("vision",
                 name() + "�ȵ����󵨣����Һͳ�͢���ٹ���ȥ��\n"NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
*/ 
int attack()
{
        object opponent,owner;
        int exp,extra;           
        opponent = select_opponent();
        if(objectp(opponent)) {
                set_temp("last_opponent", opponent);
        owner=query("possessed");
        if(opponent==owner)
        {
                this_object()->ccommand("ah");
                message_vision("$N��$n˵��������֪�Ǵ��ˣ�С�˸ղŶ��ð���ˣ��������ˡ���\n",this_object(),owner);
           this_object()->ccommand("escape");
                leave();
                return 1;
        }
        
        exp=opponent->query("combat_exp");                              
        extra=owner->query_skill("leadership",1);
        if(random(extra)) 
                COMBAT_D->fight(this_object(), opponent);
        else 
                if(random(exp)>this_object()->query("combat_exp"))
                {
                        message_vision("$N�����������������ƴ󣬻��Ǳ���Ϊ�Ȱɡ���\n",this_object());
                        this_object()->ccommand("escape");
                        leave();
                }
        return 1;
        } else
                return 0;
} 

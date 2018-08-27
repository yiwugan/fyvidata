#include <ansi.h>
inherit NPC;
void smart_fight(); 
int stone();
int stone1();
int stone2();
int stone3();
int stone4();
int stone5(); 
void create()
{
        set_name("��СС", ({ "bad kid" }) );
        set("title",WHT"����ͯ��"NOR);
        set("gender", "����" );
        set("age", 1+ random(10));
        set("long", "���ͯ����İ�С��ȴ����һ�ų��˵���������������֮����\n");
        set("combat_exp", 3500000);
        set("class","shenshui");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("str",36);
        set("cor",40);
        set("no_busy",5);
        set("resistance/kee",30);
        set("resistance/gin",random(70));
        set("resistance/sen",50);
        
        set("atman",1200);
        set("max_atman",1200);
        set("mana",1000);
        set("max_mana",1200);
        set("force",1200);
        set("max_force",1200);
        set("force_factor", 90);
        
        set("inquiry", ([
                "stone" : (: stone :),
                "�����ʯ" : (: stone :),
                "�������" : (: stone1:),
                "�̺�����" : (: stone2:),
           "��ڤ�Ͼ�" : (: stone3:),
                "�����൤" : (: stone4:),
                "��¶��ʯ" : (: stone5:),
                "��֮��" : (: stone1:),
                "��֮��" : (: stone2:),
                "��֮��" : (: stone3:),
                "ɳ֮��" : (: stone4:),
                "��֮��" : (: stone5:),
        ]));
        
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
                     
        set_skill("unarmed", 180);
        set_skill("force", 180);
        set_skill("longlife-force", 140);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("move", 180);
        set_skill("literate",120);
        set_skill("nine-moon-steps", 200);
        set_skill("nine-moon-claw", 180);
        set_skill("perception", 100);
        set_skill("kwan-yin-spells",130);
        set_skill("spells", 150); 
        map_skill("move","nine-moon-steps");
        map_skill("spells","kwan-yin-spells");       
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "longlife-force"); 
                
        setup();
        add_money("gold", random(5));
        carry_object("/obj/armor/cloth")->wear();
        if (!random(3)) carry_object(__DIR__"obj/hesan");
} 
smart_fight()
{
   int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie3");
                return;
        }
        return;
}    
int stone(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
                return 1;
        }
        message_vision(YEL"$N˵����̫��ʱ������ײ������Ĳ���ɽ��Ů��������ʯ�Բ����죬��
������������֮�ġ���֮�ǡ���֮�ơ�ɳ֮�ס���֮�۸����ռ�����ɫ��ʯ��
�������ʯ�ֱ��ǣ�������䡢�̺����ġ���ڤ�Ͼ��������൤����¶��ʯ��
��˵�κ�������ܵõ����е�һ�֣����ܴ��еõ������������������ \n"NOR,ob);
        message_vision(YEL"$N˵�����������д�������װס�������\n",ob);
        command("heihei");
        me->delete_temp("badkid/bribe");
        return 1;
} 
int stone1(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"��СС˵������������ڴ�֮�ۣ����������ö��˶�֪���ˡ������� \n"NOR);
        tell_object(me,YEL"��СС˵�������ţ���������ʱ�Ǵ����ϵ������ģ���ʱȴ�����ڵ����ҡ���\n"NOR);
   me->delete_temp("badkid/bribe");
        return 1;
} 
int stone2(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"��СС˵�����̺������ں�֮�ǣ�������������� \n"NOR);
        tell_object(me,YEL"��СС��������˭֪ʮ�������ᣬ�������黯Ѫ�ۡ���\n"NOR);
        tell_object(me,YEL"��СС˵��������������߻����ˣ����һ��Ǹ����ˡ���\n"NOR);
        me->delete_temp("badkid/bribe");
        return 1;
} 
int stone3(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"��СС˵������ڤ�Ͼ��ڷ�֮�ƣ���֮�ƾ��Ƿ��ơ��� \n"NOR);
        tell_object(me,YEL"��СС˵����������������Խ�����Խ�ҾͲ��ɡ���\n"NOR);
        me->delete_temp("badkid/bribe");
        command("sigh");
        return 1;
} 
int stone4(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
           return 1;
        }
        tell_object(me,YEL"��СС˵���������൤��ɳ֮�ס��� \n"NOR);
        tell_object(me,YEL"��СС���ĵ�������͵������ڵ��µ������������������������ߵ��˶��죬��Ҫ
���ڵ���һ�������˾����Ժ��������죬���ų�������\n"NOR);
        me->delete_temp("badkid/bribe");
        return 1;
} 
int stone5(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"��СС˵������¶��ʯ����֮�ġ��� \n"NOR);
        tell_object(me,YEL"��СС˵���������֮��ָ������·�������ҵǻ�ɽ���η��ƣ��������⣬����
��Դ������������ҹ����󹦿�һ���Ǹ������ѽ��������\n"NOR);
        me->delete_temp("badkid/bribe");
        command("hit");
        return 1;
}  
int accept_object(object who, object ob)
{
        if (ob->value()>=100000) {
                command("giggle");
                command("say ��������ʰɡ�");
                who->set_temp("badkid/bribe",1);
                return 1;
        } 
        
        command("say ��ô�㡣������Ц�ɡ�");    
        return 0;
        
}     

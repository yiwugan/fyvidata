 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight(); 
void create()
{
    set_name("����ü", ({ "master liu", "master","liu" }) );
    set("gender", "Ů��" );
    set("nickname", HIG"ӵ��ɽׯ�ٷ���"NOR);
    set("apprentice_available", 50);
    create_family("��ɽ��", 3, "����");
    set("long",
        "����ü��ɽ�����ŷ���\n"
        );
    set("age", 26);
    set("int", 30);
    set("per", 30);
    set("cor",  50);
    set("reward_npc", 1);
    set("difficulty", 30);  
       
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"�ֹ������森���ҵ�������ô�����ˣ�\n",
            }) );
    set("max_force", 2000);
    set("force", 2000);
    set("force_factor", 120);
    set("resistance/sen",80); 
    set("combat_exp", 6000000);
    
    set_skill("unarmed", 160);
    set_skill("sword", 250);
    set_skill("force", 180);
    set_skill("move", 160);
    set_skill("literate", 150);
    set_skill("dodge", 160);
    set_skill("perception", 200);
    set_skill("parry",160);
    set_skill("meihua-shou", 150);
    set_skill("siqi-sword", 180);
    set_skill("xianjing", 150);
    set_skill("liuquan-steps", 180); 
    map_skill("unarmed", "meihua-shou");
    map_skill("sword", "siqi-sword");
    map_skill("force", "xianjing");
    map_skill("dodge", "liuquan-steps");
    map_skill("move","liuquan-steps");
    map_skill("parry","siqi-sword");
        
    set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
    
    set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"}));
    setup();
    carry_object(__DIR__"obj/yellowcloth")->wear();
    carry_object(__DIR__"obj/yusword")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
} 
void init()
{ 
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
}
void punish_betray(object ob)
{
        if( ( ob->query("once_huangshan")) && ( (ob->query("class"))!= "huangshan"))
          {      
                tell_object(ob, YEL"\n����ü������Ц���������Ȼ�г����ţ��Ͳ������б��ŵ��书����\n"NOR);              
                message("vision", "����ü��"+ ob->name() +"��Ц������"+ ob->name() + "�� ���Ȼ�г����ţ��Ͳ������б��ŵ��书��\n", environment(ob), ob);
           tell_object(ob, HIW"����ü��һ�һ֧ţë��ϸС�ķ����������ֱۣ�\n"NOR);              
                message("vision", HIW"����ü����"+ ob->name() +"��һ����һ֧ţë��ϸС�ķ��룡\n"NOR, environment(ob), ob);
                
                if (ob->query_skill("liuquan-steps",1)) ob->set_skill("liuquan-steps",0);
                if (ob->query_skill("qiusheng-blade",1)) ob->set_skill("qiusheng-blade",0);
                if (ob->query_skill("yunwu-strike",1)) ob->set_skill("yunwu-strike",0);
                if (ob->query_skill("siqi-sword",1)) ob->set_skill("siqi-sword",0);
                tell_object(ob, HIR"��ֻ��Ѫ��һ���������书ȫʧ����\n"NOR);
                ob->delete("once_huangshan");
          }
}  
void attempt_apprentice(object ob)
{
/*        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����˽����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
*/
        command("shake");
        command("say �������,��Ͼ��ͽ");
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
          {      command("say ��ֻ��Ů���ӣ��㻹��ȥ���ҵķ���ɣ�");
          }
        else { 
                command("smile");
                command("say ��ɽ���Ӵ���û�б���ʦ�ŵġ�");
                command("say ���պ��Ҫ����ɽ��Ӵ��");
                command("smile");
                command("recruit " + ob->query("id") );
                ob->set("once_huangshan",1);
        }
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huangshan");
        add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
                return 0;
} 
int accept_object(object who, object ob)
{
        if(ob->query("id") == "old jade")
        {
        command("smile");
        command("thank "+who->query("id"));
        if((int)ob->query("max_cure") < 5)
        call_out("give_pena",3,who);
        else
        call_out("give_reward",3,who);
        return 1;
        } 
}
int give_reward(object who)
{
if(environment() != environment(who)) return 1;
if(!who->query("m_success/����ʯ"))
        {
                who->set("m_success/����ʯ",1);
                who->add("score",700); 
        }
return 1;
} 
int give_pena(object who)
{
if(environment() != environment(who)) return 1;
command("say �㾹Ȼ��͵�ñ����˵���ʯ������\n");
kill_ob(who);
who->kill_ob(this_object());
return 1;
}  
smart_fight()
{
        int i;
        object *enemy, who,count,j;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (who->query("kee")<8000) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                }
                if (count>=3)
                        command("perform zombie-wp1");
        }
        if (!random(3)) who->perform_action("sword.siqi");
        return;
}       

 //TIE@FY3
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight();  
void create()
{
    set_name("����", ({ "master li", "master","li" }) );
    set("gender", "����" );
    set("nickname", HIG"ӵ��ɽׯ����"NOR);
    set("age", 25);
    set("int", 30);
    set("per", 30);
    set("cor", 50);
    set("reward_npc", 1);
    set("difficulty", 30);
    set("ill_boss",5);
    set("apprentice_available", 50);
    create_family("��ɽ��", 3, "����");
    set("rank_nogen",1);
    set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"}));
    
    set("long",
        "���������µ�һ���������֮�ӣ�����ӵ��ɽׯ����������Ϊ������Ϊ��ɽ������\n"
        );
    
    set("force_factor", 120);
    set("max_force", 2000);
    set("force", 2000);
    set("resistance/sen",80); 
    set("combat_exp", 6000000);
    set("score", 90000);
    
    set_skill("unarmed", 160);
    set_skill("blade", 280);
    set_skill("force", 180);
    set_skill("move", 160);
    set_skill("literate", 150);
    set_skill("dodge", 160);
    set_skill("yunwu-strike", 180);
    set_skill("qiusheng-blade", 220);
    set_skill("xianjing", 200);
    set_skill("liuquan-steps", 180);
    set_skill("parry",160);
    set_skill("perception",200); 
    map_skill("unarmed", "meihua-shou");
    map_skill("blade", "qiusheng-blade");
    map_skill("force", "xianjing");
    map_skill("dodge", "liuquan-steps");
    map_skill("parry","qiusheng-blade");        
            
    set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
    
    setup();
    //carry_object(__DIR__"obj/cq");
    carry_object(__DIR__"obj/greencloth")->wear();
    carry_object(__DIR__"obj/yuhuan")->wield();
    if (!random(6000000)) carry_object(__DIR__"obj/cq2");
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 2);
}
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") > 0 ) {
        if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say ��ׯ�������Ѿ����˵��ӣ���������ͽ�ˡ�");
    }
}
void do_recruit(object ob)
{
	  if(ob->query_skill("qiusheng-blade")){
                command("?");
                command("say �㲻���Ѿ�ѧ���������书���ᣬ�����������ᡣѧ�ղ������ڽ����ϸ��˱��ˣ�");
                return;
                }
                
    if( (string)ob->query("gender") != "����" )
    {      command("say ��ֻ���е��ӣ��㻹��ȥ���ҵ����˰ɣ�");
    }
    else { 
        command("smile");
        command("say ���պ���д�ɣ�");
        command("smile");
        command("recruit " + ob->query("id") );
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
void init()
{
        add_action("do_get","get");
} 
int do_get(string arg)
{
    string what,where;
    object the_wall;
    if(!arg) return 0;
    if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
    the_wall = present(where,environment(this_object())) ;
    if (the_wall)
    if(the_wall->query("name") == "��ǽ")       
    {
        message_vision("$N��$n���һ�����󵨣����Ҵ��ȸ���������⣡\n",
                       this_object(),this_player());
        this_object()->kill_ob(this_player());
        this_player()->start_busy(2);
        return 1;
    }
    return 0;
}  
smart_fight()
{
        int i,j,count;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (who->query("kee")<6000) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                }
                if (count>=3)
                        command("perform zombie-wp1");
        }
        if (!random(3)&& who->query("kee")>8000) who->perform_action("blade.jingsheng");
        return;
}  
int accept_object(object who, object ob)
{
        if(!who->query("marks/��ɽ����") || who->query("class")!="legend") return 0; 
        if( ob->query("name")!="��ѩ�ż�" ) return 0;
                message_vision(CYN"$N΢΢Ц�������ղ�������ʦ������ô��\n"NOR,this_object());
                message_vision(CYN"$N˵:һ·�������ˣ��ں���ЪϢ����ɣ������и�ͽ�ܣ��п����ǿ����д�һ�¡�\n"NOR,this_object());
                tell_object(who,HIW"�����а�ϲ���û��ᣡ���Գ˻�ѧ�����ˣ���\n"NOR);
                who->set("marks/��ɽѧ��",1);
                who->delete("marks/��ɽ����",1);
        return 1;
} 

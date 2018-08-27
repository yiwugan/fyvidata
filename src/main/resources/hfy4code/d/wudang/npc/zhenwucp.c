 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
    set_name(HIY"����۾�"NOR, ({ "master zhenwu", "master", "zhenwu" }) ); 
    set("gender", "����");
    set("age", 999);
    set("long", "����Ϊ����ǵۣ������䵱��Ϊ����������ʦ����ħ�����˵��̳��Ĵ���\n");
    set("attitude", "peaceful");
    set("str", 6000);
    set("cor", 30);
    set("int", 24);
    set("cps", 30);
    set("force", 40000);
    set("max_force", 80000);
    set("force_factor", 1000);
    set("combat_exp", 10000000);
    set("score", 200000);
    set_skill("unarmed", 160);
    set_skill("force", 160);
    set_skill("sword", 160);
    set_skill("taijiforce", 200);
    set_skill("literate",150);
    set_skill("incarnation",320);
    set_skill("dodge",150);
    set_skill("taiji",130);
    set_skill("taiji-sword",130);
    set_skill("parry",190);
    set_temp("apply/damage",30000); 
    map_skill("force", "taijiforce");
    map_skill("unarmed", "taiji");
    set("no_shown",1);
    set("rank_nogen",1);
    create_family("�䵱��", 1, "������ʦ"); 
    set("ranks",({"����","����","����","�۾�"}));
    set("rank_levels",({320000,5187000,26244000}));
    setup();
}
int accept_fight(object me)
{
    return 0;
}
void attempt_apprentice(object me)
{
        if(me->query("class")=="wudang"&&me->query_skill("changelaw",1)>160)
                command("recruit " + me->query("id") );
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
}
void init()
{
    add_action("do_look","look");
} 
int do_look(string arg)
{
    if (arg == "master zhenwu" || arg == "zhenwu" || arg =="master")
    {
        write(HIY "����Ϊ����ǵۣ������䵱��Ϊ����������ʦ����ħ�����˵��̳��Ĵ��񡣡�\n"NOR);
        return 1;
    }
    return 0;
}    

 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
    set_name("��Ħ�����", ({ "damo", "master", "print", "damo print" }) );
    set("gender", "����");
    set("age", 999);
    set("long", "һ����Ħ�����̬�������������ƣ���Լ�ɼ�������һ����ɫ��ˮī���� ��\n");
    set("attitude", "peaceful");
    set("reward_npc", 1);
    set("difficulty", 40);
    set("str", 6000);
    set("cor", 30);
    set("int", 24);
    set("cps", 30);
    set("no_busy", 99);
    set("force", 80000);
    set("max_force", 80000);
    set("force_factor", 1000);
    set("combat_exp", 10000000);
    set("score", 200000);
    
    set("class", "shaolin");
    
    set_skill("move", 200);
    set_skill("dodge", 200);
    set_skill("force", 200);
    set_skill("iron-cloth",200);        
    set_skill("unarmed", 220);
    set_skill("yijinjing", 200);
    set_skill("zen", 200);
    set_skill("chanting", 220);
    set_skill("wuche-axe",140);
    set_skill("axe",150);
    set_skill("dabei-strike",280);
    set_skill("puti-steps",180);
    set_skill("parry",180);
    set_skill("xiaochengforce",200);
    set_skill("spear",160);
    set_skill("duanhun-spear",120);
    set_skill("fumostaff",180);
    set_skill("staff",200);
    set_skill("liuxing-hammer",180);
    set_skill("hammer",220);
    map_skill("hammer","liuxing-hammer");
    map_skill("unarmed","dabei-strike");
    map_skill("staff","fumostaff");
    map_skill("spear","duanhun-spear");
    map_skill("unarmed","yijinjing");
    map_skill("force","yijinjing");
    map_skill("iron-cloth","yijinjing");
    map_skill("dodge","puti-steps");
    map_skill("axe","wuche-axe");
    
    set("no_shown",1);
    set("rank_nogen",1);
    create_family("������", 1, "��Ħʦ��");
        set("ranks",({"��ɮ",YEL"��ɮ"NOR,YEL"ʥɮ"NOR,HIY"����"NOR}));
    set("rank_levels",({230000,3200000,5187000,26244000}));
    setup();
}
int accept_fight(object me){
    return 0;
}
void attempt_apprentice(object me)
{
        if(me->query("class")=="shaolin"&&me->query("marks/����_��ڳɹ�")&&me->query("once_xman")<1)
                command("recruit " + me->query("id") );
} 
void recruit_apprentice(object ob){
    if( ::recruit_apprentice(ob) )
        ob->set("class", "shaolin");
} 
void init(){
    add_action("do_look","look");
} 
int do_look(string arg){
    object me;
    me = this_player();
    if (arg == "print" || arg == "damo" || arg =="master" || arg == "damo print"){
                if(me->query("marks/����_��ڳɹ�")) {
           message("vision", me->name() + "������˼�Ķ�����ǰ��ʯ�ڡ�\n", environment(me), me);
                tell_object(me, CYN"һ����Ħ�����̬�������������ƣ���Լ�ɼ�������һ����ɫ��ˮī����\n"NOR);
                return 1;
        } else {
                tell_object(me, "�����ɵ�һƬʯ�ڣ���ʲôҲ����������\n");
                return 1;
        }
    }
    return 0;
}       

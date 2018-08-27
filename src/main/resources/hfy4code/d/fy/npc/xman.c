 // taolord.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER; 
int leave();
void create()
{
        set_name("�ڴ�", ({ "master xman", "master", "xman" }) );
        set("nickname", HIY"������ʦ"NOR);
        set("gender", "����");
        set("age", 99);
        set("long",
"�ڴ��ǵ�����Ƴǳ���������ʦ�ܣ����ǵ����ʦ���书��ɲ⡣\n"
);                
        set("combat_exp", 100000000);
        set("score", 50000); 
        set("class", "shaolin"); 
        set("str", 100);
        set("int", 100);
        set("cor", 100);
        set("cps", 100);
        set("spi", 100);
                set("fle",      100); 
                set("no_busy", 9);
        set("force", 88000);
        set("max_force", 88000);
        set("force_factor", 50);
                set("max_gin",28000);
                set("max_sen",28000); 
/*         set("inquiry", ([
                "̫������": 
"̫���������ؾ���������һ���������֡�\n",
        ]) ); */
        set("apprentice_available", 1);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
                                    
        }) ); 
         set("rank_nogen",1);
        create_family("������", 1, "ʥɮ"); 
        
        set("inquiry", ([
                "leave": (: leave:),
        ]) );
        
        set_skill("literate", 100);
        set_skill("force", 300);
        set_skill("move", 300);
        set_skill("unarmed", 300);
        set_skill("parry", 180);
        set_skill("dodge", 150);
        set_skill("perception", 120);
        set_skill("putiforce", 300);
        set_skill("nodust-steps", 300);
        set_skill("changquan", 350);
        set_skill("yizhichan", 300);
        set_skill("whip",200);
        set_skill("tianlongwhip",250);
        set_skill("xingyi-stick",300);
        set_skill("staff",160);
        
        map_skill("whip", "tianlongwhip");
        map_skill("staff", "xingyi-stick");
        map_skill("parry", "yizhichan");
        map_skill("dodge", "nodust-steps");
        map_skill("move", "nodust-steps");
        map_skill("force", "putiforce");
        map_skill("unarmed", "changquan"); 
        setup(); 
        carry_object("/d/shaolin/npc/obj/monk20_cloth")->wear();

} 
void attempt_apprentice(object me)
{
    if(me->query("family/master_id") != "damo")
    {
        command("heihei");
        command("say ̫���ˣ�һ�ж�̫���ˡ���");
        return;
    }
    else
    {
        command("haha");
        command("say �мǣ���Ϊ��ͽ���������ѣ�");
        command("recruit " + me->query("id") );
        me->set("once_xman",1);
    }
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
} 
void init()
{
        object ob;
        ::init();
//        add_action("do_killing", "kill");
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
}  
void punish_betray(object ob)
{
        if( ( ob->query("once_xman")==1) && ( (ob->query("class"))!= "shaolin"))
          {      
                tell_object(ob, YEL"\n�ڴ����:�������壡����\n"NOR);                  
                message("vision", YEL"�ڴ���"+ ob->name() +"ŭ������"+ ob->name() + "�� ���㲻�£�\n"NOR, environment(ob), ob);
                tell_object(ob, HIW"�ڴ�һȭ�������������ϣ�\n"NOR);              
                message("vision", HIW"�ڴ�һȭ����"+ ob->name() +"��������ϣ�\n"NOR, environment(ob), ob);
                tell_object(ob, HIR"��ֻ�����ε�ת,ҡҡ�λεص�����ȥ----�ڲ�����ѽ!\n"NOR);
                ob->set("title",HIW"������ͽ"NOR);
                ob->die();
          }
}  

int leave() {
        if (this_player()->query("class")!="shaolin") return 0;
        message_vision(CYN"$N����һ������������Ҳ�ǲ����Բ���쳾�ģ���Ȼ�����ţ���Ҫ�������ۣ���\n"NOR, this_object());
        message_vision(CYN"$N˵�����Ǳ����˷��棬�ҿ���Ҳ�����������Ϲ��������ӡ�\n"NOR,this_object());
        
        return 1;
}  
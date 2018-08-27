 inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������", ({ "master tie", "master","tie" }) );
    set("gender", "����" );
    set("age", 26);
    set("int", 30);
    set("cps",50);
    set("per", 15);
    set("agi",35);
    set("cor",40);
    
    set("apprentice_available", 50);
    create_family("��Ѫ������", 8, "����");
    set("rank_nogen",1);
    set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"})); 
    set("long","����������Ѫ�����ŵĴ��ˡ�\n" ); 
    set("no_busy",10); 
    set("max_force", 1000);
    set("force", 1000);
    set("force_factor",60); 
        set("resistance/kee",20);
        set("resistance/sen",60);
        set("resistance/gin",90); 
    set("reward_npc", 1);
    set("difficulty", 15);
    set("attitude", "peaceful");
    
    set("combat_exp", 4800000);
    set("score", random(90000));
    
        
    set_skill("dormancy",180);
    set_skill("unarmed", 220);
    set_skill("perception", 280);
    set_skill("move", 220);
    set_skill("sword", 130);
    set_skill("literate", 180);
    set_skill("force", 150);
    set_skill("parry", 200);
    set_skill("dodge", 200);
    set_skill("ill-quan", 200);
    set_skill("fy-sword", 160);
    set_skill("cloudsforce", 130);
    set_skill("tie-steps", 200);
        
    map_skill("unarmed", "ill-quan");
    map_skill("sword", "fy-sword");
    map_skill("force", "cloudsforce");
    map_skill("parry", "fy-sword");
    map_skill("dodge", "tie-steps"); 
    setup();
    carry_object("/obj/armor/cloth")->wear();
}
void reset()
{
    set("apprentice_available", 20);
}
void attempt_apprentice(object me)
{
      command("haha");
      command("recruit " + me->query("id") ); 
} 
/*void do_recruit(object ob)
{
    if (ob->query_temp("mark/can_apprentice_master_tie"))
        if( (string)ob->query("gender") != "����" )
        {      command("say ��ֻ���е��ӣ�");
        }
        else { 
            command("smile");
            command("say ���պ���д�ɣ�");
            command("smile");
            command("recruit " + ob->query("id") );
        }
}*/
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "tieflag");
    add("apprentice_availavble", -1);
} 
int accept_object(object me, object obj)
{
    if(obj->query("id")=="silk book" && me->query_temp("mark/silkbook"))
    {
        me->set_temp("mark/can_apprentice_master_tie",1);
        me->delete_temp("mark/silkbook");
        command("say ��⣬�����������\n");
        return 1;
    }
    if(obj->query("id")=="flag" && obj->query("fake"))
    {
        command("say �󵨣����Ķ�Ū��һ����������Ū�Ϸ�\n");
        kill_ob(me);
        return 1;
    }
    return 0;
}   

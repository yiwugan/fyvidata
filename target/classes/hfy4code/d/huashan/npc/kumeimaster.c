#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int force_convert();
int leave();
void create() 
{
    set_name("��÷��ʦ", ({ "master kumei", "kumei","master"}));
    set("long", 
        "
����һ���׷��ԲԵ��ϸ���һ�Ÿɿ����������������˰̣�����ȱ�˰����
�۾�Ҳ����һֻ��ʣ�µ�һֻ�۾��뿪��ϣ�����֮�䣬���Ⱪ�䣬����˭Ҳ
���ұ��ӡ������Ӻ���С����ȴ����˵�����������ϣ�����˭��ֻҪ������ 
һ�ۣ���˵������������ѹ��Щ��
\n"
        );
    set("nickname", HIW "���ɹ�"NOR);
    set("gender", "Ů��");
    set("class","huashan");
    create_family("��ɽ��", 16, "����");
    set("rank_nogen",1);
    set("student_title","����");
    set("reward_npc", 1);
    set("difficulty", 5);
    set("age", 59);
    set("int", 30);
    set("per", 3);
    set("con", 25);
    set("str",28);
    
    set("force", 1000);
    set("max_force", 1000);
    set("force_factor", 70);
    set("combat_exp", 3200000);
    set("attitude", "friendly"); 
    set_skill("unarmed", 140);
    set_skill("zhaixin-claw",100);
    set_skill("move", 140);
    set_skill("dodge", 140);
    set_skill("parry", 140);
    set_skill("literate", 140);
    set_skill("force", 180);
    set_skill("dugu-sword", 100);
    set_skill("sword", 150);
    set_skill("anxiang-steps", 140);
    set_skill("tanzhi-shentong", 120);
    set_skill("throwing", 150);
    set_skill("hanmei-force", 120);
    set_skill("qingfeng-sword", 150);
    set_skill("perception", 100); 
    map_skill("force", "hanmei-force");
    map_skill("move", "anxiang-steps");
    map_skill("parry", "dugu-sword");
    map_skill("sword", "qingfeng-sword");
    map_skill("dodge", "anxiang-steps");
    map_skill("unarmed", "zhaixin-claw");
    map_skill("throwing", "tanzhi-shentong");
    map_skill("sword", "qingfeng-sword");
        
        set("inquiry", ([
//              "hanmei-force" : (: force_convert :),
//              "��÷�ķ�" : (: force_convert :),
                "leave" : (: leave :),
        ])); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                 (: perform_action, "throwing.mantianhuayu" :),
        }) ); 
        
        
    set("ranks",({"����","С��","����","����","����",WHT"����"NOR,WHT"��ʥ"NOR,HIW"����"NOR}));
    setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/cloth", 
                ([      "name"  :       HIB "������"NOR,
                        "long"  :       0 ])
                )->wear();
}  
void attempt_apprentice(object ob)
{
    if (ob->query("gender")=="����") {
           command("say ��ɽֻ��Ů��Ϊͽ��\n");
        return;
    }   
    if (ob->query_skill("sword",1) < 19) {
         command("say  ��Խ�����֪���٣���Ȼ�������ң�");
                return;
    }
    if ((int)ob->query_skill("move",1) < 19 ) {
        command("say ���µ����ƺ�����ѧ�䰡��");
                return;
    }
/*    if ((int)ob->query("age") > 15 ) {
        command("say ��ν��׳��Ŭ�����ϴ�ͽ�˱����ҿ���������ѧһ��ûʲôǰ;��");
                return;
    }*/ 
    command("recruit " + ob->query("id"));
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
           if(id_class == "huashan"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ���ƶ���ͽ�ܣ��ݲ��ø������̣ܽ�\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int force_convert(){
        object me;
        int level;
        me = this_player();
        message_vision("$N֣�ص�˵������÷�ķ��˻�ɽ֮������Ҳ�Ǹ��������еİ��\n", this_object());
        if (me ->query("class")!= "huashan") return 1;
        if (!me->query_skill("wuzheng-force")) return 1;
        me->start_busy(4);
        level= me->query_skill("wuzheng-force");
        me->delete_skill("wuzheng-force");
        me->set_skill("hanmei-force",level);
        message_vision("$N˵��Ϊʦ���վʹ�����һ�ķ��Ŀھ���\n",this_object());
        message_vision("$Nһ�ְ���$n�ı��ģ�������Ĭ����ʲô��������\n",this_object(),me);
        tell_object(me,HIW"�����һ�ɺ����ӿ�÷��ʦ�����Ĵ��˹�����\n"NOR);
        call_out("convert_done", 5, me);
        return 1;
}  
int convert_done(object me) {
        tell_object(me,HIW"���������������������ã��㽥��ƽ��������\n"NOR);
        message_vision("$N��$n˵�����ˣ���ȥ�������ɣ�ΪʦҪ��Ϣ�ˡ�\n",this_object(),me);
        return 1;
} 
int leave() {
        if (this_player()->query("class")!="huashan") return 0;
        message_vision(CYN"$N��Цһ��������ɽ��Ȼ�������ĵ��ӡ���\n"NOR, this_object());
        message_vision(CYN"$N˵����÷�ķ���ժ���ֵ��ؾ�������¡�\n"NOR,this_object());
        return 1;
}  

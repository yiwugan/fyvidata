 inherit NPC;
// inherit  F_MASTER;
void create()
{
    set_name("л�ƹ�", ({ "xie zhanggui"}) );
    set("gender", "����" );
    set("age", 42);
        set("title","��ɽׯ �ڶ�����Ϊ�徲¥�ƹ�");
    set("long",
        "�������Ϊ�徲¥л�ƹ񣬴��һ�����л��������˵�书�ѳ����뻯��\n");
    set("combat_exp", 3000000);
    set("reward_npc", 1);
    set("difficulty", 10); 
    set("attitude", "friendly");
    set("max_force",1000);
    set("force",1000);
    set("force_factor",60);
    set("atman",1000);
    set("max_atman",1000);
    set("fly_target",1);
    set_skill("blade", 200);
    set_skill("move",100);
    set_skill("parry",200);
    set_skill("force",80);
    set_skill("cloudforce",60);
    set_skill("dodge", 200);
    set_skill("shenji-blade",150);
    set_skill("shenji-steps",150);
    map_skill("force","cloudforce");
    map_skill("blade","shenji-blade");
    map_skill("parry","shenji-blade");
    map_skill("dodge","shenji-steps");
    map_skill("move","shenji-steps"); 
/*
    create_family("��ɽׯ", 2, "��Ϊ�徲¥�ƹ�");
    set("rank_nogen",1);
    set("ranks",({"��ū","����","��ʿ","����","����","����","��ʥ","����",
                      "���","��ɷ","����","����"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));
*/ 
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"����û�뵽����С��������ү��ǰ��Ȼ��ô����һ����\n",
            name()+"������Ҫȥ����¥�ǵ�ɱ���Ҳ��С�\n",
            }) );
    setup();
    add_money("coin", 50);
    carry_object(__DIR__"obj/qingcloth")->wear();
    carry_object(__DIR__"obj/blade")->wield();
} 
void init()
{
        object me,meizhi;
        if(interactive(me = this_player()) && !me->is_fighting() && userp(me) && me->query("marks/����_��_��ʮ��"))
        {
                remove_call_out("greeting");
                call_out("greeting",2,me);
        }
        add_action("do_answer","answer");
}
void greeting(object me)
{
        if (objectp(me) && present(me,environment(this_object())))
        {
                if (!me->query_temp("pass_xiezhanggui"))
                {
                        message_vision("$N����$nһ�ۣ������˵����ƾ��Ĺ���Ҳ��ȥ��ս��ʮ���� 
�������ʮ���Ľ����𣿡� (answer yes/no) \n",this_object(),me);
                        me->set_temp("inask",1); 
                }
                
        }
} 
int do_answer(string arg)
{
        object me;
        me = this_player();
        if (arg != "yes" && arg != "no")
   {
                return notify_fail("��ֻ�ɴ�yes/no \n");
        }
        if (!me->query_temp("inask"))
        {
                return 0;
        }
        me->delete_temp("inask");
        if (arg == "yes")
        {
                message_vision("$N�۾�һ������$n������������ҿ���(show)���Ľ�����ʲô���ģ��� \n",this_object(),me);
                add_action("do_show","show");
        }else
        {
                message_vision("$N��$n˵���������Ľ�����û�������Ͳ�Ҫȥ�����ˡ��� \n",this_object(),me);
        }
        return 1;
} 
int do_show(string arg)
{
        object me,meizhi;
        me = this_player();
        if (arg != "meizhi" && arg != "���ϵ�÷֦" && arg != "÷֦")
        {
                return 0;
        }
        if (!present("meizhi",me))
        {
                return notify_fail("������û������������\n");
        }
        if (me->query_temp("pass_xiezhanggui"))
        {
                return 0;
        }
        message_vision( "$n�ó����ϵ�÷֦�����ȵغ���$N��ǰ�� 
$N����÷֦�ĶϿڣ���ɫ������ûҰ���ʧ�����ǵ� 
���ŵ�������ʮ�彣����ʮ�彣������ ��ȥ�ɡ���\n ",this_object(),me);
        me->set_temp("pass_xiezhanggui",1);
        return 1; 
} 
/*
 void attempt_apprentice(object me)
{
    command("say ��ֻ�Ἰ������è�Ĺ��򡣡���\n");
    me->add_temp("tried",1);
    if(me->query_temp("tried") < random(10)+10)
        return;
    else
        command("smile");
    command("recruit " + me->query("id") );
    return;
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "blademan");
}
*/    

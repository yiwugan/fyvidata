 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
int ask_fight();
void create()
{
    set_name("��ʮ��", ({ "yan13", "yan shisan" }) );
      set( "title",HIC"����ʮ����"NOR);
    set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 40); 
    set("age", 34);
    set("str", 100);
    set("cor", 30);
    set("cps", 30);
    set("int", 30);
    set("per", 30);
    set("agi",20);
    set("attitude","friendly");
    
    set("max_force", 3000);
    set("force", 3000);
    set("force_factor", 100);
    
    set("resistance/kee",90);
    set("resistance/gin",90);
    set("resistacen/sen",90);
    
     
    set("long",
        "��¶�ںڽ����һ˫�۾��������絶 
�����������Ž�����ڵĽ����ϣ�����ʮ������Ө�����顣 \n");
    set("combat_exp", 30000000);
    set("score", 200000);
    
    set_skill("move", 200);
    set_skill("parry", 200);
    set_skill("dodge", 200);
    set_skill("force", 200);
    set_skill("literate", 150);
    set_skill("sword",200);
    set_skill("13-sword",180);
    set_skill("cloudforce",120);
    set_skill("shadowsteps",120);
    set_skill("unarmed",200);
    set_skill("dragonstrike",200);
    
    map_skill("force", "cloudforce");
    map_skill("parry","softsword");
    map_skill("sword","13-sword");
    map_skill("dodge","shadowsteps");
    map_skill("move","shadowsteps"); 
    map_skill("unarmed","dragonstrike"); 
    set("chat_chance", 1);
    set("chat_msg", ({
        "��ʮ��̾Ϣ�ŵ�:����Ϊʲ�ỹû�п����� ��Ϊʲ�ỹû�����᣿��\n",
        "��ʮ��̾Ϣ�ŵ�������������ã��羰������������������֮ǰ������ 
Ҳ��������һ���������� \n",
            }) );
        set("inquiry",([
        "fight" : (: ask_fight :),
        "��ս" : (: ask_fight :),
    ]) ); 
    setup();
    carry_object(__DIR__"obj/blackcloth")->wear();
    carry_object(__DIR__"obj/yan13-sword")->wield();
        carry_object(__DIR__"obj/blackmask")->wear();
} 
int ask_fight()
{
        object me;
        me = this_player();
        if (!me->query("marks/����_��_��ʮ��") || me->query("marks/����_��_л����"))
        {
                return 0;
        }
        if (!present("meizhi",me))
        {
           message_vision("$N��$n����ص�����û�м����ҽ������ˣ�û���ʸ�������ս����\n",this_object(),me);
                return 1;
        }
        message_vision(" $NƳ��$n�����÷֦���������ʣ�����һ���������������ó������� (answer yes/no) \n",this_object(),me);
        add_action("do_answer","answer");
        me->set_temp("yan13ask",1);
        return 1;
} 
int do_answer(string arg)
{
        object me,meizhi;
        int i;
        me = this_player();
        if (arg != "yes" && arg != "no")
        {
                return notify_fail("��ֻ�ɴ�yes/no \n");
        }
        if (!me->query_temp("yan13ask"))
        {
                return 0;
        }
        me->delete_temp("yan13ask");
        if (arg == "yes")
        {
                message_vision("$N�ս����ֱ��ϣ������͹�𡣡���һ������Ѱ���ƽ���һ��������� 
ֻҪ��Ը���ܹ��ﵽ�����ֺη������ֺη����� \n",this_object());
                message_vision("$N��$n����������а���������ս���Ǿ����ɡ���\n",this_object(),me);
                this_object()->kill_ob(me);
                //me->kill_ob(this_object());
        }else
        {
                if(me->query("����A/����_����"))
                {
                        message_vision("$N˵����һ��һ�������ǽ����еġ��񡹣������ǿ�������Ҳ�Ҳ����ģ���Ҫ����ʱ�򣬾ͺ�Ȼ���ˡ������㱾��һ���ȴﵽ
�����ˡ����ҡ��������ľ��磬���Ż����������Ҳ�������ڵġ�����һ������\n\n",this_object());
                        if (!me->query("marks/dunwu"))
                        {
                                message_vision("һ�������������ȱ��֦϶�ս�����������̦���ϣ�������һ���𽣡� 
$N�����ֵ��������к�Ȼ�е�����\n",me);
                                tell_object(me, HIC "��ġ�" + SKILL_D("sword")->name() + "��ͻ���ͽ����ﵽ��һ���µľ��硣\n\n"NOR);
                           i= me->query_skill("sword",1)+10;
                                me->set_skill("sword",i);
                                me->set("marks/dunwu",1);
                        }
                        message_vision("$N��$n���ͷ˵������ȥ�ɡ��� \n",this_object(),me);
                }else
                {
                        message_vision("$N�����������ƶ�������������һ�����ѱ���˶������Ѿ��������Լ�����ͨ�仯����\n",this_object());
                        message_vision("$N��$nҡҡ˵������ȥ�ɡ��� \n",this_object(),me);
                }
                        me->delete("marks/����_��_��ʮ��");
            me->set("marks/����_��_����֮��",1); 
        }
        return 1;
} 
void die()
{
    object killer;
    if(objectp(killer = query_temp("last_damage_from")))
        {
                if (killer->query("marks/����_��_��ʮ��"))
                {
                        killer->delete("marks/����_��_��ʮ��");
                        killer->set("marks/����_��_л����",1);
                }
        }
    ::die();
}  
int return_home(object home)
{
        //if jin is in action, don't make her returning home
        if (query("marks/inaction"))
        {
                return 1;
        }
        ::return_home(home); 
} 

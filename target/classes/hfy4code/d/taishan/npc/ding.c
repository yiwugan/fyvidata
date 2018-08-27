#include <ansi.h>
inherit NPC;
int showpower();
int wieldblade();
void create()
{
        set_name("����", ({ "ding peng" }) );
        set("gender", "����");
        set("age",35);
        set("combat_exp", 3900000);
        set("reward_npc", 1);
        set("class","bandit");
        set("fly_target",1);
        set("intellgent",1);
        set("difficulty", 50);
        set("no_busy", 50);
        set("moonblade", 5);
        set("long",
                "�����Ѿ����ˣ��Ѿ�������ǰ�Ǹ��嶯��֪�������ˡ����ڲ���
��������أ����Ҵ����ֳ�Խһ�е����š�\n"
        );
        set("max_force",3000);
        set("force",3000);
        set("force_factor",30);
        set_skill("move",100);
        set_skill("parry", 250);
        set_skill("blade",250);
        set_skill("dodge",250); 
        map_skill("dodge","shenji-steps");
        set_skill("moon-blade",150);
        map_skill("blade","moon-blade");
        map_skill("parry","moon-blade");
        map_skill("dodge","moon-blade");
        set("chat_chance", 20);
        set("arrive_msg","ʩʩȻ�߹���");
        set("leave_msg","���߳���Զ����������������������һ˲������߳���Զ");
        set("chat_msg", ({
        (: random_move :),
        (: showpower :)
        }) );    
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );
        setup();
   carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/wandao");
}
int showpower()
{
command("wield moonblade");
tell_object(environment(this_object()),"������ѵ��ѳ��ʡ�����һ����
����������Ļ��ȣ���·�ߵ���ʯ������ȥ���ǿ鿴���ȸ���
��Ӳ����ʯ����Ȼ�ڵ����±��������룡\n");
command("unwield moonblade");
return 1;
}
int wieldblade()
{
command("wield moonblade");
perform_action("blade.yuanyue");
command("unwield moonblade");
return 1;
}

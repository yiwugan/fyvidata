 // acao.c
inherit NPC; 
#include <ansi.h>
void create()
{
        set_name("����", ({ "a cao","cao" }) );
        set("gender", "Ů��" );
        set("age", 21);
        set("title","����"+HIG" ����̿�"NOR);
        set("long", HIC "\n�����ü�������������˫�۾����ĵ�ֱ���Թ��˻��ǡ�\n"+
        "����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��\n"+
        "������ȻһЦ�����������·����۲���ת֮�䣬\n"+
        "���һ����������飬�������м����ľ��硣\n" NOR);
        set("chat_chance", 5);
        set("chat_msg", ({
            "��������һЦ�������ݵĵ��죿���ǰ�ˮ�Ľ��죿\n",
            "���ݴ��˸���Ƿ������������סӣ��С�ڣ��������������ˡ�\n",
            "���ݺ�Ȼݸ��һЦ��: ��ˮ�������Ҫ��ɱ˭�أ�\n",
            "�������ĵ������־̾��: ����һ���ˣ���û��˼��\n",
            "�������������һ���С�֣������°�˵: ˭�����˵˵��?\n",
            "����ն��������˵: �ţ�˭Ҫ���۸��ң��Ҿ���������\n", 
          }) );
        set("combat_exp", 2000000);
        set("attitude", "friendly");
        set("per",100);
        set("str", 100);
        set("force",2000);
        set("max_force",2000);
        set("force_factor",150);
        set_skill("dodge",300);
        set_skill("unarmed",200);
        set_skill("blade",200);
        set_skill("fall-steps",200);
        set_skill("springrain-blade",200);
        set_skill("meihua-shou",200);
        set_skill("parry", 200);
        map_skill("parry","springrain-blade");
        map_skill("dodge","fall-steps");
        map_skill("unarmed", "meihua-shou");
        map_skill("blade", "springrain-blade");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                "��������̾���������������Ǻο���?\n",
                (: command("say ���кλ����������? ����ͳ�ȫ����ɡ�\n") :),
                (: perform_action, "dodge.luoyeqiufeng" :),
                (: perform_action, "blade.dangshimingyue" :),
               // (: perform_action, "unarmed.meihai" :),              
        }) ); 
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/loulan/obj/blade")->wield();
} 
/*void die()
{
        object ob;
        //command("cry");
        message_vision("\n$N����һ������˵�������Ի�Ϊ�ұ���ġ�\n", this_object());
        message_vision("$N˵�꣬����һ������ȥ��\n", this_object());
        //this_object()->move("/d/fy/church");
        //create();
        destruct(this_object());
}*/

 // waiter.c
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���Ứ", ({ "ji zanghua" }) );
        set("gender", "����" );
        set("age", 45);
        set("title",RED  "ɱ��ׯ��"NOR);
        set("long",
                "һ��������ߵ�٪�壬ȴ������ɱ��ׯ��ׯ����
����˵���ǰ׳գ�����˵������ɱ�������֣�����Щ�˶�Ī���������ʧ�ˡ�\n");
        set("combat_exp", 50000000);
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 100);
        set("per",3);
        set("fle",50);
        set("dur",50);
        set("con",50);

        


        set_skill("dodge",250);
        set_skill("chaos-steps",250);
        set_skill("perception",250);        
        set_skill("qiankunstrike",250);        
        set_skill("unarmed",250);
        map_skill("unarmed","qiankunstrike");
        map_skill("dodge","chaos-steps");

        set("force",40000);
        set("max_force",40000);
        set("max_mana",40000);
        set("max_atman",40000);
        set("force_factor",150);

        setup();
        carry_object(__DIR__"obj/birdbox");
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
message_vision("$N����$n�����ɱ����������ɱ������ɱ���߱�ɱ����ɱ��ɱ�ˡ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N��$n��׳�һ��ɵЦ���ҿ�������ϧ���������ˡ�����\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N����$nһ�ۣ��ò��ϣ���һ����ɱ�Ĳ��ϡ�\n",this_object(),ob);
                        break;
        }
}

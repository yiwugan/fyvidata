 inherit QUESTNPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name(HIW"ѦЦ��"NOR, ({ "xue xiaoren", "xue" }) );
        set("nickname",HIG"��Ű׳�"NOR);
        set("gender", "����" );
    set("age", 43);
        set("int", 55);
        set("per", 30);
        set("long",
                "���������Ҳ����ʮ���ˣ���������Щ���ף�����ȴ���ż�����廨���·����������������Ǯ�����ϻ�����˫��ͷ���������ǹ��¿���������ɫ�ƺ�ʮ�ֺ�����ϸһ����ԭ����Ϳ����֬��
\n"
                );
        set("max_gin", 2800);
        set("max_kee", 3000);
        set("max_sen", 2800);
        set("eff_gin", 2800);
        set("eff_kee", 3000);
        set("eff_sen", 2800);
        set("gin", 2800);
        set("kee", 3000);
        set("sen", 2800);
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 120);
        set("cor",90);
        set("str",60);
        set("combat_exp", 9400000);
                set("bellicosity",0);
        set("score", -1500);
        set_skill("sword", 180);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("literate", 40);
        set_skill("dodge", 330);
        set("agi",25);
        set("int",30);
/*              set("chat_chance",10);
           set("chat_msg",({
"·С������һ�Ż���������������Ȼ������Ż����䵽�Լ���������۾���
������̾�˿�������ʼ�����׽���\n",
"·С�Ѻ�ȻЦЦ ��˵������ɱ���Ǽ��ɾ�ʹ������顣��������һ�٣���˵����
��������ɱ��֮ǰ����һ��Ҫϴ���衣��\n",
                })      );
*/
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sharenruma" :),
        }) );
        set_skill("sharen-sword", 120);
        map_skill("sword", "sharen-sword");
                
        setup();
        carry_object(__DIR__"obj/xiuhuapao")->wear();
        carry_object(__DIR__"obj/hutoushoe")->wear();
        carry_object("/obj/weapon/sword")->wield();
} 
void init()
{
        object room;
        remove_call_out("hunting");
        if(!room=environment()) return 0;
        if(!room->query("no_fight"))
        call_out("hunting",1);
} 
void hunting()
{
        int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])||userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->kill_ob(this_object());
        }
} 

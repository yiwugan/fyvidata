 //by xiaolang
// ����¥ɱ�� 
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("�����", ({ "liu yuhen" }) );
        set("gender", "����" );
        set("title",HIG"�����ɾ�"NOR);
        set("nickname",WHT"�����Թſ���ޣ��������޲�����"NOR);
        set("age", 27);
        set("class","swordsuper");
        set("libie/���_β��",1);
        set("str", 60);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
�����������ѱ�����ȥ��һ�룬�˿������Ѹɱ����������ı���
���۾�������бб�ĳ��˹���������һ�����ӣ��ǰ����Ҳ����һ
˫�۾�����һֻ������������ֻʣ����һ���ֺ�����Ķ�����Ǳ�
���õ��滮�˸���ʮ���֣�˫��Ҳ�����󿳶��ˣ�����������װ��
������������������
LONG
);
        set("attitude", "heroism");
        set("bellicosity", 1500 ); 
        set("combat_exp", 40000000); 
        set("chat_chance", 1);
        set("chat_msg", ({
"�������Ȼ���ˣ��������Թſ���ޣ��������޲����ᣬ���ڡ������ɾ���\n�������ˣ�ֻ�ɺ�����޻����ţ�ʮ��ǰ�����Ҳ���������ˣ�\n����ƫƫֱ�����ڻ����ţ��Ҵ�������һ�����ѡ���"
        }) );  
        set("force",5000);
        set("max_kee",50000);
        set("max_gin",30000);
        set("max_sen",30000);
        set("kee",50000);
        set("gin",30000);
        set("sen",30000);
        set("force_factor",80);
        set_skill("unarmed", 200);
        set_skill("sword", 250);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("force", 180);
        set_skill("libieforce",200);
        set_skill("move",200);
        set_skill("sky-steps",180);
        set_skill("xiaohun-sword",150);
        map_skill("dodge","sky-steps");
        map_skill("move","sky-steps");
        map_skill("sword","xiaohun-sword");
        map_skill("parry","xiaohun-sword");
        map_skill("force","libieforce");
        set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
    		(: exert_function, "libie" :),
        	(: perform_action, "sword.libie" :),
            }) );

        setup();
        carry_object("/d/chenxiang/npc/obj/hook")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        message("vision",
                HIW + name() + "̾��̾����һ������ʧ����Ӱ���١�\n" NOR, environment(),
                this_object() );
        destruct(this_object());
}  
void init()
{
    object ob;
    ::init();
    set_temp("libieforce_libie",1);
    if( interactive(ob = this_player()) && !is_fighting() ) 
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
} 
void greeting(object ob)
{   
        string where, location;
        if( !interactive(ob) || environment(ob) != environment() )
                return;
   if (!ob->query_temp("����¥/lou1a") ){
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
}    
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        me->set_temp("����¥/lou1a",1);
        ::die();
}  

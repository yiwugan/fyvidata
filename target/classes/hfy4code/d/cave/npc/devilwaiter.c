 // waiter.c
inherit NPC;
#include <ansi.h>
inherit F_VENDOR;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("���³���", ({ "devil waiter","waiter" }) );
        set ("nickname",HIR"�˳�"NOR);
        set ("title","������ �ֶ����");
        set("gender", "����" );
        set("age", 52);
        set("long",
        "û����֪�����˵��������������س�������������ʮ��Ķ������ɵ������֣�\nҲû��֪������ʲô��ֻ֪�����ǰ��³��˷ֶ�֮�е�Ψһ��һ������\n�����������Ҳֻ�й�����ɱ��������ˡ�\n");
        set("attitude", "friendly");
        
        set("combat_exp", 4000000);
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 2);
        
        set("class","bat");
        set("force",1000);
        set("max_force",1000);
        set("force_factor",50);
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("blade",150);
        set_skill("bat-blade",200);
        set_skill("meng-steps",150);
        set_skill("move",200);
        set_skill("blade",150);
        set_skill("lingxi-zhi",150);
        
        map_skill("dodge","meng-steps");
        map_skill("move","meng-steps");
   map_skill("blade","bat-blade");
        map_skill("parry","bat-blade");
        map_skill("unarmed","lingxi-zhi");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
        "���³��������������ϵ�Ѫ�������������ӣ��૵���������ƺ�û���ˣ�\n��ȥŪЩ���ʵĲ��ǡ���\n",
        "���³����з����۾�������һ�ۣ�ҹ�ɰ��Ц�������ʳ��������������\n�ٺ٣���ζ�����ϡ�\n",
        }) ); 
        set("rank_info/respect", "�˳�");
        set("vendor_goods", ([
        __DIR__"obj/renroubao" : 5,
        __DIR__"obj/bloodleg" : 5,
        ]) );
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/butcherknife")->wield();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
                else add_money("gold", random(4));
} 
void init()
{       
        object ob;
        ::init();
        add_action("do_vendor_list", "list");
}   
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                           && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                        if (enemy[i]->is_busy()) {
                                this_object()->smart_attack();
                        }
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.huanyinqianchong");
}
smart_attack() {
        this_object()->perform_action("blade.shiwanshenmo");    
        } 
void reset()
{
        set("vendor_goods", ([
        __DIR__"obj/renroubao" : 5,
        __DIR__"obj/bloodleg" : 5,
        ]) );
}  

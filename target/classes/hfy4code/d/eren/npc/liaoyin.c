#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
//inherit SMART_NPC;
int kill_him(); 
void create()
{ 
        set_name("����ʦ̫",({"liaoyin"}));
        set("title",YEL"÷��������"NOR);
        set("long", "һ�����°�������ᣬ˫�ֺ�ʲ����վ�ڴ��ǰ��ʯ���Ͽ����㡣�����˸ɱ����
����Ҷһ�������ϿݻƵ����ϣ������˼�į��ʹ�ĺۼ����������еĻ��֣�ȫ�Ѿ�
����̫Զ��Ҳ̫���ˡ����������۾��ȴ���Ǵ���һ˿ϣ��֮ɫ��\n");
        set("age",59);
        set("gender", "Ů��");
        set("class","taoist");
        set("combat_exp", 10000000);
        set("attitude", "friendly");
        
        set("inquiry", ([
             "������" : (: kill_him :),
             "�һ�����" : (: kill_him :),
        ]));
        
            set_skill("literate", 240);
    set_skill("force", 150);
    set_skill("spells", 240);
    set_skill("scratching",120);
    set_skill("move", 100);
    set_skill("unarmed", 100);
    set_skill("sword", 120);
    
    set_skill("parry", 120);
    set_skill("dodge", 120);
    set_skill("gouyee", 200);
    set_skill("notracesnow", 160);
    set_skill("snowshade-sword", 150);
    set_skill("taoism", 240);
    set_skill("necromancy", 200);
    set_skill("scratmancy",220);
    set_skill("perception", 100);
    set_skill("qiankunstrike", 100);
    map_skill("unarmed", "qiankunstrike"); 
    map_skill("spells", "necromancy");
    map_skill("parry", "snowshade-sword");
    map_skill("sword", "snowshade-sword");
    map_skill("move", "notracesnow");
    map_skill("dodge", "notracesnow");
    map_skill("force","gouyee"); 
    set_temp("apply/dodge", 20);
    set_temp("apply/armor", 20); 

    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: cast_spell, "superbolt" :),
        (: cast_spell, "invocation" :),
            }) ); 
    
        set("max_atman", 2000);
        set("atman", 2000);
        set("max_mana", 2000);
        set("mana", 2000);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
// setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("chat_chance_combat", 100);
        
         
        CHAR_D->setup_char(this_object());
    //    auto_npc_setup("liaoyin",250,200,0,"/obj/weapon/","magician","necromancy");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}  
int kill_him()
{
        object me, another;
        
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"����ʦ̫����û�ջش��㡣\n");
                return 1;
                }
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ������ҵ���ʮ���꣬�Ҿ�֪��һ���������������ģ�����
�ҹ�Ȼ�ȵ��ˡ���\n",this_object());
        another = new(__DIR__"taohua");
        another->move(environment(this_object()));
        destruct(this_object());
        return 1;
}

#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("�״�",({"yi dajing","yi","dajing"}));
        set("title","���־���");
        set("long","�����Ľ����������һ��������ֹ�����ˣ������ղ�������������������������\n");
        set("gender","����");
        set("age",42);
        set("reward_npc", 1);
        set("difficulty", 20);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
       set("class","wudang");
    set_skill("literate", 140);
    set_skill("force", 150);
    set_skill("move", 150);
    set_skill("unarmed", 130);
    set_skill("sword", 200);
    set_skill("parry", 220);
    set_skill("dodge", 160);
    set_skill("changelaw", 180);
    set_skill("three-sword", 160);
    set_skill("taijiforce", 200);
    set_skill("taiji", 150);
    set_skill("foreknowledge",120);
    set_skill("five-steps", 180);
    set_skill("spells",100);
    set_skill("qixing",180);
    set_skill("incarnation",180);
    set_skill("perception", 200);
    map_skill("spells","qixing");
    map_skill("parry", "three-sword");
    map_skill("sword", "three-sword");
    map_skill("move", "five-steps");
    map_skill("dodge", "five-steps");
    map_skill("literate", "changelaw");
    map_skill("force", "taijiforce");
    map_skill("unarmed", "taiji"); 
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_kee",50000);
        set("max_gin",99999);
        set("max_sen",99999);
        set("eff_kee",9999);
        set("kee",50000);

        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N������˵�������Ǿ��ӡ������ǡ�������Զ�ǡ���û�ˡ����ܸı䡣������\n"NOR);            
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
         set("chat_chance_combat", 100);
            set("chat_msg_combat", ({
            (: cast_spell, "jixing" :),
            (: perform_action, "sword.nianzijue" :),
             }) ); 
        set("chat_chance",1);
        set("chat_msg",({
//                "����Ц���еص�����Ů���ü�����ϴ����ԽϴԽ����ġ���\n",
        }) );                   
        
//           CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
      carry_object("/obj/weapon/sword")->wield();    
}   
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/�״�_ma", 1);
        }
        
        ::die(); 

}

#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int loan(); 
void create()
{ 
        set("long", "�����µ���������ű��𸽽���������������ˣ���ü�������������ֳ���\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 2000000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",30);
        set("class", "lama");
        
        set_skill("iron-cloth", 100);
        set_skill("staff", 100);
        set_skill("lamastaff", 100);
        set_skill("unarmed", 160);
        set_skill("lamaism", 100);
        set_skill("bloodystrike", 160);
        set_skill("force", 100);
        set_skill("bolomiduo", 100);
        set_skill("spells",100);
        set_skill("parry",100);

        set_skill("kwan-yin-spells",100);
        set_skill("perception", 100);
        
        map_skill("spells","kwan-yin-spells");
        map_skill("parry","lamastaff");
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("staff", "lamastaff");
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("inquiry", ([
                "���":         (: loan() :),
                "���Ǯ":       (: loan() :),
                "��ʥ":         (: loan() :),
                
 
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"˵��ʩ������ʩ�����Ǯ�ɡ�\n",  
        }) );
        set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
            (: perform_action, "fefawubian" :),
            }) ); 
/*        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) ); */
         
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
       set_name("�����µ�����",({"tagong lama","lama"}));
        set("force_factor",40+random(50));
        setup();
        carry_object(__DIR__"obj/lamacloth")->wear();
        
}  
int loan(){
        object ob=this_object();
        
        message_vision(CYN"������̾�˿���˵�������������ʧ�ޣ���������ʥ������Խ��Խ���ˡ���\n"NOR,ob);
        message_vision(CYN"��������ϣ�����۹⿴��$N����ʩ����Ը��Щ��𣿡�\n\n"NOR,this_player());
        return 1;
}   
int accept_object(object who, object ob){
        
        if (ob->query("value")<100000) {
                message_vision(CYN"����������¶��һ˿ʧ�������ţ���лʩ������\n"NOR,this_object());
        } else if (ob->query("value")<500000) {
                message_vision(CYN"������˫�ƺ�ʮ����ͷ��Ŀ�����ţ���лʩ������\n"NOR,this_object());
        } else {
                message_vision(CYN"������������Ȼ�ų�����������Ҳ��Щ������������һ���ᱣ��ʩ���ġ�
�������ȥ�������޷��������ܽ�����\n"NOR,this_object());
                tell_object(who,WHT"����������Ļ����ע�⵽��ԭ����������־þ����꣬�Ѿ�ʮ���ƾ��ˡ�\n"NOR);
                who->set("zangbei/������ʩ��",1);
        }
        return 1;
}  

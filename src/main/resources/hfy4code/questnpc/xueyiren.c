 inherit QUESTNPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("Ѧ����", ({ "xue yiren", "xue" }) );
        set("nickname",RED"Ѫ����"NOR);
        set("gender", "����" );
    	set("age", 48);
        set("int", 52);
        set("per", 15);
        set("npc_difficulty",4);
        set("fle",40);
        set("agi",25);
        set("cor",60);
        set("str",40);
        set("bellicosity",0);
        set("score", 7200);
        set("long",
                "�������������ݣ����ż��������������Ҳû��ʲô���촦��
ֻ����һ˫�۾�ȴ�Ǿ����й⣬���˲��ұ��ӡ������ᱳ�ű����ʳ��ң�
�����ķ�ʽ���κ��˶���õ�����˱�����ֻΪ�����������ʱ���ｫ
���γ�����\n"
                );
        set("max_gin", 42000);
        set("max_kee", 130000);
        set("max_sen", 33000);
        set("max_force", 3000);
        set("force", 3000);
        set("force_factor", 130);
        set("combat_exp", 40000000);
        set_skill("sword", 400);
        set_skill("force", 200);
        set_skill("parry", 180);
        set_skill("unarmed",200);
        set_skill("move",300);
        set_skill("literate", 50);
        set_skill("dodge", 350);
        set_skill("huanhua-steps",300);
        set_skill("huanhua-sword", 300);
        map_skill("sword", "huanhua-sword");
        map_skill("parry", "huanhua-sword");
        map_skill("move", "huanhua-steps");
        map_skill("dodge", "huanhua-steps");

                set("chat_chance",10);
/*              set("chat_msg",({ 
                })      );
  */
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jingtianyijian" :),
//                (: perform_action, "unarmed.hongyeluanfei" :),
        }) );                
        setup();
        carry_object("/obj/weapon/sword")->wield();
}
/*
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
*/       

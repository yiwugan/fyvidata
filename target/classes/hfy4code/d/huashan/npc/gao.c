#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("������", ({ "gao yanan", "gao" }));
    set("long", "����ĸ�����һ������խ�䣬�Ե�Ӣ������������һ˫���������ӿ���۾���\n" );
        set("title", "��ɽ�� ��ʮ�ߴ�����");
        set("gender", "Ů��");
        set("age", 18);
        set("per", 27);
        set("int", 24);
        set("con", 25);
        set("agi", 23);
        set("class","huashan");
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 30);
        set("combat_exp", 800000+random(500000));
        
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������������ʦ������������ע������ʲô����\n", 
                "�����е��������������Ϊʲô�ܲ�����Ů�����棿��\n", 
        }) );
        set_skill("unarmed", 75);
        set_skill("move", 80);
        set_skill("dodge", 90);
        set_skill("parry", 80);
        set_skill("force", 80);
        set_skill("sword", 70);
        set_skill("qingfeng-sword", 50);
        set_skill("anxiang-steps", 90); 
        map_skill("move", "anxiang-steps");
        map_skill("parry", "qingfeng-sword");
        map_skill("sword", "qingfeng-sword");
        map_skill("dodge", "anxiang-steps"); 
        setup();
        carry_object(__DIR__"obj/gcloth",
           ([      "name"  :       "����",
                "long"  :       "����ɫ��С�ӡ�"                ])
        )->wear();
        carry_object("/obj/weapon/sword")->wield(); 
}     

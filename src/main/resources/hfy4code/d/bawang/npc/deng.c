 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("�˶���", ({ "deng dinghou", "deng"}) );
        set("nickname", HIR "��ȭС���"NOR);
        set("vendetta_mark","shaolin");
        set("gender", "����" );
        set("age", 44);
        set("per", 25);
        set("int",28);
        set("str",40);
        set("attitude","friendly");
        
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor",90); 
        set("long",
                "��ԭ��Զ�ھֵ����ˣ����˶���΢΢��Щ�����⣬��Ŀ���ȥ������\n��׳С���ǡ�\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
        name()+"һ��һ�ֳ�������ʵ���벻�����ڼ�ԭ�������㣭�٣�������࣡��\n",
        }) );
        
        set("combat_exp", 4000000);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        set("no_busy",5);
        
        set_skill("move", 200);
        set_skill("dodge", 200);
        set_skill("force", 160);
        set_skill("unarmed",200);
        set_skill("dragonstrike",200);
        set_skill("parry",200);
        set_skill("fengyu-piaoxiang",200);
        
        map_skill("dodge", "fengyu-piaoxiang");
   map_skill("unarmed", "dragonstrike");
        map_skill("move","fengyu-piaoxiang");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/flag");
}    

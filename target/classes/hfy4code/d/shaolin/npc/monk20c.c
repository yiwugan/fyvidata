 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_attack(); 
void create()
{
        set_name("��ɮ", ({ "shaolin monk", "monk"}) );
        create_family("������", 17, "����");
        set("gender", "����" );
        set("age",random(30)+ 62);
        set("nickname",HIR"��ͨ����"NOR);
        set("long", "����������ר���о������书��Ѱ���ƽ���ɾ��еĺ��У�\n");
        set("vendetta_mark","shaolin");
        set("combat_exp",4990000);
        set("attitude", "friendly");
        set("cor",20);
        set("cps",80);
        
        set("force",1000);
        set("max_force",1000);
        set("force_factor",50);
        set("mana",1200);
        set("max_mana",1200);
        
        set_skill("unarmed", 200+random(100));
        set_skill("move",200);
        set_skill("force",200);
        set_skill("dodge", 180);
        set_skill("puti-steps",160);
        set_skill("xiaochengforce",140);
        set_skill("yiyangzhi",150);
        set_skill("iron-cloth",100);
        set_skill("yijinjing",100);
        
        set_skill("spells",100);
        set_skill("qixing",100); 
        map_skill("spells","qixing");
           
        set("resistance/kee",50);
        set("resistance/gin",20+random(80));
        set("resistance/sen",50);
        
        map_skill("iron-cloth","yijinjing");
        map_skill("dodge", "puti-steps");
        map_skill("force", "xiaochengforce");
        map_skill("unarmed", "yiyangzhi");
        map_skill("move","puti-steps");
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
          (: smart_fight() :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"̾����������������\n",
                name()+"Ц�������뿴��������ţ�\n",
                name()+"�������㿴Ҳû���ã�����츳������\n",
                name()+"���������Ѿ���ʮ����û����¥һ���ˣ�\n"
        }) );
        setup();
        carry_object(__DIR__"obj/monk20c_cloth")->wear();
} 
smart_fight()
{
        int j,i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        
/*      for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie())
                {       who->cast_spell("zombie-bolt");
                        return;
                }               
        }*/
   who->smart_attack();
        return;
} 
smart_attack() {
                this_object()->perform_action("unarmed.qiankun");               
        return;
        } 

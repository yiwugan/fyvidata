#include <ansi.h>
inherit QUESTNPC;
void create()
{
        set_name("����¥", ({ "hua manlou","hua" }) );
        set("gender", "����");
        set("age", 32);
    	set("nickname",WHT"�ʻ���¥"NOR);
    	set("title","��������");
        set("npc_difficulty",6);
        set("organization/����","����");
        set("long",
"�ʻ���¥������¥���ʻ���������ǿ�ҵ��Ȱ����������Ȱ����е�����һ����
\n"
               );  
        set("attitude", "peaceful");
        set("combat_exp", 50000000);
        set("chat_chance", 10);
        set("chat_msg", ({
              "����¥˵������ֻҪ���ȥ���ԣ��ͻᷢ���������Ƕ�ô��
����ÿ�������ﶼ�кܶ����������������з��յ��������¡���\n",
"����¥���������кܳ����˯�ߣ��кܺõ�θ�ڣ������
����������ӣ���һ�������ܺõĹ��٣���Щ�����㹻����
���һ��и��ܺõ����ѡ���\n",
        }) );
                set("chat_chance_combat",60);
              set("chat_msg_combat", ({
                      (:perform_action,"unarmed.xinyoulingxi":)
              })      );
        set("force", 8000);
        set("max_force", 8000);
        set("force_factor", 80);
        set("max_gin",50000);
        set("max_kee",80000);
        set("max_sen",50000);
        set("fle",30);
        set("int",41);
        set("cor",40);
        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("dodge", 220);
        set_skill("parry",220);
        set_skill("lingxi-zhi",300);
   	set_skill("move", 300);
   	set_skill("iron-cloth",300);
   	set_skill("fengyu-piaoxiang",300);
   	set_skill("xisui",200);
   	map_skill("iron-cloth","xisui");
        map_skill("unarmed","lingxi-zhi");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        setup();
    carry_object("/obj/armor/cloth")->wear();
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int myexp,hisexp;
        myexp=me->query("combat_exp");
        hisexp=victim->query("combat_exp"); 
        if (random(myexp+hisexp)>hisexp&&(!random(2)))
        {
                victim->start_busy(10+random(10));
//                victim->remove_all_killer();
        return HIR "$nֻ����һ�飬ҪѨ���ƣ�һ�������ܶ��ˡ�\n" NOR;
        }
}    

int accept_fight(object me)
{
	command("sigh");
        command("say ��һ��Ϲ�ӣ����ֺο࣬սʤ��������˵��ʲô�أ�");
        return 0;
}
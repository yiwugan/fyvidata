#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("����", ({ "ding feng", "ding", "feng" }));
    set("long", "
��������������ƮƮ�������������������Ҳ���ú�Ӣ����
���ϸ���Զ������Ц�ݡ�\n" );
 set("nickname", HIC "�����ٷ�"NOR);
 set("gender", "����");
 set("age", 27);
 set("str", 25);
 set("int", 24);
 set("con", 25);
 set("kee", 1000);
 set("max_kee", 1000);
 set("gin", 1000);
 set("max_gin", 1000);
 set("force", 2500);
 set("max_force", 1000);
 set("force_factor", 50);
 set("combat_exp", 800000);
 set("attitude", "friendly");
 set("chat_chance_combat", 50);
 set("chat_msg_combat", ({
  (: perform_action, "sword.poqi" :),
  (: perform_action, "sword.pocan" :),
 }) );
 set("chat_chance", 1);
 set("chat_msg", ({
"�����૵�����ɽ����һ�ס����ʮ��ʽ����ȷ�����������������ܼ���
�����صġ��������ʽ�����������硣\n ",
"����΢Ц���������ʮ��ʽ��������ڡ��嵭������,���������ǣ��������ޣ�
��ʵ���飬�Ʊ�δ�� ��\n",
 }) );
 set("inquiry",([
  "���ʮ��ʽ" : "�����˻�ɽ��ɽ֮��������ȴʧ���ˣ�����\n",
 ]) );
 set_skill("unarmed", 70);
   set_skill("move", 100);
        set_skill("dodge", 100);
        set_skill("parry", 90);
        set_skill("force", 90);
        set_skill("sword", 90);
        set_skill("dugu-sword", 140);
        set_skill("zixia-force", 90);
        set_skill("huashan-steps", 90);
        map_skill("force", "zixia-force");
        map_skill("move", "huashan-steps");
        map_skill("parry", "dugu-sword");
        map_skill("sword", "dugu-sword");
        map_skill("dodge", "huashan-steps"); 
        setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/sword")->wield(); 
}    

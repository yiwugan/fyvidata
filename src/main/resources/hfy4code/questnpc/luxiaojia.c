 inherit QUESTNPC;
//inherit F_MASTER;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("·С��", ({ "lu xiaojia", "lu" }) );
        set("gender", "����" );
    	set("age", 25);
    	set("title", "���п�" );
    	set("nickname", HIR"���⽭��"NOR );
        set("int", 35);
        set("per", 30);
        set("npc_difficulty",10); 
        set("organization/����","а");
        set("quest_npc",1);
        set("class","assassin");
        set("resistance/kee",60);
        set("resistance/gin",60);
        set("resistance/sen",60);
        set("long",
                "���Ǹ������ˣ�һ����ֵ������ˣ�����˫��ֵ��۾�������Ц��ʱ����˫�۾���
������ģ����������˵��۾���û����У�Ҳû�б��顣
\n"
                );
        set("max_gin", 300000);
        set("max_kee", 300000);
        set("max_sen", 300000);
        set("eff_gin", 300000);
        set("eff_kee", 300000);
        set("eff_sen", 300000);
        set("gin", 300000);
        set("kee", 300000);
        set("sen", 300000);
        set("max_force", 4000);
        set("force", 4000);
        set("force_factor", 100);
        set("cor",80);
        set("str",50);
        set("combat_exp", 80000000);
        set("score", 3000);
        set("agi",25);
        set("int",30);
        set("chat_chance",10);
                set("chat_msg",({
"·С������һ�Ż���������������Ȼ������Ż����䵽�Լ���������۾���
������̾�˿�������ʼ�����׽���\n",
"·С�Ѻ�ȻЦЦ ��˵������ɱ���Ǽ��ɾ�ʹ������顣��������һ�٣���˵����
��������ɱ��֮ǰ����һ��Ҫϴ���衣��\n",
        })      );
        set_skill("sword", 500);
        set_skill("force", 200);
        set_skill("parry", 300);
        set_skill("literate", 140);
        set_skill("dodge", 280);
        set_skill("sharen-sword", 300);
        set_skill("move", 300);
        set_skill("jinhong-steps", 200);
        set_skill("jingxing",250);
        map_skill("force","jingxing");
        map_skill("dodge","jinhong-steps");
        map_skill("move","jinhong-steps");
        map_skill("sword", "sharen-sword");
        map_skill("parry","suiyuan-sword");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );
        setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/lusword")->wield();
}   
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_skill("iron-cloth")>175) {
                                if (this_object()->query_temp("weapon")){
                                command( "say �ÿ���Ӳ�������ҵģ�");
                                command("unwield all");
                                }
                        } else  command("wield all");
                        
                        if (!enemy[i]->query_temp("till_death/lockup"))
                        {
                                this_object()->smart_busy();
                        } else this_object()->smart_attack();
                        
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.canglongzhaxian");
}
smart_attack() {
        this_object()->perform_action("sword.sharenruma");      
        }    

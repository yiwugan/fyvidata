#include <ansi.h>
inherit NPC;
string  smart_fight( object who);
void create()
{
        set_name("������ͳ��", ({ "guard leader"}) );
        set("gender", "����" );
        set("age", 42);
        set("class","assassin");
        set("long", "����һλ��Ǯ���ܶ�Ļ�����ͳ�졣\n");
//        set("vendetta_mark","jinqian");
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        
        set("max_force",500);
        set("force",500);
        set("force_factor",30); 
        set_skill("sword", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("jinhong-steps",150);
        set_skill("lefthand-sword", 150);
        set_skill("iron-cloth", 200);
        set_skill("unarmed",120);
        
        set_skill("flame-strike",100);
        map_skill("dodge","jinhong-steps");
        map_skill("sword","lefthand-sword");
        map_skill("move","jinhong-steps");
        map_skill("unarmed","flame-strike");
        
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: smart_fight(this_object()) :),
        }) ); 
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ͳ��ȵ���û�а����Ŀ�����˭����׼ͨ����\n",
        }) );
   
        setup();
        add_money("coin", 5);
        carry_object(__DIR__"obj/tangfu")->wear();
        carry_object("/obj/weapon/sword")->wield();
} 
string smart_fight(object who)
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                if (enemy[i]->query_skill("iron-cloth")>200) {
                        if (this_object()->query_temp("weapon")){
                        command( "say ��������Ӳ������һ���ҵ����溮���ƣ�");
                        command("unwield sword");
                        }
                } else  command("wield sword");
                if (enemy[i]->query_temp("till_death/lockup"))
                        command("perform duxin" );
                        else command("perform dodge.canglongzhaxian");
        }
        }
        return "1";
}  
int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 50000 ) {
                        say( name()+"͵͵��"+ob->name()+"���뻳�ڣ�Ц��������������������\n");
                        who->set_temp("jinqian", 1);
                        return 1;
                } else {
                        command("puke");
                        return 0;
                }
        return 0;
}  
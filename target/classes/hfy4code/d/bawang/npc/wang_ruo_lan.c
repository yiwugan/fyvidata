#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
    set_name( "������", ({ "wang ruolan", "wang","ruolan" }) );
        set("long", "��������������ͷ�Ķ���Ů����Ҳ�ǵ������ǹ����Ψһ���ˡ�
һϮ���£��Գ�����͹���µĽ�����ġ�һ����ˮ���˫��������Թ�����Ŷ�ϲ��\n");
        set("attitude", "friendly");
        set("title", HIM "�绨����"NOR);
        set("age", 17);
        set("gender", "Ů��" );
        set("cor", 40);
        set("cps", 25);
        set("per", 60);
        set("class","fugui");
        set("combat_exp", 4000000);
        set("reward_npc", 1);
        set("difficulty", 5);
        
        set("resistance/kee",30);
        set("resistance/gin",20);
        set("resistance/sen",30);
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
        set("force",1000);
        set("max_force",1000);
        set("force_factor",100);
        
        set_skill("move", 160);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("unarmed", 150);
        set_skill("skyforce",150);
        set_skill("iron-cloth", 120);
        set_skill("spear", 200);
        set_skill("xuezhan-spear",130);
        set_skill("hawk-steps",160);
        set_skill("eagle-claw",150);
        
        map_skill("force", "skyforce");
        map_skill("parry","xuezhan-spear");
        map_skill("spear","xuezhan-spear");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps"); 
        map_skill("unarmed","eagle-claw");     
        
        setup();
        carry_object(__DIR__"obj/white_cloth")->wear();
        carry_object(__DIR__"obj/gold_spear")->wield();
        add_money("gold", 5);
} 
int accept_object(object me, object obj)
{
        object book;
        if( (string) obj->query("name") == HIR"����ǹ"NOR)
        {
                message_vision("$N��$n���˸��򸣣�\n",this_object(),me);
                command("smile");
                command("say ��л��λ" + RANK_D->query_respect(me) + "�����һ��˶�ʧ�İ���ǹ��\n");
                
                if (me->query("m_killer/�鶫��")) {
                        command ("say ��Ϊ��л���Ȿ����ǹ�ף����͸����ɣ�");
                        book = new(__DIR__"obj/bw_book");
                        if(book) book->move(me);
                        book = new(__DIR__"obj/spear_book");
                        if(book) book->move(me);
                        message_vision("$N�ӻ����ͳ�����ǹ���͸�$n��\n",this_object(),me);
                } else
                        message_vision("$N�ƺ���ӻ�����Щʲô���������ܣ���ԥ��һ����ͣס�ˡ�\n",this_object());
                if(!me->query("m_success/������ǹ"))
                {
                        me->add("score",100);
                        me->set("m_success/������ǹ",1);
                }
           return 1;       
        }
        else
        {
                command("lean");
                command("say ��л��λ" + RANK_D->query_respect(me) + "��ʲô�Ҷ���Ҫ��ֻҪ��������߾ͺá�\n");
                return 0;
        }  
        return 1;
} 
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<this_object()->query("combat_exp")*3/2) {
                                this_object()->smart_busy();
                        }
                        if (enemy[i]->is_busy()) {
                                        this_object()->smart_attack();
                        } else ccommand("pig");
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.yingjichangkong");
}
smart_attack() {
        this_object()->perform_action("spear.bafangfengyu");    
        }

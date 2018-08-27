#include <ansi.h>
inherit NPC;
int gao();
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
    set_name("С��", ({"xiao wu","wu"}) );
    set("gender", "����" );
    set("nickname", HIC"���ֽ�"NOR);
    set("title", "������ �̿�");
    set("long", "С�俴���·��Ǹ�����㡢����ɢ���ˣ���ϲ��Ц����ϲ���ơ�û����������
����ɱ��ʱ�Ķ����Ƕ�ôѸ�٣���ô׼ȷ������Ҫ��Ϲ������ۣ����Ľ��;�
����������ĵط���\n");
        set("attitude", "friendly");
        set("age", 25);
        set("cor", 25);
        set("cps", 25);
        set("per", 25);
        set("combat_exp", 3000000);
        set("class","assassin");
        
        set_temp("apply/armor", 100);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 50);
        set("reward_npc", 1);
        set("difficulty", 3);
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",80);
                        break;
                default: set("resistance/kee",30);
        }
                
        set_skill("sword", 200);
        set_skill("parry", 150);
           set_skill("unarmed",150);
        set_skill("flame-strike",150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("sharen-sword",180);
        set_skill("three-sword",150);
        set_skill("jinhong-steps",160);
        set_skill("lefthand-sword",200);
        
        map_skill("dodge","jinhong-steps");
        map_skill("move","jinhong-steps");
        map_skill("parry","three-sword");
        map_skill("sword","sharen-sword");
        map_skill("unarmed","flame-strike");
        
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );      
        
        
        set("chat_chance", 1);
        set("chat_msg", ({
           "С��������ü���૵����������ȳ�������³ç�һ��أ�\n",
        }) );
        set("inquiry", ([
                "gaoli" : (: gao :),
                "gao" : (: gao :),
                "����" : (: gao :),
                "gao li" : (: gao :),
        ]));
        set("jadebox", 1);
        setup();
        carry_object("/d/fugui/npc/obj/m_cloth3")->wear();
        carry_object(__DIR__"obj/windsword")->wield();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
                else add_money("gold", random(4)); 
} 
int gao(){
        object me;
   me = this_player();
        if(query("answering")){
                return notify_fail("С���ƺ�����æ��\n");
        }
        if(me->query("combat_exp") < 1000000) {
                message_vision("$N������$nһ����������ü��������û����������������һ���غ��ˡ���\n", 
                                this_object(), me);
        } else if (me->query_temp("marks/underground_gao")) {
                message_vision("$N����һ����$n�����Ҹող��Ǹ�����ȸ��������ѵ��Ǹ����Ӳ����ã�\n",
                                this_object(), me);
        } else {
                message_vision("$NƲ��$nһ�ۣ���˼�˰��Σ�˫��ͻȻ�ų����������ˣ�������������
һ�����Ծȸ�����˫˫��һ�����ԡ�\n", this_object(), me);
                set("answering", 1);
                call_out("give_jadebox", 2, me);
        }
        return 1;
} 
void give_jadebox(object me){
        object box;
        if(!interactive(me) || environment(me) != environment(this_object())){
                return;
        }  
        message_vision("$N����Ц��Ц���ã���Ͱ����ȸ����н������������ţ���������ȸ�� 
�����������棬����ȸ����ڵ�����Ŀ�ģ�����ɱ�ˣ����Ǿ��������ԡ����� 
�����򲻵���ʱ������Ҫ������\n", this_object(), me);    
        me->set_temp("marks/underground_gao", 1);
        box = new(__DIR__"obj/jadebox");
        if(objectp(box)){
                box->move(me);
        }
        delete("answering");
        return;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
   while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->query_temp("till_death/lockup"))
                        {
                                this_object()->smart_busy();
                        } else  if (enemy[i]->is_busy()) 
                                        this_object()->smart_attack();
                          else {
                                command("enable sword lefthand-sword");
                                this_object()->perform_action("sword.duxin"); 
                                command("enable sword sharen-sword");
                        }
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.canglongzhaxian");
}
smart_attack() {
        this_object()->perform_action("sword.sharenruma");      
        }    

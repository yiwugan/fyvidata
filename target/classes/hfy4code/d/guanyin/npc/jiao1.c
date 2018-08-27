 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        object armor;
        set_name("����", ({ "jiao hua" }) );
        set("gender", "����");
        set("age", 45);
        set("nickname","���");
        set("title",WHT"����˫ɷ"NOR);
        set("long",
"������������ƽ������һ�飬�ޱ��޶�����üë��û�У�ֻ���۾��������麮�񣬷�
��һ�ֳ��ǵĹ�â����\n"
);
          
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty",3);
        
        set("class","lama");
        set("no_busy",6);
        set("combat_exp", 3000000);        
        set("int", 30);
        set("cps", 60);
        set("spi", 30);
        set("cor",40);
        
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/kee",40);
        set("resistance/gin",95);
        set("resistance/sen",40);
                
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );        
        
        set("marks/�����Ϭ",1);
        set_temp("xinyoulingxi", 1);
        
        set_skill("perception", 150);
        set_skill("force", 180);
        set_skill("unarmed", 180);
        set_skill("parry",200);
        set_skill("move", 180);
        set_skill("lingxi-zhi",150);
        set_skill("kwan-yin-spells",130);
        set_skill("spells",200);
        
        map_skill("spells","kwan-yin-spells");  
        map_skill("move","five-steps");
        map_skill("unarmed","lingxi-zhi");
              
        setup(); 
        add_money("gold", random(5));
        armor=new("/obj/armor/cloth");
        armor->set_name(WHT"�����"NOR,({"cloth"}) );
        armor->move(this_object());
        armor->wear();
} 
 
void init()
{
        object ob;
        ::init();
        add_action("do_killing","kill");
} 
int do_killing(string arg)
{
    object player, victim;
    string id;
    int sen; 
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id= victim->query("id");
        if( id == "jiao lao" && player->query("combat_exp")>3400000)
        {
            message_vision(
"$NЦ�����������������ֵ���һ����ϡ�\n", this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            return 0;
        }
    }
    return 0;
}  
smart_fight()
{
        int j;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie() && random(2))
                {       who->cast_spell("ni");
                        return;
                }               
        }
        return;
} 

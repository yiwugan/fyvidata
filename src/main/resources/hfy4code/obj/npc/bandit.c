 // bandit.c
#include <ansi.h>
inherit NPC;
void create() {
        set_name("����", ({ "tufei", "bandit"}) );
        set("long","һ�������˰̼Ӻ���ļһ\n");
        set("attitude", "friendly");
        set("vendetta/authority",1);
        set("per", 1);
        set("intellgent",1);
        set("pursuer",1);
        set("no_return",1);
        set("combat_exp", 400000+random(400000));
                set("bellicosity", 10000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                name()+ "�ȵ�����������ҪǮ��Ҫ������\n",
                name()+ "Ц������٣��е�վ��ߣ�Ů��վ�ұߣ����в�Ů��վ�м䣡\n",
                                HIR+ name()+ HIR"�󺰣�����һ����������������׬һ������ϲ������Ҫ�����㣡\n"NOR,
                                (: random_move :),
        }) );
        set("chat_chance", 99);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        set_skill("unarmed", 70+random(150));
        set_skill("axe", 70+random(150));
        set_skill("blade", 70+random(150));
        set_skill("hammer", 70+random(150));
        set_skill("sword", 70+random(150));
        set_skill("parry", 170+random(150));
        set_skill("dodge", 170+random(150));
        set_skill("move", 100+random(150)); 
        set_temp("apply/attack", 20+random(200));
        set_temp("apply/dodge", 20+random(200));
        set_temp("apply/armor", 20+random(200));
        set_temp("apply/damage", 20+random(200));
        set_temp("apply/move", 20+random(200)); 
        setup();
} 
void init() {
    remove_call_out("hunting");
        if(environment() && !environment()->query("no_fight")) {
        call_out("hunting",1);
        }
} 
void hunting() {
        int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
        if(ob[i]->query("class")=="bandit") continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
} 
void setup_bandit(string name, string armor, string weapon, string mark) {
        object armor_ob, weapon_ob;
        
        set("name", name);
        armor_ob = new(armor);
        if(objectp(armor_ob)) {
                armor_ob->move(this_object());
                armor_ob->wear();
        }
        weapon_ob = new(weapon);
        if(objectp(weapon_ob)) {
                weapon_ob->move(this_object());
                weapon_ob->wield();
        }
        set("area_mark", mark);
}   
void die()
{
        int i,score,exp,pot;
        object killer,owner; 
        score=random(5);
        pot=600+random(1400);
        exp=300+random(1200);
        
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->add("combat_exp",exp);
             killer->add("potential",pot);
             killer->add("score",score);
             tell_object(killer, HIW "\n�ɹ��˷ˣ������������ˣ�\n" + chinese_number(exp) + "��ʵս����\n"
                        + chinese_number(pot) + "��Ǳ��\n" + chinese_number(score)+"���ۺ�����\n" NOR);
        }
        
        ::die(); 

}

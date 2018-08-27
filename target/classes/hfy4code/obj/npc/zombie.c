 // zombie.c
#include <ansi.h> 
inherit NPC;
object get_target(string id);
void do_bite(); 
void create()
{
        set_name("��ʬ", ({ "zombie" }) );
        set("long",
                
"����һ�߱����÷�����ƵĽ�ʬ�������԰׵����Ͽ������κ�ϲŭ���֡�\n");
        set("max_gin", 40000);
        set("max_kee", 40000);
        set("max_sen", 10000);
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("no_arrest",1);
        set("no_fly",1);
        set("str", 100);
        set("cor", 40);
        set("haunt", 0);
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "��ʬ���з����ɺɵĽ�����\n",
                "��ʬ�����Ͽ�ʼ���Σ�һ��鴤�������Ƶش�С�\n",
                "��ʬ��ָ���ţ�ҧ���гݣ�¶��������Ц�ݡ�\n",
                (: do_bite :),
        }) );
        set_skill("unarmed", 40);
        set_skill("dodge", 30);
        set_skill("move", 30); 
        set_temp("apply/damage", 25); 
        setup();
} 
void init()
{
        object  ob, targ;
        string  target; 
   ::init();
        if(query("haunt") == 1) {
                target = query("haunttar");
                if(stringp(target))
                //if(objectp(targ = present(target, environment()))) {
                targ =  get_target(target);
                if(objectp(targ)) {
                        message_vision("$N�۾���Ȼ�������૵�˵����" RED
"ɱ....��....$n....\n" NOR, this_object(), targ);
                        this_object()->kill_ob(targ);
                        this_object()->set_leader(targ);
                        targ->kill_ob(this_object());
                }
        }
} 
object get_target(string id) 
{       object target, *inv;
        int i;
        inv = all_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->name() == id || inv[i] == present(id, environment()) ) {
                        if (inv[i]->is_character()) target = inv[i];
                        break;
                }
                
        }
        return target;
}  
int is_zombie() { return 1; } 
void animate(object who, int level)
{
        set("possessed", who);
        set_leader(who);
        set_skill("unarmed", 140+random(level));
        set_skill("dodge", 230+random(level));
        set_skill("move", 230+random(level));
        set("str",30+level/40+random(level/15));
        level=level*level*level/12;
        level=20000+level*2/3+random(level)*2;
        set("combat_exp", level);
} 
void dispell()
{
        object corpse; 
        if( environment() ) {
                say( name() + "�����ص�����������Ϊһ̲Ѫˮ��\n");
        } 
        destruct(this_object());
} 
int heal_up()
{
        object  master, leader;
        int     lvl; 
        if( objectp(master = query("possessed"))) { 
                lvl = (int)master->query_skill("necromancy", 1);
                if((int)master->query("atman") > lvl ) {
                        message("tell", HIR + name() +  "�����㣺��...��...Ҫ...��...��...��...��...\n" NOR, master );
                        master->add("atman", -lvl);
                        master->receive_damage("gin", lvl/10);
                        ::heal_up();
                        return 1;            
                } 
        } 
        call_out("dispell", 1);
        return ::heal_up();
} 
void do_bite()
{
        object *enemy; 
        say( name() + "�������һ���ȳ���Ż�ĳ�����ʹ�˾���ͷ�����͡�\n" );
        enemy = query_enemy();
        for(int i=0; i<sizeof(enemy); i++) {
                if( !enemy[i] ) continue;
                enemy[i]->receive_damage("gin", 20);
                COMBAT_D->report_status(enemy[i], "gin");
        }
}
     

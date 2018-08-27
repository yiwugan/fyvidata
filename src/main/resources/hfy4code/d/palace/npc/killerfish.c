 inherit NPC;
void create()
{
        set_name("食人鱼", ({ "killer fish" }) );
        set("race", "野兽");
        set("age", 4);
        set("kee",700);
        set("eff_kee",700);
        set("max_kee",700);
        set("sen",300);
        set("eff_sen",300);
        set("max_sen",300);
        set("gin",300);
        set("eff_gin",300);
        set("max_gin",300);
        set("yes_carry", 1);
        set("long", "一条眼露凶光的食人鱼。\n"); 
        set("limbs", ({ "头部", "身体", "尾巴", "眼睛" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 100);
        set_skill("move",300);
        set("combat_exp", 29999);
        set("bellicosity", 300 );
        set("chat_chance", 20);
        add_temp("apply/damage",10+random(10));
        setup();
} 
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        add_action("do_get","get");
        }
} 
int do_get(string arg)
{
string what, where;
if(!arg) return 0;
if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
if((what== "all" || what== "woodcase") && (where=="watergrass" || where=="水草"))
{
message_vision("$N狠狠瞪了$n一眼，一口向$n咬了上来！\n",this_object(),this_player());
this_object()->kill_ob(this_player());
this_player()->start_busy(2);
return 1;
}
}  

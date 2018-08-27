inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("�Թ�̽����", ({ "mazewalker" }) );
        set("gender", "����" );
        set("age", 68);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_mana", 300);
        set("mana", 300); 
        set("max_force", 10000);
        set("force", 5000);
        set("force_factor", 500); 
        set("attitude", "peaceful"); 
        set("long","����һλ�þ���˪�����ˡ�\n"); 
        set("combat_exp", 200000);
        set("score", 50);
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100); 
        set_skill("meihua-shou", 100);
        set_skill("qidaoforce", 150);
        set_skill("fall-steps", 100); 
        map_skill("unarmed", "meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge", "fall-steps");
                 set("chat_chance", 50);
        set("chat_msg", ({
                (: random_move :),
        }) );   
        setup();
        add_money( "coin" , 50);
} 
int random_move()
{
        mapping exits;
        string *dirs, direction, dest, last_room;
        object env;
        int i;
        
        if( !mapp(exits = environment()->query("exits")) ) return 0;
        last_room = query("last_room");
        
        dirs = keys (exits);
        if(!sizeof(dirs)) return 0;
        dest = last_room;
        i=0;
        while(dest==last_room&&i<20)
        {
                direction = dirs[random(sizeof(dirs))];
                dest = environment()->query("exits/"+direction);
                i++;
        }
//      if(i==5)
//              return 0;
        set("last_room",file_name(environment()));                      
        command("go " + direction); 
        return 1;
}       

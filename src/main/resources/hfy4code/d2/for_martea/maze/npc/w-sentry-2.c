 inherit NPC;
string kill_passenger(object who); 
void create()
{
        set_name("������", ({ "wood guardian","guardian"}) );
        set("gender", "����" );
        set("group","wood");
        set("attitude", "peaceful"); 
        set("long","����һλ�þ���˪�����ˡ�\n"); 
        set("combat_exp", 200000); 
        set("chat_chance", 50);
        set("chat_msg", ({ 
        }) ); 
        setup();
        add_money( "coin" , 50);
        carry_object("/obj/armor/cloth")->wear();
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

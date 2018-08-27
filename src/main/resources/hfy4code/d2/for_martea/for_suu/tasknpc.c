
 // tasknpc.c
// by suu for TASK_NPC 
inherit NPC;
void reset_npc()
{
        // npc improve exp and skill automation
        int exp;
        mapping skl;
        string *sname,skill;
        exp=query("combat_exp");
        if(exp<99999999)
                add("combat_exp",exp/100);
        skl = query_skills();
        if(random(3)) return;
        if( !mapp(skl) ) return;
        sname=keys(skl);
        skill=sname[random(sizeof(sname))];
        set_skill(skill,skl[skill]+1);
} 
// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
        string *msg;
        int chance, rnd;
        string new_room;
        object room,old_room; 
        if( !environment() ) return 0;
        if( query_temp("is_unconcious") ) return 0;
        if(query("intellgent")) intellgent_behavor();
        if(!this_object()->is_fighting() )
        {
         if(random(100)>80)this_object()->random_move();
         if(!random(300))
{
        old_room=environment(this_object());
        new_room=TASK_D->random_room();
        if(!room=find_object(new_room))
                room=load_object(new_room);
   this_object()->move(room);
        tell_room(old_room,this_object()->query("name")+"��Хһ���������ȥ��\n");
        tell_room(room,"��Ӱһ����"+this_object()->query("name")+"����������ǰ��\n");
        }                               
  }
        if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
                return 0; 
        if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
                if( random(100) < chance ) {
                        rnd = random(sizeof(msg));
                        if( stringp(msg[rnd]) )
                                say(msg[rnd]);
                        else if( functionp(msg[rnd]) )
                                return evaluate(msg[rnd]);
                }
                return 1;
        }
} 
void die()
{
        object killer, owner;
        string location;
        int difficulty;     
        
        if (this_object()->query_temp("last_damage_from")) 
        {
                killer = this_object()->query_temp("last_damage_from");
         
                if(owner=killer->query("possessed"))
                {
                        killer = owner;
                } 
                //reward killer
                TASKNPC_D->quest_reward(killer,this_object());
        }
        ::die();
}

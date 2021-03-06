 // 11/13/2002 by silencer@fy4
//      (1) revised random_move
//      (2) added conjure/curse fuction.  
#include <command.h>
inherit CHARACTER;
inherit F_CLEAN_UP;
#include <ansi.h> 
void init(){
        ::init();
        if( !query_heart_beat(this_object()) ) {
                set_heart_beat(1); 
        }
} 
varargs object carry_object(string file, mapping attr)
{
        object ob;
        string *keyList;
        int i; 
        if(!objectp(ob = new(file))) return 0;
        if(mapp(attr)) {
                keyList = keys(attr);
                for(i=0; i<sizeof(keyList); i++) {
                        ob->set(keyList[i], attr[keyList[i]]); 
                }       
        }
        
        ob->move(this_object());
        return ob;
} 
object add_money(string type, int amount)
{
        object ob; 
        ob = carry_object("/obj/money/" + type);
        if( !ob ) return 0;
        ob->set_amount(amount);
} 
int accept_fight(object who)
{
        string att; 
        att = query("attitude"); 
   if( is_fighting() )     switch(att) {
                case "heroism":
                        command("say 哼！出招吧！\n");
                        break;
                default:
                        command("say 想倚多为胜，这不是欺人太甚吗！\n");
                        return 0;
        } 
        if( (int)query("gin") * 100 / (int)query("max_gin") >= 90
                && (int)query("kee") * 100 / (int)query("max_kee") >= 90
                && (int)query("sen") * 100 / (int)query("max_sen") >= 90 ) 
        {
                switch(att)
                {
                        case "friendly":
                                command("say " + RANK_D->query_self(this_object())
                                                + "怎麽可能是" + RANK_D->query_respect(who)
                                                + "的对手？\n");
                                return 0;
                        case "aggressive":
                        case "killer":
                                command("say 哼！出招吧！\n");
                                break;
                        default:
                                if( !is_fighting() )
                                        command("say 既然" + RANK_D->query_respect(who)
                                                        + "赐教，" + RANK_D->query_self(this_object())
                                                        + "只好奉陪。\n");
                }
                return 1;
        }
        else return 0;
}  
// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
//      It's no longer in reset() of the room -- by silencer@FY4 
int return_home(object home)
{
        // Are we at home already?
   if( !environment() || environment()==home )
                return 1; 
        // Are we able to leave?
        if( !living(this_object())
        || is_fighting()
        || !mapp(environment()->query("exits")) ) return 0; 
        // Leave for home now.
        message("vision", this_object()->name() + "急急忙忙地离开了。\n",
                        environment(), this_object());
        return move(home);
}   
// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int intellgent_behavor()
{
        int enc,max;
        object *inv;
        enc = (int) query_encumbrance();
        max =  (int) query_max_encumbrance();
        if(enc * 3 < max)
        command("get all");
        return 1;
} 
int chat()
{
        string *msg;
        int chance, rnd; 
        if(!environment() ) return 0;
        if(query_temp("is_unconcious") ) return 0;
        if(query("intellgent")) intellgent_behavor();
        if( !chance = (int)query(is_fighting()? "chat_chance_combat":
                                                         "chat_chance") )
                return 0; 
        if(arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg")) 
                        && sizeof(msg) != 0) {
                if( random(100) < chance ) {
                        rnd = random(sizeof(msg));
                        if(stringp(msg[rnd])) {
                                say(msg[rnd]);
                   } else if(functionp(msg[rnd])) {
                                return evaluate(msg[rnd]);
                        }
                }
                return 1;
        }
        return 0;
}  
// Default chat function: Let the npc random move to another room.
// modified by silencer @4-14-2002 so NPC will only walk within his AREA. 
int random_move()
{
        mapping exits;
        string *dirs, direction, to_go_place, my_birth_place;
        object env; 
//      把NPC的auto_return_home 从room.c的reset()里移到这里以节省系统资源。
//      NPC return_home 暂设为 30 步，这个并不是定量时间，取决于chat_chance的频率，
//      30x100/2 = 1500 sec = 25 分钟，也就是说chat_chance(1)是大概25分钟回家一次。
//      注意，即使NPC被trap住了也会return_home。
//      query("no_return")是给一些特定的NPC的。 
        if (query_temp("random_move")>= 30 && query("startroom") && !query("no_return")) {
                if (return_home(query("startroom")))
                        delete_temp("random_move");
                return 1;
        }
                
        if( !mapp(exits = environment()->query("exits")) ) return 0;
        
        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        env = environment(this_object());
        to_go_place = env->query("exits/"+direction);
        my_birth_place = file_name(this_object());
        
        if (domain_file(to_go_place)!= domain_file(file_name(this_object()))){
                return 1;
        }
        if (!objectp(this_object()))
        	return 0;
        command("go " + direction);
        add_temp("random_move",1);
        return 1;
}   
// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
        string spell_skill; 
        if( stringp(spell_skill = query_skill_mapped("spells")))
                SKILL_D(spell_skill)->cast_spell(this_object(), spell );
} 
// Default chat function: Let the npc conjure his/her enabled magics
void conjure_magic(string magic)
{
        string magic_skill; 
        if( stringp(magic_skill = query_skill_mapped("magic")))
                SKILL_D(magic_skill)->conjure_magic(this_object(), magic );
} 
// Default chat function: Let the npc curse his/her enabled cursism
void curse_curses(string curse)
{
        string curse_skill; 
        if( stringp(curse_skill = query_skill_mapped("cursism")))
                SKILL_D(curse_skill)->curse_curses(this_object(), curse );
}  
// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
        string force_skill; 
        if( stringp(force_skill = query_skill_mapped("force")))
                SKILL_D(force_skill)->exert_function(this_object(), func);
} 
// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action) {
        object weapon;
        string martial_skill, act; 
        if(sscanf(action, "%s.%s", martial_skill, act) != 2 ) {
                return 0;
        }
        if(!stringp(martial_skill)) {
                return 0;
        }
   
        if(martial_skill == "axe" || martial_skill == "blade" 
                        || martial_skill == "dagger" || martial_skill == "fork" 
                        || martial_skill == "hammer" || martial_skill == "parry" 
                        || martial_skill == "staff" 
                        || martial_skill == "sword" || martial_skill == "throwing" 
                        || martial_skill == "spear" || martial_skill == "whip" ) {
                weapon = this_object()->query_temp("weapon");
                if(!objectp(weapon) || martial_skill != weapon->query("skill_type")) {
                        weapon = this_object()->query_temp("secondary_weapon");
                        if(!objectp(weapon) || martial_skill != weapon->query("skill_type")) {
                                return 0;               
                        }
                }       
        }
                        
        martial_skill = query_skill_mapped(martial_skill);
        return SKILL_D(martial_skill)->perform_action(this_object(), act);              
}  
/*      add reward for first time kills a npc.. 
        on the npc need to set("reward_npc", 1) and set("difficulty", lvl);
        
        current plan is to set difficulty between 1-40,
        difficulty=1 is roughly the reward of 1 task
        so the criteria of NPC setting are:
        1-5:　feel free to give it to any NPC you like, it's just a task or 2,
                However, suggest NPC exp>500k at least.
        5-15: some strong or fun NPCs, weak masters such as jinwuming,
        15-30: 
        30-40: reserved for tough NPC masters only. The reward is huge so be careful here
                example: Master shangguan=30, Huang=40 -- Silencer @Fy4 
*/ 
void die(){
        object killer, owner;
        string location;
        object objReward;
        int difficulty, difficulty2,npc_difficulty;     
        
        if (this_object()->query_temp("last_damage_from")) {
        
                killer = this_object()->query_temp("last_damage_from");
           if(owner=killer->query("possessed"))    killer = owner; 
//-----------------------------------questnpc.c------------------------------------------
        switch (query("quality"))
        {
                case "evil":
                        
                        objReward = new("/questnpc/obj/dragon-card");           
                   break;
                case "good":
                        objReward = new("/questnpc/obj/shanliu-scroll");
                        //objReward ->set("name",query("name")+"的"+objReward->query("name"));
                        //objReward ->set("dynamic_quest",query("dynamic_quest"));
                        //objReward->move(this_object());
                        break;
        }
        if (objectp(objReward))
        {
                        objReward ->set("name",query("name")+"的"+objReward->query("name"));
                        objReward ->set("dynamic_quest",query("dynamic_quest"));
                        objReward ->set("killer",killer);
                        objReward->move(this_object());
        }
        
                //增加一个mark,完成组织任务之后，给玩家加一个任务完成的mark,这样可以回去领奖
        if ( killer&&killer->query("mission/name") == this_object()->name() )
    	{
    	killer->set("mission_over",1);
    	killer->set("have_mission",0);
    	killer->delete("mission/name");
        }

        if(this_object()->query("quest_npc")){
            if(!killer->query("m_killer/" + this_object()->query("name"))&& !this_object()->is_ghost()) {
                 killer->set("m_killer/" + this_object()->query("name"),1);
                 npc_difficulty = this_object()->query("npc_difficulty");
                 if(!npc_difficulty) npc_difficulty = 1;
                 location = environment(this_object())->query("short");
                 this_object()->npc_reward(this_object(),killer,location,npc_difficulty);
             }
         }     //写到这里了
//-----------------------------------questnpc.c------------------------------------------
//-----------------------------------npc.c-----------------------------------------------
                if (killer->query("combat_exp")>this_object()->query("combat_exp")/15) {     
                        if(this_object()->query("reward_npc")){
                                if(!killer->query("m_killer/" + this_object()->query("name"))&& !this_object()->is_ghost()) {
                                        killer->set("m_killer/" + this_object()->query("name"),1);
                                        difficulty = this_object()->query("difficulty");
                                        if(!difficulty) difficulty = 1;
                                        location = environment(this_object())->query("short");
                                        this_object()->master_reward(this_object(),killer,location,difficulty);
                                }
                        }
                }    
                if(this_object()->query("dungeon_npc")=="eren2" && !this_object()->is_ghost()){
                        difficulty2 = this_object()->query("dungeon_difficulty");
                        if(!difficulty2) difficulty2 = 1;
                        this_object()->dungeon_reward(this_object(),killer,difficulty2);
                //      dungeon_reward() is defined in /std/char/smart_npc.c 
           }
//-------------------------------npc.c---------------------------------------------------       
        }
        ::die();
} 
void master_reward(object victim, object killer, string location, int difficulty)
{
        object money_reward;
        int i, pot, combat_exp, score;
        string reward_msg,kill_msg,msg;    
        string *kill_type = ({ "击杀", "刺杀", "搏杀", "击毙","狙杀","砍杀","劈杀",
                                "巧杀", "拼杀", "斩杀", "怒杀", });
        reward_msg="";
        
        kill_msg= kill_type[random(11)];
        
//-----------------------------------npc.c--------------------------------------------------------           
                pot = difficulty*300;
                combat_exp = difficulty*300;
                score = difficulty*4;
        
                killer->add("potential",pot);
                killer->add("combat_exp", combat_exp);
                killer->add("score", score);
   if(killer->query("env/savemymoney"))
                killer->add("deposit",difficulty*30000);
        else
        {
                money_reward = new("/obj/money/gold");
                money_reward->set_amount(3*difficulty);
                money_reward ->move(killer);
        }
        
        CHANNEL_D->do_sys_channel(
                "info",sprintf("%s，%s于%s"+HIY"%s"+HIY"%s。", NATURE_D->game_time(),
                        killer->query("name"), location, kill_msg, this_object()->name()) );  
        reward_msg +=HIW+"你成功地杀死了一个风云天骄，你被奖励了：\n\t\t" +
        chinese_number(combat_exp) + "点实战经验\n\t\t"+
        chinese_number(pot) + "点潜能\n\t\t" +
        chinese_number(score) + "点评价\n\t\t" + 
        chinese_number(difficulty*3) + "两黄金\n" + NOR;
                
        tell_object(killer,reward_msg); 
         
}     

void npc_reward(object victim, object killer, string location, int difficulty)
{
        object money_reward;
        int i, pot, combat_exp, score;
        string reward_msg,kill_msg,msg;    
        string *kill_type = ({ "击杀", "刺杀", "搏杀", "击毙","狙杀","砍杀","劈杀",
                                "巧杀", "拼杀", "斩杀", "怒杀", });
        reward_msg="";
        
        kill_msg= kill_type[random(11)];
        
           
                pot = difficulty*300;
                combat_exp = difficulty*1000;
                score = difficulty;
        
                killer->add("potential",pot);
                killer->add("combat_exp", combat_exp);
                if(this_object()->query("organization/性质") == "正"){    //如果是杀的是正派NPC
                  	if( killer->query("organization/性质") == "邪"
                  	            || killer->query("organization/性质") == "正"
                  	            || killer->query("organization/性质") == "中立" ){
                                killer->add("improbity", score);   //加邪值
                                msg = "邪恶值";
                        } else { killer->add("score", 4*score); msg = "评价";}     //如果没有组织，则加评价
                } else if(this_object()->query("organization/性质") == "邪") {
                  	if( killer->query("organization/性质") == "邪"
                  	            || killer->query("organization/性质") == "正"
                  	            || killer->query("organization/性质") == "中立" ){
                                killer->add("justice", score);    //加正值
                                msg = "正义值";
                        } else { killer->add("score", 4*score); msg = "评价";}
                } else { 
                	if( killer->query("organization/性质") == "邪"
                  	            || killer->query("organization/性质") == "正"
                  	            || killer->query("organization/性质") == "中立" ){
                                killer->add("neutral", score);    //加中立值
                                msg = "中立值";
                        } else { killer->add("score", 4*score); msg = "评价";}  
                }
                                                      	
                        	
   	if(killer->query("env/savemymoney"))
                killer->add("deposit",difficulty*30000);
        else
        {
                money_reward = new("/obj/money/gold");
                money_reward->set_amount(3*difficulty);
                money_reward ->move(killer);
        }
        
        CHANNEL_D->do_sys_channel(
                "info",sprintf("%s，%s在%s被%s"+HIY"%s"+HIY"！", NATURE_D->game_time(),
                        this_object()->name(),location,killer->query("name"), kill_msg) );  
        reward_msg +=HIW+"你成功地杀死了一个组织人物，你被奖励了：\n\t\t" +
        chinese_number(combat_exp) + "点实战经验\n\t\t"+
        chinese_number(pot) + "点潜能\n\t\t" +
        chinese_number(score) + "点"+msg+"\n\t\t" + 
        chinese_number(difficulty*3) + "两黄金\n" + NOR;
                
        tell_object(killer,reward_msg); 
         
}     

/* the following 2 functions are to help NPC recover. Without those, it takes long 
time for NPC to recover gin/kee/sen, and they will never recover from eff_gin/kee/sen
damages. 
if some NPCs need to be shown as hurt, for example, Master yichen, Hu tiehua...
Just set("no_heal",1) in that particular NPC. -- Silencer */  
int heal_up()
{
        int gin,kee,sen;
        int egin,ekee,esen;
        int mgin,mkee,msen;
            
        if (query("no_heal")) return 1;
        
        gin = (int) query("gin");
        kee = (int) query("kee");
        sen = (int) query("sen");
        egin = (int) query("eff_gin");
        ekee = (int) query("eff_kee");
        esen = (int) query("eff_sen");
           mgin = (int) query("max_gin");
        mkee = (int) query("max_kee");
        msen = (int) query("max_sen");
        
        if (gin==mgin && egin == mgin
                && kee==mkee && ekee==mkee
                && sen==msen && esen==msen )
                return 1;
        
        if( environment() && !is_fighting() && living(this_object()) ) {
                call_out("healing", 1);
                return 1;
        }
        else remove_call_out("healing");
        
        return ::heal_up() + 1;
} 
void healing()
{
    int gin,kee,sen;
    int egin,ekee,esen;
    int mgin,mkee,msen;
    int n;
    string force_type;
    
    if (query("combat_exp")>1500000)   n=12;
        else n=16;
                
    force_type=(string) query("class");
    
    gin = (int) query("gin");
    kee = (int) query("kee");
    sen = (int) query("sen");
    egin = (int) query("eff_gin");
    ekee = (int) query("eff_kee");
    esen = (int) query("eff_sen");
    mgin = (int) query("max_gin");
    mkee = (int) query("max_kee");
    msen = (int) query("max_sen");
    
    
    if(gin < mgin || kee < mkee || sen < msen
        ||egin<mgin || ekee<mkee || esen<msen)
        {
        if (gin+mgin/n<mgin) set("gin",gin+mgin/n);
                else set("gin",mgin);
        if (egin+mgin/n<mgin) set("eff_gin",egin+mgin/n);
                else set("eff_gin",mgin);
        if (kee+mkee/n<mkee) set("kee",kee+mkee/n);
                else set("kee",mkee);
        if (ekee+mkee/n<mkee) set("eff_kee",ekee+mkee/n);
                else set("eff_kee",mkee);
        if (sen+msen/n<msen) set("sen",sen+msen/n);
                else set("sen",msen);
        if (esen+msen/n<msen) set("eff_sen",esen+msen/n);
                else set("eff_sen",msen);          
        }
}     

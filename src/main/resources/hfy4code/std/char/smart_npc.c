#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC; 
void do_defense(int n);
void do_remove_defense(int n);
void universal_pfm(string perform_weapon_attack,object me,object target);
void setup_npc_skill(string name,string char_type,string random_choose,
        int special,int basic,int autoweapon,string weapon_dir);
string  do_choose_attack(object target);
string super_message();
int enemy_type(object target);
int accompany(object me);
int check_health(object target, int percent);
int is_he_pet(object target);
object *resort(object *group); 
void auto_npc_setup(string name, int basic, int special, int auto_weapon, string weapon_dir, string char_type, string my_char) {
        
        string *basic_skill= ({"move","dodge","parry","unarmed","blade","sword",
        "staff","axe","spells","magic","spear","throwing","hammer","whip","force",
        "perception","iron-cloth","cursism","scratching",}); 
        string *pfm_setup = ({"perform_weapon_attack","perform_weapon_attack2","perform_weapon_attack3",
                "perform_weapon_attack4","perform_unarmed_attack4",
                "perform_unarmed_attack","perform_unarmed_attack2","perform_unarmed_attack3",
                "perform_busy_d","perform_busy_u","perform_busy_w"});
        
        string *base_skill_setup = ({"skill_type_w","skill_type_u","skill_type_d",});
        
        string *other_skills = ({"others1","others2","others3","others4","others5","others6"});
        string *temp_setup = ({"set_temp1","set_temp2","set_temp3","set_temp4"});       
        string *mark_setup = ({"set_1","set_2","set_3","set_4"});       
        
        int i, total, x;
        mapping npc;
        string myclass,type,skill,pfm,weapon;
        
        npc=NPC_LIST->query_npc(char_type,my_char,special);
        set("class",npc["class"]);
        set("gender",npc["gender"]?npc["gender"]:"����");
        set("npc",npc["npc"]);
   set("myname",npc["name"]);
        
//      setting up all skills
        for (i=1;i<sizeof(basic_skill);i++){
                set_skill(basic_skill[i],basic);
                if (npc[basic_skill[i]]) {
                        set_skill(npc[basic_skill[i]],special);
                        map_skill(basic_skill[i],npc[basic_skill[i]]);
                }
        }
        set_skill("anxiang-steps", special);
        map_skill("move","anxiang-steps");
        if (!query_skill_mapped("iron-cloth"))
                delete_skill("iron-cloth");
        if (query_skill_mapped("iron-cloth")=="xisui")
                set_skill("xisui",query_skill("xisui",1)/2);
        
//      setting up defense skill.. will only use one of them.
        set_skill("lingxi-zhi",special);
        set_skill("yue-strike",special);
        set_skill("xiaohun-sword",special);
        set_skill("xiaohun-whip",special); 
//      setting up all pfm messages. also setting up secondary pfm skills if necessary
        for (i=0;i<sizeof(pfm_setup);i++){
                if (npc[pfm_setup[i]])
                if (sscanf(npc[pfm_setup[i]],"%s/%s/%s/%s",myclass,type,skill,pfm)==4)
                        set_skill(type,special);
                        set(pfm_setup[i],npc[pfm_setup[i]]);
        } 
//      setting up the basic enable skill set that NPC uses after switching skills.
        for (i=0;i<sizeof(base_skill_setup);i++){
                if (npc[base_skill_setup[i]])
                        set(base_skill_setup[i],npc[base_skill_setup[i]]);
        } 
//      setting up some suplementary skill such as chess,lamasism,...
        for (i=0;i<sizeof(other_skills);i++){
                if (npc[other_skills[i]])
                        set_skill(npc[other_skills[i]],special);
                else break;
   } 
//      the main weapon/unarmed/dodge skill level needs to be adjusted due to coff difference.
        if (npc["skill_type_w"] && npc["w_adjust"]) {
                sscanf(npc["skill_type_w"],"%s/%s",type,skill);
                set_skill(skill,(100+npc["w_adjust"])*query_skill(skill,1)/100);
        }
        if (npc["u_adjust"] && npc["skill_type_u"]) 
                set_skill(npc["skill_type_u"],(100+npc["u_adjust"])*query_skill(npc["skill_type_u"],1)/100);
        if (npc["d_adjust"] && npc["skill_type_d"]) 
                set_skill(npc["skill_type_d"],(100+npc["d_adjust"])*query_skill(npc["skill_type_d"],1)/100);
                
//      setting up temp for chill/juqi
        for (i=0;i<sizeof(temp_setup);i++){
                if (npc[temp_setup[i]])
                        set_temp(npc[temp_setup[i]],special*2+random(special));
                if (npc[mark_setup[i]])
                        set(npc[mark_setup[i]],1);
        } 
//      setting up weapons
        if (auto_weapon && npc["skill_type_w"])
        if (sscanf(npc["skill_type_w"],"%s/%s",weapon,skill)==2) 
                carry_object(weapon_dir+weapon)->wield(); 
} 
auto_smart_fight()
{
        int i,n,j,k,count,num;
        object *enemy, me, weapon,*inv;
                
        me= this_object();
        
        message_vision(HIY"ROUND START !!!.\n"NOR,me);
        
//      immediately starting to protect friends
        baohu();
        
//      setting some general defense types              
        if (me->query("class")=="shenshui") 
                me->delete("defense_type");
        num = me->query("defense_type");
   
//      those zombies/guards .... let me find their owners and add them to my kill.
        if (query("officer-killer")) find_officer();
        
//      resort enemy here, prepare to attack the weakest enemy. 
        enemy = resort_enemy("ALL");
        
//      time to check if there are any friends around to help.
        ask_help();  
//      if I can void sense, let me do it first.
        if (me->query("class")=="bonze")
        for (i=0;i<sizeof(enemy);i++){
                if (!enemy[i]->query_temp("voidsense")) {
                SKILL_D("cloudstaff")->perform_target(me,"npc_void_sense",enemy[i]);
                }
        }
        
//      if I am a healer, I will do nothing but healing to avoid busy.
        if (me->query("npc")=="healer") {
                help_friend();
                if (num) do_defense(num);
                return;
        }       
                
//      if I can kill zombies, wipe them out immediately.       
        if (me->query("zombie-killer")) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                        
                }
                if (count>=2) {
                        command("perform zombie-wp1");
                        if (num) do_defense(num);
                        }
        } 
//      how to fight like a player ?    
//      (1) how to do busy?             
//      if one enemy, and if enemy exp>3x my exp, use unarmed busy if available.
// otherwise use dodge busy... then weapon busy.... depends on skills.
//      if sizeof(enemy)>1, definately use no-self-busy-dodge busy if available. and 
//      start with lowest exp non-guard enemy till 2x exp. skip the rest highest exp 
//      ones,
//      pfm unarmed busy on high exp enemies if having friends with you
//      pfm attack on busied ones.
//      (2) how to perform attack?
//      perform on player first rather than guard.
//      perform on those weakest ones first.
        
        n=1;
        if (me->query("perform_busy_u")) n=8;
        if (me->query("perform_busy_d") || me->query("perform_busy_w")) n =3;
        
        
        i = sizeof(enemy);
//      message_vision("pfm starts.\n",me);      
//      (1)     if there is only one enemy:
        if (i==1) {
                if( enemy[0] && living(enemy[0]) ) {
                        if (!enemy[0]->is_busy()) {
//                              message_vision("busy pfm.\n",me);
                                single_busy(enemy[0]);
                        }
                        if (enemy[0]->is_busy() || n==1 ) {
//                              message_vision("attack pfms.\n",me);
                                universal_attack(enemy[0]);
                        }
                }
        }
        
//      (2)     if there are multiple enemies, things become complicated.
        if (sizeof(enemy)>1) {
//              message_vision("multiple enemy!!!.\n",me);
//              message_vision("busy pfm vs multi.\n",me);
                multi_busy(enemy);
        
                for (k=0;k<sizeof(enemy);k++) {
                        if (enemy[k]->is_busy() || n==1 || 
                   (me->query("perform_busy_w") && !me->query("perform_busy_d"))){
//                              message_vision("attack pfms vs multi."+n+" \n",me);
                                if (!me->is_busy()) {
                                        universal_attack(enemy[k]);
                                }
                        }
                }
        } 
        if (num) do_defense(num);       
        message_vision(HIW"         ROUND END.\n"NOR,me);
        return;
}  
void    single_busy(object target) {
        
        object me;
        me=this_object();
        
        if (target->query("combat_exp")<3*me->query("combat_exp")
                && (me->query("perform_busy_d") || me->query("perform_busy_w"))
                && query_temp("zonghengsihai")+10<time()
                ) {
                if (me->query("perform_busy_d"))        {
                        universal_pfm(me->query("perform_busy_d"), me, target); 
                        }
                        else if (me->query("perform_busy_w")) 
                                universal_pfm(me->query("perform_busy_w"), me, target);                 
                }
                else if (target->query("combat_exp")<6*me->query("combat_exp")) {
                        if (me->query("perform_busy_u"))
                        universal_pfm(me->query("perform_busy_u"), me, target);                 
                } 
} 
void    multi_busy(object *enemy) {
        
        int k;
        object me;
        me=this_object();
        
//      first use dodge busy on all not-so-high enemies;        
   for (k=0;k<sizeof(enemy);k++) {
                if( enemy[k] && living(enemy[k])) {
                        if (!enemy[k]->is_busy()
                                && enemy[k]->query("combat_exp")<2*this_object()->query("combat_exp")) {
                                if (me->query("perform_busy_d")) {
                                        universal_pfm(me->query("perform_busy_d"), me, enemy[k]); 
                                } else if (me->query("perform_busy_w") && me->query("class")=="wudang")
                                        universal_pfm(me->query("perform_busy_w"), me, enemy[k]); 
                        }                               
                }
        }
        
//      secondly, if have friends around, use unarmed busy as well;     
//      need to busy the most dangerous one since this can only be done once.
        if (!this_object()->is_busy()&& accompany(this_object())
                || this_object()->query("class")=="wudang") {
        for (k=0;k<sizeof(enemy);k++) {
                if(enemy[k] && living(enemy[k])) {
                        if (!enemy[k]->is_busy() && (userp(enemy[k])||me->query("class")=="wudang"|| accompany(me))
                                && enemy[k]->query("combat_exp")<6*this_object()->query("combat_exp")) {
                                if (me->query("perform_busy_u"))
                                        universal_pfm(me->query("perform_busy_u"), me, enemy[k]); 
                        }                               
                }
        }       
        }
        
        
} 
void    universal_attack(object target) {
        object me;
        string attack;
        string attack_class,attack_type,attack_skill,attack_name;
        string msg;
        
        me=this_object();
        attack = do_choose_attack(target);
        
        if (attack=="none") {
//         command(HIG"say I will idle one turn so i can busy again."NOR);
                return;
        } 
        if (sscanf(attack,"%s/%s/%s/%s",attack_class,
                        attack_type,attack_skill,attack_name)==4)
                universal_pfm(attack,me,target);  
        if (!check_health(target,20))
                message_vision(super_message(),me,target);
        
        if (!sizeof(me->query_enemy())) {
                message_vision(WHT"$N������ͷ�ϵĺ�ˮ˵���������ң����ҡ���\n"NOR,me);  
                me->receive_curing("kee", me->query("max_kee")/2);
                me->add("kee",me->query("max_kee")/2);
                }
                
        return;
} 
//      the purpose of this function is to auto switch weapon/skill to pfm
//      after pfm, the skill/weapon shall be returned to the original value.
//      parameter: perform_xxx_xxx =  legend/sword/diesword/caidiekuangwu 
void    universal_pfm(string perform_attack, object me, object target) { 
        string attack;
        string attack_class,attack_type,attack_skill,attack_name;
        object weapon, new_weapon, *inv;
        int k;
        string old_basic_skill,old_special_skill,old_class;
        
        
        if (sscanf(perform_attack,"%s/%s/%s/%s",attack_class,
                        attack_type,attack_skill,attack_name)==4)
 {               { 
//              message_vision(attack_class+" "+attack_type+" "+attack_skill+" "+attack_name+".\n",me); 
        }
        
        weapon=me->query_temp("weapon");
        old_basic_skill=attack_type;
        old_special_skill=me->query_skill_mapped(old_basic_skill);
        old_class=me->query("class");
//      message_vision("i had "+old_basic_skill+" and "+old_special_skill+" .\n",me);
   
        if (attack_type!="unarmed" && attack_type!="dodge") {
                if (!weapon || weapon->query("skill_type")!=attack_type){
                        command ("unwield all");
                        inv=all_inventory(me);
                        for (k=0;k<sizeof(inv);k++){
                                if (inv[k]->query("skill_type")==attack_type)
                                        command("wield "+inv[k]->query("id"));
                        }                       
                }
                if (!me->query_temp("weapon")) {
                        new_weapon = carry_object("/obj/weapon/"+attack_type);
                        command("wield "+new_weapon->query("id"));      
                }
        } else if (weapon && attack_type=="unarmed" ) command ("unwield all");  
        
        set("class",attack_class);
        map_skill(attack_type,attack_skill);     
        if (enemy_type(target)==5) set("str",55);
        if (enemy_type(target)==4) set("str",45);
        if (me->query("npc")=="yue-spear") me->set("force_factor",100);
        
//      message_vision("when pfm, i have "+old_basic_skill+" and "+attack_skill+" "+attack_name+" .\n",me);
        if (attack_name=="sharenruma" || attack_name=="mantianhuayu" || attack_name=="tianxiawugou" 
                        || attack_name=="qiankun" 
                        )
                        perform_action(attack_type+"."+attack_name);
                else {
                        SKILL_D(attack_skill)->perform_target(me,attack_name,target);
                        }
        set("class",old_class);
        map_skill(attack_type,old_special_skill);
//      message_vision("after pfm, i have "+old_basic_skill+" and "+old_special_skill+" .\n",me); 
        if (weapon)
        if (me->query_temp("weapon")!=weapon) {
                        command("unwield all");
                        command("wield "+weapon->query("id"));
        } 
        
   set("str",40);
        if (me->query("npc")=="yue-spear") me->set("force_factor",100);
} 
}
string  do_choose_attack(object target) { 
        object me;
        string type;
        int danger, number;
        int npc_number, pc_number;
        
        me=this_object();
        
        danger=enemy_type(target);
        number=sizeof(me->query_enemy());
        pc_number=sizeof(me->resort_enemy("PC"));
        npc_number=sizeof(me->resort_enemy("NPC"));
        
        
//      message_vision("number is "+(string)(number)+" .\n",me);
        switch (me->query("npc")) {
        case "shenji-blade": 
                if  (!check_health(me,20)) {
                        type=me->query("perform_unarmed_attack3");
                        break;
                }
                if  (accompany(me)) {
                        if (!check_health(target,10)) type=me->query("perform_weapon_attack2");
                        else if (!check_health(target,20)) type=me->query("perform_unarmed_attack");
                                else type=me->query("perform_weapon_attack");
                } else {
                        if (target->query("kee")<1000) type=me->query("perform_weapon_attack2");
                                else if (target->query("kee")<3000 && (userp(target)||number<3)) 
                                        type=me->query("perform_unarmed_attack");
                                else if ((target->query("kee")<5000 || target->query_busy()>3)
                                                && (userp(target)||number<3)) 
                                        type=me->query("perform_weapon_attack");
                                else if (target->query_busy()==1 && number<2) type ="none";
                                else { if (random(3)) type=me->query("perform_weapon_attack2");
                                        else type=me->query("perform_unarmed_attack2");
                                }
                   }
                break;
        case "bat-blade": 
                if  (!check_health(me,20)) {
                        type=me->query("perform_unarmed_attack3");
                        break;
                }
                if (target->query("kee")<1000) type=me->query("perform_weapon_attack2");
                        else if (target->query_busy()<=2) {
                                if (number>1 || accompany(me)) type=me->query("perform_weapon_attack");
                                        else type="none";
                                }
                        else type=me->query("perform_weapon_attack");
                break;
        case "longfenghuan":
                if (me->query_temp("timer/sharen")+20<time() || target->query("kee")<3000)
                                type=me->query("perform_weapon_attack2");
                        else type= me->query("perform_weapon_attack");                  
                break;  
        case "longfenghua2":
                if (target->query_busy()==1 && random(2)) type="none";
                        else type= me->query("perform_weapon_attack");
        case "dagou-stick":
                if (me->query("kee")<me->query("max_kee")*20/100) type=me->query("perform_weapon_attack3");                     
                        else if (number>1)      type=me->query("perform_weapon_attack");                        
                        else if (target->query_skill("iron-cloth")>300) type=me->query("perform_unarmed_attack");                       
                        else {switch (random(3)) {
                                 case 0: type=me->query("perform_weapon_attack"); break;
                                 case 1: type=me->query("perform_unarmed_attack"); break;
                                 default: type=me->query("perform_weapon_attack2");     
                                }
                                }       
                        break;  
        
        case "siqi-sword":
        case "qiusheng-blade":
                if (!check_health(target,30) && me->query("perform_weapon_attack"))
                                type=me->query("perform_weapon_attack");
                else if (target->query_busy()==1 && number<2 && !accompany(me)
                           && target->query("combat_exp")<2*me->query("combat_exp")) 
                                        type ="none";
                                else type=me->query("perform_weapon_attack");   
                break;
        case "mind-sense":
        case "yue-spear":
                if (!check_health(target,30) && me->query("perform_unarmed_attack") && !is_he_pet(target))
                                type=me->query("perform_unarmed_attack");
                else if (accompany(me)) type = me->query("perform_weapon_attack");
                else if (target->query_busy()==1 && number<2
                                && target->query("combat_exp")<2*me->query("combat_exp")) 
                                        type ="none";
                                else type=me->query("perform_weapon_attack");   
                break;
        case "yue-spear2":
                set("family/master_id","master yue");
                type =me->query("perform_weapon_attack");
                break;
        case "taiji":
        case "taiji-sword":
                me->set("defense_type",1);
                me->set("max_force",4000);
                me->set("force",4000);
                if (!check_health(me,20)) type=me->query("perform_unarmed_attack2");                    
                        else if (number>1)      type="none";
                        else if (target->query_busy()==1 
                                && target->query("combat_exp")<2*me->query("combat_exp")) 
                                        type ="none";
                        else {switch (random(2)) {
                                case 0: type =me->query("perform_unarmed_attack");break;
                                default: type="none";
                                }
                        }
                break;
        case "nine-moon-sword":
        case "nine-moon-sword2":
                if (me->query("timer/polu") + 8 < time() || !target->is_busy()) type=   me->query("perform_unarmed_attack");
                        else type=me->query("perform_weapon_attack");
                        break;
   
        case "doomsword":
                me->set("defense_type",1);
                if (target->query("kee")<2000) type=me->query("perform_weapon_attack");
                        else if (!check_health(me,20)) type=me->query("perform_unarmed_attack2");
                        else if ((danger==2||danger==4 || target->query("combat_exp")>2*me->query("combat_exp"))
                                 && target->query("force")>100)
                                type=me->query("perform_weapon_attack2");
                        else type=me->query("perform_weapon_attack");
                break;
        case "qingfeng-sword":
                me->set("defense_type",1);
                if ((danger==2||danger==4) && target->query("force")>100)
                        type=me->query("perform_weapon_attack");
                        else if (number>1) type=me->query("perform_weapon_attack2");
                        else if (target->query_busy()==1) type = "none";
                                else type=me->query("perform_weapon_attack2");
                break;
        case "tanzhi-shentong":
                if ((danger==2||danger==4) && target->query("force")>100)
                        type=me->query("perform_weapon_attack2");
                        else if (number>1) type=me->query("perform_weapon_attack3");
                        else if(target->query_busy()==1) type="none";
                        else type=me->query("perform_weapon_attack");
                break;
        case "softsword":
                me->set("defense_type",1);
                if (target->query("kee")<2000) type=me->query("perform_weapon_attack");
                        else if ((danger==1 || danger==2||danger==4) && target->query("force")>100)
                                type=me->query("perform_weapon_attack2");       
                        else {switch (random(3)){
                                case 0: type=me->query("perform_weapon_attack3");
                                default: type=me->query("perform_weapon_attack");
                        }
                        }
                break;  
        case "xuezhan-spear":
                if (!me->query_temp("daoqian") && !target->query_skill("dragonstrike")) {
                        perform_action("iron-cloth.npc_jinzhongzhao");
                   type="none";
                        } 
                else if (me->query_temp("timer/bafang")+60<time()) type=me->query("perform_weapon_attack2");
                else if (target->query("kee")<4000 || target->query_busy()==1 
                                || number>1) 
                                type=me->query("perform_weapon_attack");
                else type=me->query("perform_weapon_attack3");
                break;                  
        case "xuanyuan-axe":
                if (target->query_busy()>=3) {
                        if (me->query_temp("timer/jiuqipoxiao")+30<time())
                                type=me->query("perform_weapon_attack2");
                                else type = me->query("perform_unarmed_attack");
                }else if (me->query_temp("timer/jiuqipoxiao")+30<time()) type=me->query("perform_weapon_attack2");
                                else if (target->query_busy()<2 && number<2) type="none";
                                        else type=me->query("perform_weapon_attack");
                break;  
        case "ittouryu":
                if (!check_health(me,60)&& !me->query("perform_busy_d")) {
                                message_vision(CYN"$N������ü˵�������������Ҷ��֡���\n"NOR,me);
                                me->set("perform_busy_u",me->query("perform_unarmed_attack3"));
                                me->set("perform_busy_d",me->query("perform_unarmed_attack"));
                        }
                if (!check_health(target,20) && me->query_temp("timer/hyakki")+60<time()) 
                                type=me->query("perform_weapon_attack3");
                        else if (!check_health(me,20)) 
                                type=me->query("perform_unarmed_attack2");      
                        else if (!me->query("perform_busy_d")&&!target->is_busy()
                                        && target->query_temp("weapon") && accompany(me)) 
                                type=me->query("perform_weapon_attack");
                        else {switch (random(2)) {
                                case 0: type=me->query("perform_weapon_attack2"); 
                                        break;
                                default:type=me->query("perform_unarmed_attack4");
                                }
                        }
                break;
        case "xinyue-dagger":
                 if (me->query_temp("max_guard")<3) universal_pfm("wolfmount/unarmed/wolf-strike/npc_xiao",me,target);
            if (me->query("kee")<me->query("max_kee")*40/100) 
                                me->set("perform_busy_u",me->query("perform_unarmed_attack3"));
                        else me->delete("perform_busy_u");
                 if (target->query_busy()>=2
                        ||(target->is_busy()&& accompany(me)))
                                type=me->query("perform_weapon_attack");
                        else type=me->query("perform_unarmed_attack2");
                 break; 
        case "assasin-hammer":
                 if (me->query_temp("max_guard")<3) universal_pfm("wolfmount/unarmed/wolf-strike/npc_xiao",me,target);
                 if (me->query("kee")<me->query("max_kee")*40/100) 
                                me->set("perform_busy_u",me->query("perform_unarmed_attack3"));
                        else me->delete("perform_busy_u");
                 type=me->query("perform_unarmed_attack2");
                 break; 
        case "thunderwhip":
                 me->set("defense_type",2);
                 if (me->query("kee")<6000)
                        me->set("perform_unarmed_u",me->query("perform_unarmed_attack3"));
                 if (target->query("combat_exp")<me->query("combat_exp")
                        && target->query("max_gin")<4500)
                        type=me->query("perform_weapon_attack2");
                 else if (target->query_busy() && target->query("kee")<4000 
                        || target->query_busy()>=3)
                        type=me->query("perform_weapon_attack3");
                 else if (target->query_skill("iron-cloth")>300)
                        type=me->query("perform_unarmed_attack2");
                 else {switch (random(3)) { 
                        case 2:  type=me->query("perform_unarmed_attack");
                        default: type=me->query("perform_weapon_attack");
                        }
                 }
                 break;
        case "wuche-axe":
                me->set("force_factor",150);
                if (target->query_busy()>=3) type=me->query("perform_weapon_attack");
                else if (target->query_busy()==1 && !accompany(me)) type ="none";
                else if (target->query_skill_mapped("unarmed")=="nine-moon-claw")
                        type=me->query("perform_unarmed_attack");

                else if (target->query_skill_mapped("iron-cloth")=="yijinjing")
                        type=me->query("perform_unarmed_attack2");
                else { switch (random(3)) {
                        case 0: type=me->query("perform_unarmed_attack");break;
                        case 1: type=me->query("perform_weapon_attack2");break;
                        case 2: type=me->query("perform_weapon_attack3");
                        }
                }
                break;
        case "yijinjing":
                me->set("force_factor",150);
                if (me->query("kee")<5000 && me->query("force")>0 
                        && !me->query_temp("shield_force/type")) {
                        message_vision(YEL"$N����һ���������������ȶ�������������\n"NOR,me);
                        message_vision(YEL"�����Ŷ����ƺ���$N��Χ���һΧ��ǽ��\n"NOR,me);
                        me->set_temp("till_death/shield_lock",1);
                        me->set_temp("shield_force/type","force");
                        me->set_temp("shield_force/ratio",1000);
                        me->set_temp("shield_force/msg",
                                YEL"$N��ʽ����$n��ǰ����֮�⣬����������һ������֮����ȴ�ּ�Ӳ֮�������ϡ�\n"NOR);
                }
                if (!me->is_fighting() && me->query_temp("shield_force/type")){
                        me->delete_temp("shield_force");
                        me->delete_temp("till_death/shield_lock");
                        me->set("force",me->query("max_force"));
                        }
                if (!me->query_temp("shield_force"))
                        type=me->query("perform_unarmed_attack");
                        else type="none";
                break;  
        case "jin-gang":
                if (!me->query_temp("daoqian") && !target->query_skill("dragonstrike")) {
                        perform_action("iron-cloth.npc_daoqiangburu");
                        type="none";
                        } 
                else if (!check_health(me,60) 
                                && check_health(me,41) && !me->query("perform_busy_d")) {
                        message_vision(CYN"$N˵������˵����Ҫ�õ���������ˡ�\n"NOR,me);
                        me->set("perform_busy_d",me->query("perform_weapon_attack2"));

                        type="none";
                        } 
                else if (target->query_busy()>=3) 
                                type=me->query("perform_weapon_attack");                        
                else if (!check_health(me,40)&& check_health(target,20)
                                && number<2 && !accompany(me)) {
                                        me->delete("perform_busy_d");
                                        type = "none";
                        }  
                else    type=me->query("perform_weapon_attack");
                break;
        case "kwan-yin-spells":
                if (target->query("kee")<2000) type=me->query("perform_weapon_attack");
                        else if (!me->query_temp("daoqian")) {
                                perform_action("iron-cloth.daoqiangburu");
                                type="none";
                        } 
                        else if (!target->query_temp("block_msg/all")) {
                                cast_spell("npc_hong");
                                type="none";
                        }
                        else if (target->query("gin")<5000) {
                                cast_spell("npc_an");
                                type="none";
                        } else type=me->query("perform_weapon_attack");
                break;  
        case "necromancy":
                me->set("defense_type",1);
                if (me->query("kee")<5000) me->set("perform_busy_u",me->query("perform_unarmed_attack2"));
                else {  if (me->query_temp("max_guard")<4) 
                                        cast_spell("npc_invocation");
                                else cast_spell("superbolt");
                        me->set("mana",me->query("max_mana"));
                        type="none";
                }
                break;
        case "scratmancy":
                if (me->query("kee")<5000 && me->query("mana")>0 
                        &&!me->query_temp("shield_force/type")) {

                        message_vision(MAG"$N���˷�������ɫ������ϡ���������\n"NOR,me);
                        message_vision(MAG"����Խ��ԽŨ��������$N��Χ��\n"NOR,me);
                        me->set_temp("till_death/shield_lock",1);
                        me->set_temp("shield_force/type","mana");
                        me->set_temp("shield_force/ratio",500);
                        me->set_temp("shield_force/msg",
                                MAG"$N��ʽ����$n��ǰ����֮�⣬����ţ�뺣,��ʧ�������С�\n"NOR);
                }
                if (!me->is_fighting() && me->query_temp("shield_force/type")){
                        me->delete_temp("shield_force");
                        me->delete_temp("till_death/shield_lock");
                        me->set("force",me->query("max_mana"));
                        }
                me->set("perform_busy_u",me->query("perform_unarmed_attack"));
                if (me->query_skill("scratmancy")>400) {
                        me->set_skill("scratmancy",200);
                        me->set_skill("scratching",200);
                        }
                if ( me->query_temp("max_guard") < 5 ) me->sheet_fight(); 
                        else if (me->query_temp("shield_force"))
                                me->delete("perform_busy_u");
                        type="none";
                break;  
        case "scratmancy2":
                if (me->query("kee")<10000 && me->query("mana")>0
                        && !me->query_temp("shield_force/type")) {
                        message_vision(MAG"$N���˷�������ɫ������ϡ���������\n"NOR,me);
                        message_vision(MAG"����Խ��ԽŨ��������$N��Χ��\n"NOR,me);
                        me->set_temp("till_death/shield_lock",1);
                        me->set_temp("shield_force/type","mana");
                        me->set_temp("shield_force/ratio",500);
                        me->set_temp("shield_force/msg",
                                MAG"$N��ʽ����$n��ǰ����֮�⣬����ţ�뺣,��ʧ�������С�\n"NOR);
                }
                if (!me->is_fighting() && me->query_temp("shield_force/type")){
                        me->delete_temp("shield_force");
                        me->delete_temp("till_death/shield_lock");
                        me->set("force",me->query("max_mana"));
                        }

                if (me->query_skill("scratmancy")>400) {
                        me->set_skill("scratmancy",200);
                        me->set_skill("scratching",200);
                        }
                me->alchemy_fight(); 
                type="none";
                break;  
        default: if (me->query_temp("weapon") && me->query("perform_weapon_attack")) 
                                type =me->query("perform_weapon_attack");
                        else if (me->query("perform_unarmed_attack"))
                                type =me->query("perform_unarmed_attack");
                        else    type="none";
        }
//      message_vision("attack type is "+type+" .\n",me);
        return type;
} 
string super_message(){
        string msg;
        
        switch (random(10)) {
        case 0: msg=CYN"\n$N�������أ���縳���Ʈɢ���У����������Ȳ�����������������\n\n"NOR; break;
        case 1: msg=CYN"\n$N��Ц����������֮�£�Ψ�Ҷ���\n\n"NOR; break;
        case 2: msg=CYN"\n$N�߸�$n��ױ����̾���������ӣ�����ŵ�ʱ���û����������װ��ǰ�Ҹ���úô���硣��\n\n"NOR;break; 
        case 3: msg=CYN"\n$N��ϧ�ؿ���$n˵������Ȫ������һ·���ء���\n\n"NOR;break;
        case 4: msg=CYN"\n$N˵����ɱ�㣬�治���ס���\n\n"NOR;break;
        case 5: msg=CYN"\n$N��$n΢΢һЦ�������Ȳ�ʤ�㡣\n\n"NOR;break;
        case 6: msg=CYN"\n$N��Ц��������������������������������أ�Ψ����������\n\n"NOR;break;
        case 7: msg=CYN"\n$N��$n˵�����Բ��𡣡�\n\n"NOR;break;
        case 8: msg=CYN"\n$N���������س��� : ����ǣ�����ǣ�ÿ�����Ϲ���æ~~~\n\n"NOR;break;
        default: msg = CYN"\n$N����$n���˻��֡�\n\n"NOR;
        }
        return msg;
} 
int     check_health(object target, int percent){
        int health;
        if (target->query("kee")<target->query("max_kee")*percent/100
                ||target->query("gin")<target->query("max_gin")*percent/100
                ||target->query("sen")<target->query("max_sen")*percent/100
                )

                { health=0; 
                }
                else health = 1;
        return health;
}
        
void    find_officer() {
        object me,*enemy,owner;
        int i;
                
        me=this_object();
        enemy=me->query_enemy();
//      command("say in officer now.");
        for (i=0;i<sizeof(enemy);i++) {
                if (!userp(enemy[i])) { 
                        if(owner=enemy[i]->query("possessed")) {
                                if (!is_fighting(owner)&& environment(this_object())==environment(owner)) {
                                        command("say ����������ǰ�滨�У�");
                                        kill_ob(owner);
                                        owner->kill_ob(me);
                                }
                        }
                }
        }
}  
//      this function set NPC with same group starting to protect each other.
void    baohu() {
        object me, *pros, *inv, ob;
        string type;
        int i,j, gotit;
        
        pros= ({});
        me= this_object();
        pros = me->query_temp("protectors");
//      message_vision(" in baohu.\n",me);      
        type = me->query("dungeon_npc");
        if (!type) return;
        
        inv = all_inventory(environment(me));

        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (userp(ob) || !ob->is_character() || ob->is_corpse() 
                        || ob->query("dungeon_npc")!=type || ob==me) {
                        continue;
                }
//              message_vision(" find a baohu.\n",me);
                gotit=0;
                if (sizeof(pros)) {
                        for (j=0;j<sizeof(pros);j++) {
                                if (pros[j]==ob) gotit=1;
//                              command("say already protecting me");}
                        }
                }
                if (gotit) continue;
                
                if(sizeof(pros))
                        pros += ({ ob });
                else
                        pros = ({ ob });
//              message_vision(" one baohu is added.\n",me);
        }
        
        me->set_temp("protectors",pros);
//      message_vision(" out baohu.\n",me);
}       
                 
//      this function resort the query_enemy(), put lowest-exp-player on top, and
//      put NPC below players. 
object *resort_enemy(string flag) {
        object *enemy,*pc_enemy,*npc_enemy, *total_enemy, me;
        int i,k,j;
        int num,lowest;
        object mem;
        
        pc_enemy= ({});
        npc_enemy= ({});
        total_enemy=({});
        

        me=this_object();
        enemy=me->query_enemy();
        
        for( i=0;i<sizeof(enemy);i++) {
                if (!userp(enemy[i])) npc_enemy += ({ enemy[i] });
                        else pc_enemy += ({ enemy[i] });
        }
        
        if (sizeof(npc_enemy)>1) npc_enemy=resort(npc_enemy);
        if (sizeof(pc_enemy)>1) pc_enemy=resort(pc_enemy);
        
        if (flag=="NPC") return npc_enemy;
        if (flag=="PC")  return pc_enemy;
        
        if (sizeof(enemy)<=1) return enemy;
        
/*      for(i=0;i<sizeof(pc_enemy);i++){
                message_vision("pc_enemy "+(string)(i)+" is "+pc_enemy[i]->query("name")+" .\n",me);
                }
        for(i=0;i<sizeof(npc_enemy);i++){
                message_vision("npc_enemy "+(string)(i)+" is "+npc_enemy[i]->query("name")+" .\n",me);
                }*/
                
        total_enemy=pc_enemy;
        
        if (sizeof(npc_enemy))  
        for( i=0;i<sizeof(npc_enemy);i++) {
                total_enemy += ({ npc_enemy[i] });
                
        }
        return total_enemy;
}       
        
object *resort(object *group){
        int j,k, lowest, num;
        object *sorted_group, mem;
        
        sorted_group= ({});
        num= sizeof(group);

        
        for (j=0;j<num;j++) {   
                lowest=100000000;
                for (k=0;k<sizeof(group);k++) {
                        if (group[k]->query("combat_exp")<lowest) {
                                mem=group[k];
                                lowest=mem->query("combat_exp");
                        }
                }
                sorted_group += ({ mem });
                group -= ({ mem });
        }
        return sorted_group;
}         
int is_he_pet(object target){
        if (target->query("possessed")) return 1;
                else return 0;
}  
//      this function checks if there are similar group NPCs around.
int accompany(object me) {
        string type;
        object *inv;
        int i;
        
        type = me->query("dungeon_npc");
        if (!type) return 0;
        inv=all_inventory(environment(me));
        for (i=0;i<sizeof(inv);i++) {
                if (inv[i]==me) continue;
                if (inv[i]->query("dungeon_npc")==type) {
                        return 1;
                }
        }       
        return 0;
} 
void heart_beat() {
        int wimpy_ratio, to_wimpy, cnd_flag, oldbusy;
        mapping my;
        object ob;

        string savemyass;
        object *enemy;
        if(!this_object()) {
                return;
        } 
        if (query_temp("in_heart_beat"))
                return; 
        my = query_entire_dbase();
        
        // If we are dying because of mortal wounds?
        if( my["eff_kee"] < 0 || my["eff_sen"] < 0 || my["eff_gin"] < 0  
                        || my["kee"] < -10 * my["dur"]  || my["sen"] < -10 * my["dur"] || my["gin"] < -10 * my["dur"]) {
                remove_all_enemy();
                die();
                return;
        }
        
        // If we are unconcious, just return;
        if(query_temp("is_unconcious"))  {
                return;
        }
        
        // If we're dying or falling unconcious?
        if( my["kee"] < 0 || my["sen"] < 0 || my["gin"] < 0) {
                remove_all_enemy();
                unconcious();
                return;
        }
        
        
        // do_densive/offensive choice
        if (query("defense_type") && is_fighting()) {
                if(is_busy()) do_defense(query("defense_type"));
                        else  {
                                do_remove_defense(query("defense_type"));
                        }
        }
        
        if (is_fighting() && this_object()->query_temp("guard_count")<4

                && this_object()->query("class")=="official") {
                if (this_object()->query("npc")=="yue-spear2")
                        this_object()->set("family/master_id","master yue");
                this_object()->set_skill("strategy",200);
                this_object()->set_skill("leadership",250);
                oldbusy=this_object()->query_busy();
                this_object()->stop_busy();
                perform_action("unarmed.npc_alert");
                this_object()->start_busy(oldbusy);
        }
        
        if (!is_busy()) {
        
        // (2) Do attack or clean up enemy if we have fleed.
        if(is_fighting()) {
                // as long as we are in a fight, we are nervous, our ���� drops
                my["sen"]--;
                attack();
        } 
        // (3) chat() may do anything -- include destruct(this_object())
        // objectp check is added for some strange this_object() return 0 reason.
        if(objectp(this_object()) && !userp(this_object())) {
                this_object()->chat();
                if(!this_object()) {
                        return;
                }
        }
        }
        
        // If busy, continue action and return here.
        if(is_busy()) {
                continue_action();
                return;
        } 
        if(tick--) {
                return;
        } else {
                tick = 5 + random(10);
        }

        
        cnd_flag = update_condition();
        if (!living(this_object())) return;
        // If we are compeletely in peace, turn off heart beat.
        // heal_up() must be called prior to other two to make sure it is called
        // because the && operator is lazy :P 
        if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up()) && !is_fighting() 
                        && !interactive(this_object())) {
                if(environment()) {
                        ob = first_inventory(environment());
                        while(ob && !interactive(ob)) {
                                ob = next_inventory(ob);
                        }
                }
                if(!ob && !query("ALWAYS_ACTIVE")) set_heart_beat(0);
        }
        if(!this_object()) return;
        if(!interactive(this_object())) return;
        
}  
void do_remove_defense(int num) {
        
        object weapon,me,*inv;
        int k;
        string weapon_type,weapon_skill,unarmed_skill;
        
        me=this_object();
        
        if (num) {
                unarmed_skill=query("skill_type_u");
                command("enable unarmed "+unarmed_skill);
                if (query("skill_type_w")) {
                if (sscanf(query("skill_type_w"),"%s/%s",weapon_type,weapon_skill)==2){
                        command("enable parry "+weapon_skill);
                        command("enable "+weapon_type+" "+weapon_skill);
                        weapon=query_temp("weapon");
                        if (!weapon || weapon->query("skill_type")!=weapon_type){
                                if (weapon) weapon->unwield();
//                              command ("unwield all");

                                inv=all_inventory(me);
                                for (k=0;k<sizeof(inv);k++){
                                        if (inv[k]->query("skill_type")==weapon_type)
                                                inv[k]->wield();
//                                              command("wield "+inv[k]->query("id"));
                                }                       
                        }
                }
                } else command("unwield all");
        }
} 
void do_defense(int n) {
        object me, *inv,weapon,newweapon;
        int k; 
        
        if (!n) return;
        me=this_object();
        switch (n) {
                case 1: map_skill("parry","xiaohun-sword");
                        map_skill("sword","xiaohun-sword");
                        weapon=me->query_temp("weapon");
                        if (!weapon || weapon->query("skill_type")!="sword")    {
                                if (weapon) weapon->unwield();
//                              command("unwield all");
                                inv=all_inventory(me);
                                for (k=0;k<sizeof(inv);k++){
                                        if (inv[k]->query("skill_type")=="sword")
//                                              command("wield "+inv[k]->query("id"));
                                                inv[k]->wield();
                                }
                                if (!query_temp("weapon"))
                                        carry_object("/obj/weapon/sword")->wield();
//                                      command("wield sword");
//                              command("say xiaohun enabled from clone weapon");       
                        }
                        break;
                case 2: map_skill("parry","xiaohun-whip");
                        map_skill("whip","xiaohun-whip");
                        weapon=me->query_temp("weapon");

                        if (!weapon || weapon->query("skill_type")!="whip")     {
//                              command("unwield all");
                                if (weapon) weapon->unwield();
                                inv=all_inventory(me);
                                for (k=0;k<sizeof(inv);k++){
                                        if (inv[k]->query("skill_type")=="whip")
//                                              command("wield "+inv[k]->query("id"));
                                                inv[k]->wield();
                                }
                                if (!query_temp("weapon"))
                                        carry_object("/obj/weapon/whip")->wield();
//                                      command("wield whip");
//                              command("say xiaohun enabled from clone weapon");       
                        }
                        break;
                case 3: command("unwield all");
                        map_skill("unarmed","yue-strike");
                        break;
                default: break;
                case 4: command("unwield all");
                        map_skill("unarmed","lingxi-zhi");
                        break;
                }               
}  
void cast_attack() {
        string cast_type;
        cast_type=this_object()->query("cast_attack");
        this_object()->set("mana",this_object()->query("max_mana"));
        this_object()->cast_spell(cast_type);
        this_object()->set("mana",this_object()->query("max_mana"));
        return;
}  
void sheet_fight() { 
        object obj, soldier, me;
        int spells;
        me = this_object();
        if( me->query_temp("max_guard") > 4 ) return;
        message_vision("$N���о��񣬼�����ζ�������һ����ʦ������������\n", me);
        me->start_busy(1);

        spells = me->query_skill("scratching");
        seteuid(getuid());
        if( random(10) < 5 )
                soldier = new("/obj/npc/heaven_soldier");
        else
                soldier = new("/obj/npc/hell_guard");
        soldier->move(environment(me));
        soldier->invocation(me, spells);
        soldier->set("possessed", me);
        me->add_temp("max_guard",1);
        message_vision(HIB "\n$N����$n�ı��󺰵�������ɱ��\n" NOR, me, soldier );
} 
void alchemy_fight() {
                
        string weapon_name,x;
        int i;
        object *enemy,weapon,owner,victim;
        switch( random(4)){
                case 0: weapon_name="zhui";
                        break;
                case 1: weapon_name="chain";
                        break;
                case 2: weapon_name="mirror";
                        break;
                case 3: weapon_name="flag";
                        break;
                }
        switch (weapon_name) {
                case "mirror": x="m";break;
                case "flag" : x="f";break;
                case "chain": x="c";break;
                case "zhui": x="z";break;
        }
        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        while(i--)       {
                weapon = new("/obj/specials/alchemy/magic/"+weapon_name);
                weapon->move(this_object());
                if(enemy[i] && objectp(enemy[i]) && environment(this_object())==environment(enemy[i])) {

                        if (!userp(enemy[i])) { 
                                if(owner=enemy[i]->query("possessed") && !owner->query_temp("shot")) {
                                        victim = owner;
                                        if (!victim->is_fighting()) {
                                                victim->set_temp("shot",1);
                                                kill_ob(victim);
                                                command("shoot"+x+" "+victim->get_id());
                                        }
                                }
                        }
                        this_object()->stop_busy();
                        command("shoot"+x+" "+enemy[i]->get_id());
                        this_object()->stop_busy();
                }
        }
        this_object()->start_busy(2);
        
        for (i=0;i<sizeof(enemy);i++){
                enemy[i]->delete_temp("shot");
        }
}  
void ask_help() {
        object me, *enemy, *inv, ob;
        string type;
        int i, j;
        
        me= this_object();
        type = me->query("dungeon_npc");
        if (!type) return;
        enemy = me->query_enemy();
        inv = all_inventory(environment(this_object()));
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (userp(ob) || !ob->is_character() || ob->is_corpse() 
                        || ob->query("dungeon_npc")!=type || ob==me) {
                        continue;
                }
                for (j=0;j<sizeof(enemy);j++) {
                        if (ob->is_fighting(enemy[j])) {

                                continue;
                                }
                        ob->kill_ob(enemy[j]);
                }               
        }
}  
void help_friend() {
        object me, *inv, ob;
        string type;
        int i, j;
        
        me= this_object();
        type = me->query("dungeon_npc");
        inv = all_inventory(environment(this_object()));
        
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (userp(ob) || !ob->is_character() || ob->is_corpse() 
                        || ob->query("dungeon_npc")!=type) {
                        continue;
                }
                if (ob->query("kee")>ob->query("max_kee")/3 
                        && ob->query("eff_kee")>ob->query("max_kee")/3
                        && ob->query("gin")>ob->query("max_gin")/3 
                        && ob->query("eff_gin")>ob->query("max_gin")/3
                        && ob->query("sen")>ob->query("max_sen")/3 
                        && ob->query("eff_sen")>ob->query("max_sen")/3)
                {
                        continue;
                }
                if (ob!=me)
                        message_vision(HIY "$N�����ڹ�������������$n���ģ������ؽ���������$n����....\n\n"NOR,me,ob);
                        else
                                message_vision(HIY "$N�����ڹ��������ؽ�������������ת....\n\n"NOR,me);
                        call_out("heal_him", 6, me, ob);
                        me->start_busy(1);
                        return;
                                
        }

        return;
}  
int heal_him(object me, object target)
{
        int amount;
        amount=6000;
        if (!objectp(me)) return 0;
        if (me->is_unconcious()) return 0;
        
        if (!present(target,environment(me))) {
                tell_object(me,"��Ҫ���ε����Ѿ����������ˡ�\n");
                return notify_fail("");
                }
        if (target!=me)
        message_vision(HIY"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me,target);
        else 
        message_vision(HIY"���˲��ã�$N�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me);
        target->receive_curing("kee", amount);
        target->receive_curing("sen", amount);
        target->receive_curing("gin", amount);
        if (target->query("kee")+ amount<target->query("max_kee"))
                target->add("kee",amount);
                else target->set("kee",target->query("max_kee"));
        if (target->query("sen")+ amount<target->query("max_sen"))
                target->add("sen",amount);
                else target->set("sen",target->query("max_sen"));
        if (target->query("gin")+ amount<target->query("max_gin"))
                target->add("gin",amount);
                else target->set("gin",target->query("max_gin"));
        return 1;
}  
int enemy_value(object *all_enm)
{
        int i,val,exp;
        val=0;
        exp=query("combat_exp");
        for(i=0;i<sizeof(all_enm);i++)
        {
                if(all_enm[i]->query("combat_exp")<exp*2/3)

                        val+=1;
                else if(all_enm[i]->query("combat_exp")<exp)
                        val+=3;
                else if(all_enm[i]->query("combat_exp")<exp*2)
                        val+=6;
                else val+=10;
        }
        return val;
} 
int enemy_type(object enemy) {
        string class_type;
        int type;
        object me;
        
        me=this_object();
        class_type=enemy->query("class");
//      message_vision("this is enemy type "+class_type+".\n",me);      
        switch (class_type) {
        //      this need cut mana by any means, then leave them alone
        case "taoist": if (enemy->query("mana")>200) type =1;
                                else type =6;
                        break;
        //      this needs cut mana than using special way to kill
        case "lama":    if (enemy->query("mana")>200) type =1;
                                else type =3;
                        break;
        //      this needs cut force if he is using shield, then put in asap kill
        case "shaolin": if (enemy->query("force")>50) type =2;
                                else type =3;
                        break;                          
        //      this needs to be killed asap purely due to their damage and busy power  
        case "fugui":
        case "legend":
        case "knight":
        case "huashan": type = 4;       break;
        //      this needs to be taken notice
        case "official": type = 5;      break;
        //      these are tricky classes and requires skills to play, so mostly we can 
        //      let them live a while.

        case "wudang":
        case "bonze":
        case "beggar":
        case "yinshi":
        case "shenshui":
        case "swordsman":
        case "assassin":
        case "bat":
        default:        type =6;        break;
        }
//      message_vision("this is enemy return "+(string)(type)+".\n",me);        
        return type;
}       
          
void die(){
        object book;
        int i;
        message_vision(HIR"\n$N�ҽ�һ��������ȥ������һ��������ʧ�ˡ�\n"NOR,this_object());     
        book = new("obj/money/silver");
        book->set_amount(10);
        book->move(environment(this_object()));
        destruct(this_object());        
}   

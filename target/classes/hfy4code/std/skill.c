 // Skill.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// This is the standard skill daemon object. All objects defining a skill
// should inherit this as its skeleton.
// 
// Last modification:
//              - 08/08/2001 by Daniel Q. Yu.
//                      * Rewriten the whole thing.                     
//
inherit F_CLEAN_UP; 
mapping skill_attr = ([
        "name"                                          : "武功",
        "type"                                          : "martial",
        "usage/axe"                                     : 0,
        "usage/blade"                           : 0,
        "usage/cursism"                         : 0,
        "usage/dagger"                          : 0,
        "usage/dodge"                           : 0,
        "usage/force"                           : 0,
        "usage/iron-cloth"                      : 0,
        "usage/literate"                        : 0,
        "usage/move"                            : 0,
        "usage/parry"                           : 0,
        "usage/spear"                           : 0,
        "usage/spells"                          : 0,
        "usage/whip"                            : 0,
        "usage/staff"                           : 0,
        "usage/unarmed"                         : 0,
        "learn_bonus"                           : 0,
        "practice_bonus"                        : 0,
        "black_white_ness"                      : 0,
        "effective_level"                       : 100,
        "bounce_ratio"                          : 0,
        "effect"                                : 100,
        "practice_damage"                       : 30,
        "practice_limit"                        : 200,
        "skill_class"                           : 0
   
]); 
mapping *action; 
void set(string prop, mixed value);
void setup(); 
void create() {
        seteuid(getuid());
        setup();
} 
void setup() {
        
}  
void set(string prop, mixed value) {
        skill_attr[prop] = value;
}  
int valid_effect(object me, object weapon, string action_name, int skill) 
{ 
        return 1;
}   
// name of this skill. Instead of need of dictionary, the name is defined 
// here.
string name() {
        return (string)skill_attr["name"];
} 
// 
// type()
//
// This function should return the type of the skill. The skill type now
// affects if the skill requires combat exp in order to be learned (see
// /cmds/std/learn.c ) and the ranking of a skill level (see 
// /cmds/usr/skills.c )。
// Currently we have only 2 types of skill: "martial" and "knowledge". 
string type() { 
        return (string)skill_attr["type"]; 
} 
int learn_bonus() {
        return (int)skill_attr["learn_bonus"];
} 
int practice_bonus() {
        return (int)skill_attr["practice_bonus"];
} 
int black_white_ness() {
        return (int)skill_attr["black_white_ness"];
} 
int effective_level() {
        return (int)skill_attr["effective_level"];
} 
int effect() {
        return (int)skill_attr["effect"];
} 
string skill_class() {
        return (string)skill_attr["skill_class"];
} 
// this is to define how high we allow a skill to be practiced
int practice_limit() {
        return (int)skill_attr["practice_limit"];
} 
//
// valid_learn()
//
// This function is to check if a character should be able to 
// learn/study/practice the skill. The default function just
// returns 1 to allow any characters improve the skill. However,
// a good skill should has its own feature and restriction. Redefine
// this function in your skill object and make it reasonable 
// according to the power of the skill. 
int valid_learn(object me) { 
        object weapon, s_weapon;
        string* w_skills = ({ "axe", "blade", "dagger", "fork", "hammer", "spear", 
                        "staff", "sword", "throwing", "whip" }); 
        int i; 
        weapon = me->query_temp("weapon");
        s_weapon = me->query_temp("secondary_weapon");
        if(skill_attr["usage/unarmed"] || base_name(this_object()) == SKILL_D("unarmed")) {
                if(weapon || s_weapon) {
                        return notify_fail("学习或练习" + skill_attr["name"] + "必须空手。\n");
                }
        } 
        for(i=0; i<sizeof(w_skills); i++) {
                if(skill_attr["usage/" + w_skills[i]] 
                           || base_name(this_object()) == SKILL_D(w_skills[i])) {                 
                        if(!objectp(weapon) && !objectp(s_weapon)) {
                                return notify_fail("空手无法学习或练习" + skill_attr["name"] + "。\n");
                        } 
                        if((!objectp(weapon) || weapon->query("skill_type") != w_skills[i])
                                && (!objectp(s_weapon) || s_weapon->query("skill_type") != w_skills[i])) {
                                return notify_fail("不能使用" + weapon->name() + "学习或练习" + skill_attr["name"] + "。\n");
                        }
                }
        }
        return 1;
} 
//
// skill_improved()
//
// This function is called when a character's skill has gained a new level.
// You can make some modify to a character according to the skill. 
void skill_improved(object me) {} 
mapping query_action(object me, object weapon) {
        if(sizeof(action) > 0) {
                return action[random(sizeof(action))];
        }
} 
string query_absorb_msg() {
        mapping msg; 
        msg = skill_attr["absorb_msg"];
        
        if(sizeof(msg) > 0) {   
                return msg[random(sizeof(msg))];
        }
        
        return 0;
} 
string query_dodge_msg() {
        mapping msg; 
        msg = skill_attr["dodge_msg"];
        
        if(sizeof(msg) > 0) {   
                return msg[random(sizeof(msg))];
        }
   
        return 0;
} 
string query_parry_msg(object weapon) {
        mapping msg;
        
        if(objectp(weapon)) {
                msg = skill_attr["parry_msg"];
        }
        
        if(sizeof(msg) == 0) {
                msg = skill_attr["unarmed_parry_msg"];
        }
        
        if(sizeof(msg) > 0) {
                return msg[random(sizeof(msg))];
        }
        
        return 0;
}  
int valid_enable(string usage) {
        return skill_attr["usage/" + usage];
} 
int bounce_ratio()
{
        return skill_attr["bounce_ratio"];
} 
int practice_skill(object me) {
        object weapon; 
        if(skill_attr["type"] == "knowledge") {
                return notify_fail(skill_attr["name"] + "只能用学的。\n");
        }
        
        if(skill_attr["usage/literate"] || skill_attr["usage/perception"]
                || skill_attr["usage/iron-cloth"])
                return notify_fail(skill_attr["name"] + "只能用学的。\n");              
                
                
        if(skill_attr["usage/force"]) {
                return notify_fail(skill_attr["name"] + "只能用学的，或是从运用(exert)中增加熟练度。\n");
   }
        
        if((int)me->query("kee") < skill_attr["practice_damage"]) {
                return notify_fail("你的体力不够练" + skill_attr["name"] + "，还是先休息休息吧。\n");
        }
        
        me->receive_damage("kee", skill_attr["practice_damage"]);
        return 1;
} 
//
// exert_function()
//
//     This function is used by the "exert" command as specific skill's 
// command parser. This function parses the arguments in the standard form
// (that is, exert <function> [<target>] [<amount>]). When <target> is not 
// present, use the character himself as default. When amount is not present
// use default amount which is different for each function.
//     In order to use this default exert command parser, you must define
// a function called exert_function_file(string func) in the skill object
// that takes the function name as argument and return the file name that
// defines the specified function.  
int exert_function(object me, string arg) {
        string func, target, file;
        object target_ob;
        int    amount; 
        amount = -1;
        if(sscanf(arg, "%s %s %d", func, target, amount)==3) {
                target_ob = present(target, environment(me));
                if(!target_ob) {
                        return notify_fail("这里没有 " + target + "。\n");
                }
        } else if(sscanf(arg, "%s %d", func, amount)==2) {
                target_ob = me;
        } else if(sscanf(arg, "%s %s", func, target)==2) {
                target_ob = present(target, environment(me));
                if(!target_ob) {
                        return notify_fail("这里没有 " + target + "。\n");
                }
        } else {
                func = arg;
           target_ob = me;
        }
        
        notify_fail("你所选用的内功中没有这种技能。\n");
        if((func == "heal") 
                        && target_ob->query("eff_kee") == target_ob->query("max_kee")) {
                return notify_fail("你或者你要疗伤的对象并没有受伤。\n");
        }
        if((func == "lifeheal") 
                        && target_ob->query("kee") == target_ob->query("max_kee")) {
                return notify_fail("你或者你要疗伤的对象并没有受伤。\n");
        }
        
        if(stringp(skill_attr["skill_class"])) {
                file = replace_string(file_name(this_object()), SKILL_D(""), 
                                CLASS_D(skill_attr["skill_class"] + "/")) + "/" + func + ".c";
                if(file_size(file) > 10) {
                        return (int)call_other(file, "exert", me, target_ob, amount);
                }
        }
        file = CLASS_D("GENERIC/FORCE/") + func + ".c";
        if(file_size(file) > 10) {
                return (int)call_other(file, "exert", me, target_ob, amount);
        }
        return 0;
} 
int perform_action(object me, string arg) {
        string action, target, file;
        object target_ob;
        object weapon;
        int i;
        
        if(sscanf(arg, "%s %s", action, target)==2 ) {
                target_ob = present(target, environment(me));
                if( !target_ob ) {
                        return notify_fail("这里没有 " + target + "。\n");
                }
        } else {
                action = arg;
        }
   
        notify_fail("你所选用的武功中没有这种必杀技。\n");
        
        if (me->query_temp("till_death/lockup")==1)
                return notify_fail(" （你血脉不畅，真气受滞，一时竟然运不起外功。）\n");  
        if (me->query_temp("till_death/shield_lock")==1)
                return notify_fail(" （使用护体真气时不能分心。）\n"); 
        if( me->is_busy() )
                return notify_fail("（你现在正忙着呢。） \n");
        
        if(stringp(skill_attr["skill_class"])) {
                file = replace_string(file_name(this_object()), SKILL_D(""), 
                                CLASS_D(skill_attr["skill_class"] + "/")) + "/" + action + ".c";
                if(file_size(file) > 10) {
                        return (int)call_other( file, "perform", me, target_ob);
                }
        }
        file = CLASS_D("GENERIC/PERFORM/") + action + ".c";
        if(file_size(file) > 10) {
                return (int)call_other( file, "perform", me, target_ob);
                
        }
        return 0;
} 
int perform_target(object me,string perform,object target)
{
        string file;
        string s_type;
        object weapon;
        
        notify_fail("你所选用的武功中没有这种必杀技。\n"); 
        
        weapon=me->query_temp("weapon");
        if(objectp(weapon))
                s_type=weapon->query("skill_type");
        else
                s_type="unarmed";
        if(!skill_attr["usage/"+s_type]&&!skill_attr["usage/dodge"])
                return notify_fail(" skill not matched\n");
        if (me->query_temp("till_death/lockup")==1)
                   return notify_fail(" （你血脉不畅，真气受滞，一时竟然运不起外功。）\n");  
        if (me->query_temp("till_death/shield_lock")==1)
                return notify_fail(" （使用护体真气时不能分心。）\n");   
        if( me->is_busy() )
                return notify_fail("（你现在正忙着呢。） \n");                  
        
        if(stringp(skill_attr["skill_class"])) {
                file = replace_string(file_name(this_object()), SKILL_D(""), 
                                CLASS_D(skill_attr["skill_class"] + "/")) + "/" + perform + ".c";
                if(file_size(file) > 10) {
                        return (int)call_other(file, "perform", me, target);
                }
        }
        file = CLASS_D("GENERIC/PERFORM/") + perform + ".c";
        if(file_size(file) > 10) {
                return (int)call_other(file, "perform", me, target);
        }
        return 0;
} 
int cast_spell(object me, string spell, object target) {
        string file; 
        notify_fail("你所选用的咒文系中没有这种咒文。\n");
        
        if (me->query_temp("till_death/lockup")==1)
                return notify_fail(" （你血脉不畅，真气受滞，一时竟然不能念咒文。）\n");  
        if (me->query_temp("till_death/shield_lock")==1)
                return notify_fail(" （使用护体真气时不能分心。）\n");   
        if( me->is_busy() )
                return notify_fail("（你现在正忙着呢。） \n");                  
        
        if(stringp(skill_attr["skill_class"])) {
                file = replace_string(file_name(this_object()), SKILL_D(""), 
                                CLASS_D(skill_attr["skill_class"] + "/")) + "/" + spell + ".c";
                if(file_size(file) > 10) {
                        return (int)call_other(file, "cast", me, target);
                }
        }
        file = CLASS_D("GENERIC/CAST/") + spell + ".c";
        if(file_size(file) > 10) {
                return (int)call_other(file, "cast", me, target);
   }
        return 0;
} 
int curse_curses(object me, string curse, object target) {
        string file;
        
        notify_fail("你所选用的降头术中没有这种降头。\n");
        
        if (me->query_temp("till_death/lockup")==1)
                return notify_fail(" （你血脉不畅，真气受滞，一时竟然下不了降头。）\n");  
        if (me->query_temp("till_death/shield_lock")==1)
                return notify_fail(" （使用护体真气时不能分心。）\n"); 
        if( me->is_busy() )
                return notify_fail("（你现在正忙着呢。） \n");
                        
        if(stringp(skill_attr["skill_class"])) {
                file = replace_string(file_name(this_object()), SKILL_D(""), 
                                CLASS_D(skill_attr["skill_class"] + "/")) + "/" + curse + ".c";
                if(file_size(file) > 10) {
                        return (int)call_other(file, "curse", me, target);
                }
        }
        file = CLASS_D("GENERIC/CURSE/") + curse + ".c";
        if(file_size(file) > 10) {
                return (int)call_other(file, "curse", me, target);
        }
        return 0;
} 
int conjure_magic(object me, string spell, object target) {
        string file; 
        notify_fail("你所选用的法术系中没有这种法术。\n");
        
        if (me->query_temp("till_death/lockup")==1)
                return notify_fail(" （你血脉不畅，真气受滞，一时竟然不能施展神通。）\n");  
        if (me->query_temp("till_death/shield_lock")==1)
                return notify_fail(" （使用护体真气时不能分心。）\n"); 
        if( me->is_busy() )
                return notify_fail("（你现在正忙着呢。） \n");
                        
        if(stringp(skill_attr["skill_class"])) {
           file = replace_string(file_name(this_object()), SKILL_D(""), 
                                CLASS_D(skill_attr["skill_class"] + "/")) + "/" + spell + ".c";
                if(file_size(file) > 10) {
                        return (int)call_other(file, "conjure", me, target);
                }
        }
        file = CLASS_D("GENERIC/CONJURE/") + spell + ".c";
        if(file_size(file) > 10) {
                return (int)call_other(file, "conjure", me, target);
        }
        return 0;
} 
int scribe_spell(object me, object ob, string spell) {
        string file; 
        notify_fail("你所选用的符之术中没有这种符术。\n");
        
        if(stringp(skill_attr["skill_class"])) {
                file = replace_string(file_name(this_object()), SKILL_D(""), 
                                CLASS_D(skill_attr["skill_class"] + "/")) + "/" + spell + ".c";
                if(file_size(file) > 10) {
                        return (int)call_other( file, "scribe", me, ob );
                }
        }
        file = CLASS_D("GENERIC/CONJURE/") + spell + ".c";
        if(file_size(file) > 10) {
                return (int)call_other( file, "scribe", me, ob );
        }
        return 0;
} 
varargs mixed hit_ob(object me, object victim, int damage_bonus, int factor) {
        int damage;
        
        if(skill_attr["usage/force"]) {
                damage = (int)me->query_skill("force")/20 + factor 
                                - (int)victim->query_skill("force")/100;
                
                if(damage < 0) {
                        if(!me->query_temp("weapon") && random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
                                damage = -damage;
                                me->receive_damage("kee", damage * 2 );
                           me->receive_wound("kee", damage );
                                if(damage < 10) {
                                        return "$N受到$n的内力反震，闷哼一声。\n";
                                } else if( damage < 20 ) {
                                        return "$N被$n以内力反震，「嘿」地一声退了两步。\n";
                                } else if( damage < 40 ) {
                                        return "$N被$n以内力一震，胸口有如受到一记重击，连退了五六步！\n";
                                } else {
                                        return "$N被$n的内力一震，眼前一黑，身子向後飞出丈许！！\n";
                                }
                        }
                        if(damage_bonus + damage < 0) {
                                return -damage_bonus;
                        }
                        return damage;
                }
                
                damage -= victim->query_temp("apply/armor_vs_force");
                if(damage_bonus + damage < 0) {
                        return - damage_bonus;
                }
                return random(damage) * 2 + 1;
        }
        return 0;
} 

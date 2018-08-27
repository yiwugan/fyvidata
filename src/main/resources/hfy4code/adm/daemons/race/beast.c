 // beast.c
#include <race/beast.h> 
mapping combat_action =
([
        "hoof": ([
                "action":               "$N�ú�����$n��$l�������",
                "damage":               100,
                "damage_type":  "����",
        ]),
        "bite": ([
                "action":               "$N������������$n��$l�ݺݵ�һҧ",
                "damage":               20,
                "damage_type":  "ҧ��",
        ]),
        "claw": ([
                "action":               "$N˫צ��$n��$l����һ˺",
                "damage_type":  "ץ��",
        ]),
        "poke": ([
                "action":               "$N��ǰ��$n��$lһ��",
                "damage":               30,
                "damage_type":  "����",
        ]),
        "kick": ([
                "action":               "$Nƴ����$n��$lײȥ",
                "damage":               30,
                "damage_type":  "����",
        ]),
        "endd": ([
                "action":               "$Nβ��������$n��$lһɨ",
                "damage":               30,
                "damage_type":  "����",
        ]),
        "dragonslash": ([
                "action":               "$N���۹��࣬Ծ��$n��ǰ����צ��$n��$lһɨ",
                "damage":               100,
                "parry" :               400,
                "dodge" :               400,
                "damage_type":  "ץ��",
        ]),
        "dragonbreath": ([
                "action":               "$Nһ�������������ʱ���ذ���������ɳ��ʯ����ǵص���$n��ȥ",
                "damage":               100,
                "parry" :               200,
                "dodge" :               200,
                "damage_type":  "����",
        ]),
        "dragonbite": ([
                "action":               "$N�ſ�Ѫ���ڣ��䲻����$n��$lһ��ҧ��",
                "damage":               400,
           "parry" :               400,
                "dodge" :               100,
                "damage_type":  "ҧ��",
        ]),
        "dragonswing": ([
                "action":               "$N����޴����������β�ڿ��л�������������֮����$n�ͻ�����",
                "damage":               200,
                "parry" :               500,
                "dodge" :               100,
                "damage_type":  "ץ��",
        ]),
        "dragonthrow": ([
                "action":               "$N����һ���������������ֳ�������������Ȼ������ҫ����Ƭ������$n��$l����",
                "damage":               200,
                "parry" :               100,
                "dodge" :               400,
                "damage_type":  "ץ��",
        ]),
        "dragonpoke": ([
                "action":               "$N�������Ұڶ�����������ʮ�����룬���ŷ���֮����$n��$l��ȥ",
                "damage":               100,
                "parry" :               100,
                "dodge" :               100,
                "damage_type":  "ץ��",
        ]),
]); 
string *actions; 
void create()
{
        actions = keys(combat_action);
} 
void setup_beast(object ob)
{
        mapping my;
        my = ob->query_entire_dbase(); 
        my["unit"] = "ֻ"; 
        if( undefinedp(my["actions"]) || !my["actions"]) {
                if( pointerp(my["verbs"]) )
                        ob->set("default_actions", (: call_other, __FILE__, "query_action" :) );
                else
                   my["default_actions"] = ([
                                "action": "$N����$n��%s��%s\n",
                        ]);
        }
        
        if( undefinedp(my["gender"]) ) my["gender"] = "����";
        if( undefinedp(my["age"]) ) my["age"] = random(30) + 5; 
        if( undefinedp(my["str"]) ) my["str"] = random(25) + 5;
        if( undefinedp(my["cor"]) ) my["cor"] = random(21) + 5;
        if( undefinedp(my["int"]) ) my["int"] = random(21) + 5;
        if( undefinedp(my["spi"]) ) my["spi"] = 0;
        if( undefinedp(my["cps"]) ) my["cps"] = random(21) + 5;
        if( undefinedp(my["per"]) ) my["per"] = random(21) + 5;
        if( undefinedp(my["con"]) ) my["con"] = random(21) + 5;
        if( undefinedp(my["agi"]) ) my["agi"] = random(21) + 15;
        if( undefinedp(my["dur"]) ) my["dur"] = random(2) + 1;
        if( undefinedp(my["fle"]) ) my["fle"] = random(21) + 5;
        if( undefinedp(my["tol"]) ) my["tol"] = random(21) + 5;  
        if( undefinedp(my["max_gin"]) ) {
                if( my["age"] <= 3 ) my["max_gin"] = 50;
                else if( my["age"] <= 10 ) my["max_gin"] = 50 + (my["age"] - 3) * 20;
                else if( my["age"] <= 30 ) my["max_gin"] = 190 + (my["age"] - 10) * 5;
                else my["max_gin"] = my["max_gin"] = 290 + (my["age"] - 30);
        }
        if( undefinedp(my["max_kee"]) ) {
                if( my["age"] <= 5 ) my["max_kee"] = 50;
                else if( my["age"] <= 20 ) my["max_kee"] = 50 + (my["age"] - 5) * 25;
                else my["max_kee"] = my["max_kee"] = 425 + (my["age"] - 20) * 5;
        }
        if( undefinedp(my["max_sen"]) ) {
                if( my["age"] <= 20 ) my["max_sen"] = 50;
                else my["max_sen"] = 50 + (my["age"] - 20) * 10;
        } 
        //      NOTE: beast has no initial limbs defined, you must define it yourself.
        //      ob->init_limbs(LIMBS);
        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 200);
} 
mapping query_action(object me)
{
        string *act; 
   act = me->query("verbs");
        return combat_action[act[random(sizeof(act))]];
} 

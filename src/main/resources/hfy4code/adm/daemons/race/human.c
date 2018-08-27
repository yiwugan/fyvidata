 // human.c
// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000 
inherit F_DBASE; 
mapping *combat_action = ({
        ([      "action":               "$N��ȭ����$n��$l",
                "damage_type":  "����",
        ]),
        ([      "action":               "$N��$n��$lһץ",
                "damage_type":  "ץ��",
        ]),
        ([      "action":               "$N��$n��$l�ݺݵ�����һ��",
                "damage_type":  "����",
        ]),
        ([      "action":               "$N����ȭͷ��$n��$l��ȥ",
                "damage_type":  "����",
        ]),
        ([      "action":               "$N��׼$n��$l�����ӳ�һȭ",
                "damage_type":  "����",
        ]),
}); 
void create() {
        seteuid(getuid());
        set("unit", "λ");
        set("gender", "����");
        set("can_speak", 1);
        set("attitude", "peaceful");
        set("limbs", ({
                "ͷ��", "����", "�ؿ�", "����", "���", "�Ҽ�", "���",
                "�ұ�", "����", "����", "����", "С��", "����", "����",
                "���", "�ҽ�", "����", "����", "ǰ��", "��", "ü��",
                "����", "��", "���", "�ҿ�", "����", "����", "����",
                "���", "�Ҽ�"
        }) );
}   
//      NPC bonus from EXP 
void setup_human(object ob) {
        mapping my;
        int combat_exp, bonus, bonus_str, bonus_others;
        my = ob->query_entire_dbase();
   combat_exp = my["combat_exp"];
        bonus_str=0;
        bonus_others=0; 
//      Setting Bonus HP for NPC from exp
        if(combat_exp < 200001) {
                bonus = combat_exp * 0.004;     
        } else if(combat_exp < 3000001) {
                bonus = combat_exp * 0.001 + 900;
        } else if(combat_exp < 7000001) {
                bonus = combat_exp * 0.0003 + 4000;
        } else if(combat_exp< 10000001) {
                bonus = combat_exp * 0.0001 + 6000;
        } else  bonus = 8000;
        bonus=bonus*85/100;  //3-18-2002 to tune down NPC hp 
//      Setting str bonus to NPC, since they don't have enforce nor unarmed bonus       
//      setting int/spi/agi/fle/dur/con bonus to NPC according to their levels 
        if (!userp(ob)) {
                if(combat_exp < 10001) {
                        bonus_str = 1+random(10);
                        bonus_others = 1+random(10);
                } else if(combat_exp < 50001) {
                        bonus_str = 3 + random(10);
                        bonus_others = 3 + random(10);
                } else if(combat_exp < 100001) {
                        bonus_str = 5 + random(10);
                        bonus_others = 4 + random(10);
                } else if(combat_exp < 200001) {
                        bonus_str = 10 + random(10);
                        bonus_others = 5 + random(10);
                } else if(combat_exp < 300001) {
                        bonus_str = 12 + random(10);
                        bonus_others = 7 + random(10);
                } else if(combat_exp < 400001) {
                        bonus_str = 14 + random(10);
                        bonus_others = 9 + random(10);  
                } else if(combat_exp < 500001) {
                        bonus_str = 16 + random(20);
                        bonus_others = 10 + random(10); 
                } else if(combat_exp < 800001) {
                        bonus_str = 17 + random(20);
                   bonus_others = 11 + random(10);
                } else if(combat_exp < 1000001) {
                        bonus_str = 18 + random(20);
                        bonus_others = 12 + random(10);
                } else if(combat_exp < 2000001) {
                        bonus_str = 19 + random(20);
                        bonus_others = 13 + random(10);
                } else if(combat_exp < 3000001) {
                        bonus_str = 24 + random(20);
                        bonus_others = 14 + random(10);
                } else if(combat_exp< 3500001) {
                        bonus_str = 30 + random(20);
                        bonus_others = 15 + random(10);
                } else if(combat_exp< 4000001) {
                        bonus_str = 34 + random(20);
                        bonus_others = 20 + random(10);
                } else if(combat_exp< 4500001) {
                        bonus_str = 36 + random(20);
                        bonus_others = 20 + random(10);
                } else if(combat_exp< 5000001) {
                        bonus_str = 38 + random(20);
                        bonus_others = 20 + random(10);
                } else if(combat_exp< 7000001) {
                        bonus_str = 40 + random(20);
                        bonus_others = 25 + random(10);
                } else  if (combat_exp< 10000001) {
                        bonus_str = 40 + random(20);
                        bonus_others = 25 + random(10);
                } else { bonus_str = 50 + random(20);   
                         bonus_others = 25 + random(10);
                }
        }
          
//      Adding attributes bonus to NPCs 
//      Set default attr. for PC and NPC
        ob->set("default_actions", (: call_other, __FILE__, "query_action" :)); 
        if(undefinedp(my["national"])) my["national"] = "����";
        if(undefinedp(my["age"])) my["age"] = random(30) + 15; 
        if(undefinedp(my["str"])) my["str"] = 10 + bonus_str;
        if(undefinedp(my["cor"])) my["cor"] = 5  + bonus_others;
   if(undefinedp(my["int"])) my["int"] = 10 + bonus_others;
        if(undefinedp(my["spi"])) my["spi"] = 10 + bonus_others;
        if(undefinedp(my["cps"])) my["cps"] = 5  + bonus_others;
        if(undefinedp(my["per"])) my["per"] = random(20) + 5 ;
        if(undefinedp(my["con"])) my["con"] = 10 + bonus_others;
        if(undefinedp(my["kar"])) my["kar"] = random(10) + 10;
        if(undefinedp(my["agi"])) my["agi"] = 10 + bonus_others;
        if(undefinedp(my["dur"])) my["dur"] = 10 + bonus_others;
        if(undefinedp(my["fle"])) my["fle"] = 10 + bonus_others;
        if(undefinedp(my["tol"])) my["tol"] = random(20) + 5; 
          
//      Setting NPC and PC Gin/Kee/Sen,
//      Add bonus to NPC according to their levels since they don't meditate/respirate/exercise
//      Add bonus to PC above 1M to promote level difference 
        if(userp(ob) || undefinedp(my["max_gin"])) {
                if(my["age"] <= 14) {
                        my["max_gin"] = 100 + my["spi"]*10;
                } else if( my["age"] <= 20 ) {
                        my["max_gin"] = 100 + (my["age"] - 14) * 20  + my["spi"]*10;
                } else if( my["age"] <= 30 ) {
                         my["max_gin"] = 220  + my["spi"]*10;
                } else if( my["age"] <= 60 ) {
                        my["max_gin"] = 220 - (my["age"] - 30) * 5  + my["spi"]*10;
                } else {
                        my["max_gin"] = 70  + my["spi"]*10;
                }
                if(my["max_atman"] > 0) {
                        my["max_gin"] += my["max_atman"]*3/2 ;
                }
                my["max_gin"] += my["dur"]*my["dur"]; 
                if(!userp(ob)) {
                        my["max_gin"] += bonus / 2;
                }
                else my["max_gin"] += (my["max_gin"]*(combat_exp/1000000))/(10+6000000/(combat_exp+10));
        }
        
        if(userp(ob) || undefinedp(my["max_kee"])) {
                if(my["age"] <= 14) {
                        my["max_kee"] = 100 + my["con"]*10;
                } else if(my["age"] <= 20) {
                   my["max_kee"] = 100 + (my["age"] - 14) * 20 + my["con"]*10;
                } else {
                        my["max_kee"] = 220 + my["con"]*10;
                }
                if(my["max_force"] > 0) {
                        my["max_kee"] += my["max_force"]*2;
                }
                my["max_kee"] += my["dur"]*my["dur"];
                if(!userp(ob)) {
                        my["max_kee"] += bonus; 
                }
                else my["max_kee"] += 2*(my["max_kee"]*(combat_exp/1000000))/(10+6000000/(combat_exp+10));
        }
        
        if(userp(ob) || undefinedp(my["max_sen"])) {
                if(my["age"] <= 30) {
                        my["max_sen"] = 100 + my["int"]*10;
                } else {
                        my["max_sen"] = 100 + (my["age"] - 30) * 5 + my["int"]*10;
                }
                if(my["max_mana"] > 0) {
//                      my["max_sen"] += my["max_mana"] ;
                        my["max_sen"] += my["max_mana"]*3/2 ;
                }
                my["max_sen"] += my["dur"]*my["dur"];
                if(!userp(ob)) {
                        my["max_sen"] += bonus / 2;     
                }
                else my["max_sen"] += (my["max_sen"]*(combat_exp/1000000))/(10+6000000/(combat_exp+10));
        } 
        ob->set_default_object(__FILE__);
        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 200);
} 
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}    

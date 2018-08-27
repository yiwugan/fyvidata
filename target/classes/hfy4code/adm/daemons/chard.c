 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// chard.c 
#include <race.h> 
void create() { seteuid(getuid()); }
void setup_char(object ob)
{
        string race;
        mapping my;
        if( !stringp(race = ob->query("race")) ) {
                race = "����";
                ob->set("race", "����");
        }
                
        switch(race) {
                case "������":
                case "����":
                        HUMAN_RACE->setup_human(ob);
                        break;
                case "��ħ":
                        MONSTER_RACE->setup_monster(ob);
                        break;
                case "Ұ��":
                        BEAST_RACE->setup_beast(ob);
                        break;
                default:
                        error("Chard: undefined race " + race + ".\n");
        } 
        my = ob->query_entire_dbase(); 
        if( undefinedp(my["gin"]) ) my["gin"] = my["max_gin"];
        if( undefinedp(my["kee"]) ) my["kee"] = my["max_kee"];
        if( undefinedp(my["sen"]) ) my["sen"] = my["max_sen"]; 
        if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
        if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
        if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"]; 
        if( !ob->query_max_encumbrance() )
                ob->set_max_encumbrance( my["str"] * 20000 ); 
        ob->reset_action();
} 
varargs object make_corpse(object victim, object killer) {
        int i;
        object corpse, *inv;
        
        if(!victim->is_ghost() && !victim->is_zombie()) {
                corpse = new(CORPSE_OB);
                corpse->set_name(victim->name(1) + "��ʬ��", ({ "corpse" }) );
                corpse->set("long", victim->long(1) + "Ȼ����" 
                                + gender_pronoun(victim->query("gender")) 
                                + "�Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n");
                corpse->set("age", victim->query("age"));
                corpse->set("gender", victim->query("gender"));
                corpse->set("race", victim->query("race"));
                corpse->set("victim_name", victim->name(1));
                if (victim->query("possessed")) corpse->set("possessed",1);
                if (victim->query("owner")) corpse->set("possessed",1);
                corpse->set_weight(victim->query_weight()  * (userp(victim)? 100: 1));
                corpse->set_max_encumbrance(victim->query_max_encumbrance());
                corpse->set("family", victim->query("family"));
                corpse->move(environment(victim));
        } else if(victim->is_ghost()) {
                message_vision("�˵�һ����$N����һ�����̱��紵ɢ�ˡ�\n", victim);                               
        } else {
                message_vision("$N�����ص�����������Ϊһ̲Ѫˮ��\n", victim);           
        }
        
        // Don't let wizard left illegal items in their corpses.
        if(!wizardp(victim)) {
                inv = all_inventory(victim);
                inv->owner_is_killed(killer);
                inv -= ({ 0 });
                i = sizeof(inv);
                while(i--) {
                        if(!inv[i]->query("no_drop")) {
                                if(objectp(corpse)) {
                                        if((string)inv[i]->query("equipped")=="worn") {
                                                inv[i]->unequip();                              
                                                inv[i]->move(corpse);
                                                inv[i]->wear();
                                        } else if((string)inv[i]->query("equipped")=="wielded") {
                                           inv[i]->unequip();                              
                                                inv[i]->move(corpse);
                                                inv[i]->wield();
                                        } else {
                                                inv[i]->move(corpse);
                                        }       
                                } else {
                                        inv[i]->move(environment(victim));      
                                }                               
                        }
                }
        }
        return corpse;
}

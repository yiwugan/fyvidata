#include <ansi.h>
#include <weapon.h>  
mixed hit_ob(object me,object victim){       
        
        string my_attr = me->query("attribute_mark");
        string attr = (string) this_object()->query("attribute");            
        int dam =1;
        if (my_attr !=  attr) return 0;
        if (random(3)) return 0;
        if(attr == "fire") {
                    dam = me->query("force")/4 ;
                    if (victim->query("attribute_mark")== "gold") dam *= 3; 
                    victim->receive_damage("kee",dam, me);
                    return HIR"$N����"NOR+ this_object()->name() + HIR "�����Ѥ���ĺ�ɫ���棬ϯ����$nȫ��\n"NOR;
        } else if(attr == "water"){
                    dam = me->query("mana")/3 ;
                    if (victim->query("attribute_mark")== "fire") dam *= 2; 
                    victim->receive_damage("sen",dam, me);
                    return HIW"$N����"NOR+ this_object()->name() + HIW "͸��˿˿����ϯ����$nȫ��\n"NOR;
        } else if(attr == "wood"){
                    dam = me->query("atman")/2 ;
                    if (victim->query("attribute_mark")== "earth") dam *= 2; 
                    victim->receive_damage("gin",dam, me);
                    return HIC"$N����"NOR+ this_object()->name() + HIC "�Ϻ�Ȼ����һ����������$n���壡\n"NOR;
        } else if(attr == "gold"){
                    dam = me->query_str() * 10 ;
                    if (victim->query("attribute_mark")== "wood") dam *= 3; 
                    victim->receive_damage("kee",dam, me);
                    return HIY"$N����"NOR+ this_object()->name() + HIY "�����񲻿ɵ���ɭɭ���������$nȫ��\n"NOR;
        } else if(attr == "earth"){
                    dam = me->query("kee")/10 ;
                    if (victim->query("attribute_mark")== "water") dam *= 2; 
                    victim->receive_damage("kee",dam, me);
                    return NOR MAG"$N����"NOR+ this_object()->name() +NOR MAG "�����������ɽ��������ѹ��$n������������\n"NOR;
        }
        return 0; 
} 
